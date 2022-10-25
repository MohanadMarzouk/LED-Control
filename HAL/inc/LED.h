/******************************************************************************
 *
 * Module: LED Module
 *
 * File Name: LED.h
 *
 * Description: Functions definitions of LED module
 *
 * Authors: Mohanad Marzouk
 *
 *******************************************************************************/

#ifndef HAL_INC_LED_H_
#define HAL_INC_LED_H_

/*******************************************************************************
 *                             Included header files                           *
 *******************************************************************************/
#include "MCAL/inc/Dio.h"


/*******************************************************************************
 *                           LED API's Prototype                               *
 *******************************************************************************/
void Toggle_REDLED(void);
void Toggle_BLUELED(void);
void Toggle_GREENLED(void);

void RED_LED_ON(void);
void BLUE_LED_ON(void);
void GREEN_LED_ON(void);
void All_LED_OFF(void);

#endif /* HAL_INC_LED_H_ */
