/**********************************************************************************/
/***						Date: 20/9/2023	Day: Wednesday						***/
/***    LED driver for STM32F401 a graduation project for thE NTI 	program	    ***/
/**********************************************************************************/

#ifndef LED_CONFIG_H_
#define LED_CONFIG_H_

#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"
#include "../GPIO/GPIO_interface.h"
#include "LED_private.h"

// Number of channels
#define LED_NO_CHANNELS		2

// Configurations for LEDs
#define LedRight_PORTID			GPIOC_PORT
#define LedRight_PINID			PIN3
#define LedLeft_PORTID			GPIOC_PORT
#define LedLeft_PINID			PIN4

#endif /* LED_CONFIG_H_ */
