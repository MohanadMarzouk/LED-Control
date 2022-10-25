/******************************************************************************
 *
 * Module: IntCtrl
 *
 * File Name: IntCtrl.c
 *
 * Description: Functions declaration of Interrupt Driver
 *
 * Authors: Mohanad Marzouk
 *
 *******************************************************************************/

#include "MCAL/inc/IntCtrl.h"

/************************************************************************************
 * Service Name: IntCtrl_init
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): None
 * Parameters (out): None
 * Return value: None
 * Description: Initializes driver based on the user's configurations
 ************************************************************************************/
void IntCtrl_init(void)
{

    uint8 Priority;

    volatile uint32 * Ptr = NULL_PTR;

    APINT = (VECTKEY << 16) | ( IntCtrl_Gr_SubGr_cfg << 8);

    uint8 count;
    for(count = 0; count < NO_OF_INT; count++)
    {
        IntCtrl_IntGroup Gr_Pri_Value = IntCtrlConfig[count].intGroup;
        IntCtrl_IntSubGroup SubGr_Pri_Value = IntCtrlConfig[count].intSubGroup;
        switch(IntCtrl_Gr_SubGr_cfg)
        {
        case NVIC_PRI_GR8_SUBGR1:
            Priority = Gr_Pri_Value;
            break;
        case NVIC_PRI_GR1_SUBGR8:
            Priority = SubGr_Pri_Value;
            break;
        case NVIC_PRI_GR4_SUBGR2:
            Priority = ((Gr_Pri_Value << 1) & 0x06) | (SubGr_Pri_Value & 0x01);
            break;
        case NVIC_PRI_GR2_SUBGR4:
            Priority = ((Gr_Pri_Value << 2) & 0x04) | (SubGr_Pri_Value & 0x03);
            break;
        }

        if(IntCtrlConfig[count].intType <0)
        {
            // adjust priority of system exception only and go to next iteration
            switch (IntCtrlConfig[count].intType)
            {
            case MEM_MANAG_FAULT:
                NVIC_SYS_PRI1_R |= (Priority << 5);
                break;
            case BUS_FAULT:
                NVIC_SYS_PRI1_R |= (Priority << 13);
                break;
            case USAGE_FAULT:
                NVIC_SYS_PRI1_R |= (Priority << 21);
                break;
            case SVC:
                NVIC_SYS_PRI2_R |= (Priority << 29);
                break;
            case DEBUG:
                NVIC_SYS_PRI3_R |= (Priority << 5);
                break;
            case PENDSV:
                NVIC_SYS_PRI3_R |= (Priority << 21);
                break;
            case SYSTICK:
                NVIC_SYS_PRI3_R |= (Priority << 29);
                break;
            default:
                break;
            }
            continue;
        }
        if(IntCtrlConfig[count].status == ENABLED)
        {
            Ptr = &NVIC_PRI0_R;
        }

        else
        {
            continue;
        }

        Ptr += ((uint32)(IntCtrlConfig[count].intType / 4));

        (*Ptr)|=(Priority << (((IntCtrlConfig[count].intType % 4)*8)+5));
    }
}
