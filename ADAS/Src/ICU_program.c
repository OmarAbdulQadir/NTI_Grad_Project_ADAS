/**********************************************************************************/
/***						Date: 22/9/2023	Day: Wednesday						***/
/***    ICU driver for STM32F401 a graduation project for thE NTI 	program	    ***/
/**********************************************************************************/

/*							Private includes									  */
#include "../Inc/ICU_private.h"
#include "../Inc/ICU_config.h"
#include "../Inc/ICU_interface.h"

/*--------------------------------------------------------------------------------*/
/*							Global variables									  */

/*--------------------------------------------------------------------------------*/
/*					Global functions implementation								  */

/* Configure TIMER Peripheral using pre-build configurations		*/
/* Input Parameters: TIMER Peripheral ID							*/
/* Return value: STD_TRUE -> Success, STD_FALSE -> Failed			*/
STD_ReturnType ICU_u8Init( u8 copy_u8TIM_ID )
{
	return 0;
}


/*--------------------------------------------------------------------------------*/
/* Set the event to be captured										*/
/* Input Parameters: TIMER Peripheral ID, Input channel ID, Trigger	*/
/* Return value: STD_TRUE -> Success, STD_FALSE -> Failed			*/
STD_ReturnType ICU_u8SetTrigger(  u8 copy_u8TIM_ID , u8 copy_u8CH_ID, u8 copy_u8Trigger )
{
	return 0;
}


/*--------------------------------------------------------------------------------*/
/* Start counting with according to the configured event			*/
/* Input Parameters: TIMER Peripheral ID, Input channel ID			*/
/* Return value: STD_TRUE -> Success, STD_FALSE -> Failed			*/
STD_ReturnType ICU_u8Start(  u8 copy_u8TIM_ID , u8 copy_u8CH_ID )
{
	return 0;
}


/*--------------------------------------------------------------------------------*/
/* Stop ICU detection and counting									*/
/* Input Parameters: TIMER Peripheral ID, Input channel ID			*/
/* Return value: STD_TRUE -> Success, STD_FALSE -> Failed			*/
STD_ReturnType ICU_u8Stop( u8 copy_u8TIM_ID ,  u8 copy_u8CH_ID )
{
	return 0;
}


/*--------------------------------------------------------------------------------*/
/* Set callback function to be excuted when event is captured		*/
/* Input Parameters: TIMER Peripheral ID, ptr to callback function	*/
/* Return value: STD_TRUE -> Success, STD_FALSE -> Failed			*/
STD_ReturnType ICU_u8SetCallback( u8 copy_u8TIM_ID ,  u8 copy_u8CH_ID , ( ( void ) ( *ptr_ICUcallback ) ( u32 ) ) )
{
	return 0;
}


/*--------------------------------------------------------------------------------*/