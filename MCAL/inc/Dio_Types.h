/******************************************************************************
 *
 * Module: Dio
 *
 * File Name: Dio_Types.h
 *
 * Description: Type Definitions and Included Containers of DIO Driver
 *
 * Authors: Mohanad Marzouk
 *
 *******************************************************************************/
#ifndef MCAL_DIO_TYPES_H_
#define MCAL_DIO_TYPES_H_


/*******************************************************************************
 *                             Included header files                           *
 *******************************************************************************/
#include "Common/Std_Types.h"


/*******************************************************************************
 *                    Macros for pins mapping                                  *
 *******************************************************************************/
#define PA0     0
#define PA1     1
#define PA2     2
#define PA3     3
#define PA4     4
#define PA5     5
#define PA6     6
#define PA7     7

#define PB0     8
#define PB1     9
#define PB2     10
#define PB3     11
#define PB4     12
#define PB5     13
#define PB6     14
#define PB7     15

#define PC0     16
#define PC1     17
#define PC2     18
#define PC3     19
#define PC4     20
#define PC5     21
#define PC6     22
#define PC7     23

#define PD0     24
#define PD1     25
#define PD2     26
#define PD3     27
#define PD4     28
#define PD5     29
#define PD6     30
#define PD7     31

#define PE0     32
#define PE1     33
#define PE2     34
#define PE3     35
#define PE4     36
#define PE5     37
#define PE6     38
#define PE7     39

#define PF0     40
#define PF1     41
#define PF2     42
#define PF3     43
#define PF4     44
#define PF5     45
#define PF6     46
#define PF7     47

/*******************************************************************************
 *                 Macros for registers offsets                                *
 *******************************************************************************/
#define GPIO_IS_Offset         (0x404)
#define GPIO_DATA_Offset       (0x3FC)
#define GPIO_DIR_Offset        (0x400)
#define GPIO_IBE_Offset        (0x408)
#define GPIO_IEV_Offset        (0x40C)
#define GPIO_IM_Offset         (0x410)
#define GPIO_RIS_Offset        (0x414)
#define GPIO_MIS_Offset        (0x418)
#define GPIO_ICR_Offset        (0x41C)
#define GPIO_AFSEL_Offset      (0x420)
#define GPIO_DR2R_Offset       (0x500)
#define GPIO_DR4R_Offset       (0x504)
#define GPIO_DR8R_Offset       (0x508)
#define GPIO_ODR_Offset        (0x50C)
#define GPIO_PUR_Offset        (0x510)
#define GPIO_PDR_Offset        (0x514)
#define GPIO_SLR_Offset        (0x518)
#define GPIO_DEN_Offset        (0x51C)
#define GPIO_LOCK_Offset       (0x520)
#define GPIO_CR_Offset         (0x524)
#define GPIO_AMSEL_Offset      (0x528)
#define GPIO_PCTL_Offset       (0x52C)
#define GPIO_ADCCTL_Offset     (0x530)
#define GPIO_DMACTL_Offset     (0x534)


#define DIO_CHANNEL_SIZE            0
#define DIO_CHANNEL_GROUP_SIZE      10


/*******************************************************************************
 *******************************************************************************
 *                               Type Definitions                          *
 *******************************************************************************
 *******************************************************************************/

typedef uint8   Dio_ChannelType;
typedef uint8   Dio_PortType;
typedef uint8   Dio_LevelType;
typedef uint8   Dio_PortLevelType;

typedef uint8 ChannelId;

typedef enum{
                INPUT,
                OUTPUT
}PinDirection_e;

struct PortConfig_s{
    ChannelId                       DioPinId;
    PinDirection_e              PinDirection;
    bool                        PullUp_PullDown;
    Dio_LevelType               DioLevelType;
};


#endif /* MCAL_DIO_TYPES_H_ */
