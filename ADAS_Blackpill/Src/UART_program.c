/**********************************************************************************/
/***						Date: 20/9/2023	Day: Wednesday						***/
/***    UART driver for STM32F401 a graduation project for thE NTI	program	    ***/
/**********************************************************************************/

/*							Private includes									  */
#include "../Inc/UART/UART_interface.h"
#include "../Inc/UART/UART_private.h"
#include "../Inc/UART/UART_config.h"

/*--------------------------------------------------------------------------------*/
/*							Global variables									  */
static volatile UART_t* UART_bases[NO_UART] = { UART1_BASE, UART2_BASE, UART6_BASE };
static void (*ptr_UART1_IRQHandlerCallback)(void) = Null;
static u8 UART_Init = UART_NOT_INIT;


/*--------------------------------------------------------------------------------*/
/*					Global functions implementation								  */

/* Configure UART Peripheral using pre-build configurations			*/
/* Input Parameters: UART Peripheral ID								*/
/* Return value: STD_TRUE -> Success, STD_FALSE -> Failed			*/
STD_ReturnType UART_u8Init( u8 copy_u8UART_ID )
{
	// Check input data validity
	if( ( copy_u8UART_ID == UART1ID ) && ( ( UART_Init & UART1_INIT ) == UART_NOT_INIT ) )
	{// If valid
		// Check which channel is selected
		switch( copy_u8UART_ID )
		{
		case UART1ID: // Case of selecting UART 1
			// Set the Boad Rate value
			UART_bases[copy_u8UART_ID]->UART_BRR = ( ( UART1_MANTISSA << UART_MANTISSA_BIT ) | UART1_FRACTION );
			// Set the control register configurations
			UART_bases[copy_u8UART_ID]->UART_CR1 = UART1_CR1;
			// Set init variable for UART1 init
			UART_Init |= UART1_INIT;
			// Return success
			return STD_TRUE;
			break;
		case UART2ID: // Case of selecting UART 2
			break;
		case UART6ID: // Case of selecting UART 6
			break;
		default: // Case of wrong selection
			// Return failed
			return STD_FALSE;
			break;
		}
		// Return failed
		return STD_FALSE;
	}
	else
	{// If not valid
		// Return failed
		return STD_FALSE;
	}
}



/*--------------------------------------------------------------------------------*/
/* Check if the UART Peripheral is currently available for sending	*/
/* Input Parameters: UART Peripheral ID								*/
/* Return value: STD_TRUE -> Av., STD_FALSE -> N/A, failed -> 100	*/
STD_ReturnType UART_u8IfTxAvailable( u8 copy_u8UART_ID )
{
	// Check data validity
	if( ( copy_u8UART_ID == UART1ID ) && ( ( UART_Init & UART1_INIT ) == UART1_INIT ) )
	{// If valid
		return get_bit( (UART_bases[copy_u8UART_ID]->UART_SR) , UART_TXE_BIT );
	}
	else
	{// If not valid
		// return failed
		return IF_FAILED;
	}
}



/*--------------------------------------------------------------------------------*/
/* Check if there is available byte in the buffer to receive		*/
/* Input Parameters: UART Peripheral ID								*/
/* Return value: STD_TRUE -> Available, STD_FALSE -> Not available	*/
STD_ReturnType UART_u8IfRxAvailable( u8 copy_u8UART_ID )
{
	// Check data validity
	if( ( copy_u8UART_ID == UART1ID ) && ( ( UART_Init & UART1_INIT ) == UART1_INIT ) )
	{// If valid
		return get_bit( (UART_bases[copy_u8UART_ID]->UART_SR) , UART_RXNE_BIT );
	}
	else
	{// If not valid
		// return failed
		return IF_FAILED;
	}
}



/*--------------------------------------------------------------------------------*/
/* Put one byte in the transmit buffer of the UART Peripheral		*/
/* Input Parameters: UART Peripheral ID, Data Byte					*/
/* Return value: STD_TRUE -> Success, STD_FALSE -> Collision action	*/
STD_ReturnType UART_u8SendByte( u8 copy_u8UART_ID , u8 copy_u8DataByte )
{
	// Check data validity
	if( ( copy_u8UART_ID == UART1ID ) && ( ( UART_Init & UART1_INIT ) == UART1_INIT ) )
	{// If valid
		// It data transmission is ready or not
		if( get_bit( (UART_bases[copy_u8UART_ID]->UART_SR) , UART_TC_BIT ) == STD_TRUE )
		{// if available
			// Sent data byte to the buffer
			UART_bases[copy_u8UART_ID]->UART_DR = copy_u8DataByte;
			// Return success
			return STD_TRUE;
		}
		else
		{// if not available
			// Return failed
			return STD_FALSE;
		}
	}
	else
	{// If not valid
		// Return failed
		return STD_FALSE;
	}
}


/*--------------------------------------------------------------------------------*/
/* Get Data byte from the receive buffer of the UART peripheral		*/
/* Input Parameters: UART Peripheral ID, Ptr to Rx data variable	*/
/* Return value: STD_TRUE -> Success, STD_FALSE -> Collision action	*/
STD_ReturnType UART_u8ReceiveByte( u8 copy_u8UART_ID , u8* ptr_u8DataByte  )
{
	// Check data validity
	if( ( copy_u8UART_ID == UART1ID ) && ( ( UART_Init & UART1_INIT ) == UART1_INIT ) )
	{// If valid
		// It recived data is ready in the DR
		//if( get_bit( (UART_bases[copy_u8UART_ID]->UART_SR) , UART_RXNE_BIT ) == STD_TRUE )
		//{// if available
			// Recive data byte
			*ptr_u8DataByte = UART_bases[copy_u8UART_ID]->UART_DR;
			// Return success
			return STD_TRUE;
		//}
		//else
		//{// if not available
			// Return failed
			//return STD_FALSE;
		//}
	}
	else
	{// If not valid
		// Return failed
		return STD_FALSE;
	}
}

/*--------------------------------------------------------------------------------*/
/* Set callback function for the UART receive by interrupt			*/
/* Input Parameters: UART Peripheral ID								*/
/* Return value: STD_TRUE -> Success, STD_FALSE -> Failed			*/
STD_ReturnType UART_u8SetCallback( u8 copy_u8UART_ID , void ( *ptr_UARTcallback )( void ) )
{
	// Check is the input pointer to function is not null
	if( (ptr_UARTcallback != Null) )
	{// if valid
		// Check which UART peripheral is selected
		switch(copy_u8UART_ID)
		{
		case UART1ID: // Case UART1 is selected
			// Set the interrupt callback
			ptr_UART1_IRQHandlerCallback = ptr_UARTcallback;
			// Return success
			return STD_TRUE;
			break;
		case UART2ID: // Case UART2 is selected
			// Set the interrupt callback

			// Return success
			return STD_FALSE;
			break;
		case UART6ID: // Case UART6 is selected
			// Set the interrupt callback

			// Return success
			return STD_FALSE;
			break;
		default: // Case of wrong selection
			// Return failed
			return STD_FALSE;
		}
		// Return failed
		return STD_FALSE;
	}
	else
	{// if not valid
		// return failed
		return STD_FALSE;
	}
}

/*--------------------------------------------------------------------------------*/
/* UART interrupt request handler									*/
/* Input Parameters: void											*/
/* Return value: void												*/
void USART1_IRQHandler( void )
{
	if(ptr_UART1_IRQHandlerCallback != Null)
		ptr_UART1_IRQHandlerCallback();
}

/*--------------------------------------------------------------------------------*/
