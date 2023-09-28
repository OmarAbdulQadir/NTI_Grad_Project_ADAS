/**********************************************************************************/
/***						Date: 20/9/2023	Day: Wednesday						***/
/***    NVIC driver for STM32F401 a graduation project for thE NTI 	program	    ***/
/**********************************************************************************/

#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_

// Libraries includes
#include "../Inc/LIB/STD_TYPES.h"
#include "../Inc/LIB/BIT_MATH.h"


#define	NVIC_IRQ_ID_TIM10				25
#define	NVIC_IRQ_ID_TIM2				28
#define	NVIC_IRQ_ID_TIM3				29
#define	NVIC_IRQ_ID_TIM4				30
#define	NVIC_IRQ_ID_USART1				37
#define	NVIC_IRQ_ID_TIM5				50

// Priority Macros
#define NVIC_PRIORITY_0					0x00
#define NVIC_PRIORITY_1					0x10
#define NVIC_PRIORITY_2					0x20
#define NVIC_PRIORITY_3					0x30
#define NVIC_PRIORITY_4					0x40
#define NVIC_PRIORITY_5					0x50
#define NVIC_PRIORITY_6					0x60
#define NVIC_PRIORITY_7					0x70
#define NVIC_PRIORITY_8					0x80
#define NVIC_PRIORITY_9					0x90
#define NVIC_PRIORITY_10				0xA0
#define NVIC_PRIORITY_11				0xB0
#define NVIC_PRIORITY_12				0xC0
#define NVIC_PRIORITY_13				0xD0
#define NVIC_PRIORITY_14				0xE0
#define NVIC_PRIORITY_15				0xF0


/* Enables the IRQx interrupt										*/
/* Input Parameters: IRQx ID										*/
/* Return value: STD_TRUE -> Success, STD_FALSE -> Failed			*/
STD_ReturnType NVIC_u8EnableIRQ( u8 );

/* Disable the IRQx interrupt										*/
/* Input Parameters: IRQx ID										*/
/* Return value: STD_TRUE -> Success, STD_FALSE -> Failed			*/
STD_ReturnType NVIC_u8DisableIRQ( u8 );

/* Set pending flag for the IRQx interrupt							*/
/* Input Parameters: IRQx ID										*/
/* Return value: STD_TRUE -> Success, STD_FALSE -> Failed			*/
STD_ReturnType NVIC_u8SetPendingIRQ( u8 );

/* Clear pending flag for the IRQx interrupt						*/
/* Input Parameters: IRQx ID										*/
/* Return value: STD_TRUE -> Success, STD_FALSE -> Failed			*/
STD_ReturnType NVIC_u8ClearPendingIRQ( u8 );

/* Get pending and active flags value for the IRQx interrupt		*/
/* Input Parameters: IRQx ID, Pointer to u8 variable				*/
/* Return value: STD_TRUE -> Success, STD_FALSE -> Failed			*/
STD_ReturnType NVIC_u8GetStateIRQ( u8 , u8* );

/* Set priority value for the IRQx interrupt						*/
/* Input Parameters: IRQx ID, Priority u8 value						*/
/* Return value: STD_TRUE -> Success, STD_FALSE -> Failed			*/
STD_ReturnType NVIC_u8SetPriority( u8 , u8 );

/* Get priority value for the IRQx interrupt						*/
/* Input Parameters: IRQx ID, Pointer to u8 variable				*/
/* Return value: STD_TRUE -> Success, STD_FALSE -> Failed			*/
STD_ReturnType NVIC_u8GetPriority( u8 , u8* );

#endif /* NVIC_INTERFACE_H_ */
