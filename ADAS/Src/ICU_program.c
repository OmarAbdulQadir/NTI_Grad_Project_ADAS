/**********************************************************************************/
/***						Date: 22/9/2023	Day: Wednesday						***/
/***    ICU driver for STM32F401 a graduation project for thE NTI 	program	    ***/
/**********************************************************************************/

/*							Private includes									  */
#include "../Inc/ICU/ICU_private.h"

/*--------------------------------------------------------------------------------*/
/*							Global variables									  */
static u8 ICU_Init = 0;

/*--------------------------------------------------------------------------------*/
/*					Global functions implementation								  */

/* Configure TIMER Peripheral using pre-build configurations		*/
/* Input Parameters: TIMER Peripheral ID							*/
/* Return value: STD_TRUE -> Success, STD_FALSE -> Failed			*/
STD_ReturnType ICU_u8Init( u8 copy_u8TIM_ID )
{
	// Check data validity
	if ( ( ( copy_u8TIM_ID == TIMER2ID ) || ( copy_u8TIM_ID == TIMER5ID ) ) && ( ( ICU_Init == TIM_NOT_Init ) || ( ICU_Init == TIM2_Init ) || ( ICU_Init == TIM5_Init) ) )
	{
		switch(copy_u8TIM_ID)
		{
		case TIMER2ID:
			TIM2_CR1_ADR = TIM_CR1_CONFIG;
			TIM2_CCMR1_ADR = TIM_CCMR1_CONFIG;
			TIM2_CCMR2_ADR = TIM_CCMR2_CONFIG;
			TIM2_CCER_ADR = TIM_CCER_CONFIG;
			TIM2_PSR_ADR = TIM_PSR_CONFIG;
			ICU_Init |= TIM2_Init;
			break;
		case TIMER5ID:
			TIM5_CR1_ADR = TIM_CR1_CONFIG;
			TIM5_CCMR1_ADR = TIM_CCMR1_CONFIG;
			TIM5_CCMR2_ADR = TIM_CCMR2_CONFIG;
			TIM5_CCER_ADR = TIM_CCER_CONFIG;
			TIM5_PSR_ADR = TIM_PSR_CONFIG;
			ICU_Init |= TIM5_Init;
			break;
		default:
			return STD_FALSE;
			break;
		}
		return STD_TRUE;
	}
	else
	{
		return STD_FALSE;
	}
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
STD_ReturnType ICU_u8SetCallback( u8 copy_u8TIM_ID ,  u8 copy_u8CH_ID ,  void  ( *ptr_ICUcallback ) ( u32 )  )
{
	return 0;
}


/*--------------------------------------------------------------------------------*/
