/**********************************************************************************/
/***						Date: 22/9/2023	Day: Wednesday						***/
/***    ICU driver for STM32F401 a graduation project for thE NTI 	program	    ***/
/**********************************************************************************/

#ifndef ICU_INTERFACE_H_
#define ICU_INTERFACE_H_

// Libraries includes
#include "../Inc/STD_TYPES.h"
#include "../Inc/BIT_MATH.h"


/* Configure TIMER Peripheral using pre-build configurations		*/
/* Input Parameters: TIMER Peripheral ID							*/
/* Return value: STD_TRUE -> Success, STD_FALSE -> Failed			*/
STD_ReturnType ICU_u8Init( u8 copy_u8TIM_ID );


/* Set the event to be captured										*/
/* Input Parameters: TIMER Peripheral ID, Input channel ID, Trigger	*/
/* Return value: STD_TRUE -> Success, STD_FALSE -> Failed			*/
STD_ReturnType ICU_u8SetTrigger(  u8 copy_u8TIM_ID , u8 copy_u8CH_ID, u8 copy_u8Trigger );


/* Start counting with according to the configured event			*/
/* Input Parameters: TIMER Peripheral ID, Input channel ID			*/
/* Return value: STD_TRUE -> Success, STD_FALSE -> Failed			*/
STD_ReturnType ICU_u8Start(  u8 copy_u8TIM_ID , u8 copy_u8CH_ID );


/* Stop ICU detection and counting									*/
/* Input Parameters: TIMER Peripheral ID, Input channel ID			*/
/* Return value: STD_TRUE -> Success, STD_FALSE -> Failed			*/
STD_ReturnType ICU_u8Stop( u8 copy_u8TIM_ID ,  u8 copy_u8CH_ID );


/* Set callback function to be excuted when event is captured		*/
/* Input Parameters: TIMER Peripheral ID, ptr to callback function	*/
/* Return value: STD_TRUE -> Success, STD_FALSE -> Failed			*/
STD_ReturnType ICU_u8SetCallback( u8 copy_u8TIM_ID ,  u8 copy_u8CH_ID , ( ( void ) ( *ptr_ICUcallback ) ( u32 ) ) );


#endif /* ICU_INTERFACE_H_ */
