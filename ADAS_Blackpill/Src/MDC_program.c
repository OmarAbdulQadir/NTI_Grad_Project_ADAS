/**********************************************************************************/
/***						Date: 24/9/2023	Day: Sunday							***/
/***    Motor driver for STM32F401 a graduation project for thE NTI program	    ***/
/**********************************************************************************/

#include "../Inc/MDC/MDC_private.h"
#include "../Inc/MDC/MDC_config.h"
#include "../Inc/GPIO/GPIO_interface.h" // You may need to adjust the path if necessary
#include "../Inc/PWM/PWM_interface.h"   // You may need to adjust the path if necessary

/*--------------------------------------------------------------------------------*/
/* Global variables */
extern MotorChannel_t MDC_MotorChannels[];
static u8 Channel_Flag=0;

/*--------------------------------------------------------------------------------*/
/* Global functions implementation */

/* Initialize the motor driver for a specific channel */
STD_ReturnType MDC_u8Init(u8 copy_u8MDC_ID) {
    // Check if the specified motor channel is valid

    if(get_bit(Channel_Flag,copy_u8MDC_ID) != 1 && copy_u8MDC_ID < MDC_NO_CHANNELs)
    {
    	set_bit(Channel_Flag,copy_u8MDC_ID);
        // Initialize GPIO pins for the motor channel
        GPIO_voidSetPinMode(MDC_MotorChannels[copy_u8MDC_ID].MDC_IN1_PORTID, MDC_MotorChannels[copy_u8MDC_ID].MDC_IN1_PINID, MODE_OUTPUT);
        GPIO_voidSetPinMode(MDC_MotorChannels[copy_u8MDC_ID].MDC_IN2_PORTID, MDC_MotorChannels[copy_u8MDC_ID].MDC_IN2_PINID, MODE_OUTPUT);

        // Initialize PWM for motor control
        PWM_u8Init(MDC_MotorChannels[copy_u8MDC_ID].MDC_EN_TIMID);

        // Return success status
        return STD_TRUE;
    }
    else
    {
       return STD_FALSE;
    }

}

/* Start motor in clockwise direction with specific speed */
STD_ReturnType MDC_u8StartCW(u8 copy_u8MDC_ID, u8 copy_u8MotorSpeed) {
    // Check if the specified motor channel is valid
    if (get_bit(Channel_Flag,copy_u8MDC_ID) != 1 && copy_u8MDC_ID < MDC_NO_CHANNELs) {
        // Set motor direction (clockwise)
        GPIO_voidWriteData(MDC_MotorChannels[copy_u8MDC_ID].MDC_IN1_PORTID, MDC_MotorChannels[copy_u8MDC_ID].MDC_IN1_PINID, HIGH);
        GPIO_voidWriteData(MDC_MotorChannels[copy_u8MDC_ID].MDC_IN2_PORTID, MDC_MotorChannels[copy_u8MDC_ID].MDC_IN2_PINID, LOW);

        // Start PWM
        PWM_u8Start( MDC_MotorChannels[copy_u8MDC_ID].MDC_EN_TIMID , copy_u8MotorSpeed );

        // Return success status
        return STD_TRUE;
    } else {
        // Invalid motor channel ID
        return STD_FALSE;
    }
}

/* Start motor in counterclockwise direction with specific speed */
STD_ReturnType MDC_u8StartCCW(u8 copy_u8MDC_ID, u8 copy_u8MotorSpeed) {

    // Check if the specified motor channel is valid
    if (get_bit(Channel_Flag,copy_u8MDC_ID) != 1 && copy_u8MDC_ID < MDC_NO_CHANNELs) {
        // Set motor direction (counterclockwise)
        GPIO_voidWriteData(MDC_MotorChannels[copy_u8MDC_ID].MDC_IN1_PORTID, MDC_MotorChannels[copy_u8MDC_ID].MDC_IN1_PINID, LOW);
        GPIO_voidWriteData(MDC_MotorChannels[copy_u8MDC_ID].MDC_IN2_PORTID, MDC_MotorChannels[copy_u8MDC_ID].MDC_IN2_PINID, HIGH);

        // Start PWM
        PWM_u8Start( MDC_MotorChannels[copy_u8MDC_ID].MDC_EN_TIMID , copy_u8MotorSpeed );

        // Return success status
        return STD_TRUE;
    } else {
        // Invalid motor channel ID
        return STD_FALSE;
    }
}

/* Stop motor */
STD_ReturnType MDC_u8Stop(u8 copy_u8MDC_ID) {
    // Check if the specified motor channel is valid
    if (get_bit(Channel_Flag,copy_u8MDC_ID) != 1 && copy_u8MDC_ID < MDC_NO_CHANNELs) {
        // Stop PWM to stop the motor
        PWM_u8Stop( MDC_MotorChannels[ copy_u8MDC_ID ].MDC_EN_TIMID );

        // Return success status
        return STD_TRUE;
    } else {
        // Invalid motor channel ID
        return STD_FALSE;
    }
}
