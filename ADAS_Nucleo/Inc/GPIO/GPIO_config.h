/**********************************************************************************/
/***						Date: 20/9/2023	Day: Wednesday						***/
/***    GPIO driver for STM32F401 a graduation project for thE NTI 	program	    ***/
/**********************************************************************************/

#ifndef GPIO_CONFIG_H_
#define GPIO_CONFIG_H_

/**********************************************************************************
 *******************		 		Configuration macros			***************
 **********************************************************************************/
#define GPIO_ENABLE					1
#define GPIO_DISABLE				0

/**********************************************************************************
 *******************		 		GPIOA configurations			***************
 **********************************************************************************/
#define	GPIOA_CONFIG_EN				GPIO_DISABLE
<<<<<<< Updated upstream:ADAS_Nucleo/Inc/GPIO/GPIO_config.h
#define	GPIOA_CONFIG_MODER			0x02
=======
#define	GPIOA_CONFIG_MODER			0x2
>>>>>>> Stashed changes:ADAS/Inc/GPIO/GPIO_config.h
#define GPIOA_CONFIG_OTYPER			0x0
#define GPIOA_CONFIG_OSPEEDR		0x0
#define GPIOA_CONFIG_PUPDR			0x0
#define GPIOA_CONFIG_ODR			0x0
#define GPIOA_CONFIG_BSRR			0x0
#define GPIOA_CONFIG_LCKR			0x0
#define GPIOA_CONFIG_AFRL			0x02
#define GPIOA_CONFIG_AFRH			0x00

/**********************************************************************************
 *******************		 		GPIOB configurations			***************
 **********************************************************************************/
<<<<<<< Updated upstream:ADAS_Nucleo/Inc/GPIO/GPIO_config.h
#define	GPIOB_CONFIG_EN				GPIO_DISABLE
#define	GPIOB_CONFIG_MODER			0x02
=======
#define	GPIOB_CONFIG_EN				GPIO_Enable
#define	GPIOB_CONFIG_MODER			0x0
>>>>>>> Stashed changes:ADAS/Inc/GPIO/GPIO_config.h
#define GPIOB_CONFIG_OTYPER			0x0
#define GPIOB_CONFIG_OSPEEDR		0x0
#define GPIOB_CONFIG_PUPDR			0x0
#define GPIOB_CONFIG_IDR			0x0
#define GPIOB_CONFIG_ODR			0x0
#define GPIOB_CONFIG_BSRR			0x0
#define GPIOB_CONFIG_LCKR			0x0
#define GPIOB_CONFIG_AFRL			0x02
#define GPIOB_CONFIG_AFRH			0x0

/**********************************************************************************
 *******************		 		GPIOC configurations			***************
 **********************************************************************************/
#define	GPIOC_CONFIG_EN				GPIO_DISABLE
#define	GPIOC_CONFIG_MODER			0x0
#define GPIOC_CONFIG_OTYPER			0x0
#define GPIOC_CONFIG_OSPEEDR		0x0
#define GPIOC_CONFIG_PUPDR			0x0
#define GPIOC_CONFIG_IDR			0x0
#define GPIOC_CONFIG_ODR			0x0
#define GPIOC_CONFIG_BSRR			0x0
#define GPIOC_CONFIG_LCKR			0x0
#define GPIOC_CONFIG_AFRL			0x0
#define GPIOC_CONFIG_AFRH			0x0

/**********************************************************************************
 *******************		 		GPIOD configurations			***************
 **********************************************************************************/
#define	GPIOD_CONFIG_EN				GPIO_DISABLE
#define	GPIOD_CONFIG_MODER			0x0
#define GPIOD_CONFIG_OTYPER			0x0
#define GPIOD_CONFIG_OSPEEDR		0x0
#define GPIOD_CONFIG_PUPDR			0x0
#define GPIOD_CONFIG_IDR			0x0
#define GPIOD_CONFIG_ODR			0x0
#define GPIOD_CONFIG_BSRR			0x0
#define GPIOD_CONFIG_LCKR			0x0
#define GPIOD_CONFIG_AFRL			0x0
#define GPIOD_CONFIG_AFRH			0x0


/**********************************************************************************
 *******************		 		GPIOE configurations			***************
 **********************************************************************************/
#define	GPIOE_CONFIG_EN				GPIO_DISABLE
#define	GPIOE_CONFIG_MODER			0x0
#define GPIOE_CONFIG_OTYPER			0x0
#define GPIOE_CONFIG_OSPEEDR		0x0
#define GPIOE_CONFIG_PUPDR			0x0
#define GPIOE_CONFIG_IDR			0x0
#define GPIOE_CONFIG_ODR			0x0
#define GPIOE_CONFIG_BSRR			0x0
#define GPIOE_CONFIG_LCKR			0x0
#define GPIOD_CONFIG_AFRL			0x0
#define GPIOD_CONFIG_AFRH			0x0

/**********************************************************************************
 *******************		 		GPIOH configurations			***************
 **********************************************************************************/
#define	GPIOH_CONFIG_EN				GPIO_DISABLE
#define	GPIOH_CONFIG_MODER			0x0
#define GPIOH_CONFIG_OTYPER			0x0
#define GPIOH_CONFIG_OSPEEDR		0x0
#define GPIOH_CONFIG_PUPDR			0x0
#define GPIOH_CONFIG_IDR			0x0
#define GPIOH_CONFIG_ODR			0x0
#define GPIOH_CONFIG_BSRR			0x0
#define GPIOH_CONFIG_LCKR			0x0
#define GPIOH_CONFIG_AFRL			0x0
#define GPIOH_CONFIG_AFRH			0x0



#endif /* GPIO_CONFIG_H_ */


