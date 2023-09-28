/**********************************************************************************/
/***						Date: 20/9/2023	Day: Wednesday						***/
/***    ICU driver for STM32F401 a graduation project for thE NTI 	program	    ***/
/**********************************************************************************/

#ifndef ICU_PRIVATE_H_
#define ICU_PRIVATE_H_

#include "ICU_config.h"
#include "ICU_interface.h"

// Timers base address
#define TIM2_BASE_ADR						((u32)(0x40000000))
#define TIM5_BASE_ADR						((u32)(0x40000C00))
#define TIM10_BASE_ADR						((u32)(0x40014400))

// Registers offset address of timer 2
#define	TIM2_CR1_ADR						(*((volatile u32*) (TIM2_BASE_ADR+0x00)))
#define TIM2_EGR_ADR						(*((volatile u32*) (TIM5_BASE_ADR+0x14)))
#define TIM2_CCMR1_ADR						(*((volatile u32*) (TIM2_BASE_ADR+0x18)))
#define TIM2_CCMR2_ADR						(*((volatile u32*) (TIM2_BASE_ADR+0x1C)))
#define TIM2_CCER_ADR						(*((volatile u32*) (TIM2_BASE_ADR+0x20)))
#define TIM2_PSR_ADR						(*((volatile u32*) (TIM5_BASE_ADR+0x28)))
#define TIM2_CRR1_ADR						(*((volatile u32*) (TIM2_BASE_ADR+0x34)))
#define TIM2_CRR2_ADR						(*((volatile u32*) (TIM2_BASE_ADR+0x38)))
#define TIM2_CRR3_ADR						(*((volatile u32*) (TIM2_BASE_ADR+0x3C)))
#define TIM2_CRR4_ADR						(*((volatile u32*) (TIM2_BASE_ADR+0x40)))

// Registers offset address of timer 2
#define	TIM5_CR1_ADR						(*((volatile u32*) (TIM5_BASE_ADR+0x00)))
#define TIM5_EGR_ADR						(*((volatile u32*) (TIM5_BASE_ADR+0x14)))
#define TIM5_CCMR1_ADR						(*((volatile u32*) (TIM5_BASE_ADR+0x18)))
#define TIM5_CCMR2_ADR						(*((volatile u32*) (TIM5_BASE_ADR+0x1C)))
#define TIM5_CCER_ADR						(*((volatile u32*) (TIM5_BASE_ADR+0x20)))
#define TIM5_PSR_ADR						(*((volatile u32*) (TIM5_BASE_ADR+0x28)))
#define TIM5_CRR1_ADR						(*((volatile u32*) (TIM5_BASE_ADR+0x34)))
#define TIM5_CRR2_ADR						(*((volatile u32*) (TIM5_BASE_ADR+0x38)))
#define TIM5_CRR3_ADR						(*((volatile u32*) (TIM5_BASE_ADR+0x3C)))
#define TIM5_CRR4_ADR						(*((volatile u32*) (TIM5_BASE_ADR+0x40)))

// Registers offset address of timer 10
#define	TIM10_CR1_ADR						(*((volatile u32*) (TIM5_BASE_ADR+0x00)))
#define TIM10_EGR_ADR						(*((volatile u32*) (TIM5_BASE_ADR+0x14)))
#define TIM10_CCMR1_ADR						(*((volatile u32*) (TIM5_BASE_ADR+0x18)))
#define TIM10_CCER_ADR						(*((volatile u32*) (TIM5_BASE_ADR+0x20)))
#define TIM10_PSR_ADR						(*((volatile u32*) (TIM5_BASE_ADR+0x28)))
#define TIM10_CRR1_ADR						(*((volatile u32*) (TIM5_BASE_ADR+0x34)))

// Timer/Counter Enable
#define TIMx_EN								0

// Input channels enable bit number
#define TIMx_CH1EN							0
#define TIMx_CH2EN							4
#define TIMx_CH3EN							8
#define TIMx_CH4EN							12

// Timers initiation value
#define TIM2_Init							0x03
#define TIM5_Init							0x0C
#define TIM10_Init							0x30
#define TIM_NOT_Init						0x0

#endif /* ICU_PRIVATE_H_ */
