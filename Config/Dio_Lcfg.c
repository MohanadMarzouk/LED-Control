/******************************************************************************
 *
 * Module: Dio
 *
 * File Name: Dio_Lcfg.c
 *
 * Description: Link time configurations for the DIO Driver
 *
 * Authors: Mohanad Marzouk
 *
 *******************************************************************************/

/*******************************************************************************
 *                             Included header files                           *
 *******************************************************************************/
#include "Config/Dio_Cfg.h"
#include "MCAL/inc/Dio_Types.h"

/*******************************************************************************
 *                             Configuration Structure                        *
 *******************************************************************************/
struct PortConfig_s PortConfig [PORT_CONFIG_SIZE] =
{
	{
		.DioPinId = PF1,
		.PinDirection = STD_HIGH,
		.PullUp_PullDown = FALSE,
		.DioLevelType = STD_LOW,
	},
	{
		.DioPinId = PF2,
		.PinDirection = STD_HIGH,
		.PullUp_PullDown = FALSE,
		.DioLevelType = STD_LOW,
	},
	{
		.DioPinId = PF3,
		.PinDirection = STD_HIGH,
		.PullUp_PullDown = FALSE,
		.DioLevelType = STD_LOW,
	}
};
