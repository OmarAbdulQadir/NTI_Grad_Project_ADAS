/**********************************************************************************/
/***						Date: 22/9/2023	Day: Wednesday						***/
/***    ICU driver for STM32F401 a graduation project for thE NTI 	program	    ***/
/**********************************************************************************/

/*							Private includes									  */
#include "../Inc/ICU/ICU_private.h"

/*--------------------------------------------------------------------------------*/
/*							Global variables									  */
static u8 ICU_Init = TIM_NOT_Init;

/*--------------------------------------------------------------------------------*/
/*					Global functions implementation								  */

/* Configure TIMER Peripheral using pre-build configurations		*/
/* Input Parameters: TIMER Peripheral ID							*/
/* Return value: STD_TRUE -> Success, STD_FALSE -> Failed			*/
STD_ReturnType ICU_u8Init( u8 copy_u8TIM_ID )
{
	// Check data validity
	if ( ( ( copy_u8TIM_ID == TIMER2ID  ) && ( ( ICU_Init & TIM2_Init  ) == TIM_NOT_Init  ) ) ||
		 ( ( copy_u8TIM_ID == TIMER5ID  ) && ( ( ICU_Init & TIM5_Init  ) == TIM_NOT_Init  ) ) ||
		 ( ( copy_u8TIM_ID == TIMER10ID ) && ( ( ICU_Init & TIM10_Init ) == TIM_NOT_Init  ) ) )
	{
		// Check which timer is selected to be initiated
		switch( copy_u8TIM_ID )
		{
		case TIMER2ID:// Case of timer 2 is selected
			// Configure the registers
			TIM2_CCMR1_ADR = TIM_CCMR1_CONFIG;
			TIM2_CCMR2_ADR = TIM_CCMR2_CONFIG;
			TIM2_CCER_ADR = TIM_CCER_CONFIG;
			TIM2_PSR_ADR = TIM_PSR_CONFIG;
			// Set the init flag
			ICU_Init |= TIM2_Init;
			break;
		case TIMER5ID: // Case of timer 5 is selected
			// Configure the registers
			TIM5_CCMR1_ADR = TIM_CCMR1_CONFIG;
			TIM5_CCMR2_ADR = TIM_CCMR2_CONFIG;
			TIM5_CCER_ADR = TIM_CCER_CONFIG;
			TIM5_PSR_ADR = TIM_PSR_CONFIG;
			// Set the init flag
			ICU_Init |= TIM5_Init;
			break;
		case TIMER10ID: // Case of timer 5 is selected
			// Configure the registers
			TIM10_EGR_ADR = TIM10_EGR_CONFIG;
			TIM10_CCMR1_ADR = TIM10_CCMR1_CONFIG;
			TIM10_CCER_ADR = TIM10_CCER_CONFIG;
			TIM10_PSR_ADR = TIM10_PSR_CONFIG;
			// Set the init flag
			ICU_Init |= TIM10_Init;
			break;
		default: // Case of wrong selection
			// Return false
			return STD_FALSE;
			break;
		}
		// Return true
		return STD_TRUE;
	}
	else
	{// In case of in valid data or re-init
		// Return false
		return STD_FALSE;
	}
}


/*--------------------------------------------------------------------------------*/
/* Enables the timer and start event detection						*/
/* Input Parameters: TIMER Peripheral ID							*/
/* Return value: STD_TRUE -> Success, STD_FALSE -> Failed			*/
STD_ReturnType ICU_u8StartTim(  u8 copy_u8TIM_ID )
{
	// Check data validity
	if( ( ( ICU_Init == TIM2_Init ) && ( copy_u8TIM_ID == TIMER2ID ) ) ||
		( ( ICU_Init == TIM5_Init ) && ( copy_u8TIM_ID == TIMER5ID ) ) )
	{
		// Check which timer is selected to be initiated
		switch( copy_u8TIM_ID )
		{
		case TIMER2ID:// Case of timer 2 is selected
			// Enable timer 2
			set_bit( TIM2_CR1_ADR , TIMx_EN );
			break;
		case TIMER5ID: // Case of timer 5 is selected
			// Enable timer 5
			set_bit( TIM5_CR1_ADR , TIMx_EN );
			break;
		case TIMER10ID:// Case of timer 10 is selected
			// Enable timer 10
			set_bit( TIM10_CR1_ADR , TIMx_EN );
			break;
		default: // Case of wrong selection
			// Return false
			return STD_FALSE;
			break;
		}
		// Return true
		return STD_TRUE;
	}
	else
	{// In case of in valid data or re-init
		// Return false
		return STD_FALSE;
	}
}


