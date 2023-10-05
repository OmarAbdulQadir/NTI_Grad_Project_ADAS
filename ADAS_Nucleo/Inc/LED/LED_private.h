/**********************************************************************************/
/***						Date: 20/9/2023	Day: Wednesday						***/
/***    LED driver for STM32F401 a graduation project for thE NTI 	program	    ***/
/**********************************************************************************/

#ifndef LED_PRIVATE_H_
#define LED_PRIVATE_H_

#include "../Inc/GPIO/GPIO_private.h"
#include "LED_interface.h"

// Define LED control
#define LED_ON STD_TRUE
#define LED_OFF STD_FALSE

// Structure to channels
typedef struct
{
    u8 port_id;
    u8 pin_id;
} LED_Channel_ID;


#endif /* LED_PRIVATE_H_ */
