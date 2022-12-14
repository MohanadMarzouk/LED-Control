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
#ifndef MCAL_INTCTRL_H_
#define MCAL_INTCTRL_H_

/*******************************************************************************
 *                             Included header files                           *
 *******************************************************************************/
#include "common/Platform_Types.h"
#include "MCAL/inc/IntCtrl_Types.h"
#include "Config/IntCtrl_Cfg.h"
#include "common/tm4c123gh6pm.h"

/*******************************************************************************
 *                            Macros                                           *
 *******************************************************************************/

#define APINT                     (*((volatile uint32 *)0xE000ED0C))
#define VECTKEY                    0x05FA

/**********************************************************************************************************************
 *                  Global STRUCTURES
 *********************************************************************************************************************/

extern const uint8 IntCtrl_Gr_SubGr_cfg;

/*******************************************************************************
 *                           IntCtrl API's Prototype                           *
 *******************************************************************************/
void IntCtrl_init(void);


#endif
