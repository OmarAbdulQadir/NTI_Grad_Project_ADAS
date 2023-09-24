/**********************************************************************************/
/***						Date: 20/9/2023	Day: Wednesday						***/
/***    NVIC driver for STM32F401 a graduation project for thE NTI 	program	    ***/
/**********************************************************************************/

/*							Private includes									  */
#include "../Inc/NVIC/NVIC_private.h"

/*--------------------------------------------------------------------------------*/
/*							Global variables									  */

/*--------------------------------------------------------------------------------*/
/*					Global functions implementation								  */

/* Enables the IRQx interrupt										*/
/* Input Parameters: IRQx ID										*/
/* Return value: STD_TRUE -> Success, STD_FALSE -> Failed			*/
STD_ReturnType NVIC_u8EnableIRQ( u8 )
{
	return 0;
}


/*--------------------------------------------------------------------------------*/
/* Disable the IRQx interrupt										*/
/* Input Parameters: IRQx ID										*/
/* Return value: STD_TRUE -> Success, STD_FALSE -> Failed			*/
STD_ReturnType NVIC_u8DisableIRQ( u8 )
{
	return 0;
}


/*--------------------------------------------------------------------------------*/
/* Set pinding flag for the IRQx interrupt							*/
/* Input Parameters: IRQx ID										*/
/* Return value: STD_TRUE -> Success, STD_FALSE -> Failed			*/
STD_ReturnType NVIC_u8SetPendingIRQ( u8 )
{
	return 0;
}


/*--------------------------------------------------------------------------------*/
/* Clear pinding flag for the IRQx interrupt						*/
/* Input Parameters: IRQx ID										*/
/* Return value: STD_TRUE -> Success, STD_FALSE -> Failed			*/
STD_ReturnType NVIC_u8ClearPendingIRQ( u8 )
{
	return 0;
}


/*--------------------------------------------------------------------------------*/
/* Get pinding and active flags value for the IRQx interrupt		*/
/* Input Parameters: IRQx ID, Pointer to u8 variable				*/
/* Return value: STD_TRUE -> Success, STD_FALSE -> Failed			*/
STD_ReturnType NVIC_u8GetStateIRQ( u8 , u8* )
{
	return 0;
}


/*--------------------------------------------------------------------------------*/
/* Set priority value for the IRQx interrupt						*/
/* Input Parameters: IRQx ID, Priority u8 value						*/
/* Return value: STD_TRUE -> Success, STD_FALSE -> Failed			*/
STD_ReturnType NVIC_u8SetPriority( u8, u8 )
{
	return 0;
}


/*--------------------------------------------------------------------------------*/
/* Get priority value for the IRQx interrupt						*/
/* Input Parameters: IRQx ID, Pointer to u8 variable				*/
/* Return value: STD_TRUE -> Success, STD_FALSE -> Failed			*/
STD_ReturnType NVIC_u8GetPriority( u8 , u8* )
{
	return 0;
}


/*--------------------------------------------------------------------------------*/
