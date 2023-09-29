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
extern const MotorChannel_t MDC_MotorChannels[];
static u8 Channel_Flag = MDC_CH_NOT_INIT;

/*--------------------------------------------------------------------------------*/
/* Global functions implementation */

/* Initialize the motor driver for a specific channel */
STD_ReturnType MDC_u8Init(u8 copy_u8MDC_ID) {
    // Check if the specified motor channel is valid
    if( ( ( ( Channel_Flag & MDC_CH1_INIT ) == MDC_CH_NOT_INIT ) && ( copy_u8MDC_ID == MDC_MOTION_CHANNEL   ) ) ||
    	( ( ( Channel_Flag & MDC_CH2_INIT ) == MDC_CH_NOT_INIT ) && ( copy_u8MDC_ID == MDC_STEERING_CHANNEL ) ) )
    {// If data is valid
    	// Check which motor to initiate
    	switch(copy_u8MDC_ID)
    	{
    	case MDC_MOTION_CHANNEL: // Case motion motor
    		// Activate init flag for motion channel
    		Channel_Flag |= MDC_CH1_INIT;
    		break;
    	case MDC_STEERING_CHANNEL: // Case steering motor
    		// Activate init flag for steering channel
    		Channel_Flag |= MDC_CH2_INIT;
    		break;
    	default: // Wrong input case
    		// Return failed
    		return STD_FALSE;
    		break;
    	}
		// Set GPIO pins' mode and initial value
		GPIO_voidSetPinMode(MDC_MotorChannels[copy_u8MDC_ID].MDC_IN1_PORTID,
							MDC_MotorChannels[copy_u8MDC_ID].MDC_IN1_PINID,
							MODE_OUTPUT);
		GPIO_voidWriteData(MDC_MotorChannels[copy_u8MDC_ID].MDC_IN1_PORTID,
						   MDC_MotorChannels[copy_u8MDC_ID].MDC_IN1_PINID,
						   LOW);
		GPIO_voidSetPinMode(MDC_MotorChannels[copy_u8MDC_ID].MDC_IN2_PORTID,
							MDC_MotorChannels[copy_u8MDC_ID].MDC_IN2_PINID,
							MODE_OUTPUT);
		GPIO_voidWriteData(MDC_MotorChannels[copy_u8MDC_ID].MDC_IN2_PORTID,
						   MDC_MotorChannels[copy_u8MDC_ID].MDC_IN2_PINID,
						   LOW);
		GPIO_voidSetPinMode(MDC_MotorChannels[copy_u8MDC_ID].MDC_EN_PORTID,
							MDC_MotorChannels[copy_u8MDC_ID].MDC_EN_PINID,
							MODE_ALTF);
		GPIO_voidPinSetAltFn(MDC_MotorChannels[copy_u8MDC_ID].MDC_EN_PORTID,
							 MDC_MotorChannels[copy_u8MDC_ID].MDC_EN_PINID,
							 MDC_MOTTION_CH_AFT);
		// Initiate PWM
		PWM_u8Init(MDC_MotorChannels[copy_u8MDC_ID].MDC_EN_TIMID);

		// Return success status
        return STD_TRUE;
    }
    else
    {// if Data is not valid
    	// Return failed
    	return STD_FALSE;
    }

}

/* Start motor in clockwise direction with specific speed */
STD_ReturnType MDC_u8StartCW(u8 copy_u8MDC_ID, u8 copy_u8MotorSpeed) {
    // Check if the specified motor channel is valid
    if( ( ( ( Channel_Flag & MDC_CH1_INIT ) == MDC_CH1_INIT ) && ( copy_u8MDC_ID == MDC_MOTION_CHANNEL   ) ) ||
        ( ( ( Channel_Flag & MDC_CH2_INIT ) == MDC_CH2_INIT ) && ( copy_u8MDC_ID == MDC_STEERING_CHANNEL ) ) )
    {
        // Set motor direction (clockwise)
        GPIO_voidWriteData(MDC_MotorChannels[copy_u8MDC_ID].MDC_IN1_PORTID, MDC_MotorChannels[copy_u8MDC_ID].MDC_IN1_PINID, HIGH);
        GPIO_voidWriteData(MDC_MotorChannels[copy_u8MDC_ID].MDC_IN2_PORTID, MDC_MotorChannels[copy_u8MDC_ID].MDC_IN2_PINID, LOW);

        // Start PWM
        PWM_u8Start( MDC_MotorChannels[copy_u8MDC_ID].MDC_EN_TIMID , copy_u8MotorSpeed );

        // Return success status
        return STD_TRUE;
    }
    else
    {// If Data is not valid
        // Return failed
        return STD_FALSE;
    }
}

/* Start motor in counterclockwise direction with specific speed */
STD_ReturnType MDC_u8StartCCW(u8 copy_u8MDC_ID, u8 copy_u8MotorSpeed) {

    // Check if the specified motor channel is valid
	if( ( ( ( Channel_Flag & MDC_CH1_INIT ) == MDC_CH1_INIT ) && ( copy_u8MDC_ID == MDC_MOTION_CHANNEL   ) ) ||
	    ( ( ( Channel_Flag & MDC_CH2_INIT ) == MDC_CH2_INIT ) && ( copy_u8MDC_ID == MDC_STEERING_CHANNEL ) ) )
	{
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
	if( ( ( ( Channel_Flag & MDC_CH1_INIT ) == MDC_CH1_INIT ) && ( copy_u8MDC_ID == MDC_MOTION_CHANNEL   ) ) ||
	    ( ( ( Channel_Flag & MDC_CH2_INIT ) == MDC_CH2_INIT ) && ( copy_u8MDC_ID == MDC_STEERING_CHANNEL ) ) )
	{// If data is valid
		// Stabilize both motor inputs
        GPIO_voidWriteData(MDC_MotorChannels[copy_u8MDC_ID].MDC_IN1_PORTID, MDC_MotorChannels[copy_u8MDC_ID].MDC_IN1_PINID, LOW);
        GPIO_voidWriteData(MDC_MotorChannels[copy_u8MDC_ID].MDC_IN2_PORTID, MDC_MotorChannels[copy_u8MDC_ID].MDC_IN2_PINID, LOW);

        // Stop PWM to stop the motor
        PWM_u8Stop( MDC_MotorChannels[ copy_u8MDC_ID ].MDC_EN_TIMID );

        // Return success status
        return STD_TRUE;
    }
	else
	{// If data is not valid
        // Invalid motor channel ID
        return STD_FALSE;
    }
}
