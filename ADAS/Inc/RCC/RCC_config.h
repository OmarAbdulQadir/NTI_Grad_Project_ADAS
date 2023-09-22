/**********************************************************************************/
/***						Date: 20/9/2023	Day: Wednesday						***/
/***    RCC driver for STM32F401 a graduation project for thE NTI 	program	    ***/
/**********************************************************************************/

#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_

/*
			- Configurations of clock source
*/

// External clock source
#define		RCC_HSI					1
// Internal clock source
#define 	RCC_HSE					0
// Clock source selection
#define		RCC_Clk_SRC				RCC_HSI

// Bypass bit if the external clock source is selected
#if			RCC_Clk_SRC == RCC_HSE

#define		RCC_HSE_BYP				1

#endif

// Clock securty system enable
#define		RCC_CSSON				0

/*
			- PLL Configuration
*/

// PLL enable
#define		RCC_PLL_Enable			0

// PLL parameters if PLL is selected
#if			RCC_PLL_Enable == 1

	#define		RCC_PLLSRC			RCC_HSI

	#define		RCC_PLL_P			2

	#define		RCC_PLL_N			192

	#if			RCC_PLL_N < 192
		#error: PLLN Value is lower than boundaries
	#elif		RCC_PLL_N > 432
		#error:	PLLN Value is higher than boundaries
	#endif

	#define		RCC_PLL_M			4

	#if			RCC_PLL_M < 3
		#error: PLLM Value is lower than boundaries
	#elif		RCC_PLL_M > 63
		#error:	PLLM Value is higher than boundaries
	#endif

#endif

/*
			- Peripheral buses pre-scaler
*/

// AHB pre-scaler
#define		RCC_HPRE			(0b1000u)

#if			RCC_HPRE == (0b0000u)
	#warning: Assigning AHB clock - System clock not divided
#endif

// APB1 low speed bus pre-scaler (Caution: Max freq is 42MHz)
#define		RCC_PPRE1			(0b111u)

#if			RCC_PPRE1 == (0b000u)
	#warning: Assigning APB1 clock - AHB clock not divided
#endif

// APB2 high speed bus pre-scaler (Caution: Max freq is 84MHz)
#define 	RCC_PPRE2			(0b101u)

#if			RCC_PPRE2 == (0b0000u)
	#warning: Assigning APB2 clock - AHB clock not divided
#endif


/*
			- Peripherals enable
*/


/*			AHB1 Peripheral clock enable			*/

// DMA1 clock enable
#define		RCC_DMA1EN			0

// DMA2 clock enable
#define		RCC_DMA2EN			0

// CRC clock enable
#define		RCC_CRCEN			0

// GPIOA clock enable
#define		RCC_GPIOAEN			1

// GPIOB clock enable
#define		RCC_GPIOBEN			0

// GPIOC clock enable
#define		RCC_GPIOCEN			0

// GPIOD clock enable
#define		RCC_GPIODEN			0

// GPIOE clock enable
#define		RCC_GPIOEEN			0

// GPIOH clock enable
#define		RCC_GPIOHEN			0

// RCC_AHB1ENR Reg init value
#define		RCC_AHB1LPENR_init	(										\
								(RCC_DMA1EN << RCC_DMA1EN_bit		) | \
								(RCC_DMA2EN << RCC_DMA2EN_bit		) | \
								(RCC_CRCEN << RCC_CRCEN_bit			) | \
								(RCC_GPIOAEN << RCC_GPIOAEN_bit		) | \
								(RCC_GPIOBEN << RCC_GPIOBEN_bit		) | \
								(RCC_GPIOCEN << RCC_GPIOCEN_bit		) | \
								(RCC_GPIODEN << RCC_GPIODEN_bit		) | \
								(RCC_GPIOEEN << RCC_GPIOEEN_bit		) | \
								(RCC_GPIOHEN << RCC_GPIOHEN_bit		)	\
																	)


/*			AHB2 Peripheral clock enable			*/