/*--------------------------------------------------------------------------------*/
/* Enables a certain channel										*/
/* Input Parameters: TIMER Peripheral ID, Input channel ID			*/
/* Return value: STD_TRUE -> Success, STD_FALSE -> Failed			*/
STD_ReturnType ICU_u8StartCh(  u8 copy_u8TIM_ID , u8 copy_u8CH_ID )
{
	// Check data validity
	if( ( ( ( ICU_Init == TIM2_Init ) && ( copy_u8TIM_ID == TIMER2ID ) ) ||
		( ( ICU_Init == TIM5_Init ) && ( copy_u8TIM_ID == TIMER5ID ) ) ) &&
		( copy_u8CH_ID <= CH4ID ) )
	{
		// Check which channel is selected
		switch( copy_u8CH_ID )
		{
		case CH1ID: // Case of Channel 1 is selected
			// Check which timer is selected
			switch( copy_u8TIM_ID )
			{
			case TIMER2ID: // Case of timer 2 is selected
				// Enable the selected channel
				set_bit( TIM2_CCER_ADR , TIMx_CH1EN );
				break;
			case TIMER5ID: // Case of timer 5 is selected
				// Enable the selected channel
				set_bit( TIM5_CCER_ADR , TIMx_CH1EN );
				break;
			case TIMER10ID: // Case of timer 10 is selected
				// Enable the selected channel
				set_bit( TIM10_CCER_ADR , TIMx_CH1EN );
				break;
			default: // Case of wrong timer selection
				break;
			}
			break;
		case CH2ID: // Case of Channel 2 is selected
			// Check which timer is selected
			switch( copy_u8TIM_ID )
			{
			case TIMER2ID: // Case of timer 2 is selected
				// Enable the selected channel
				set_bit( TIM2_CCER_ADR , TIMx_CH2EN );
				break;
			case TIMER5ID: // Case of timer 5 is selected
				// Enable the selected channel
				set_bit( TIM5_CCER_ADR , TIMx_CH2EN );
				break;
			case TIMER10ID: // Case of timer 10 is selected
				// Enable the selected channel
				return STD_FALSE;
				break;
			default: // Case of wrong timer selection
				break;
			}
			break;
		case CH3ID: // Case of Channel 3 is selected
			// Check which timer is selected
			switch( copy_u8TIM_ID )
			{
			case TIMER2ID: // Case of timer 2 is selected
				// Enable the selected channel
				set_bit( TIM2_CCER_ADR , TIMx_CH3EN );
				break;
			case TIMER5ID: // Case of timer 5 is selected
				// Enable the selected channel
				set_bit( TIM5_CCER_ADR , TIMx_CH3EN );
				break;
			case TIMER10ID: // Case of timer 10 is selected
				// Enable the selected channel
				return STD_FALSE;
			default: // Case of wrong timer selection
				break;
			}
			break;
		case CH4ID: // Case of Channel 4 is selected
			// Check which timer is selected
			switch( copy_u8TIM_ID )
			{
			case TIMER2ID: // Case of timer 2 is selected
				// Enable the selected channel
				set_bit( TIM2_CCER_ADR , TIMx_CH4EN );
				break;
			case TIMER5ID: // Case of timer 5 is selected
				// Enable the selected channel
				set_bit( TIM5_CCER_ADR , TIMx_CH4EN );
				break;
			case TIMER10ID: // Case of timer 10 is selected
				// Enable the selected channel
				return STD_FALSE;
			default: // Case of wrong timer selection
				break;
			}
			break;
		default: // Case of wrong channel selection
			// Return false
			return STD_FALSE;
			break;
		}
		return STD_TRUE;
	}
	else
	{// In case of in valid data or re-init
		// Return false
		return STD_FALSE;
	}
}


