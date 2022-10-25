# LED-Control
MCU: Tiva C - TM4C123GH6PM
Controlling LED blinking through variable PWM signal created by a timer and defined by the LED driver user. 
The project simulates the working principle of the PWM by using timer. The SysTick timer is the timer used to control the ON-OFF time duration defined by the user.
************************************************************************************************************************************************************************
The project is implemented using the following drivers:
MCAL:
-------
- Timer Driver (SysTick).
- DIO Driver. 
- Interrupt Control Driver.

HAL:
-------
- LED Driver. 


Drivers Description:
------
DIO: The driver initializes the port/pin, as GPIO, the user configure in the configuration structure.
The DIO Driver provides services for reading and writing to/from:
- DIO Channels (Pins).
- DIO Ports.
Timer Driver (SysTick): The driver provides services for enabling/ disabling timer, set and get the timer period, and get the current timer value.
Interrupt Control Driver: The driver provides a service for initializing configured interrupts according to the user configuration.
LED Driver: The driver provides services for turning on, toggling, and turning off the 3 LEDs offered on the Tiva C.
********************************************************************************************************************************************************

![Diagram](https://user-images.githubusercontent.com/89541126/197794988-84156180-b19d-4d7c-a6bc-cb9588392890.jpg)
