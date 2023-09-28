/**********************************************************************************/
/***						Date: 20/9/2023	Day: Wednesday						***/
/***    ICU driver for STM32F401 a graduation project for thE NTI 	program	    ***/
/**********************************************************************************/

#ifndef ICU_CONFIG_H_
#define ICU_CONFIG_H_

// Timer 2/5 registers configurations
#define TIM_CCMR1_CONFIG					(0x1111u)
#define TIM_CCMR2_CONFIG					(0x1111u)
#define TIM_CCER_CONFIG						(0xAAAAu)
#define TIM_PSR_CONFIG						(0x7Cu)

// Timer 10 register configurations
#define TIM10_EGR_CONFIG					(0x1u)
#define TIM10_CCMR1_CONFIG					(0x11u)
#define TIM10_CCER_CONFIG					(0xAu)
#define TIM10_PSR_CONFIG					(0x7Cu)

#endif /* ICU_CONFIG_H_ */
