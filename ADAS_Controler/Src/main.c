/*
 * main.c
 *
 *  Created on: Sep 28, 2023
 *      Author: Omar A.Qadir
 */

/* STD libraries section */
#include <util/delay.h>
#include "../Inc/LIB/BIT_MATH.h"
#include "../Inc/LIB/STD_TYPES.h"

/* MCAL Drivers section */
#include "../Inc/DIO/DIO_interface.h"
#include "../Inc/ADC/ADC_interface.h"
#include "../Inc/EXTI/EXTI_interface.h"
#include "../Inc/UART/UART_interface.h"
#include "../Inc/TIMER/TIMER_interface.h"
#include "../Inc/LCD/LCD_interface.h"

/* HAL Drivers section */

/* Macros section */
#define CMD_FRAME_ID			0x10
#define START_FRAME				0x0C

#define THROTTLEFRAME_ID		0x20
#define STEERINGFRAME_ID		0x24
#define	DRIVEMODEFRAME_ID		0x28

#define ACC_FRAME_ID			0x26
#define	BREAK_FRAME_ID			0x22

#define BREAK_ON				0x0F
#define BREAK_OFF				0xF0

#define CRUISE_ON				0x0F
#define CRUISE_OFF				0xF0

#define DRIVEMODE_R				0x52
#define DRIVEMODE_N				0x4E
#define DRIVEMODE_D				0x44

#define MAX_ADC					1023.0
#define PERCENT					100
#define ADC_THROTTLE_CH			0
#define ADC_STEERING_CH			1
#define ADC_PRESCALER			ADPS_8
#define ADC_DISABLE				0
#define ADC_ENABLE				1

#define DIO_D0_PORT				DIO_REF_PORTB
#define DIO_D0_PIN				B3
#define DIO_D1_PORT				DIO_REF_PORTB
#define DIO_D1_PIN				B4
#define DIO_BR_PORT				DIO_REF_PORTD
#define DIO_BR_PIN				B2
#define DIO_ACC_PORT			DIO_REF_PORTD
#define DIO_ACC_PIN				B3
#define DIO_BUTTON_PRESSED		0

#define LCD_FR_SENSOR			1
#define LCD_FL_SENSOR			2
#define LCD_R_IR_SENSOR			3
#define LCD_L_IR_SENSOR			4
#define LCD_DRIVEMODE			5
#define LCD_ACC					6
#define	LCD_SPEED				7
#define LCD_CONN				8
#define LCD_RR_SENSOR			9
#define LCD_RC_SENSOR			10
#define LCD_RL_SENSOR			11

#define LCD_FR_SENSOR_POS		0,3
#define LCD_FL_SENSOR_POS		0,13
#define LCD_R_IR_SENSOR_POS		0,0
#define LCD_L_IR_SENSOR_POS		0,19
#define LCD_DRIVEMODE_POS		1,3
#define LCD_ACC_POS				1,9
#define	LCD_SPEED_POS			1,13
#define LCD_CONN_POS			2,2
#define LCD_RR_SENSOR_POS		3,0
#define LCD_RC_SENSOR_POS		3,8
#define LCD_RL_SENSOR_POS		3,16

/* Private functions section */
void vReadThrottle( void );
void vReadSteering( void );

void vReadDriveMode( u8* );

void vUpdateScreen( u8 );
void vSendFrame( u8 , u8 );
void vReciveFrame( u8 );

void vBreakAction( void );
void vACCAction( void );

/* Global variables section */
u16 Global_u16ThrottleValue = 0;
u16 Global_u16SteeringAnalogValue = 0;
u8 Global_u8DriveMode = DRIVEMODE_N;
u8 Global_u8CruiseState = CRUISE_OFF;

u16 Global_u16FrontRightDist = 0;
u16 Global_u16FrontLeftDist = 0;
u16 Global_u16RearRightDist = 0;
u16 Global_u16RearCenterDist = 0;
u16 Global_u16RearLeftDist = 0;
u16 Global_u16Speed = 0;
u8 Global_u8RightLane = 0;
u8 Global_u8LeftLane = 0;
u8 Global_u8ConnState = START_FRAME;

