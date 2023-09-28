/**********************************************************************************/
/***						Date: 20/9/2023	Day: Wednesday						***/
/***    PWM driver for STM32F401 a graduation project for thE NTI 	program	    ***/
/**********************************************************************************/

#ifndef PWM_INTERFACE_H_
#define PWM_INTERFACE_H_

// Dummy definition till there actual timer ID definition
#define TIM1		0
// Dummy definition till there actual channel ID definition
#define CH1			0

STD_ReturnType PWM_u8Init( u8 );
STD_ReturnType PWM_u8Start( u8 , u8 );
STD_ReturnType PWM_u8Stop( u8 );

#endif /* PWM_INTERFACE_H_ */
