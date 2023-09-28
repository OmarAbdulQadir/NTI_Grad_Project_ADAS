/**********************************************************************************/
/***						Date: 20/9/2023	Day: Wednesday						***/
/***    NVIC driver for STM32F401 a graduation project for thE NTI 	program	    ***/
/**********************************************************************************/

#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_

#include "../Inc/NVIC/NVIC_interface.h"

#define NVIC_BASE_ADR						((u32)(0xE000E000))

#define NVIC_ISERx_ARD(REG_ID)				(*((volatile u32*) (NVIC_BASE_ADR+0x100+(0x04*(REG_ID)))))
#define NVIC_ICERx_ARD(REG_ID)				(*((volatile u32*) (NVIC_BASE_ADR+0x180+(0x04*(REG_ID)))))
#define NVIC_ISPRx_ARD(REG_ID)				(*((volatile u32*) (NVIC_BASE_ADR+0x200+(0x04*(REG_ID)))))
#define NVIC_ICPRx_ARD(REG_ID)				(*((volatile u32*) (NVIC_BASE_ADR+0x280+(0x04*(REG_ID)))))
#define NVIC_IABRx_ARD(REG_ID)				(*((volatile u32*) (NVIC_BASE_ADR+0x300+(0x04*(REG_ID)))))
#define NVIC_IPRx_ADR(REG_ID)				(*((volatile u32*) (NVIC_BASE_ADR+0x400+(0x04*(REG_ID)))))

#define NVIC_IPRx_SETMASK(ST_LOC)			~(((u32) 0xFF) << ST_LOC)
#define NVIC_IPRx_GETMASK(Value, ST_LOC)	(u8)(((u32)Value >> ST_LOC) & 0xFF)

#define REGSC_MAX_IRQ				32
#define REGP_MAX_IRQ				4
#define REGP_IRQ_BITS				8

#define IRQ_MAX						84

#endif /* NVIC_PRIVATE_H_ */
