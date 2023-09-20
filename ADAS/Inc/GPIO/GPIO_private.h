/**********************************************************************************/
/***						Date: 20/9/2023	Day: Wednesday						***/
/***    GPIO driver for STM32F401 a graduation project for thE NTI 	program	    ***/
/**********************************************************************************/

/**********************************************************************************
 ******************* 	guard of file will call on time in .c		***************
 **********************************************************************************/ 
#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

/**********************************************************************************
 *******************			GPIO ports struct type				***************
 **********************************************************************************/ 

typedef struct{

	volatile u32 MODER;
	volatile u32 OTYPER;
	volatile u32 OSPEEDR;
	volatile u32 PUPDR;
	volatile u32 IDR;
	volatile u32 ODR;
	volatile u32 BSRR;
	volatile u32 LCKR;
	volatile u64 AFR;

}GPIO_t;


/**********************************************************************************
 *******************		GPIO ports base addresses				***************
 **********************************************************************************/ 

#define  GPIOA_BASE_ADDRESS								( ( volatile GPIO_t * ) 0x40020000u )
#define  GPIOB_BASE_ADDRESS								( ( volatile GPIO_t * ) 0x40020400u )
#define  GPIOC_BASE_ADDRESS								( ( volatile GPIO_t * ) 0x40020800u )
#define  GPIOD_BASE_ADDRESS								( ( volatile GPIO_t * ) 0x40020C00u )
#define  GPIOE_BASE_ADDRESS								( ( volatile GPIO_t * ) 0x40021000u )
#define  GPIOH_BASE_ADDRESS								( ( volatile GPIO_t * ) 0x40021C00u )


/**********************************************************************************
 *******************			GPIO private macros					***************
 **********************************************************************************/

#define	 GPIO_bases_max									6
#define  GPIO_MODER_MASK(pin_number)					(~(((u32) 0b11)<<(pin_number)))
#define  GPIO_OSPEEDR_MASK(pin_number)					(~(((u32) 0b11)<<(pin_number)))
#define  GPIO_PUPDR_MASK(pin_number)					(~(((u32) 0b11)<<(pin_number)))
#define  GPIO_ODR_MASK(pin_number)						(~(((u32) 0b1)<<(pin_number)))
#define  GPIO_AFR_MAX									(0b1111)
#define  GPIO_AFR_MASK(pin_number)						(~(((u64) 0b1111)<<(pin_number)))

#endif //GPIO_PRIVATE_H

