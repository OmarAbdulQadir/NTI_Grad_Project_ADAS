/**********************************************************************************/
/***						Date: 20/9/2023	Day: Wednesday						***/
/***    PWM driver for STM32F401 a graduation project for thE NTI 	program	    ***/
/**********************************************************************************/

#include "../LIB/STD_TYPES.h"

#ifndef PWM_INTERFACE_H_
#define PWM_INTERFACE_H_


/*
 - Function To Enable Timer Prepheral :
 - timerID      :  ID of the desired timer (TIM3_ID, TIM4_ID)
 */
u8 PWM_u8Init(u8 timerID);

/*
 - Function To Start Timer, its Channel and set the duty cycle:
 - timerID      :  ID of the desired timer (TIM3_ID, TIM4_ID)
 - duty :  desigred duty cycle from 0 - 100

 */
u8 PWM_u8Start(u8 timerID, u8 duty);

/*
 - Function To Stop Timer:
 - timerID      :  ID of the desired timer (TIM3_ID, TIM4_ID)
 */
u8 PWM_u8Stop(u8 timerID);


/************************ Timers IDs **********************/
#define TIM1_ID									1
#define TIM2_ID									2
#define TIM3_ID									3
#define TIM4_ID									4
#define TIM5_ID									5

#define TIM8_ID									8
#define TIM9_ID									9
#define TIM10_ID								10
#define TIM11_ID								11


/****************************** channel IDs ******************************/
#define CHANNEL1_ID				1
#define CHANNEL2_ID				2
#define CHANNEL3_ID				3
#define CHANNEL4_ID				4

/****************************** Direction ******************************/
#define UPCOUNTER				0
#define DOWNCOUNTER				1

#define EN_AUTO_RELOAD_PRELOAD	1
#define DIS_AUTO_RELOAD_PRELOAD	0

#define PWM_MODE1				1    //OCxM bit in CCMR2 reg
#define PWM_MODE2				2

/****************************** polarity ******************************/
#define ACTIVE_HIGH_POL			0
#define ACTIVE_LOW_POL			1

#define PRESCALER				(1600 - 1)
#define AUTO_RELOAD_VAL			255


#endif /* PWM_INTERFACE_H_ */
