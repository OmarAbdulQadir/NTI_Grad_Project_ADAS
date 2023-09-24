/**********************************************************************************/
/***						Date: 24/9/2023	Day: Sunday						***/
/***    Motor driver for STM32F401 a graduation project for thE NTI program	    ***/
/**********************************************************************************/

/*							Private includes									  */
#include "../Inc/MDC/MDC_private.h"

/*--------------------------------------------------------------------------------*/
/*							Global variables									  */

extern const MotorChannel_t MDC_MotorChannels;

/*--------------------------------------------------------------------------------*/
/*					Global functions implementation								  */

/* Initiate the GPIO, PWM modules for certain channel				*/
/* Input Parameters: Motor channel ID								*/
/* Return value: STD_TRUE -> Success, STD_FALSE -> Failed			*/
STD_ReturnType MDC_u8Init( u8 copy_u8MDC_ID )
{

}


/* Start motor in clock wise with specific speed					*/
/* Input Parameters: Motor channel ID, Motor speed 0 - 100			*/
/* Return value: STD_TRUE -> Success, STD_FALSE -> Failed			*/
STD_ReturnType MDC_u8StartCW( u8 copy_u8MDC_ID , u8 copy_u8MotorSpeed )
{

}


/* Start motor in counter clock wise with specific speed			*/
/* Input Parameters: Motor channel ID, Motor speed 0 - 100			*/
/* Return value: STD_TRUE -> Success, STD_FALSE -> Failed			*/
STD_ReturnType MDC_u8startCCW( u8 copy_u8MDC_ID , u8 copy_u8MotorSpeed )
{

}


/* Stop motor														*/
/* Input Parameters: Motor channel ID								*/
/* Return value: STD_TRUE -> Success, STD_FALSE -> Failed			*/
STD_ReturnType MDC_u8Stop( u8 copy_u8MDC_ID )
{

}
