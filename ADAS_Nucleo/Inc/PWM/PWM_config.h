/**********************************************************************************/
/***						Date: 20/9/2023	Day: Wednesday						***/
/***    PWM driver for STM32F401 a graduation project for thE NTI 	program	    ***/
/**********************************************************************************/

#include "PWM_interface.h"
#ifndef PWM_CONFIG_H_
#define PWM_CONFIG_H_

#define DIRECTION							UPCOUNTER
#define AUTO_RELOAD_PRELOAD			EN_AUTO_RELOAD_PRELOAD
#define PWM_MODE					PWM_MODE1
#define CHANNEL_ID					CHANNEL4_ID
#define OUTPUT_POLARITY				ACTIVE_HIGH_POL

#endif /* PWM_CONFIG_H_ */
