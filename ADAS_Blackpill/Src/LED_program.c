/**********************************************************************************/
/***						Date: 20/9/2023	Day: Wednesday						***/
/***    LED driver for STM32F401 a graduation project for the NTI program	    ***/
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

#define LED_Right_CHANNEL	0
#define LED_Left_CHANNEL	1

// Number of channels
#define LED_NO_CHANNELS		2

/****************************************/
/****************************************/
/****************************************/

// Define LED control 
#define LED_ON STD_TRUE
#define LED_OFF STD_FALSE

// Define a flag for initialization 
int led_initialized[LED_NO_CHANNELS] = {STD_FALSE}; 

// Structure to channels
typedef struct
{
    u8 port_id;
    u8 pin_id;
} LED_Channel;

// Configuration for LEDs
LED_Channel LED_Channels[LED_NO_CHANNELS] = {   {LedRight_PORTID , LedRight_PINID}  ,  
                                                {LedLeft_PORTID  , LedLeft_PINID}    };

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