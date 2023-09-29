/**********************************************************************************/
/***						Date: 24/9/2023	Day: Sunday						***/
/***    Motor driver for STM32F401 a graduation project for thE NTI program	    ***/
/**********************************************************************************/

#ifndef MDC_PRIVATE_H_
#define MDC_PRIVATE_H_

#include "../GPIO/GPIO_interface.h"
#include "../PWM/PWM_interface.h"
#include "MDC_interface.h"

typedef struct
{
	u8 MDC_IN1_PORTID	:	4;
	u8 MDC_IN1_PINID	:	4;
	u8 MDC_IN2_PORTID 	:	4;
	u8 MDC_IN2_PINID	:	4;
	u8 MDC_EN_PORTID	:	4;
	u8 MDC_EN_PINID		:	4;
	u8 MDC_EN_TIMID		:	4;
}MotorChannel_t;

#define MDC_CH_NOT_INIT			0
#define MDC_CH1_INIT			0x0F
#define MDC_CH2_INIT			0xF0

#endif /* MDC_PRIVATE_H_ */
