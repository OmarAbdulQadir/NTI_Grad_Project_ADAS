#include <stdio.h>

#define NVIC_BASE_ADR				((int)(0xE000E100))
#define NVIC_IPR2_ADR				(((volatile int*) (NVIC_BASE_ADR+0x400+0x04+0x2)))
#define NVIC_IPRx_ADR(REG_ID)		(((volatile int*) (NVIC_BASE_ADR+0x400+0x04+(REG_ID))))

#define NVIC_IPRx_GETMASK(Value, ST_LOC)	(char)(((int)Value >> ST_LOC) & 0xFF)


int main(void){

    //printf("org: %u\n", NVIC_IPR2_ADR);
	//printf("test: %u\n", NVIC_IPRx_ADR(0x02));
	
	printf("test: %u\n", NVIC_IPRx_GETMASK(3883850685, 16));

    return 0;
}


/*
#define NVIC_IPR1_ADR				(*((volatile u32*) (NVIC_BASE_ADR+0x400+0x04+0x1)))
#define NVIC_IPR2_ADR				(*((volatile u32*) (NVIC_BASE_ADR+0x400+0x04+0x2)))
#define NVIC_IPR3_ADR				(*((volatile u32*) (NVIC_BASE_ADR+0x400+0x04+0x3)))
#define NVIC_IPR4_ADR				(*((volatile u32*) (NVIC_BASE_ADR+0x400+0x04+0x4)))
#define NVIC_IPR5_ADR				(*((volatile u32*) (NVIC_BASE_ADR+0x400+0x04+0x5)))
#define NVIC_IPR6_ADR				(*((volatile u32*) (NVIC_BASE_ADR+0x400+0x04+0x6)))
#define NVIC_IPR7_ADR				(*((volatile u32*) (NVIC_BASE_ADR+0x400+0x04+0x7)))
#define NVIC_IPR7_ADR				(*((volatile u32*) (NVIC_BASE_ADR+0x400+0x04+0x8)))
#define NVIC_IPR8_ADR				(*((volatile u32*) (NVIC_BASE_ADR+0x400+0x04+0x9)))
#define NVIC_IPR10_ADR				(*((volatile u32*) (NVIC_BASE_ADR+0x400+0x04+0x10)))
#define NVIC_IPR11_ADR				(*((volatile u32*) (NVIC_BASE_ADR+0x400+0x04+0x11)))
#define NVIC_IPR12_ADR				(*((volatile u32*) (NVIC_BASE_ADR+0x400+0x04+0x12)))
#define NVIC_IPR13_ADR				(*((volatile u32*) (NVIC_BASE_ADR+0x400+0x04+0x13)))
#define NVIC_IPR14_ADR				(*((volatile u32*) (NVIC_BASE_ADR+0x400+0x04+0x14)))
#define NVIC_IPR15_ADR				(*((volatile u32*) (NVIC_BASE_ADR+0x400+0x04+0x15)))
#define NVIC_IPR16_ADR				(*((volatile u32*) (NVIC_BASE_ADR+0x400+0x04+0x16)))
#define NVIC_IPR17_ADR				(*((volatile u32*) (NVIC_BASE_ADR+0x400+0x04+0x17)))
#define NVIC_IPR18_ADR				(*((volatile u32*) (NVIC_BASE_ADR+0x400+0x04+0x18)))
#define NVIC_IPR19_ADR				(*((volatile u32*) (NVIC_BASE_ADR+0x400+0x04+0x19)))
#define NVIC_IPR20_ADR				(*((volatile u32*) (NVIC_BASE_ADR+0x400+0x04+0x20)))
#define NVIC_IPR21_ADR				(*((volatile u32*) (NVIC_BASE_ADR+0x400+0x04+0x21)))
*/