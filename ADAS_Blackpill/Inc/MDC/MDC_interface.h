/**********************************************************************************/
/***						Date: 24/9/2023	Day: Sunday						***/
/***    Motor driver for STM32F401 a graduation project for thE NTI program	    ***/
/**********************************************************************************/

#ifndef MDC_INTERFACE_H_
#define MDC_INTERFACE_H_

#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"

#define MDC_MOTION_CHANNEL				0
#define MDC_STEERING_CHANNEL			1

/* Initiate the GPIO, PWM modules for certain channel				*/
/* Input Parameters: Motor channel ID								*/
/* Return value: STD_TRUE -> Success, STD_FALSE -> Failed			*/
STD_ReturnType MDC_u8Init( u8 );

/* Start motor in clock wise with specific speed					*/
/* Input Parameters: Motor channel ID, Motor speed 0 - 100			*/
/* Return value: STD_TRUE -> Success, STD_FALSE -> Failed			*/
STD_ReturnType MDC_u8StartCW( u8 , u8 );

/* Start motor in counter clock wise with specific speed			*/
/* Input Parameters: Motor channel ID, Motor speed 0 - 100			*/
/* Return value: STD_TRUE -> Success, STD_FALSE -> Failed			*/
STD_ReturnType MDC_u8StartCCW( u8 , u8 );

/* Stop motor														*/
/* Input Parameters: Motor channel ID								*/
/* Return value: STD_TRUE -> Success, STD_FALSE -> Failed			*/
STD_ReturnType MDC_u8Stop( u8 );

#endif /* MDC_INTERFACE_H_ */
