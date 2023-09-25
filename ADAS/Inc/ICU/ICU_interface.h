/**********************************************************************************/
/***						Date: 22/9/2023	Day: Wednesday						***/
/***    ICU driver for STM32F401 a graduation project for thE NTI 	program	    ***/
/**********************************************************************************/

#ifndef ICU_INTERFACE_H_
#define ICU_INTERFACE_H_

// Libraries includes
#include "../Inc/LIB/STD_TYPES.h"
#include "../Inc/LIB/BIT_MATH.h"

#define		TIMER2ID			TIM2PRIV_ID
#define 	TIMER5ID			TIM5PRIV_ID

#define		CH1ID				CH1PRIV_ID
#define		CH2ID				CH2PRIV_ID
#define		CH3ID				CH3PRIV_ID
#define		CH4ID				CH4PRIV_ID

/* Configure TIMER Peripheral using pre-build configurations		*/
/* Input Parameters: TIMER Peripheral ID							*/
/* Return value: STD_TRUE -> Success, STD_FALSE -> Failed			*/
STD_ReturnType ICU_u8Init( u8 );


/* Enables the timer and start event detection						*/
/* Input Parameters: TIMER Peripheral ID							*/
/* Return value: STD_TRUE -> Success, STD_FALSE -> Failed			*/
STD_ReturnType ICU_u8StartTim( u8 );

/* Enables a certain channel										*/
/* Input Parameters: TIMER Peripheral ID, Input channel ID			*/
/* Return value: STD_TRUE -> Success, STD_FALSE -> Failed			*/
STD_ReturnType ICU_u8StartCh(  u8 , u8 );


/* Disable certain channel											*/
/* Input Parameters: TIMER Peripheral ID, Input channel ID			*/
/* Return value: STD_TRUE -> Success, STD_FALSE -> Failed			*/
STD_ReturnType ICU_u8StopCh( u8 ,  u8 );


/* Disable the timer and stop counting								*/
/* Input Parameters: TIMER Peripheral ID							*/
/* Return value: STD_TRUE -> Success, STD_FALSE -> Failed			*/
STD_ReturnType ICU_u8StopTim( u8 );


/* Return the saved count of timer for last detected event			*/
/* Input Parameters: TIMER Peripheral ID, Ch ID, Ptr to variable	*/
/* Return value: STD_TRUE -> Success, STD_FALSE -> Failed			*/
STD_ReturnType ICU_u8GetCh( u8 , u8 , u32* );


/* Set callback function to be executed when event is captured		*/
/* Input Parameters: TIMER Peripheral ID, ptr to callback function	*/
/* Return value: STD_TRUE -> Success, STD_FALSE -> Failed			*/
STD_ReturnType ICU_u8SetCallback( u8 ,  u8 , void ( *ptr_ICUcallback ) ( u32 )  );


#endif /* ICU_INTERFACE_H_ */
