/**********************************************************************************/
/***						Date: 20/9/2023	Day: Wednesday						***/
/***    UART driver for STM32F401 a graduation project for thE NTI	program	    ***/
/**********************************************************************************/

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

// Libraries includes
#include "../Inc/LIB/STD_TYPES.h"
#include "../Inc/LIB/BIT_MATH.h"

#define UART1ID				0
#define UART2ID				1
#define UART6ID				2

/* Configure UART Peripheral using pre-build configurations			*/
/* Input Parameters: UART Peripheral ID								*/
/* Return value: STD_TRUE -> Success, STD_FALSE -> Failed			*/
STD_ReturnType UART_u8Init( u8 );

/* Check if the UART Peripheral is currently available for sending	*/
/* Input Parameters: UART Peripheral ID								*/
/* Return value: STD_TRUE -> Available, STD_FALSE -> Not available	*/
STD_ReturnType UART_u8IfTxAvailable( u8 );

/* Check if there is available byte in the buffer to receive		*/
/* Input Parameters: UART Peripheral ID								*/
/* Return value: STD_TRUE -> Available, STD_FALSE -> Not available	*/
STD_ReturnType UART_u8IfRxAvailable( u8 );

/* Put one byte in the transmit buffer of the UART Peripheral		*/
/* Input Parameters: UART Peripheral ID, Data Byte					*/
/* Return value: STD_TRUE -> Success, STD_FALSE -> Collision action	*/
STD_ReturnType UART_u8SendByte( u8 , u8 );

/* Get Data byte from the receive buffer of the UART peripheral		*/
/* Input Parameters: UART Peripheral ID								*/
/* Return value: STD_TRUE -> Success, STD_FALSE -> Collision action	*/
STD_ReturnType UART_u8ReceiveByte( u8 , u8* );

/* Set callback function for the UART receive by interrupt			*/
/* Input Parameters: UART Peripheral ID								*/
/* Return value: STD_TRUE -> Success, STD_FALSE -> Failed			*/
STD_ReturnType UART_u8SetCallback( u8 , void ( *ptr_UARTcallback )( void ) );

#endif /* UART_INTERFACE_H_ */
