/**********************************************************************************/
/***						Date: 20/9/2023	Day: Wednesday						***/
/***    LED driver for STM32F401 a graduation project for the NTI program	    ***/
/**********************************************************************************/


#include "../Inc/LED/LED_interface.h"
#include "../Inc/LED/LED_config.h"
#include "../Inc/GPIO/GPIO_interface.h"

extern const LED_Channel_ID LED_Channels[];

// Define a flag for initialization
u8 led_initialized[LED_NO_CHANNELS] = {STD_FALSE};

// Function to initialize the LED
STD_ReturnType LED_u8Init( u8 copy_u8LED_ID ) 
{
    if ( copy_u8LED_ID < LED_NO_CHANNELS ) 
    {
        if ( !led_initialized[copy_u8LED_ID] )
        {

        	GPIO_voidSetPinMode( LED_Channels[copy_u8LED_ID].port_id ,
                       			 LED_Channels[copy_u8LED_ID].pin_id  , 
								 MODE_OUTPUT );


            GPIO_voidWriteData( LED_Channels[copy_u8LED_ID].port_id ,
			                    LED_Channels[copy_u8LED_ID].pin_id  , 
								LED_OFF ); // Initially, turn off the LED
            led_initialized[copy_u8LED_ID] = STD_TRUE; // Mark the LED as initialized
            return STD_TRUE; // Initialization succeeded
        } 
        else 
        {
            return STD_FALSE; // LED is already initialized
        }
    }
    return STD_FALSE; // Initialization failed
}

// Function to turn on the LED
STD_ReturnType LED_u8On( u8 copy_u8LED_ID ) 
{
    if ( copy_u8LED_ID < LED_NO_CHANNELS && led_initialized[copy_u8LED_ID] ) 
    {

        GPIO_voidWriteData( LED_Channels[copy_u8LED_ID].port_id , 
		                    LED_Channels[copy_u8LED_ID].pin_id  ,
							LED_ON );
        return STD_TRUE; // LED turned on succeeded
    }
    return STD_FALSE; // LED turn on failed
}

// Function to turn off the LED
STD_ReturnType LED_u8Off( u8 copy_u8LED_ID ) 
{
    if ( copy_u8LED_ID < LED_NO_CHANNELS && led_initialized[copy_u8LED_ID] ) 
    {

        GPIO_voidWriteData( LED_Channels[copy_u8LED_ID].port_id ,
                     		LED_Channels[copy_u8LED_ID].pin_id  ,
							LED_OFF );
        return STD_TRUE; // LED turned off succeeded
    }
    return STD_FALSE; // LED turn off failed
}
