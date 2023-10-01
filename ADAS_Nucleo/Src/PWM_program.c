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
#include "../inc/LIB/BIT_MATH.h"
#include "../inc/LIB/STD_TYPES.h"

/* Initialize timer registers */
/*< Driver Should contain a static global flag to ensure that init is done before use and do not allow re-init >*/
static u8 init_Tim3_Is_Done = 0;
static u8 init_Tim4_Is_Done = 0;

u8 PWM_u8Init(u8 timerID) {
	if (((timerID == TIM3_ID) || (timerID == TIM4_ID))) {

		switch (timerID) {
		case TIM3_ID:
			if (init_Tim3_Is_Done == 0) {
				init_Tim3_Is_Done = 1u;
				switch (DIRECTION) {
				case UPCOUNTER:
					agn_bit(TIM3_CR1, DIR, UPCOUNTER)
					;
					break;
				case DOWNCOUNTER:
					agn_bit(TIM3_CR1, DIR, DOWNCOUNTER)
					;
					break;
				}

				/*auto reload preload register*/
				switch (AUTO_RELOAD_PRELOAD) {
				case EN_AUTO_RELOAD_PRELOAD:
					agn_bit(TIM3_CR1, ARPE, EN_AUTO_RELOAD_PRELOAD)
					;
					break;
				case DIS_AUTO_RELOAD_PRELOAD:
					agn_bit(TIM3_CR1, ARPE, DIS_AUTO_RELOAD_PRELOAD)
					;
					break;
				}

				/*PWM mode 1*/
				switch (PWM_MODE) {
				case PWM_MODE1:
					clr_bit(TIM3_CCMR2, OC4M0);
					set_bit(TIM3_CCMR2, OC4M1);
					set_bit(TIM3_CCMR2, OC4M2);
					break;
				case PWM_MODE2:
					set_bit(TIM3_CCMR2, OC4M0);
					set_bit(TIM3_CCMR2, OC4M1);
					set_bit(TIM3_CCMR2, OC4M2);
					break;
				}

				/*enable output compare 1 preload*/
				set_bit(TIM3_CCMR2, OC4PE);

				/*Active high polarity*/
				switch (OUTPUT_POLARITY) {
				case ACTIVE_HIGH_POL:
					agn_bit(TIM3_CCER, CC4P, ACTIVE_HIGH_POL)
					;
					break;
				case ACTIVE_LOW_POL:
					agn_bit(TIM3_CCER, CC4P, ACTIVE_LOW_POL)
					;
					break;
				}

				TIM3_PSC = PRESCALER;
				TIM3_ARR = AUTO_RELOAD_VAL;

				/*initialize all the registers*/
				set_bit(TIM3_EGR, UG);
			}
			else{

			}
			break;







		case TIM4_ID:
			if (init_Tim4_Is_Done == 0) {
				init_Tim4_Is_Done = 1u;
				switch (DIRECTION) {
				case UPCOUNTER:
					agn_bit(TIM4_CR1, DIR, UPCOUNTER)
					;
					break;
				case DOWNCOUNTER:
					agn_bit(TIM4_CR1, DIR, DOWNCOUNTER)
					;
					break;
				}

				/*auto reload preload register*/
				switch (AUTO_RELOAD_PRELOAD) {
				case EN_AUTO_RELOAD_PRELOAD:
					agn_bit(TIM4_CR1, ARPE, EN_AUTO_RELOAD_PRELOAD)
					;
					break;
				case DIS_AUTO_RELOAD_PRELOAD:
					agn_bit(TIM4_CR1, ARPE, DIS_AUTO_RELOAD_PRELOAD)
					;
					break;
				}

				/*PWM mode 1*/
				switch (PWM_MODE) {
				case PWM_MODE1:
					clr_bit(TIM4_CCMR2, OC4M0);
					set_bit(TIM4_CCMR2, OC4M1);
					set_bit(TIM4_CCMR2, OC4M2);
					break;
				case PWM_MODE2:
					set_bit(TIM4_CCMR2, OC4M0);
					set_bit(TIM4_CCMR2, OC4M1);
					set_bit(TIM4_CCMR2, OC4M2);
					break;
				}

				/*enable output compare 1 preload*/
				set_bit(TIM4_CCMR2, OC4PE);

				/*Active high polarity*/
				switch (OUTPUT_POLARITY) {
				case ACTIVE_HIGH_POL:
					agn_bit(TIM4_CCER, CC4P, ACTIVE_HIGH_POL)
					;
					break;
				case ACTIVE_LOW_POL:
					agn_bit(TIM4_CCER, CC4P, ACTIVE_LOW_POL)
					;
					break;
				}

				TIM4_PSC = PRESCALER;
				TIM4_ARR = AUTO_RELOAD_VAL;

				/*initialize all the registers*/
				set_bit(TIM4_EGR, UG);
			}
			else{

			}
			break;

		}
		return STD_TRUE;
	} else {
		return STD_FALSE;
	}
	/*< All IFs should have an else :: Misra C >*/

}






