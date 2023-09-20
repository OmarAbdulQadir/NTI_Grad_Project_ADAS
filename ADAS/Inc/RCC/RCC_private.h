#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

/***********************************************************************************
	*
	-----> Macros
			*  Base_Address is				0x40023800 
			*  Register Map
************************************************************************************/

#define         RCC_BASE_ADDRESS                ((u32)(0x40023800u))

#define			RCC_CR							(*((volatile u32*) (RCC_BASE_ADDRESS+0X00)))
#define			RCC_PLLCFGR					    (*((volatile u32*) (RCC_BASE_ADDRESS+0x04)))
#define			RCC_CFGR						(*((volatile u32*) (RCC_BASE_ADDRESS+0x08)))
#define			RCC_CIR							(*((volatile u32*) (RCC_BASE_ADDRESS+0x0C)))
#define			RCC_AHB1RSTR					(*((volatile u32*) (RCC_BASE_ADDRESS+0x10)))
#define			RCC_AHB2RSTR					(*((volatile u32*) (RCC_BASE_ADDRESS+0x14)))
#define			RCC_APB1RSTR					(*((volatile u32*) (RCC_BASE_ADDRESS+0x20)))
#define			RCC_APB2RSTR					(*((volatile u32*) (RCC_BASE_ADDRESS+0x24)))
#define			RCC_AHB1ENR					    (*((volatile u32*) (RCC_BASE_ADDRESS+0x30)))
#define			RCC_AHB2ENR					    (*((volatile u32*) (RCC_BASE_ADDRESS+0x34)))
#define			RCC_APB1ENR					    (*((volatile u32*) (RCC_BASE_ADDRESS+0x40)))
#define			RCC_APB2ENR					    (*((volatile u32*) (RCC_BASE_ADDRESS+0x44)))
#define			RCC_AHB1LPENR				    (*((volatile u32*) (RCC_BASE_ADDRESS+0x50)))
#define			RCC_AHB2LPENR				    (*((volatile u32*) (RCC_BASE_ADDRESS+0x54)))
#define			RCC_APB1LPENR				    (*((volatile u32*) (RCC_BASE_ADDRESS+0x60)))
#define			RCC_APB2LPENR				    (*((volatile u32*) (RCC_BASE_ADDRESS+0x64)))
#define			RCC_BDCR						(*((volatile u32*) (RCC_BASE_ADDRESS+0x70)))
#define			RCC_CSR							(*((volatile u32*) (RCC_BASE_ADDRESS+0x74)))
#define			RCC_SSCGR						(*((volatile u32*) (RCC_BASE_ADDRESS+0x80)))
#define			RCC_PLLI2SCFGR				    (*((volatile u32*) (RCC_BASE_ADDRESS+0x84)))

/************************************************************************************/

/*
			- RCC clock control register (RCC_CR) bits numbers
*/

// PLL ready flag
#define			RCC_PLLRDY_bit					25

// Main PLL (PLL) enable
#define			RCC_PLLON_bit					24

// Clock securty system enable
#define 		RCC_CSSON_bit					19

// 	HSE clock bypass
#define			RCC_HSEBYP_bit					18

// HSE ready flag
#define			RCC_HSERDY_bit					17

// HSE clock enable
#define			RCC_HSEON_bit					16

// HSI ready flag
#define			RCC_HSIRDY_bit					1

// Internal high-speed clock enable
#define			RCC_HSION_bit					0

/*
			- RCC PLL configuration register (RCC_PLLCFGR) bit numbers
*/
// PLL entry clock
#define			RCC_PLLSRC_bit					22

// Main PLL (PLL) division factor for main system clock
#define			RCC_PLLP_bit					16

// Main PLL (PLL) multiplication factor for VCO
#define			RCC_PLLN_bit					14

// Division factor for the main PLL (PLL) and audio PLL (PLLI2S) input clock
#define			RCC_PLLM_bit					5

/*
			- RCC clock configuration register (RCC_CFGR) bit numbers
*/

// APB high-speed pre-scaler (APB2)
#define			RCC_PPRE2_bit					15

// APB Low speed pre-scaler (APB1)
#define			RCC_PPRE1_bit					12

// AHB pre-scaler
#define			RCC_PRE_bit						7

/*
			- General Macros
*/

// PLL

// PLL Configuration Resister mask
#define			RCC_PLLCFGR_mask				((u32)(0xFFFC8000u))

// Clock configuration register mask
#define			RCC_CFGR_mask					((u32)(0xFFFF030Cu))

// Select HSI as clk source
#define			RCC_HSI_Clk_Src					(0b00u)

// Select HSE as clk source
#define			RCC_HSE_Clk_Src					(0b01u)

// Select PLL as clk source
#define			RCC_PLL_Clk_Src					(0b10u)


#endif //RCC_PRIVATE_H

