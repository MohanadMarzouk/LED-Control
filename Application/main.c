/******************************************************************************
 *
 * Module: main
 *
 * File Name: main.c
 *
 * Description: Program initialize and UI
 *
 * Authors: Mohanad Marzouk
 *
 *******************************************************************************/

/*******************************************************************************
 *                             Included header files                           *
 *******************************************************************************/
#include "MCAL/inc/Dio.h"
#include "Config/Dio_Cfg.h"
#include "HAL/inc/LED.h"
#include "MCAL/inc/SysTick.h"
#include "MCAL/inc/IntCtrl.h"

/*******************************************************************************
 *                             Global Variables                                *
 *******************************************************************************/
uint32 T_On = 0;
uint32 T_Off = 0;
uint32 ledstate = 0;
uint32 flag = 0;
uint32 loadedval = 0;


/*******************************************************************************
 *                             Functions' Declaration                           *
 *******************************************************************************/
void blink(uint32 on, uint32 off)
{
    T_On = (on * 16000);
    T_Off = off * 16000;
    SysTickPeriodSet(T_Off);
    ledstate = 0;
    SysTickEnable();
}

void SysTickISR(void)
{
    ++flag;
}

void checkFlag(void)
{
    while(flag<=253);

    Toggle_BLUELED();

    ledstate ^= 1 ;
    flag = 0;

    if(ledstate == 1)
    {
        loadedval = T_On ;
    }
    else
    {
        loadedval = T_Off ;
    }
    SysTickPeriodSet(loadedval);
}

void main(void)
{
    Port_Init(PortConfig);          // initialize GPIO diver --> PORTF
    IntCtrl_init();                 // initialize IntrCtrl Driver
    SysTickDisable();               // disable systick timer to avoid any undefined behavior during systick initialization
    SetCallBack(SysTickISR);        // set systick ISR in a callback functoin

    blink(2,2);                     // User's function to provide ON & OFF TIME

    while(1)
    {
        checkFlag();                // check if timer elapsed
    }
}