/*--------------------------------------------------------------------------------*/
/* Stop ICU detection and counting									*/
/* Input Parameters: TIMER Peripheral ID, Input channel ID			*/
/* Return value: STD_TRUE -> Success, STD_FALSE -> Failed			*/
STD_ReturnType ICU_u8StopCh( u8 copy_u8TIM_ID ,  u8 copy_u8CH_ID )
{
	// Check data validity
	if( ( ( ( ICU_Init == TIM2_Init ) && ( copy_u8TIM_ID == TIMER2ID ) ) ||
		( ( ICU_Init == TIM5_Init ) && ( copy_u8TIM_ID == TIMER5ID ) ) ) &&
		( copy_u8CH_ID <= CH4ID ) )
	{
		// Check which channel is selected
		switch( copy_u8CH_ID )
		{
		case CH1ID: // Case of Channel 1 is selected
			// Check which timer is selected
			switch( copy_u8TIM_ID )
			{
			case TIMER2ID: // Case of timer 2 is selected
				// Enable the selected channel
				clr_bit( TIM2_CCER_ADR , TIMx_CH1EN );
				break;
			case TIMER5ID: // Case of timer 5 is selected
				// Enable the selected channel
				clr_bit( TIM5_CCER_ADR , TIMx_CH1EN );
				break;
			case TIMER10ID: // Case of timer 10 is selected
				// Enable the selected channel
				clr_bit( TIM10_CCER_ADR , TIMx_CH1EN );
				break;
			default: // Case of wrong timer selection
				break;
			}
			break;
		case CH2ID: // Case of Channel 2 is selected
			// Check which timer is selected
			switch( copy_u8TIM_ID )
			{
			case TIMER2ID: // Case of timer 2 is selected
				// Enable the selected channel
				clr_bit( TIM2_CCER_ADR , TIMx_CH2EN );
				break;
			case TIMER5ID: // Case of timer 5 is selected
				// Enable the selected channel
				clr_bit( TIM5_CCER_ADR , TIMx_CH2EN );
				break;
			case TIMER10ID: // Case of timer 10 is selected
				// Enable the selected channel
				return STD_FALSE;
			default: // Case of wrong timer selection
				break;
			}
			break;
		case CH3ID: // Case of Channel 3 is selected
			// Check which timer is selected
			switch( copy_u8TIM_ID )
			{
			case TIMER2ID: // Case of timer 2 is selected
				// Enable the selected channel
				clr_bit( TIM2_CCER_ADR , TIMx_CH3EN );
				break;
			case TIMER5ID: // Case of timer 5 is selected
				// Enable the selected channel
				clr_bit( TIM5_CCER_ADR , TIMx_CH3EN );
				break;
			case TIMER10ID: // Case of timer 10 is selected
				// Enable the selected channel
				return STD_FALSE;
			default: // Case of wrong timer selection
				break;
			}
			break;
		case CH4ID: // Case of Channel 4 is selected
			// Check which timer is selected
			switch( copy_u8TIM_ID )
			{
			case TIMER2ID: // Case of timer 2 is selected
				// Enable the selected channel
				clr_bit( TIM2_CCER_ADR , TIMx_CH4EN );
				break;
			case TIMER5ID: // Case of timer 5 is selected
				// Enable the selected channel
				clr_bit( TIM5_CCER_ADR , TIMx_CH4EN );
				break;
			case TIMER10ID: // Case of timer 10 is selected
				// Enable the selected channel
				return STD_FALSE;
			default: // Case of wrong timer selection
				break;
			}
			break;
		default: // Case of wrong channel selection
			// Return false
			return STD_FALSE;
			break;
		}
		return STD_TRUE;
	}
	else
	{// In case of in valid data or re-init
		// Return false
		return STD_FALSE;
	}
}


/*--------------------------------------------------------------------------------*/
/* Disable the timer and stop counting								*/
/* Input Parameters: TIMER Peripheral ID							*/
/* Return value: STD_TRUE -> Success, STD_FALSE -> Failed			*/
STD_ReturnType ICU_u8StopTim( u8 copy_u8TIM_ID )
{
	// Check data validity
	if( ( ( ICU_Init == TIM2_Init ) && ( copy_u8TIM_ID == TIMER2ID ) ) ||
		( ( ICU_Init == TIM5_Init ) && ( copy_u8TIM_ID == TIMER5ID ) ) )
	{
		// Check which timer is selected to be initiated
		switch( copy_u8TIM_ID )
		{
		case TIMER2ID:// Case of timer 2 is selected
			// Disable timer 2
			clr_bit( TIM2_CR1_ADR , TIMx_EN );
			break;
		case TIMER5ID: // Case of timer 5 is selected
			// Disable timer 5
			clr_bit( TIM5_CR1_ADR , TIMx_EN );
			break;
		case TIMER10ID: // Case of timer 10 is selected
			// Disable timer 10
			clr_bit( TIM10_CR1_ADR , TIMx_EN );
			break;
		default: // Case of wrong selection
			// Return false
			return STD_FALSE;
			break;
		}
		// Return true
		return STD_TRUE;
	}
	else
	{// In case of in valid data or re-init
		// Return false
		return STD_FALSE;
	}
}


