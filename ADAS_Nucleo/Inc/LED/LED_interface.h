/**********************************************************************************/
/***						Date: 20/9/2023	Day: Wednesday						***/
/***    LED driver for STM32F401 a graduation project for thE NTI 	program	    ***/
/**********************************************************************************/

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

// Libraries includes
#include "../Inc/LIB/STD_TYPES.h"
#include "../Inc/LIB/BIT_MATH.h"

#define LED_Right_CHANNEL	0
#define LED_Left_CHANNEL	1

STD_ReturnType LED_u8Init( u8 copy_u8LED_ID );
STD_ReturnType LED_u8On( u8 copy_u8LED_ID );
STD_ReturnType LED_u8Off( u8 copy_u8LED_ID );

#endif /* LED_INTERFACE_H_ */
