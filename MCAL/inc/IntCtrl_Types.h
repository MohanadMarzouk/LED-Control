/******************************************************************************
 *
 * Module: IntCtrl
 *
 * File Name: IntCtrl_Types.h
 *
 * Description: Type Definitions and Included Containers of Interrupt Driver
 *
 * Authors: Mohanad Marzouk
 *
 *******************************************************************************/


#ifndef MCAL_INTCTRL_TYPES_H_
#define MCAL_INTCTRL_TYPES_H_

/*******************************************************************************
 *                             Included header files                           *
 *******************************************************************************/
#include "common/Platform_Types.h"



/*******************************************************************************
 *******************************************************************************
 *                               Type Definitions                          *
 *******************************************************************************
 *******************************************************************************/
typedef enum
{
    MEM_MANAG_FAULT=-7,
    BUS_FAULT,
    USAGE_FAULT,
    SVC,
    DEBUG,
    PENDSV,
    SYSTICK,

    GPIO_PORT_A = 0,
    GPIO_PORT_B,
    GPIO_PORT_C,
    GPIO_PORT_D,
    GPIO_PORT_E,
    UART0,
    UART1,
    SSI0,
    I2C0,
    PWM_FAULT,
    PWM_GEN_0,
    PWM_GEN_1,
    PWM_GEN_2,
    QUAD_ENCODER,
    ADC_SEQ_0,
    ADC_SEQ_1,
    ADC_SEQ_2,
    ADC_SEQ_3,
    WATCHDOG,
    TIMER0_A,
    TIMER0_B,
    TIMER1_A,
    TIMER1_B,
    TIMER2_A,
    TIMER2_B,
    COMP0,
    COMP1,
    COMP2,
    SYSTEM_CONTROL,
    FLASH_CONTROL,
    GPIO_PORT_F,
    GPIO_PORT_G,
    GPIO_PORT_H,
    UART2,
    SSI1,
    TIMER_3A,
    TIMER_3B,
    I2C1,
    QUAD_ENCODER1,
    CAN0,
    CAN1,
    CAN2,
    ETHERNET,
    HIBERNATE,
    USB0,
    PWM_GEN_3,
    UDMA_SOFT_TFR,
    UDMA_ERROR,


}IntCtrl_InterruptType;

typedef enum
{
    NVIC_PRI_GR8_SUBGR1 = 0x4,
    NVIC_PRI_GR4_SUBGR2,
    NVIC_PRI_GR2_SUBGR4,
    NVIC_PRI_GR1_SUBGR8


}IntCtrl_Gr_Sub;


typedef enum
{
    DISABLED,
    ENABLED,
    NONE
}IntCtrl_En_Dis;


typedef  uint8 IntCtrl_IntGroup;
typedef  uint8 IntCtrl_IntSubGroup;

typedef struct
{
    IntCtrl_InterruptType intType;
    IntCtrl_En_Dis status;
    IntCtrl_IntGroup intGroup;
    IntCtrl_IntSubGroup intSubGroup;
}IntCtrl_Cfg;

#endif
