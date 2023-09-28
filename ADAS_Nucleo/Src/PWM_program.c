/**********************************************************************************/
/***						Date: 20/9/2023	Day: Wednesday						***/
/***    PWM driver for STM32F401 a graduation project for thE NTI 	program	    ***/
/**********************************************************************************/

/*
 * PWM_program.c
 *
 *  Created on: Sep 21, 2023
 *      Author: Esraa Ossama
 */

#include "../inc/PWM/PWM_config.h"
#include "../inc/PWM/PWM_interface.h"
#include "../inc/PWM/PWM_private.h"
//#include "../inc/RCC/RCC_interface.h"
//#include "../inc/GPIO/GPIO_interface.h"
#include "../inc/LIB/BIT_MATH.h"
#include "../inc/LIB/STD_TYPES.h"

/* Initialize timer registers */

u8 PWM_u8Init(u8 timerID) {
	if ((timerID == TIM3_ID) || (timerID == TIM4_ID)) {

		switch (timerID) {
		case TIM3_ID:
			switch (DIR) {
			case UPCOUNTER:
				agn_bit(TIM3_CR1, 4, UPCOUNTER)
				;
				break;
			case DOWNCOUNTER:
				agn_bit(TIM3_CR1, 4, DOWNCOUNTER)
				;
				break;
			}

			/*auto reload preload register*/
			switch (AUTO_RELOAD_PRELOAD) {
			case EN_AUTO_RELOAD_PRELOAD:
				agn_bit(TIM3_CR1, 7, EN_AUTO_RELOAD_PRELOAD)
				;
				break;
			case DIS_AUTO_RELOAD_PRELOAD:
				agn_bit(TIM3_CR1, 7, DIS_AUTO_RELOAD_PRELOAD)
				;
				break;
			}

			/*PWM mode 1*/
			switch (PWM_MODE) {
			case PWM_MODE1:
				clr_bit(TIM3_CCMR2, 12);
				set_bit(TIM3_CCMR2, 13);
				set_bit(TIM3_CCMR2, 14);
				break;
			case PWM_MODE2:
				set_bit(TIM3_CCMR2, 12);
				set_bit(TIM3_CCMR2, 13);
				set_bit(TIM3_CCMR2, 14);
				break;
			}

			/*enable output compare 1 preload*/
			set_bit(TIM3_CCMR2, 11);

			/*Active high polarity*/
			switch (OUTPUT_POLARITY) {
			case ACTIVE_HIGH_POL:
				agn_bit(TIM3_CCER, 13, ACTIVE_HIGH_POL)
				;
				break;
			case ACTIVE_LOW_POL:
				agn_bit(TIM3_CCER, 13, ACTIVE_LOW_POL)
				;
				break;
			}

			TIM3_PSC = PRESCALER;
			TIM3_ARR = AUTO_RELOAD_VAL;

			/*initialize all the registers*/
			set_bit(TIM3_EGR, 0);
			break;

		case TIM4_ID:
			switch (DIR) {
			case UPCOUNTER:
				agn_bit(TIM4_CR1, 4, UPCOUNTER)
				;
				break;
			case DOWNCOUNTER:
				agn_bit(TIM4_CR1, 4, DOWNCOUNTER)
				;
				break;
			}

			/*auto reload preload register*/
			switch (AUTO_RELOAD_PRELOAD) {
			case EN_AUTO_RELOAD_PRELOAD:
				agn_bit(TIM4_CR1, 7, EN_AUTO_RELOAD_PRELOAD)
				;
				break;
			case DIS_AUTO_RELOAD_PRELOAD:
				agn_bit(TIM4_CR1, 7, DIS_AUTO_RELOAD_PRELOAD)
				;
				break;
			}

			/*PWM mode 1*/
			switch (PWM_MODE) {
			case PWM_MODE1:
				clr_bit(TIM4_CCMR2, 12);
				set_bit(TIM4_CCMR2, 13);
				set_bit(TIM4_CCMR2, 14);
				break;
			case PWM_MODE2:
				set_bit(TIM4_CCMR2, 12);
				set_bit(TIM4_CCMR2, 13);
				set_bit(TIM4_CCMR2, 14);
				break;
			}

			/*enable output compare 1 preload*/
			set_bit(TIM4_CCMR2, 11);

			/*Active high polarity*/
			switch (OUTPUT_POLARITY) {
			case ACTIVE_HIGH_POL:
				agn_bit(TIM4_CCER, 13, ACTIVE_HIGH_POL)
				;
				break;
			case ACTIVE_LOW_POL:
				agn_bit(TIM4_CCER, 13, ACTIVE_LOW_POL)
				;
				break;
			}

			TIM4_PSC = PRESCALER;
			TIM4_ARR = AUTO_RELOAD_VAL;

			/*initialize all the registers*/
			set_bit(TIM4_EGR, 0);
			break;

		}
		return STD_TRUE;
	}
	return STD_FALSE;
}

u8 PWM_u8Start(u8 timerID, u8 duty) {
	if ((timerID == TIM3_ID) || (timerID == TIM4_ID)) {
		switch (timerID) {
		case TIM3_ID:
			/*enable counter*/
			set_bit(TIM3_CR1, 0);

			/*enable output on channel 4*/
			switch (CHANNEL_ID) {
			case CHANNEL1_ID:
				set_bit(TIM3_CCER, 0);
				break;
			case CHANNEL2_ID:
				set_bit(TIM3_CCER, 4);
				break;
			case CHANNEL3_ID:
				set_bit(TIM3_CCER, 8);
				break;
			case CHANNEL4_ID:
				set_bit(TIM3_CCER, 12);
				break;
			}
			if ((duty >= 0) && (duty <= 100)) {
				TIM3_CCR4 = ((u16) 255 * duty) / 100;
			}

			break;
		case TIM4_ID:
			/*enable counter*/
			set_bit(TIM4_CR1, 0);
			/*enable output on channel 4*/
			switch (CHANNEL_ID) {
			case CHANNEL1_ID:
				set_bit(TIM4_CCER, 0);
				break;
			case CHANNEL2_ID:
				set_bit(TIM4_CCER, 4);
				break;
			case CHANNEL3_ID:
				set_bit(TIM4_CCER, 8);
				break;
			case CHANNEL4_ID:
				set_bit(TIM4_CCER, 12);
				break;
			}
			if ((duty >= 0) && (duty <= 100)) {
				TIM4_CCR4 = ((u16) 255 * duty) / 100;
			}

			break;
		}
		return STD_TRUE;
	}
	return STD_FALSE;
}

u8 PWM_u8Stop(u8 timerID) {
	if ((timerID == TIM3_ID) || (timerID == TIM4_ID)) {

		switch (timerID) {
		case TIM3_ID:
			TIM3_CCR4 = 0;
			/*disable counter*/
			clr_bit(TIM3_CR1, 0);
			break;
		case TIM4_ID:
			TIM4_CCR4 = 0;
			/*disable counter*/
			clr_bit(TIM4_CR1, 0);
			break;
		}
		return STD_TRUE;
	}
	return STD_FALSE;
}
