/******************************************************************************
 *
 * Module: SysTick Timer
 *
 * File Name: SysTick.h
 *
 * Description: Functions definitions of SysTick module
 *
 * Authors: Mohanad Marzouk
 *
 *******************************************************************************/

#ifndef MCAL_SYSTICK_H_
#define MCAL_SYSTICK_H_

/*******************************************************************************
 *                             Included header files                           *
 *******************************************************************************/
#include "common/Std_Types.h"
#include "common/tm4c123gh6pm.h"


/*******************************************************************************
 *                           SysTick API's Prototype                           *
 *******************************************************************************/
void SysTickDisable(void);
void SysTickEnable (void);
void SysTickIntDisable (void);
void SysTickIntEnable (void);
uint32 SysTickPeriodGet (void);
void SysTickPeriodSet (uint32 ui32Period);
uint32 SysTickValueGet (void);

void SetCallBack(void (*ptr) (void));
void SysTickISR();

#endif /* MCAL_DIO_H_ */
