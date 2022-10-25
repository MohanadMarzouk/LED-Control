/******************************************************************************
 *
 * Module: SysTick Timer
 *
 * File Name: SysTick.c
 *
 * Description: Functions declaration of SysTick module
 *
 * Authors: Mohanad Marzouk
 *
 *******************************************************************************/


/*******************************************************************************
 *                             Included header files                           *
 *******************************************************************************/

#include "MCAL/inc/SysTick.h"


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

void (*SysTickCallBack) (void);



/*******************************************************************************
 *                         SysTick API's Declaration                        *
 *******************************************************************************/

/************************************************************************************
 * Service Name: SysTickDisable
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): None
 * Parameters (out): None
 * Return value: None
 * Description: Disables the SysTick counter.
 ************************************************************************************/
void SysTickDisable(void)
{
    NVIC_ST_CTRL_R = 0;
	//clear_bit(NVIC_ST_CTRL_R, 0);
}

/************************************************************************************
 * Service Name: SysTickEnable
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): None
 * Parameters (out): None
 * Return value: None
 * Description: Enable the SysTick counter.
 ************************************************************************************/
void SysTickEnable(void)
{
    NVIC_ST_CTRL_R |= 0x03;
}

/************************************************************************************
 * Service Name: SysTickIntDisable
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): None
 * Parameters (out): None
 * Return value: None
 * Description: Disables the SysTick interrupt.
 ************************************************************************************/
void SysTickIntDisable (void)
{
    NVIC_ST_CTRL_R &=~ 0x02;
	//clear_bit(NVIC_ST_CTRL_R, 1);
}

/************************************************************************************
 * Service Name: SysTickIntEnable
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): None
 * Parameters (out): None
 * Return value: None
 * Description: Enables the SysTick interrupt.
 ************************************************************************************/
void SysTickIntEnable (void)
{
    NVIC_ST_CTRL_R |= 0x02;
	//set_bit(NVIC_ST_CTRL_R, 1);
}

/************************************************************************************
 * Service Name: SysTickPeriodSet
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): Systick Period
 * Parameters (out): None
 * Return value: None
 * Description: Sets the period of the SysTick counter.
 ************************************************************************************/
void SysTickPeriodSet (uint32 ui32Period)
{
			//
			// Check the arguments.
			//
	if(ui32Period <= 16777216)
	{
			//
			// Set the period of the SysTick counter.
			//
		NVIC_ST_RELOAD_R = ui32Period - 1;
	}
	else
	{
		/*error*/
	}
}

/************************************************************************************
 * Service Name: SysTickPeriodGet
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): None
 * Parameters (out): None
 * Return value: Returns the period of the SysTick counter.
 * Description: Gets the period of the SysTick counter.
 ************************************************************************************/
uint32 SysTickPeriodGet (void)
{
	uint32 ui32Period = NVIC_ST_RELOAD_R;
	    //
			// Return the period of the SysTick counter.
			//
	return (ui32Period+1);
}

/************************************************************************************
 * Service Name: SysTickValueGet
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): None
 * Parameters (out): None
 * Return value: Returns the current value of the SysTick counter.
 * Description: Gets the current value of the SysTick counter.
 ************************************************************************************/
uint32 SysTickValueGet (void)
{
	uint32 value = NVIC_ST_CURRENT_R;
	    //
			// Return the current value of the SysTick counter.
			//
	return value;
}

void SetCallBack(void(*ptr)(void))
{
    SysTickCallBack = ptr;
}

