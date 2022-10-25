/******************************************************************************
 *
 * Module: LED Module
 *
 * File Name: LED.c
 *
 * Description: Functions declaration of LED module
 *
 * Authors: Mohanad Marzouk
 *
 *******************************************************************************/

/*******************************************************************************
 *                             Included header files                           *
 *******************************************************************************/
#include "HAL/inc/LED.h"


/************************************************************************************
 * Service Name: Toggle_REDLED
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): None
 * Parameters (out): None
 * Return value: None
 * Description: Toggle red LED
 ************************************************************************************/
void Toggle_REDLED(void)
{
    Dio_FlipChannel(PF1);
}

/************************************************************************************
 * Service Name: Toggle_BLUELED
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): None
 * Parameters (out): None
 * Return value: None
 * Description: Toggle blue LED
 ************************************************************************************/
void Toggle_BLUELED(void)
{
    Dio_FlipChannel(PF2);
}

/************************************************************************************
 * Service Name: Toggle_GREENLED
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): None
 * Parameters (out): None
 * Return value: None
 * Description: Toggle green LED
 ************************************************************************************/
void Toggle_GREENLED(void)
{
    Dio_FlipChannel(PF3);
}

/************************************************************************************
 * Service Name: RED_LED_ON
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): None
 * Parameters (out): None
 * Return value: None
 * Description: Turn red LED
 ************************************************************************************/
void RED_LED_ON(void)
{
	Dio_WriteChannel(PF1, STD_HIGH);
}

/************************************************************************************
 * Service Name: BLUE_LED_ON
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): None
 * Parameters (out): None
 * Return value: None
 * Description: Turn blue LED
 ************************************************************************************/
void BLUE_LED_ON(void)
{
	Dio_WriteChannel(PF2, STD_HIGH);
}

/************************************************************************************
 * Service Name: GREEN_LED_ON
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): None
 * Parameters (out): None
 * Return value: None
 * Description: Turn green LED
 ************************************************************************************/
void GREEN_LED_ON(void)
{
	Dio_WriteChannel(PF3, STD_HIGH);	
}

/************************************************************************************
 * Service Name: All_LED_OFF
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): None
 * Parameters (out): None
 * Return value: None
 * Description: Turn All LEDs Off
 ************************************************************************************/
void All_LED_OFF(void)
{
    Dio_WriteChannel(PF1, STD_LOW);
    Dio_WriteChannel(PF2, STD_LOW);
    Dio_WriteChannel(PF3, STD_LOW);
}
