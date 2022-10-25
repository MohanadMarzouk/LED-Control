/******************************************************************************
 *
 * Module: Dio
 *
 * File Name: Dio.h
 *
 * Description: Functions definitions of DIO module
 *
 * Authors: Mohanad Marzouk
 *
 *******************************************************************************/

#ifndef MCAL_DIO_H_
#define MCAL_DIO_H_

/*******************************************************************************
 *                             Included header files                           *
 *******************************************************************************/
#include "common/Std_Types.h"
#include "MCAL/inc/Dio_Types.h"
#include "common/tm4c123gh6pm.h"

/*******************************************************************************
 *                            Macros Used                                      *
 *******************************************************************************/
#define unlock    0x4C4F434B
#define NUM_OF_PORTS    6
#define DIVISOR         8
#define PORT_CONFIG_SIZE  3
#define MAX_CHANNEL_ID  47
#define Start_of_bit_band_region    0x40000000
#define Start_of_bit_band_alias     0x42000000

/*******************************************************************************
 *                   Set & clear API's Prototype                               *
 *******************************************************************************/
static void set_bit (uint32 , uint32 );
static void clear_bit (uint32 , uint32 );

/*******************************************************************************
 *                           DIO API's Prototype                               *
 *******************************************************************************/
void Port_Init(struct PortConfig_s* ConfigPtr );
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level);
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId);

#endif /* MCAL_DIO_H_ */
