/**********************************************************************************/
/***						Date: 27/9/2023	Day: Wednesday						***/
/***    NVIC driver for STM32F401 a graduation project for thE NTI 	program	    ***/
/**********************************************************************************/

/*							Private includes									  */
#include "../Inc/NVIC/NVIC_private.h"

/*--------------------------------------------------------------------------------*/
/*							Global variables									  */


/*--------------------------------------------------------------------------------*/
/*					Global functions implementation								  */

/* Enables the IRQx interrupt										*/
/* Input Parameters: IRQx ID										*/
/* Return value: STD_TRUE -> Success, STD_FALSE -> Failed			*/
STD_ReturnType NVIC_u8EnableIRQ( u8 copy_u8IRQ_ID )
{
	// Check data validity and if valid address the IRQ to its register
	if(copy_u8IRQ_ID <= IRQ_MAX)
	{// if ID is valid
		// Calculate the register ID
		u8 IRQ_RegID = copy_u8IRQ_ID / REGSC_MAX_IRQ;
		// Calculate the bits location for the selected IRQ
		u8 IRQ_BitLOC = ( ( copy_u8IRQ_ID - ( IRQ_RegID * REGSC_MAX_IRQ ) ) );
		// Set enable IRQ bit
		set_bit(NVIC_ISERx_ARD(IRQ_RegID), IRQ_BitLOC);
		// Return success
		return STD_TRUE;
	}
	else
	{// If not valid return failed
		// Return failed
		return STD_FALSE;
	}
}


/*--------------------------------------------------------------------------------*/
/* Disable the IRQx interrupt										*/
/* Input Parameters: IRQx ID										*/
/* Return value: STD_TRUE -> Success, STD_FALSE -> Failed			*/
STD_ReturnType NVIC_u8DisableIRQ( u8 copy_u8IRQ_ID )
{
	// Check data validity and if valid address the IRQ to its register
	if(copy_u8IRQ_ID <= IRQ_MAX)
	{// if ID is valid
		// Calculate the register ID
		u8 IRQ_RegID = copy_u8IRQ_ID / REGSC_MAX_IRQ;
		// Calculate the bits location for the selected IRQ
		u8 IRQ_BitLOC = ( ( copy_u8IRQ_ID - ( IRQ_RegID * REGSC_MAX_IRQ ) ) );
		// Set disable IRQ bit
		set_bit(NVIC_ICERx_ARD(IRQ_RegID), IRQ_BitLOC);
		// Return success
		return STD_TRUE;
	}
	else
	{// If not valid return failed
		// Return failed
		return STD_FALSE;
	}
}


/*--------------------------------------------------------------------------------*/
/* Set pinding flag for the IRQx interrupt							*/
/* Input Parameters: IRQx ID										*/
/* Return value: STD_TRUE -> Success, STD_FALSE -> Failed			*/
STD_ReturnType NVIC_u8SetPendingIRQ( u8 copy_u8IRQ_ID )
{
	// Check data validity and if valid address the IRQ to its register
	if(copy_u8IRQ_ID <= IRQ_MAX)
	{// if ID is valid
		// Calculate the register ID
		u8 IRQ_RegID = copy_u8IRQ_ID / REGSC_MAX_IRQ;
		// Calculate the bits location for the selected IRQ
		u8 IRQ_BitLOC = ( ( copy_u8IRQ_ID - ( IRQ_RegID * REGSC_MAX_IRQ ) ) );
		// Set disable IRQ bit
		set_bit(NVIC_ISPRx_ARD(IRQ_RegID), IRQ_BitLOC);
		// Return success
		return STD_TRUE;
	}
	else
	{// If not valid return failed
		// Return failed
		return STD_FALSE;
	}
}