ADC_config_struct ADC_Config = { ADC_THROTTLE_CH, ADPS_2, ADC_DISABLE, ADC_DISABLE, ADC_DISABLE };

/* Main function */
int main( void )
{
	/* Create local version of every thing */
	u16 Local_u16ThrottleValue = 0;
	u16 Local_u16SteeringAnalogValue = 0;
	u8 Local_u8DriveMode = DRIVEMODE_N;

	u8 Local_u8ThrottlePercent = 0;
	u8 Local_u8SteeringPercent = 0;

	/* Init Peripherals */
	// Initiating the ADC
	ADC_void_init();
	vReadThrottle();
	vReadSteering();
	TIMER_u8CreatePeriodicTask(TIMER0ID, 150, vReadThrottle);
	_delay_ms(75);
	TIMER_u8CreatePeriodicTask(TIMER2ID, 150, vReadSteering);

	// Initiating the DIO pins
	DIO_void_set_pin_in_pullUP(DIO_D0_PORT,  DIO_D0_PIN );
	DIO_void_set_pin_in_pullUP(DIO_D1_PORT,  DIO_D1_PIN );
	DIO_void_set_pin_in_pullUP(DIO_BR_PORT,  DIO_BR_PIN );
	DIO_void_set_pin_in_pullUP(DIO_ACC_PORT, DIO_ACC_PIN);

	// Initiating the EXTI
	EXTI_init_config_struct EXTI_Config = {enable, EXTI_IOC, enable, EXTI_falling_edge, disable, EXTI_INT2_falling_edge};
	EXTI_void_init( &EXTI_Config );
	EXTI_void_INT_callback(INT0, vBreakAction);
	EXTI_void_INT_callback(INT1, vACCAction);

	// Initiating the UART
	UART_void_init();
	vSendFrame(CMD_FRAME_ID, START_FRAME);

	// Initiating the LCD
	LCD_init();
	LCD_write_str((u8*)" <>    <<||>>    <> ");
	vUpdateScreen(LCD_FL_SENSOR); // Left US sensor
	vUpdateScreen(LCD_FR_SENSOR); // Riht US sensor
	vUpdateScreen(LCD_R_IR_SENSOR); // IR right sensor
	vUpdateScreen(LCD_L_IR_SENSOR); // IR Left Sensors
	LCD_set_cursor(1, 0);
	LCD_write_str((u8*)"DM:  ACC:  S:   cm/s");
	vUpdateScreen(LCD_DRIVEMODE); // DM
	vUpdateScreen(LCD_ACC); // ACC
	vUpdateScreen(LCD_SPEED); // Speed
	LCD_set_cursor(2, 0);
	LCD_write_str((u8*)"C:                  ");
	vUpdateScreen(LCD_CONN); // connectivity
	LCD_set_cursor(3, 0);
	LCD_write_str((u8*)"    <<>>    <<>>    ");
	vUpdateScreen(LCD_RL_SENSOR); // Left US sensor
	vUpdateScreen(LCD_RC_SENSOR); // Center US sensor
	vUpdateScreen(LCD_RR_SENSOR); // Riht US sensor

	/* Super loop */
	while( 1 )
	{
		// Check is the connectivity is started or not
		if( Global_u8ConnState == START_FRAME )
		{// if started
			vReadDriveMode( &Local_u8DriveMode );

			if( ( Local_u16ThrottleValue != Global_u16ThrottleValue ) && ( Global_u8DriveMode != DRIVEMODE_N)  )
			{
				Local_u16ThrottleValue = Global_u16ThrottleValue;
				Local_u8ThrottlePercent = ( (Global_u16ThrottleValue / MAX_ADC ) * PERCENT );
				vSendFrame( THROTTLEFRAME_ID , Local_u8ThrottlePercent );
			}
			else
			{
				// Do nothing
			}
			if( Local_u16SteeringAnalogValue != Global_u16SteeringAnalogValue )
			{
				Local_u16SteeringAnalogValue = Global_u16SteeringAnalogValue;
				Local_u8SteeringPercent = ( (Global_u16SteeringAnalogValue / MAX_ADC ) * PERCENT );
				vSendFrame( STEERINGFRAME_ID , Local_u8SteeringPercent );
			}
			else
			{
				// Do nothing
			}
			if( Local_u8DriveMode != Global_u8DriveMode )
			{
				Global_u8DriveMode = Local_u8DriveMode;
				vSendFrame( DRIVEMODEFRAME_ID , Local_u8DriveMode );
			}
			else
			{
				// Do nothing
			}
		}
		else
		{
			// Send start frame
			vSendFrame(CMD_FRAME_ID, START_FRAME);
			// Wait till ack is recived
			_delay_ms(500);
		}
	}
	return 0;
}