u8 PWM_u8Start(u8 timerID, u8 duty) {
	if ((timerID == TIM3_ID) || (timerID == TIM4_ID)) {
		switch (timerID) {
		case TIM3_ID:
			/* map duty from 0-100 to 0-255*/
			if ((duty >= 0) && (duty <= 100)) {
				TIM3_CCR4 = ((u16) AUTO_RELOAD_VAL * duty) / 100;
			} else {

			}

			/*enable counter*/
			set_bit(TIM3_CR1, CEN);

			/*enable output on channel 4*/
			switch (CHANNEL_ID) {
			case CHANNEL1_ID:
				set_bit(TIM3_CCER, CC1E);
				break;
			case CHANNEL2_ID:
				set_bit(TIM3_CCER, CC2E);
				break;
			case CHANNEL3_ID:
				set_bit(TIM3_CCER, CC3E);
				break;
			case CHANNEL4_ID:
				set_bit(TIM3_CCER, CC4E);
				break;
			}
			/*< Feeding the Compare register with the new values should by done before enable and not vise versa >*/

			break;
		case TIM4_ID:
			if ((duty >= 0) && (duty <= 100)) {
				TIM4_CCR4 = ((u16) AUTO_RELOAD_VAL * duty) / 100;
			} else {

			}
			/*enable counter*/
			set_bit(TIM4_CR1, CEN);
			/*enable output on channel 4*/
			switch (CHANNEL_ID) {
			case CHANNEL1_ID:
				set_bit(TIM4_CCER, CC1E);
				break;
			case CHANNEL2_ID:
				set_bit(TIM4_CCER, CC2E);
				break;
			case CHANNEL3_ID:
				set_bit(TIM4_CCER, CC3E);
				break;
			case CHANNEL4_ID:
				set_bit(TIM4_CCER, CC4E);
				break;
			}
			/*< Feeding the Compare register with the new values should by done before enable and not vise versa >*/

			break;
		}
		return STD_TRUE;
	} else {
		return STD_FALSE;
	}
	// All IFs should have an else :: Misra C

}

u8 PWM_u8Stop(u8 timerID) {
	if ((timerID == TIM3_ID) || (timerID == TIM4_ID)) {

		switch (timerID) {
		case TIM3_ID:
			/* duty = 0 */
			TIM3_CCR4 = 0;
			/*disable counter*/
			clr_bit(TIM3_CR1, CEN);
			break;
		case TIM4_ID:
			TIM4_CCR4 = 0;
			/*disable counter*/
			clr_bit(TIM4_CR1, CEN);
			break;
		}
		return STD_TRUE;
	} else {
		return STD_FALSE;
	}
	/*< All IFs should have an else :: Misra C */

}

/*< And Don't use magic numbers use macros or enums >*/
/*< Please insert more comments to describe the code >*/