/*--------------------------------------------------------------------------------*/
/* Return the saved count of timer for last detected event			*/
/* Input Parameters: TIMER Peripheral ID, Ch ID, Ptr to variable	*/
/* Return value: STD_TRUE -> Success, STD_FALSE -> Failed			*/
STD_ReturnType ICU_u8GetCh( u8 copy_u8TIM_ID , u8 copy_u8CH_ID , u32* ptr_u32Counterdata )
{
	// Check data validity
	if( ( ( ICU_Init == TIM2_Init ) && ( copy_u8TIM_ID == TIMER2ID ) ) ||
		( ( ICU_Init == TIM5_Init ) && ( copy_u8TIM_ID == TIMER5ID ) ) )
	{
		// Check which channel is selected to be initiated
		switch(copy_u8CH_ID)
		{
			case CH1ID: // Case of Channel 1 is selected
				// Check which timer is selected
				switch(copy_u8TIM_ID)
				{
				case TIMER2ID: // Case of selection timer 2
					*ptr_u32Counterdata = TIM2_CRR1_ADR;
					break;
				case TIMER5ID: // Case of selection timer 5
					*ptr_u32Counterdata = TIM5_CRR1_ADR;
					break;
				case TIMER10ID: // Case of selection timer 10
					 *ptr_u32Counterdata = TIM10_CRR1_ADR;
					break;
				default:// Case of wrong selection
					// Return false
					return STD_FALSE;
					break;
				}
				break;
			case CH2ID: // Case of Channel 2 is selected
				// Check which timer is selected
				switch(copy_u8TIM_ID)
				{
				case TIMER2ID:
					*ptr_u32Counterdata = TIM2_CRR2_ADR;
					break;
				case TIMER5ID:
					*ptr_u32Counterdata = TIM5_CRR2_ADR;
					break;
				case TIMER10ID: // Case of selection timer 10
					return STD_FALSE;
					break;
				default:// Case of wrong selection
					// Return false
					return STD_FALSE;
					break;
				}
				break;
			case CH3ID: // Case of Channel 3 is selected
				// Check which timer is selected
				switch(copy_u8TIM_ID)
				{
				case TIMER2ID:
					*ptr_u32Counterdata = TIM2_CRR3_ADR;
					break;
				case TIMER5ID:
					*ptr_u32Counterdata = TIM5_CRR3_ADR;
					break;
				case TIMER10ID: // Case of selection timer 10
					return STD_FALSE;
					break;
				default:// Case of wrong selection
					// Return false
					return STD_FALSE;
					break;
				}
				break;
			case CH4ID: // Case of Channel 4 is selected
				// Check which timer is selected
				switch(copy_u8TIM_ID)
				{
				case TIMER2ID:
					*ptr_u32Counterdata = TIM2_CRR4_ADR;
					break;
				case TIMER5ID:
					*ptr_u32Counterdata = TIM5_CRR4_ADR;
					break;
				case TIMER10ID: // Case of selection timer 10
					return STD_FALSE;
					break;
				default:// Case of wrong selection
					// Return false
					return STD_FALSE;
					break;
				}
				break;
			default:// Case of wrong selection
				// Return false
				return STD_FALSE;
				break;
		}
		return STD_TRUE;
	}
	else
	{// In case of in valid data or re-init
		// Return false
		return STD_FALSE;
	}
}


/*--------------------------------------------------------------------------------*/
/* Set callback function to be executed when event is captured		*/
/* Input Parameters: TIMER Peripheral ID, ptr to callback function	*/
/* Return value: STD_TRUE -> Success, STD_FALSE -> Failed			*/
STD_ReturnType ICU_u8SetCallback( u8 copy_u8TIM_ID ,  u8 copy_u8CH_ID ,  void  ( *ptr_ICUcallback ) ( u32 )  )
{
	return 0;
}


/*--------------------------------------------------------------------------------*/
