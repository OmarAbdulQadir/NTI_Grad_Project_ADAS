/**********************************************************************************/
/***						Date: 20/9/2023	Day: Wednesday						***/
/***    LED driver for STM32F401 a graduation project for thE NTI 	program	    ***/
/**********************************************************************************/


/**********************************************************************************
 *******************	 	   Standard libraries section			***************
 **********************************************************************************/ 
#include "../Inc/LIB/STD_TYPES.h"
#include "../Inc/LIB/BIT_MATH.h"

/**********************************************************************************
 *******************		 	Private headers section				***************
 **********************************************************************************/
#include "../Inc/GPIO/GPIO_private.h"


// Define 
#define STD_TRUE 1
#define STD_FALSE 0

// Define LED control 
#define LED_ON STD_TRUE
#define LED_OFF STD_FALSE

// Define a flag to initialization status 
int led_initialized[PIN_COUNT] = {STD_FALSE}; 

// Function to initialize the LED
STD_ReturnType LED_u8Init(u8 user_u8PORT, u8 user_u8PIN) 
{
    if ((user_u8PORT <= GPIOH_PORT) && (user_u8PIN <= PIN15)) 
	{
        if (!led_initialized[user_u8PIN]) 
		{
            GPIO_voidSetPinMode(user_u8PORT, user_u8PIN, MODE_OUTPUT);
            GPIO_voidWriteData(user_u8PORT, user_u8PIN, LED_OFF); // Initially, turn off the LED
            led_initialized[user_u8PIN] = STD_TRUE; // Mark the LED as initialized
            return STD_TRUE; // Initialization succeeded
        } else 
		{
            return STD_FALSE; // LED is already initialized
        }
    }
    return STD_FALSE; // Initialization failed
}

// Function to turn on the LED
STD_ReturnType LED_u8On(u8 user_u8PORT, u8 user_u8PIN) 
{
    if ((user_u8PORT <= GPIOH_PORT) && (user_u8PIN <= PIN15)) 
	{
        if (led_initialized[user_u8PIN]) 
		{
            GPIO_voidWriteData(user_u8PORT, user_u8PIN, LED_ON);
            return STD_TRUE; // LED turned on successfully
        } else 
		{
            return STD_FALSE; // LED not initialized
        }
    }
    return STD_FALSE; // LED turn on failed
}

// Function to turn off the LED
STD_ReturnType LED_u8Off(u8 user_u8PORT, u8 user_u8PIN) 
{
    if ((user_u8PORT <= GPIOH_PORT) && (user_u8PIN <= PIN15)) 
	{
        if (led_initialized[user_u8PIN]) 
		{
            GPIO_voidWriteData(user_u8PORT, user_u8PIN, LED_OFF);
            return STD_TRUE; // LED turned off successfully
        } else 
		{
            return STD_FALSE; // LED not initialized
        }
    }
    return STD_FALSE; // LED turn off failed
}