/* Private functions implementation */
// Function that configure the ADC to read throttle value and return the reading in the local variable
void vReadThrottle( void )
{
	// Set steering channel in the configurations
	ADC_Config.MUX = ADC_THROTTLE_CH;
	// Configure the ADC to the new update
	ADC_void_config(&ADC_Config);
	// Read ADC Date
	ADC_void_read_data( &Global_u16ThrottleValue );
}

// Function that configure the ADC to read steering value and return the reading in the local variable
void vReadSteering( void )
{
	// Set steering channel in the configurations
	ADC_Config.MUX = ADC_STEERING_CH;
	// Configure the ADC to the new update
	ADC_void_config(&ADC_Config);
	// Read ADC Data
	ADC_void_read_data( &Global_u16SteeringAnalogValue );
}

// Function to read the Drive mode buttons and return the change in the local variable
void vReadDriveMode( u8* ptr_u8DriveMode )
{
	// Check if the D0 button is pressed
	if( DIO_u8_get_pin( DIO_D0_PORT, DIO_D0_PIN) == DIO_BUTTON_PRESSED )
	{
		// Check which mode is the currently running
		switch(*ptr_u8DriveMode)
		{
		case DRIVEMODE_N: // if the current mode is Neutral
			_delay_ms(10);
			*ptr_u8DriveMode = DRIVEMODE_R;
			while( DIO_u8_get_pin( DIO_D0_PORT, DIO_D0_PIN) == DIO_BUTTON_PRESSED );
			break;
		case DRIVEMODE_D: // if the current mode is Drive
			_delay_ms(10);
			*ptr_u8DriveMode = DRIVEMODE_N;
			while( DIO_u8_get_pin( DIO_D0_PORT, DIO_D0_PIN) == DIO_BUTTON_PRESSED );
			break;
		case DRIVEMODE_R: // if the current mode is Reverse
			_delay_ms(10);
			// Do nothing
			while( DIO_u8_get_pin( DIO_D0_PORT, DIO_D0_PIN) == DIO_BUTTON_PRESSED );
			break;
		default: // if the current mode is fault value
			*ptr_u8DriveMode = DRIVEMODE_N;
			break;
		}
	}
	// Check if the D1 button is pressed
	else if( DIO_u8_get_pin( DIO_D1_PORT, DIO_D1_PIN) == DIO_BUTTON_PRESSED )
	{
		// Check which mode is the currently running
		switch(*ptr_u8DriveMode)
		{
		case DRIVEMODE_N: // if the current mode is Neutral
			_delay_ms(10);
			*ptr_u8DriveMode = DRIVEMODE_D;
			while( DIO_u8_get_pin( DIO_D1_PORT, DIO_D1_PIN) == DIO_BUTTON_PRESSED );
			break;
		case DRIVEMODE_D: // if the current mode is Drive
			_delay_ms(10);
			// Do nothing
			while( DIO_u8_get_pin( DIO_D1_PORT, DIO_D1_PIN) == DIO_BUTTON_PRESSED );
			break;
		case DRIVEMODE_R: // if the current mode is Reverse
			_delay_ms(10);
			*ptr_u8DriveMode = DRIVEMODE_N;
			while( DIO_u8_get_pin( DIO_D1_PORT, DIO_D1_PIN) == DIO_BUTTON_PRESSED );
			break;
		default: // if the current mode is fault value
			*ptr_u8DriveMode = DRIVEMODE_N;
			break;
		}
	}
	// If nothing is pressed
	else
	{
		// Do nothing
	}
}


