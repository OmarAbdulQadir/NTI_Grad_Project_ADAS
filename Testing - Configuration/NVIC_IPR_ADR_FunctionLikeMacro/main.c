#include <stdio.h>

#define TIM2_Init							0x03
#define TIM5_Init							0x0C
#define TIM10_Init							0x30
#define TIM_NOT_Init						0x0
#define	TIMER2ID                			0
#define TIMER5ID			                1
#define	TIMER10ID			                2


#define REG0_ID					        	0
#define REG1_ID					        	1
#define REG2_ID					        	2

#define mask(ID)                            ~((int)0xFF << ID)
#define REGP_MAX_IRQ		        		4
#define REGP_IRQ_BITS				        8

#define GETMASK(value, ID)                  (char)(((int)value >> ID) & 0xFF)


int main() {
    // Write C code here
    
    /*
    int copy_u8TIM_ID = TIMER5ID;
    int ICU_Init = TIM_NOT_Init | TIM5_Init;
    
    printf("%d", ( ( copy_u8TIM_ID == TIMER5ID  ) && ( ( ICU_Init & TIM5_Init ) == TIM_NOT_Init  ) ) );
    */
    
  
    int copy_u8IRQ_ID = 20;
    /*
    if((copy_u8IRQ_ID/32) == REG0_ID)
        printf("%d", REG0_ID);
    else if((copy_u8IRQ_ID/32) == REG1_ID)
        printf("%d", REG1_ID);
    else if((copy_u8IRQ_ID/32) == REG2_ID)
        printf("%d", REG2_ID);
    else
        printf("%d", 255);
    
    
    printf("Reg id: %d\n", copy_u8IRQ_ID/4);
    printf("Reg loc: %d\n", copy_u8IRQ_ID%4);
    */
    
    /*
	int IRQ_RegID = copy_u8IRQ_ID / REGP_MAX_IRQ;
    int IRQ_LOC = ( ( copy_u8IRQ_ID - ( IRQ_RegID * REGP_MAX_IRQ ) ) * REGP_IRQ_BITS );
    
    printf("%u\n", IRQ_RegID);
    printf("%u\n", IRQ_LOC);
    printf("%u", mask(IRQ_LOC));
    */
    
    printf("%u",  GETMASK(2683927005 >> 16));

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