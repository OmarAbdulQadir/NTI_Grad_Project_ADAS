/**********************************************************************************/
/***						Date: 20/9/2023	Day: Wednesday						***/
/***    NVIC driver for STM32F401 a graduation project for thE NTI 	program	    ***/
/**********************************************************************************/

#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_

#include "../Inc/NVIC/NVIC_interface.h"

#define NVIC_BASE_ADR						((u32)(0xE000E100))

#define NVIC_ISER0_ARD						(*((volatile u32*) (NVIC_BASE_ADR+0x100+0x04+0x0)))
#define NVIC_ISER1_ARD						(*((volatile u32*) (NVIC_BASE_ADR+0x100+0x04+0x1)))
#define NVIC_ISER2_ARD						(*((volatile u32*) (NVIC_BASE_ADR+0x100+0x04+0x2)))

#define NVIC_ICER0_ARD						(*((volatile u32*) (NVIC_BASE_ADR+0x180+0x04+0x0)))
#define NVIC_ICER1_ARD						(*((volatile u32*) (NVIC_BASE_ADR+0x180+0x04+0x1)))
#define NVIC_ICER2_ARD						(*((volatile u32*) (NVIC_BASE_ADR+0x180+0x04+0x2)))

#define NVIC_ISPR0_ARD						(*((volatile u32*) (NVIC_BASE_ADR+0x200+0x04+0x0)))
#define NVIC_ISPR1_ARD						(*((volatile u32*) (NVIC_BASE_ADR+0x200+0x04+0x1)))
#define NVIC_ISPR2_ARD						(*((volatile u32*) (NVIC_BASE_ADR+0x200+0x04+0x2)))

#define NVIC_ICPR0_ARD						(*((volatile u32*) (NVIC_BASE_ADR+0x280+0x04+0x0)))
#define NVIC_ICPR1_ARD						(*((volatile u32*) (NVIC_BASE_ADR+0x280+0x04+0x1)))
#define NVIC_ICPR2_ARD						(*((volatile u32*) (NVIC_BASE_ADR+0x280+0x04+0x2)))

#define NVIC_IABR0_ARD						(*((volatile u32*) (NVIC_BASE_ADR+0x300+0x04+0x0)))
#define NVIC_IABR1_ARD						(*((volatile u32*) (NVIC_BASE_ADR+0x300+0x04+0x1)))
#define NVIC_IABR2_ARD						(*((volatile u32*) (NVIC_BASE_ADR+0x300+0x04+0x2)))

#define NVIC_IPRx_ADR(REG_ID)				(*((volatile u32*) (NVIC_BASE_ADR+0x400+0x04+(REG_ID))))
#define NVIC_IPRx_SETMASK(ST_LOC)			~(((u32) 0xFF) << ST_LOC)
#define NVIC_IPRx_GETMASK(Value, ST_LOC)	(u8)(((u32)Value >> ST_LOC) & 0xFF)

#define REG0_ID						0
#define REG1_ID						1
#define REG2_ID						2

#define REGSC_MAX_IRQ				32
#define REGP_MAX_IRQ				4
#define REGP_IRQ_BITS				8
#define REG0MAX						32
#define REG1MAX						64

#define IRQ_MAX						84

#endif /* NVIC_PRIVATE_H_ */
