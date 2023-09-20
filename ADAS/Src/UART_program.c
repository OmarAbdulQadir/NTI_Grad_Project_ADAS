/**********************************************************************************/
/***						Date: 20/9/2023	Day: Wednesday						***/
/***    UART driver for STM32F401 a graduation project for thE NTI	program	    ***/
/**********************************************************************************/

/*							Private includes									  */
#include "../Inc/UART_interface.h"

/*--------------------------------------------------------------------------------*/
/*							Global variables									  */

/*--------------------------------------------------------------------------------*/
/*					Global functions implementation								  */

/* Configure UART Peripheral using pre-build configurations			*/
/* Input Parameters: UART Peripheral ID								*/
/* Return value: STD_TRUE -> Success, STD_FALSE -> Failed			*/
STD_ReturnType UART_u8Init( u8 )
{
	return 0;
}



/*--------------------------------------------------------------------------------*/
/* Check if the UART Peripheral is currently available for sending	*/
/* Input Parameters: UART Peripheral ID								*/
/* Return value: STD_TRUE -> Available, STD_FALSE -> Not available	*/
STD_ReturnType UART_u8IfTxAvailable( u8 )
{
	return 0;
}



/*--------------------------------------------------------------------------------*/
/* Check if there is available byte in the buffer to receive		*/
/* Input Parameters: UART Peripheral ID								*/
/* Return value: STD_TRUE -> Available, STD_FALSE -> Not available	*/
STD_ReturnType UART_u8IfRxAvailable( u8 )
{

}



/*--------------------------------------------------------------------------------*/
/* Put one byte in the transmit buffer of the UART Peripheral		*/
/* Input Parameters: UART Peripheral ID, Data Byte					*/
/* Return value: STD_TRUE -> Success, STD_FALSE -> Collision action	*/
STD_ReturnType UART_u8SendByte( u8 , u8 )
{
	return 0;
}


/*--------------------------------------------------------------------------------*/
/* Get Data byte from the receive buffer of the UART peripheral		*/
/* Input Parameters: UART Peripheral ID								*/
/* Return value: Data byte											*/
/* To ensure data integrity availability check must be performed	*/
STD_ReturnType UART_u8SendByte( u8 )
{
	return 0;
}


/*--------------------------------------------------------------------------------*/
/* Set callback function for the UART receive by interrupt			*/
/* Input Parameters: UART Peripheral ID								*/
/* Return value: STD_TRUE -> Success, STD_FALSE -> Failed			*/
STD_ReturnType UART_u8SetRxCallback( u8 )
{
	return 0;
}


/*--------------------------------------------------------------------------------*/
