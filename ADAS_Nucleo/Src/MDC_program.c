#include "../Inc/MDC/MDC_private.h"
#include "../Inc/GPIO/GPIO_interface.h" // You may need to adjust the path if necessary
#include "../Inc/PWM/PWM_interface.h"   // You may need to adjust the path if necessary

/*--------------------------------------------------------------------------------*/
/* Global variables */
extern const MotorChannel_t MDC_MotorChannels

static u8 Channel_Flag=0;

/*--------------------------------------------------------------------------------*/
/* Global functions implementation */

/* Initialize the motor driver for a specific channel */
STD_ReturnType MDC_u8Init(u8 copy_u8MDC_ID) {
    // Check if the specified motor channel is valid

    if(get_bit(Channel_Flag,copy_u8MDC_ID) != 1 && copy_u8MDC_ID < NUM_MOTOR_CHANNELS)
    {
    	set_bit(Channel_Flag,copy_u8MDC_ID);
        // Initialize GPIO pins for the motor channel
        GPIO_u8SetPinMode(MDC_MotorChannels[copy_u8MDC_ID].MDC_IN1_PORTID, MDC_MotorChannels[copy_u8MDC_ID].MDC_IN1_PINID, GPIO_MODE_OUTPUT);
        GPIO_u8SetPinMode(MDC_MotorChannels[copy_u8MDC_ID].MDC_IN2_PORTID, MDC_MotorChannels[copy_u8MDC_ID].MDC_IN2_PINID, GPIO_MODE_OUTPUT);

        // Initialize PWM for motor control
        PWM_u8Init(MDC_MotorChannels[copy_u8MDC_ID].MDC_EN_TIMID);

        // Return success status
        return E_OK;
    }
    else
    {
       return E_NOT_OK;
    }

}

/* Start motor in clockwise direction with specific speed */
STD_ReturnType MDC_u8StartCW(u8 copy_u8MDC_ID, u8 copy_u8MotorSpeed) {
    // Check if the specified motor channel is valid
    if (get_bit(Channel_Flag,copy_u8MDC_ID) != 1 && copy_u8MDC_ID < NUM_MOTOR_CHANNELS) {
        // Set motor direction (clockwise)
        GPIO_u8WriteData(MDC_MotorChannels[copy_u8MDC_ID].MDC_IN1_PORTID, MDC_MotorChannels[copy_u8MDC_ID].MDC_IN1_PINID, HIGH);
        GPIO_u8WriteData(MDC_MotorChannels[copy_u8MDC_ID].MDC_IN2_PORTID, MDC_MotorChannels[copy_u8MDC_ID].MDC_IN2_PINID, LOW);

        // Set PWM duty cycle for motor speed
        PWM_u8SetDutyCycle(MDC_MotorChannels[copy_u8MDC_ID].MDC_EN_TIMID, MDC_MotorChannels[copy_u8MDC_ID].MDC_EN_CHID, copy_u8MotorSpeed);

        // Start PWM
        PWM_u8Start(MDC_MotorChannels[copy_u8MDC_ID].MDC_EN_TIMID);

        // Return success status
        return E_OK;
    } else {
        // Invalid motor channel ID
        return E_NOT_OK;
    }
}

/* Start motor in counterclockwise direction with specific speed */
STD_ReturnType MDC_u8StartCCW(u8 copy_u8MDC_ID, u8 copy_u8MotorSpeed) {

    u16 Duty_Cycle=0;
    // Check if the specified motor channel is valid
    if (get_bit(Channel_Flag,copy_u8MDC_ID) != 1 && copy_u8MDC_ID < NUM_MOTOR_CHANNELS) {
        // Set motor direction (counterclockwise)
        GPIO_u8WriteData(MDC_MotorChannels[copy_u8MDC_ID].MDC_IN1_PORTID, MDC_MotorChannels[copy_u8MDC_ID].MDC_IN1_PINID, LOW);
        GPIO_u8WriteData(MDC_MotorChannels[copy_u8MDC_ID].MDC_IN2_PORTID, MDC_MotorChannels[copy_u8MDC_ID].MDC_IN2_PINID, HIGH);

        // Set PWM duty cycle for motor speed
        Duty_Cycle = copy_u8MotorSpeed * 655;

        // Start PWM
        PWM_u8Start(MDC_MotorChannels[copy_u8MDC_ID].MDC_EN_TIMID,Duty_Cycle);

        // Return success status
        return E_OK;
    } else {
        // Invalid motor channel ID
        return E_NOT_OK;
    }
}

/* Stop motor */
STD_ReturnType MDC_u8Stop(u8 copy_u8MDC_ID) {
    // Check if the specified motor channel is valid
    if (get_bit(Channel_Flag,copy_u8MDC_ID) != 1 && copy_u8MDC_ID < NUM_MOTOR_CHANNELS) {
        // Stop PWM to stop the motor
        PWM_u8Stop(MDC_MotorChannels[copy_u8MDC_ID].MDC_EN_TIMID);

        // Return success status
        return E_OK;
    } else {
        // Invalid motor channel ID
        return E_NOT_OK;
    }
}
