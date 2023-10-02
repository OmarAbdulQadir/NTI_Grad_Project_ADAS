/**********************************************************************************/
/***						Date: 20/9/2023	Day: Wednesday						***/
/***    UART driver for STM32F401 a graduation project for thE NTI 	program	    ***/
/**********************************************************************************/

#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_


typedef struct
{
	u32 UART_SR;
	u32 UART_DR;
	u32 UART_BRR;
	u32 UART_CR1;
	u32 UART_CR2;
	u32 UART_CR3;
	u32 UART_GTP;
}UART_t;


#define NO_UART				3
#define UART1_BASE			( ( volatile UART_t * ) 0x40011000u )
#define UART2_BASE			( ( volatile UART_t * ) 0x40004400u )
#define UART6_BASE			( ( volatile UART_t * ) 0x40011400u )

#define Null				((void *)0)
#define IF_FAILED			100

#define UART_TXE_BIT		7
#define UART_TC_BIT			6
#define UART_RXNE_BIT		5

#define UART_MANTISSA_BIT	4

#define UART_NOT_INIT		0x00
#define UART1_INIT			0x03
#define UART2_INIT			0x0C
#define UART6_INIT			0x30


#endif /* UART_PRIVATE_H_ */
