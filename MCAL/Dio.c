/******************************************************************************
 *
 * Module: Dio
 *
 * File Name: Dio.c
 *
 * Description: Functions declaration of DIO module
 *
 * Authors: Mohanad Marzouk
 *
 *******************************************************************************/


/*******************************************************************************
 *                             Included header files                           *
 *******************************************************************************/
#include "MCAL/inc/Dio.h"

/*******************************************************************************
 *                        Static variables deceleration                        *
 *******************************************************************************/
static uint32   GPIO_Port_Base_Address[6]   =   {0x40004000,            //Port A base
                                                 0x40005000,            //Port B base
                                                 0x40006000,            //Port C base
                                                 0x40007000,            //Port D base
                                                 0x40024000,            //Port E base
                                                 0x40025000};           //Port F base

//********************************************************************************************************************************************************************

// Set & clear functions  *Using bit-band feature*

//********************************************************************************************************************************************************************

static void set_bit (uint32  Reg, uint32 bits)
{
    uint32 bit_band_alias =((Reg - Start_of_bit_band_region) *32 + Start_of_bit_band_alias + (bits * 4)) ;
    *((volatile unsigned long *) bit_band_alias) = 0x1;            //Setting a bit. Use the bitwise OR operator ( | ) to set a bit. number |= 1 << x; That will set a bit x .
}

static void clear_bit (uint32  Reg,uint32 bits)
{
    uint32 bit_band_alias =((Reg - Start_of_bit_band_region) *32 + Start_of_bit_band_alias + (bits * 4)) ;
    *((volatile unsigned long *) bit_band_alias) = 0x0;        //Clearing a bit. Use the bitwise AND operator ( & ) to clear a bit. number &= ~(1 << x); That will clear bit x . ...
}


/*******************************************************************************
 *                         DIO API's Declaration                        *
 *******************************************************************************/

/************************************************************************************
 * Service Name: Port_Init
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): ConfigPtr
 * Parameters (out): None
 * Return value: None
 * Description: Initializes the GPIO port and pin according to the user's configuration
 ************************************************************************************/
void Port_Init(struct PortConfig_s* ConfigPtr)
{
    if (ConfigPtr == NULL_PTR)
    {
        /*error*/
    }
    else
    {
        /*start of service*/

        SYSCTL_RCGCGPIO_R |= 0x20;          // enable clock for PORTF

        uint8 counter = 0;                  // for-loop counter
        uint8 portIndex;                    // variable to store port index
        uint8 pinIndex;                     // variable to store pin index

        /*Loop over the Config Struct given by the user*/
        for(counter = 0; counter < PORT_CONFIG_SIZE; counter++)
        {

            portIndex = ConfigPtr[counter].DioPinId / DIVISOR;        // get port index
            pinIndex = ConfigPtr[counter].DioPinId % DIVISOR;         // get pin index

            // Unlock the port to enable change to commit register
            *((volatile unsigned long *)(GPIO_Port_Base_Address[portIndex] + GPIO_LOCK_Offset )) = unlock;

            // enable commit changes
            set_bit( GPIO_Port_Base_Address[portIndex] + GPIO_CR_Offset , pinIndex );

            // clear the alternative functions for the pin as it's DIO
            clear_bit(GPIO_Port_Base_Address[portIndex] + GPIO_AFSEL_Offset , pinIndex);

            // enable the digital enable for the pin
            set_bit( GPIO_Port_Base_Address[portIndex] + GPIO_DEN_Offset , pinIndex );


            /*Configuring Direction*/
            if(ConfigPtr[counter].PinDirection)
            {
                // if pin is set as output pin
                set_bit((GPIO_Port_Base_Address[portIndex] + GPIO_DIR_Offset), pinIndex);
            }
            else
            {
                // pin is set as input pin
                clear_bit((GPIO_Port_Base_Address[portIndex] + GPIO_DIR_Offset), pinIndex);
            }

            /*Configuring Resistor Type*/
            if(ConfigPtr[counter].PullUp_PullDown)
            {
                // resistor type is configured as pullup
                set_bit((GPIO_Port_Base_Address[portIndex] + GPIO_PUR_Offset) , pinIndex);
            }
            else
            {
                // resistor type is configured as pulldown
                set_bit((GPIO_Port_Base_Address[portIndex] + GPIO_PDR_Offset) , pinIndex);
            }

            /*Configuring Level Type*/
            if (ConfigPtr[counter].DioLevelType)
            {
                // pin is set as high
                set_bit((GPIO_Port_Base_Address[portIndex] + GPIO_DATA_Offset), pinIndex);
            }
            else
            {
                // pin is set as low
                clear_bit((GPIO_Port_Base_Address[portIndex] + GPIO_DATA_Offset), pinIndex);
            }
        }
    }
}

