/**********************************************************************************/
/***						Date: 20/9/2023	Day: Wednesday						***/
/***    RCC driver for STM32F401 a graduation project for thE NTI 	program	    ***/
/**********************************************************************************/

#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H
/*
	- First You Must Know The Peripheral On Which Bus
*/

#include "../Inc/LIB/STD_TYPES.h"
#include "../Inc/LIB/BIT_MATH.h"

/*
-Function To Set System CLK From preconfigurations Send :
												* ClkSrcName_t 		: RCC_HSE  RCC_HSI	RCC_PLL
												* HSESrcName_t 		: Crystal CLK From (HSE_Crystal , HSE_RC )
												* AHBPreName_t		: AHB  Prescaller ( 1 : 512 )
												* APB1PreName_t   	: APB1 Prescaller ( 1 : 16  )
												* APB2PreName_t   	: APB2_Prescaller ( 1 : 16  )
												*( M N P Q )      	: By #define


*/
void RCC_voidInitSysClock(void );


/*
- Function To Enable Peripheral :
												- BusName_t      	: The Bus Of The Peripheral ( AHB1 , AHB2 , AHB3 , APB1 , APB2 ) Every One Detect Which REG To Choice Pripheral From It
												- Copy_u8PerName 	: The Order Of Peripheral On The Selected Reg
	
*/
void RCC_voidEnableClock (u8 , u8 );


/*
- Function To Disable Peripheral :
												- BusName_t      	: The Bus Of The Peripheral ( AHB1 , AHB2 , AHB3 , APB1 , APB2 ) Every One Detect Which REG To Choice Pripheral From It
												- Copy_u8PerName 	: The Order Of Peripheral On The Selected Reg
*/
void RCC_voidDisableClock (u8 , u8 );


/*
		- Buses, And peripherals
*/

/*
			- RCC AHB1 peripheral clock enable register (RCC_AHB1ENR) bit numbers
*/
/*			AHB1 Bus			*/
#define AHB1_BUS			0

// DMA2 clock enable
#define 		RCC_DMA2EN_bit					22

// DMA1 clock enable
#define			RCC_DMA1EN_bit					21

// CRC clock enable
#define			RCC_CRCEN_bit					12

// IO port H clock enable
#define			RCC_GPIOHEN_bit					7

// IO port E clock enable
#define			RCC_GPIOEEN_bit					4

// IO port D clock enable
#define			RCC_GPIODEN_bit					3

// IO port C clock enable
#define			RCC_GPIOCEN_bit					2

// IO port B clock enable
#define			RCC_GPIOBEN_bit					1

// IO port A clock enable
#define			RCC_GPIOAEN_bit					0


/*
			- RCC AHB2 peripheral clock enable register (RCC_AHB2ENR) bit numbers
*/
/*			AHB2 Bus			*/
#define AHB2_BUS			1

// USB OTG FS clock enable
#define			RCC_OTGFSEN_bit					7

/*
			- RCC APB1 peripheral clock enable register (RCC_APB1ENR) bit numbers
*/
/*			APB1 Bus			*/
#define	APB1_BUS			2

// Power interface clock enable
#define			RCC_PWREN_bit					28

// I2C3 clock enable
#define			RCC_I2C3EN_bit					23

// I2C2 clock enable
#define			RCC_I2C2EN_bit					22

// I2C1 clock enable
#define			RCC_I2C1EN_bit					21

// USART2 clock enable
#define			RCC_USART2EN_bit				17

// SPI3 clock enable
#define			RCC_SPI3EN_bit					15

// SPI2 clock enable
#define			RCC_SPI2EN_bit					14

// Window watch-dog clock enable
#define			RCC_WWDGEN_bit					11

// TIM5 clock enable
#define			RCC_TIM5EN_bit					3

// TIM4 clock enable
#define			RCC_TIM4EN_bit					2

// TIM3 clock enable
#define			RCC_TIM3EN_bit					1

// TIM2 clock enable
#define			RCC_TIM2EN_bit					0

/*
			- RCC APB2 peripheral clock enable register (RCC_APB2ENR) bit numbers
*/
/*			APB2 Bus			*/
#define	APB2_BUS			3
// TIM11 clock enable
#define			RCC_TIM11EN_bit					18

// TIM10 clock enable
#define			RCC_TIM10EN_bit					17

// TIM9 clock enable
#define			RCC_TIM9EN_bit					16

// System configuration controller clock enable
#define			RCC_SYSCFGEN_bit				14

// SPI4 clock enable
#define			RCC_SPI4EN_bit					13

// SPI1 clock enable
#define			RCC_SPI1EN_bit					12

// SDIO clock enable
#define			RCC_SDIOEN_bit					11

// ADC1 clock enable
#define			RCC_ADC1EN_bit					8

// USART6 clock enable
#define			RCC_USART6EN_bit				5

// USART1 clock enable
#define			RCC_USART1EN_bit				4

// TIM1 clock enable
#define			RCC_TIM1EN_bit					0


#endif //RCC_INTERFACE_H