void vBreakAction( void )
{
	if( Global_u8ConnState == START_FRAME )
	{// Check is the connectivity is started or not
		// Check if the break button is pressed
		if( DIO_u8_get_pin(DIO_BR_PORT, DIO_BR_PIN) == DIO_BUTTON_PRESSED )
		{// if pressed send break on frame
			vSendFrame( BREAK_FRAME_ID, BREAK_ON );
		}
		else
		{// if not pressed send break off frame
			vSendFrame( BREAK_FRAME_ID, BREAK_OFF );
		}
	}
	else
	{
		// Do nothing
	}
}

void vACCAction( void )
{
	if( Global_u8ConnState == START_FRAME )
	{// Check is the connectivity is started or not
		// Check if the cruise control is on
		if( Global_u8CruiseState == CRUISE_ON )
		{// if cruise is on
			// Send cruise off frame
			vSendFrame( ACC_FRAME_ID, CRUISE_OFF );
			// Save the current state
			Global_u8CruiseState = CRUISE_OFF;
		}
		else
		{// if cruise is off
			// Send cruise on frame
			vSendFrame( ACC_FRAME_ID, CRUISE_ON );
			// Save the current state
			Global_u8CruiseState = CRUISE_ON;
		}
	}
	else
	{
		// Do notiong
	}
}


void vUpdateScreen( u8 copy_u8FrameID )
{
	switch(copy_u8FrameID)
	{
	case LCD_FR_SENSOR:
		LCD_set_cursor(LCD_FR_SENSOR_POS);
		LCD_write_s32_number(Global_u16FrontRightDist);
		break;
	case LCD_FL_SENSOR:
		LCD_set_cursor(LCD_FL_SENSOR_POS);
		LCD_write_s32_number(Global_u16FrontLeftDist);
		break;
	case LCD_R_IR_SENSOR:
		LCD_set_cursor(LCD_R_IR_SENSOR_POS);
		if(Global_u8RightLane == enable)
			LCD_write_char('E');
		else
			LCD_write_char('D');
		break;
	case LCD_L_IR_SENSOR:
		LCD_set_cursor(LCD_L_IR_SENSOR_POS);
		if(Global_u8LeftLane == enable)
			LCD_write_char('E');
		else
			LCD_write_char('D');
		break;
	case LCD_DRIVEMODE:
		LCD_set_cursor(LCD_DRIVEMODE_POS);
		LCD_write_char(Global_u8DriveMode);
		break;
	case LCD_ACC:
		LCD_set_cursor(LCD_ACC_POS);
		if(Global_u8CruiseState == CRUISE_ON)
			LCD_write_char('E');
		else
			LCD_write_char('D');
		break;
	case LCD_SPEED:
		LCD_set_cursor(LCD_SPEED_POS);
		LCD_write_s32_number(Global_u16Speed);
		break;
	case LCD_CONN:
		LCD_set_cursor(LCD_CONN_POS);
		if(Global_u8ConnState == START_FRAME)
			LCD_write_char('E');
		else
			LCD_write_char('D');
		break;
	case LCD_RR_SENSOR:
		LCD_set_cursor(LCD_RR_SENSOR_POS);
		LCD_write_s32_number(Global_u16RearRightDist);
		break;
	case LCD_RC_SENSOR:
		LCD_set_cursor(LCD_RC_SENSOR_POS);
		LCD_write_s32_number(Global_u16RearCenterDist);
		break;
	case LCD_RL_SENSOR:
		LCD_set_cursor(LCD_RL_SENSOR_POS);
		LCD_write_s32_number(Global_u16RearLeftDist);
		break;
	default:
		break;
	}
}


void vSendFrame( u8 copy_u8FrameID , u8 copy_u8FrameDataByte )
{
	UART_void_transmit_char(copy_u8FrameID);
	UART_void_transmit_char(copy_u8FrameDataByte);
}

void vReciveFrame( u8 copy_u8RecivedByte )
{

}
