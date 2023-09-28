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
#define MDC_NO_CHANNELs			1

// Configurations for motor 1
#define MDC1_IN1_PORTID			GPIOA_PORT
#define MDC1_IN1_PINID			PIN0
#define MDC1_IN2_PORTID			GPIOA_PORT
#define MDC1_IN2_PINID			PIN1
#define MDC1_EN_TIMID			TIM1
#define MDC1_EN_CHID			CH1

#endif /* MDC_CONFIG_H_ */

