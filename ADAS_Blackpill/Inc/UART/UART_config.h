/**********************************************************************************/
/***						Date: 20/9/2023	Day: Wednesday						***/
/***    UART driver for STM32F401 a graduation project for thE NTI 	program	    ***/
/**********************************************************************************/

#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_

#define	SYS_CLK				16

// For boad rate 9600 bps UARTDIV = 16/8*(BR)
#define UART1_MANTISSA		208
#define UART1_FRACTION		3

// Control register 1 configurations
#define UART1_CR1			0xA02C

#endif /* UART_CONFIG_H_ */
