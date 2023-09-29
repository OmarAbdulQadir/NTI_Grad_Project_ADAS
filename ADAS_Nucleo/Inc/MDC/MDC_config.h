/**********************************************************************************/
/***						Date: 24/9/2023	Day: Sunday							***/
/***    Motor driver for STM32F401 a graduation project for thE NTI program	    ***/
/**********************************************************************************/

#ifndef MDC_CONFIG_H_
#define MDC_CONFIG_H_

#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"

#include "../GPIO/GPIO_interface.h"
#include "../PWM/PWM_interface.h"
#include "MDC_private.h"


// Number of channels
#define MDC_NO_CHANNELs			2

// Configurations for motion motor
#define MDC1_IN1_PORTID			GPIOB_PORT
#define MDC1_IN1_PINID			PIN0
#define MDC1_IN2_PORTID			GPIOB_PORT
#define MDC1_IN2_PINID			PIN2
#define MDC1_EN_PORTID			GPIOB_PORT
#define MDC1_EN_PINID			PIN1
#define MDC1_EN_TIMID			TIM3_ID

// Configurations for steering motor
#define MDC2_IN1_PORTID			GPIOB_PORT
#define MDC2_IN1_PINID			PIN12
#define MDC2_IN2_PORTID			GPIOB_PORT
#define MDC2_IN2_PINID			PIN13
#define MDC2_EN_PORTID			GPIOB_PORT
#define MDC2_EN_PINID			PIN9
#define MDC2_EN_TIMID			TIM4_ID

#endif /* MDC_CONFIG_H_ */