// USB OTG FS clock enable
#define		RCC_OTGFSEN			0

// RCC_AHB2ENR Reg init value
#define		RCC_AHB2LPENR_init	(										\
								(RCC_OTGFSEN << RCC_OTGFSEN_bit		)	\
																		)


/*			APB1 Peripheral clock enable			*/

// Power interface clock enable
#define		RCC_PWREN			0

// I2C1 clock enable
#define		RCC_I2C1EN			0

// I2C2 clock enable
#define		RCC_I2C2EN			0

// I2C3 clock enable
#define		RCC_I2C3EN			0

// USART2 clock enable
#define		RCC_USART2EN		0

// SPI2 clock enable
#define		RCC_SPI2EN			0

// SPI3 clock enable
#define		RCC_SPI3EN			0

// Window watch-dog clock enable
#define		RCC_WWDGEN			0

// TIM2 clock enable
#define		RCC_TIM2EN			0

// TIM3 clock enable
#define		RCC_TIM3EN			0

// TIM4 clock enable
#define		RCC_TIM4EN			0

// TIM5 clock enable
#define		RCC_TIM5EN			0

// RCC_APB1LPENR Reg init value
#define		RCC_APB1LPENR_init	(										\
								(RCC_PWREN << RCC_PWREN_bit			) | \
								(RCC_I2C1EN << RCC_I2C1EN_bit		) | \
								(RCC_I2C2EN << RCC_I2C2EN_bit		) | \
								(RCC_I2C3EN << RCC_I2C3EN_bit		) | \
								(RCC_USART2EN << RCC_USART2EN_bit) | \
								(RCC_SPI2EN << RCC_SPI2EN_bit		) | \
								(RCC_SPI3EN << RCC_SPI3EN_bit		) | \
								(RCC_WWDGEN << RCC_WWDGEN_bit		) | \
								(RCC_TIM2EN << RCC_TIM2EN_bit		) | \
								(RCC_TIM3EN << RCC_TIM3EN_bit		) | \
								(RCC_TIM4EN << RCC_TIM4EN_bit		) | \
								(RCC_TIM5EN << RCC_TIM5EN_bit		)	\
																	)


/*			APB2 Peripheral clock enable			*/

// TIM9 clock enable
#define		RCC_TIM9EN			0

// TIM10 clock enable
#define		RCC_TIM10EN			0

// TIM11 clock enable
#define		RCC_TIM11EN			0

// System configuration controller clock enable
#define		RCC_SYSCFGEN		0

// SPI1 clock enable
#define		RCC_SPI1EN			0

// SPI4 clock enable
#define		RCC_SPI4EN			0

// SDIO clock enable
#define		RCC_SDIOEN			0

// ADC1 clock enable
#define		RCC_ADC1EN			0

// USART1 clock enable
#define		RCC_USART1EN		0

// USART6 clock enable
#define		RCC_USART6EN		0

// TIM1 clock enable
#define		RCC_TIM1EN			0

// RCC_APB2LPENR Reg init value
#define		RCC_APB2LPENR_init	(										\
								(RCC_TIM9EN << RCC_TIM9EN_bit		) | \
								(RCC_TIM10EN << RCC_TIM10EN_bit		) | \
								(RCC_TIM11EN << RCC_TIM11EN_bit		) | \
								(RCC_SYSCFGEN << RCC_SYSCFGEN_bit	) | \
								(RCC_SPI1EN << RCC_SPI1EN_bit		) | \
								(RCC_SPI4EN << RCC_SPI4EN_bit		) | \
								(RCC_SDIOEN << RCC_SDIOEN_bit		) | \
								(RCC_ADC1EN << RCC_ADC1EN_bit		) | \
								(RCC_USART1EN << RCC_USART1EN_bit	) | \
								(RCC_USART6EN << RCC_USART6EN_bit	) | \
								(RCC_TIM1EN << RCC_TIM1EN_bit		)	\
																	)

	
#endif /* RCC_CONFIG_H_ */