/*--------------------------------------------------------------------------------*/
/* Clear pinding flag for the IRQx interrupt						*/
/* Input Parameters: IRQx ID										*/
/* Return value: STD_TRUE -> Success, STD_FALSE -> Failed			*/
STD_ReturnType NVIC_u8ClearPendingIRQ( u8 copy_u8IRQ_ID )
{
	// Check data validity and if valid address the IRQ to its register
	if(copy_u8IRQ_ID <= IRQ_MAX)
	{// if ID is valid
		// Calculate the register ID
		u8 IRQ_RegID = copy_u8IRQ_ID / REGSC_MAX_IRQ;
		// Calculate the bits location for the selected IRQ
		u8 IRQ_BitLOC = ( ( copy_u8IRQ_ID - ( IRQ_RegID * REGSC_MAX_IRQ ) ) );
		// Set disable IRQ bit
		set_bit(NVIC_ICPRx_ARD(IRQ_RegID), IRQ_BitLOC);
		// Return success
		return STD_TRUE;
	}
	else
	{// If not valid return failed
		// Return failed
		return STD_FALSE;
	}
}


/*--------------------------------------------------------------------------------*/
/* Get pending and active flags value for the IRQx interrupt		*/
/* Input Parameters: IRQx ID, Pointer to u8 variable				*/
/* Return value: STD_TRUE -> Success, STD_FALSE -> Failed			*/
STD_ReturnType NVIC_u8GetStateIRQ( u8 copy_u8IRQ_ID , u8* ptr_IRQ_Status )
{
	// Check data validity and if valid address the IRQ to its register
	return 0;
}


/*--------------------------------------------------------------------------------*/
/* Set priority value for the IRQx interrupt						*/
/* Input Parameters: IRQx ID, Priority u8 value						*/
/* Return value: STD_TRUE -> Success, STD_FALSE -> Failed			*/
STD_ReturnType NVIC_u8SetPriority( u8 copy_u8IRQ_ID , u8 copy_u8IRQ_Priority )
{
	// Check data validity and if valid address the IRQ to its register
	if(copy_u8IRQ_ID <= IRQ_MAX)
	{// if ID is valid
		// Calculate the register ID
		u8 IRQ_RegID = copy_u8IRQ_ID / REGP_MAX_IRQ;
		// Calculate the bits location for the selected IRQ
		u8 IRQ_BitLOC = ( ( copy_u8IRQ_ID - ( IRQ_RegID * REGP_MAX_IRQ ) ) * REGP_IRQ_BITS );
		// Masking whatever the value of the priority to zeros
		NVIC_IPRx_ADR( IRQ_RegID ) &= NVIC_IPRx_SETMASK( IRQ_BitLOC );
		// assign the new priority value
		NVIC_IPRx_ADR( IRQ_RegID ) |= ( ( (u32) copy_u8IRQ_Priority ) << IRQ_BitLOC );
		// Return success
		return STD_TRUE;
	}
	else
	{// If not valid return failed
		// Return failed
		return STD_FALSE;
	}
}


/*--------------------------------------------------------------------------------*/
/* Get priority value for the IRQx interrupt						*/
/* Input Parameters: IRQx ID, Pointer to u8 variable				*/
/* Return value: STD_TRUE -> Success, STD_FALSE -> Failed			*/
STD_ReturnType NVIC_u8GetPriority( u8 copy_u8IRQ_ID , u8* copy_u8IRQ_Priority )
{
	// Check data validity and if valid address the IRQ to its register
	if(copy_u8IRQ_ID <= IRQ_MAX)
	{// if ID is valid
		// Calculate the register ID
		u8 IRQ_RegID = copy_u8IRQ_ID / REGP_MAX_IRQ;
		// Calculate the bits location for the selected IRQ
		u8 IRQ_BitLOC = ( ( copy_u8IRQ_ID - ( IRQ_RegID * REGP_MAX_IRQ ) ) * REGP_IRQ_BITS );
		// Read the register value to a local variable
		u32 PriorityRegvalue = NVIC_IPRx_ADR( IRQ_RegID );
		// Return the priority value in the IRQ priority container
		*copy_u8IRQ_Priority = NVIC_IPRx_GETMASK( PriorityRegvalue , IRQ_BitLOC );
		// Return success
		return STD_TRUE;
	}
	else
	{// If not valid return failed
		// Return failed
		return STD_FALSE;
	}
}


/*--------------------------------------------------------------------------------*/
