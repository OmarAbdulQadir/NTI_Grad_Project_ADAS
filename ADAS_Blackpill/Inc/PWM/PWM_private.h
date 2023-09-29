/**********************************************************************************/
/***						Date: 20/9/2023	Day: Wednesday						***/
/***    PWM driver for STM32F401 a graduation project for thE NTI 	program	    ***/
/**********************************************************************************/

#ifndef PWM_PRIVATE_H_
#define PWM_PRIVATE_H_

/*
 * PWM_private.h
 *
 *  Created on: Sep 21, 2023
 *      Author: Esraa Ossama
 */



#include "../LIB/STD_TYPES.h"

#define APB2_BASE								(0x40014C00)

#define TIM11_BASE_ADDRESS						(0x40014800)
#define TIM10_BASE_ADDRESS						(0x40014400)
#define TIM9_BASE_ADDRESS						(0x40014000)

#define TIM8_BASE_ADDRESS						(0x40010400)
#define TIM1_BASE_ADDRESS						(0x40010000)


#define APB1_BASE 								(0x40007000)

#define TIM2_BASE_ADDRESS						(0x40000000)
#define TIM3_BASE_ADDRESS						(0x40000400)
#define TIM4_BASE_ADDRESS						(0x40000800)
#define TIM5_BASE_ADDRESS						(0x40000C00)


#define TIM3_CR1					(*((volatile u32*) (TIM3_BASE_ADDRESS +0x00)))
#define TIM3_CR2					(*((volatile u32*) (TIM3_BASE_ADDRESS +0x04)))
#define TIM3_SMCR					(*((volatile u32*) (TIM3_BASE_ADDRESS +0x08)))
#define TIM3_DIER					(*((volatile u32*) (TIM3_BASE_ADDRESS +0x0C)))
#define TIM3_SR						(*((volatile u32*) (TIM3_BASE_ADDRESS +0x10)))
#define TIM3_EGR					(*((volatile u32*) (TIM3_BASE_ADDRESS +0x14)))
#define TIM3_CCMR1					(*((volatile u32*) (TIM3_BASE_ADDRESS +0x18)))
#define TIM3_CCMR2					(*((volatile u32*) (TIM3_BASE_ADDRESS +0x1C)))
#define TIM3_CCER					(*((volatile u32*) (TIM3_BASE_ADDRESS +0x20)))
#define TIM3_CNT					(*((volatile u32*) (TIM3_BASE_ADDRESS +0x24)))
#define TIM3_PSC					(*((volatile u32*) (TIM3_BASE_ADDRESS +0x28)))
#define TIM3_ARR					(*((volatile u32*) (TIM3_BASE_ADDRESS +0x2C)))
#define TIM3_CCR1					(*((volatile u32*) (TIM3_BASE_ADDRESS +0x34)))
#define TIM3_CCR2					(*((volatile u32*) (TIM3_BASE_ADDRESS +0x38)))
#define TIM3_CCR3					(*((volatile u32*) (TIM3_BASE_ADDRESS +0x3C)))
#define TIM3_CCR4					(*((volatile u32*) (TIM3_BASE_ADDRESS +0x40)))
#define TIM3_DCR					(*((volatile u32*) (TIM3_BASE_ADDRESS +0x48)))
#define TIM3_DMAR					(*((volatile u32*) (TIM3_BASE_ADDRESS +0x4C)))


#define TIM4_CR1					(*((volatile u32*) (TIM4_BASE_ADDRESS +0x00)))
#define TIM4_CR2					(*((volatile u32*) (TIM4_BASE_ADDRESS +0x04)))
#define TIM4_SMCR					(*((volatile u32*) (TIM4_BASE_ADDRESS +0x08)))
#define TIM4_DIER					(*((volatile u32*) (TIM4_BASE_ADDRESS +0x0C)))
#define TIM4_SR						(*((volatile u32*) (TIM4_BASE_ADDRESS +0x10)))
#define TIM4_EGR					(*((volatile u32*) (TIM4_BASE_ADDRESS +0x14)))
#define TIM4_CCMR1					(*((volatile u32*) (TIM4_BASE_ADDRESS +0x18)))
#define TIM4_CCMR2					(*((volatile u32*) (TIM4_BASE_ADDRESS +0x1C)))
#define TIM4_CCER					(*((volatile u32*) (TIM4_BASE_ADDRESS +0x20)))
#define TIM4_CNT					(*((volatile u32*) (TIM4_BASE_ADDRESS +0x24)))
#define TIM4_PSC					(*((volatile u32*) (TIM4_BASE_ADDRESS +0x28)))
#define TIM4_ARR					(*((volatile u32*) (TIM4_BASE_ADDRESS +0x2C)))
#define TIM4_CCR1					(*((volatile u32*) (TIM4_BASE_ADDRESS +0x34)))
#define TIM4_CCR2					(*((volatile u32*) (TIM4_BASE_ADDRESS +0x38)))
#define TIM4_CCR3					(*((volatile u32*) (TIM4_BASE_ADDRESS +0x3C)))
#define TIM4_CCR4					(*((volatile u32*) (TIM4_BASE_ADDRESS +0x40)))
#define TIM4_DCR					(*((volatile u32*) (TIM4_BASE_ADDRESS +0x48)))
#define TIM4_DMAR					(*((volatile u32*) (TIM4_BASE_ADDRESS +0x4C)))

/*********************************** Registers' Bits ********************************************/
#define CEN							0
#define DIR							4
#define ARPE						7

#define UG							0
#define OC1PE						3
#define OC1CE						7
#define OC2PE						11
#define OC2CE						15
#define OC3PE						3
#define OC3CE						7
#define OC4PE						11
#define OC4CE						15
#define OC4M0						12
#define OC4M1						13
#define OC4M2						14

#define CC1E						0
#define CC2E						4
#define CC3E						8
#define CC4E						12
#define CC4P						13


#endif /* PWM_PRIVATE_H_ */