/************************************************************************************
 * Service Name: Dio_ReadChannel
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): ChannelId
 * Parameters (out): None
 * Return value: Dio_levelTypeType
 * Description: Returns the value of the specified DIO channel.
 ************************************************************************************/
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
    Dio_LevelType levelType = STD_LOW;
    if(ChannelId > MAX_CHANNEL_ID)
    {
        /*error*/
    }
    else
    {
        uint8 portIndex = ChannelId / DIVISOR;      // save port index
        uint8 pinIndex  = ChannelId % DIVISOR;      // save pin index

        /*saves the data register value*/
        volatile uint32  reg = *((volatile unsigned long *)(GPIO_Port_Base_Address[portIndex] + GPIO_DATA_Offset));

        if(reg & (1<<pinIndex))
        {
            // pin level is high
            levelType = STD_HIGH;
        }
        else
        {
            // pin level is low
            levelType = STD_LOW;
        }
    }
    return levelType;       // return pin status
}

/************************************************************************************
 * Service Name: Dio_WriteChannel
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): ChannelId, Level
 * Parameters (out): None
 * Return value: Dio_LevelType
 * Description: Service to set a level of a channel.
 ************************************************************************************/
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
    if(ChannelId > MAX_CHANNEL_ID)
    {
        /*error*/
    }
    else
    {
        uint8 portIndex = ChannelId / DIVISOR;      // save port index
        uint8 pinIndex  = ChannelId % DIVISOR;      // save pin index

        /*saves the data register value*/
        volatile uint32  data_Reg = *((volatile unsigned long *)(GPIO_Port_Base_Address[portIndex] + GPIO_DATA_Offset));

        /*saves the direction register value*/
        volatile uint32  dir_Reg = *((volatile unsigned long *)(GPIO_Port_Base_Address[portIndex] + GPIO_DIR_Offset));

        if(dir_Reg & (1<<pinIndex))     // check if pin is configured as output
        {
            if(Level == STD_HIGH)
            {                           // set pin level high
                set_bit((GPIO_Port_Base_Address[portIndex] + GPIO_DATA_Offset), pinIndex);
            }
            else if(Level == STD_LOW)
            {                           // set pin level low
                clear_bit((GPIO_Port_Base_Address[portIndex] + GPIO_DIR_Offset), pinIndex);
            }
        }
    }
}
/************************************************************************************
 * Service Name: Dio_ReadPort
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): PortId
 * Parameters (out): None
 * Return value: Dio_PortLevelType
 * Description: Returns the level of all channels of that port.
 ************************************************************************************/
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
{
    Dio_PortLevelType portLevel;
    if(PortId > NUM_OF_PORTS)
    {
        /*error*/
    }
    else
    {       // saves data register value
        volatile uint32 data_Reg = *((volatile unsigned long *)(GPIO_Port_Base_Address[PortId] + GPIO_DATA_Offset));
        portLevel = data_Reg;
    }
    return portLevel;       // return port value
}

/************************************************************************************
 * Service Name: Dio_WritePort
 * Service ID[hex]: 0x03
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): PortId, Level
 * Parameters (out): None
 * Return value: None
 * Description: Service to set a value of the port.
 ************************************************************************************/
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level)
{
    if(PortId > NUM_OF_PORTS)
    {
        /*error*/
    }
    else
    {
        // saves data register value
        volatile uint32 data_Reg = *((volatile unsigned long *)(GPIO_Port_Base_Address[PortId] + GPIO_DATA_Offset));

        // set port value as high
        set_bit((GPIO_Port_Base_Address[PortId] + GPIO_DATA_Offset), Level);
    }
}
/************************************************************************************
 * Service Name: Dio_FlipChannel
 * Service ID[hex]: 0x11
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): ChannelId
 * Parameters (out): None
 * Return value: None
 * Description: Service to flip (change from 1 to 0 or from 0 to 1) the level of a channel and
 *              return the level of the channel after flip.
 ************************************************************************************/
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId)
{
    Dio_LevelType levelType = STD_LOW;
    if(ChannelId > MAX_CHANNEL_ID)
    {
        /*error*/
    }
    else
    {
        uint8 portIndex = ChannelId / DIVISOR;      // save port index
        uint8 pinIndex = ChannelId % DIVISOR;       // save pin index

        // save direction register value
        volatile uint32 dir_Reg = *((volatile unsigned long *)(GPIO_Port_Base_Address[portIndex] + GPIO_DIR_Offset));

        // save data register value
        volatile uint32 data_Reg = *((volatile unsigned long *)(GPIO_Port_Base_Address[portIndex] + GPIO_DATA_Offset));

        if(dir_Reg & (1<<pinIndex))         // check if pin is configured as output pin
        {
            if(data_Reg & (1<<pinIndex))
            {
                // pin level is high so flip it to low
                clear_bit((GPIO_Port_Base_Address[portIndex] + GPIO_DATA_Offset), pinIndex);
                levelType = STD_LOW;
            }
            else
            {
                // pin level is low so flip it to high
                set_bit((GPIO_Port_Base_Address[portIndex] + GPIO_DATA_Offset), pinIndex);
                levelType = STD_HIGH;
            }
        }
        else
        {
            /*do nth as pin is input*/
        }
    }
    return levelType;   // return pin level
}
