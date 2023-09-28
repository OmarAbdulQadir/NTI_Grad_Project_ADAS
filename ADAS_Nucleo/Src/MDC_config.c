/**********************************************************************************/
/***						Date: 24/9/2023	Day: Sunday						***/
/***    Motor driver for STM32F401 a graduation project for thE NTI program	    ***/
/**********************************************************************************/

/*							Private includes									  */
#include "../Inc/MDC/MDC_config.h"

/*--------------------------------------------------------------------------------*/
/*							Configuration variables								  */
//
/* Motor Channel configuration initialization						*/
MotorChannel_t MDC_MotorChannels[MDC_NO_CHANNELs] =
{
		{MDC1_IN1_PORTID,
		 MDC1_IN1_PINID,
		 MDC1_IN2_PORTID,
		 MDC1_IN2_PINID,
		 MDC1_EN_TIMID,
		 MDC1_EN_CHID}
};

