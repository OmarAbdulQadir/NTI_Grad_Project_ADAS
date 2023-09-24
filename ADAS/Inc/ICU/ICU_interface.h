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


/* Start counting with according to the configured event			*/
/* Input Parameters: TIMER Peripheral ID, Input channel ID			*/
/* Return value: STD_TRUE -> Success, STD_FALSE -> Failed			*/
STD_ReturnType ICU_u8Start(  u8 , u8 );


/* Stop ICU detection and counting									*/
/* Input Parameters: TIMER Peripheral ID, Input channel ID			*/
/* Return value: STD_TRUE -> Success, STD_FALSE -> Failed			*/
STD_ReturnType ICU_u8Stop( u8 ,  u8 );


/* Set callback function to be excuted when event is captured		*/
/* Input Parameters: TIMER Peripheral ID, ptr to callback function	*/
/* Return value: STD_TRUE -> Success, STD_FALSE -> Failed			*/
STD_ReturnType ICU_u8SetCallback( u8 ,  u8 , void ( *ptr_ICUcallback ) ( u32 )  );


#endif /* ICU_INTERFACE_H_ */
