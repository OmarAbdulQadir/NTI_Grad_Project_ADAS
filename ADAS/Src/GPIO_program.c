/**********************************************************************************/
/***						Date: 20/9/2023	Day: Wednesday						***/
/***    GPIO driver for STM32F401 a graduation project for thE NTI 	program	    ***/
/**********************************************************************************/



/**********************************************************************************
 *******************	 	   Standard libraries section			***************
 **********************************************************************************/ 
#include "../Inc/STD_TYPES.h"
#include "../Inc/BIT_MATH.h"

/**********************************************************************************
 *******************		 	MCAL libraries section				***************
 **********************************************************************************/
#include "../Inc/RCC_interface.h"

/**********************************************************************************
 *******************		 	Private headers section				***************
 **********************************************************************************/
#include "../Inc/GPIO_config.h"
#include "../Inc/GPIO_private.h"
#include "../Inc/GPIO_interface.h"


/**********************************************************************************
 *******************	 		Global variables section			***************
 **********************************************************************************/ 
volatile GPIO_t* GPIO_bases[GPIO_bases_max] = {GPIOA_BASE_ADDRESS,
									  	  	   GPIOB_BASE_ADDRESS,
											   GPIOC_BASE_ADDRESS,
											   GPIOD_BASE_ADDRESS,
											   GPIOE_BASE_ADDRESS,
											   GPIOH_BASE_ADDRESS};


/**********************************************************************************
 *******************		 		GPIO_voidSysInit				***************
 **********************************************************************************/
/*		Function configure the GPIO peripherals initially		*/
void GPIO_voidSysInit(void ){

	#if		GPIOA_CONFIG_EN == GPIO_ENABLE

		RCC_voidEnableClock(AHB1_BUS, RCC_GPIOAEN_bit);
		GPIO_bases[GPIOA_PORT] -> MODER = GPIOA_CONFIG_MODER;
		GPIO_bases[GPIOA_PORT] -> OTYPER = GPIOA_CONFIG_OTYPER;
		GPIO_bases[GPIOA_PORT] -> OSPEEDR = GPIOA_CONFIG_OSPEEDR;
		GPIO_bases[GPIOA_PORT] -> PUPDR = GPIOA_CONFIG_PUPDR;
		GPIO_bases[GPIOA_PORT] -> ODR = GPIOA_CONFIG_ODR;
		GPIO_bases[GPIOA_PORT] -> BSRR = GPIOA_CONFIG_BSRR;
		GPIO_bases[GPIOA_PORT] -> LCKR = GPIOA_CONFIG_LCKR;
		GPIO_bases[GPIOA_PORT] -> AFR = GPIOA_CONFIG_AFR;

	#endif

	#if		GPIOB_CONFIG_EN == GPIO_ENABLE

		RCC_voidEnableClock(AHB1_BUS, RCC_GPIOBEN_bit);
		GPIO_bases[GPIOB_PORT] -> MODER = GPIOB_CONFIG_MODER;
		GPIO_bases[GPIOB_PORT] -> OTYPER = GPIOB_CONFIG_OTYPER;
		GPIO_bases[GPIOB_PORT] -> OSPEEDR = GPIOB_CONFIG_OSPEEDR;
		GPIO_bases[GPIOB_PORT] -> PUPDR = GPIOB_CONFIG_PUPDR;
		GPIO_bases[GPIOB_PORT] -> ODR = GPIOB_CONFIG_ODR;
		GPIO_bases[GPIOB_PORT] -> BSRR = GPIOB_CONFIG_BSRR;
		GPIO_bases[GPIOB_PORT] -> LCKR = GPIOB_CONFIG_LCKR;
		GPIO_bases[GPIOB_PORT] -> AFR = GPIOB_CONFIG_AFR;

	#endif

	#if		GPIOC_CONFIG_EN == GPIO_ENABLE

		RCC_voidEnableClock(AHB1_BUS, RCC_GPIOCEN_bit);
		GPIO_bases[GPIOC_PORT] -> MODER = GPIOC_CONFIG_MODER;
		GPIO_bases[GPIOC_PORT] -> OTYPER = GPIOC_CONFIG_OTYPER;
		GPIO_bases[GPIOC_PORT] -> OSPEEDR = GPIOC_CONFIG_OSPEEDR;
		GPIO_bases[GPIOC_PORT] -> PUPDR = GPIOC_CONFIG_PUPDR;
		GPIO_bases[GPIOC_PORT] -> ODR = GPIOC_CONFIG_ODR;
		GPIO_bases[GPIOC_PORT] -> BSRR = GPIOC_CONFIG_BSRR;
		GPIO_bases[GPIOC_PORT] -> LCKR = GPIOC_CONFIG_LCKR;
		GPIO_bases[GPIOC_PORT] -> AFR = GPIOC_CONFIG_AFR;

	#endif

	#if		GPIOD_CONFIG_EN == GPIO_ENABLE

		RCC_voidEnableClock(AHB1_BUS, RCC_GPIODEN_bit);
		GPIO_bases[GPIOD_PORT] -> MODER = GPIOD_CONFIG_MODER;
		GPIO_bases[GPIOD_PORT] -> OTYPER = GPIOD_CONFIG_OTYPER;
		GPIO_bases[GPIOD_PORT] -> OSPEEDR = GPIOD_CONFIG_OSPEEDR;
		GPIO_bases[GPIOD_PORT] -> PUPDR = GPIOD_CONFIG_PUPDR;
		GPIO_bases[GPIOD_PORT] -> ODR = GPIOD_CONFIG_ODR;
		GPIO_bases[GPIOD_PORT] -> BSRR = GPIOD_CONFIG_BSRR;
		GPIO_bases[GPIOD_PORT] -> LCKR = GPIOD_CONFIG_LCKR;
		GPIO_bases[GPIOD_PORT] -> AFR = GPIOD_CONFIG_AFR;

	#endif

	#if		GPIOE_CONFIG_EN == GPIO_ENABLE

		RCC_voidEnableClock(AHB1_BUS, RCC_GPIOEEN_bit);
		GPIO_bases[GPIOE_PORT] -> MODER = GPIOE_CONFIG_MODER;
		GPIO_bases[GPIOE_PORT] -> OTYPER = GPIOE_CONFIG_OTYPER;
		GPIO_bases[GPIOE_PORT] -> OSPEEDR = GPIOE_CONFIG_OSPEEDR;
		GPIO_bases[GPIOE_PORT] -> PUPDR = GPIOE_CONFIG_PUPDR;
		GPIO_bases[GPIOE_PORT] -> ODR = GPIOE_CONFIG_ODR;
		GPIO_bases[GPIOE_PORT] -> BSRR = GPIOE_CONFIG_BSRR;
		GPIO_bases[GPIOE_PORT] -> LCKR = GPIOE_CONFIG_LCKR;
		GPIO_bases[GPIOE_PORT] -> AFR = GPIOE_CONFIG_AFR;

	#endif

	#if		GPIOH_CONFIG_EN == GPIO_ENABLE

		RCC_voidEnableClock(AHB1_BUS, RCC_GPIOHEN_bit);
		GPIO_bases[GPIOH_PORT] -> MODER = GPIOH_CONFIG_MODER;
		GPIO_bases[GPIOH_PORT] -> OTYPER = GPIOH_CONFIG_OTYPER;
		GPIO_bases[GPIOH_PORT] -> OSPEEDR = GPIOH_CONFIG_OSPEEDR;
		GPIO_bases[GPIOH_PORT] -> PUPDR = GPIOH_CONFIG_PUPDR;
		GPIO_bases[GPIOH_PORT] -> ODR = GPIOH_CONFIG_ODR;
		GPIO_bases[GPIOH_PORT] -> BSRR = GPIOH_CONFIG_BSRR;
		GPIO_bases[GPIOH_PORT] -> LCKR = GPIOH_CONFIG_LCKR;
		GPIO_bases[GPIOH_PORT] -> AFR = GPIOH_CONFIG_AFR;

	#endif

}


/**********************************************************************************
 *******************		 		GPIO_voidSetPinMode				***************
 **********************************************************************************/
/*		Function Set The Mode Of Pin Mode Take 2Bits	

									MODE_INPUT
									MODE_OUTPUT
									MODE_ALTF
									MODE_ANALOG	

*/
void GPIO_voidSetPinMode(u8 copy_u8PORT, u8 copy_u8PIN, u8 copy_u8MODE)
 {
	 if((copy_u8PORT <= GPIOH_PORT) && (copy_u8PIN <= PIN15) && (copy_u8MODE <= MODE_ANALOG)){

		 GPIO_bases[copy_u8PORT] -> MODER &= GPIO_MODER_MASK( copy_u8PIN * 2 );
		 GPIO_bases[copy_u8PORT] -> MODER |= ( ( ( u32 ) copy_u8MODE ) << copy_u8PIN * 2 );

	 }
	 else{

	 }
 }
 
 
/**********************************************************************************
 *******************		 	GPIO_voidSetOutType					***************
 **********************************************************************************/ 
/*				Function Set The Type Of OutPut (OpenDrain = 0 , PushPull = 1)

								OUTPUT_TYPE_PUSH_PULL
								OUTPUT_TYPE_OPEN_DRAIN	

*/
void GPIO_voidSetOutType(u8 copy_u8PORT ,u8 copy_u8PIN,u8 copy_u8Type) 
{
	 if((copy_u8PORT <= GPIOH_PORT) && (copy_u8PIN <= PIN15)){

		 ( copy_u8Type == LOW ) ? clr_bit( ( GPIO_bases[copy_u8PORT] -> OTYPER ), copy_u8PIN ) : set_bit( ( GPIO_bases[copy_u8PORT] -> OTYPER ), copy_u8PIN);

	 }
	 else{
	 }
}


/**********************************************************************************
 *******************		 	GPIO_voidSetOutSpee					***************
 **********************************************************************************/ 
/*						Function Set The Speed (LOW , Meduim , High ,VeryHaigh		
							
							OUTPUT_LOW_SPEED
							OUTPUT_MEDUIM_SPEED
							OUTPUT_HIGH_SPEED
							OUTPUT_VERY_HIGH_SPEED
							
							

*/
void GPIO_voidSetOutSpeed(u8 copy_u8PORT ,u8 copy_u8PIN,u8 copy_u8Speed)
{
	 if((copy_u8PORT <= GPIOH_PORT) && (copy_u8PIN <= PIN15) && (copy_u8Speed <= OUTPUT_VERY_HIGH_SPEED)){

		 GPIO_bases[copy_u8PORT] -> OSPEEDR &= GPIO_OSPEEDR_MASK( copy_u8PIN * 2 );
		 GPIO_bases[copy_u8PORT] -> OSPEEDR |= ( ( u32 ) copy_u8Speed << ( copy_u8PIN * 2 ) );

	 }
	 else{

	 }
}


/**********************************************************************************
 *******************		 	GPIO_voidSetPull					***************
 **********************************************************************************/ 
/*		Function Set The PULL :
								
					PULL_OFF
					PULL_UP
					PULL_DOWN
	
	
*/
void GPIO_voidSetPull(u8 copy_u8PORT ,u8 copy_u8PIN,u8 copy_u8PULL_TYPE)
{
	 if((copy_u8PORT <= GPIOH_PORT) && (copy_u8PIN <= PIN15) && (copy_u8PULL_TYPE <= PULL_DOWN)){

		 GPIO_bases[copy_u8PORT] -> PUPDR &= GPIO_PUPDR_MASK( copy_u8PIN * 2);
		 GPIO_bases[copy_u8PORT] -> PUPDR |= ( ( u32 ) copy_u8PULL_TYPE << ( copy_u8PIN * 2) );

	 }
	 else{

	 }
}


/**********************************************************************************
 *******************		 	GPIO_u8ReadData						***************
 **********************************************************************************/ 
/*		Function To Read Data From IDR		*/
u8 GPIO_u8ReadData(u8 copy_u8PORT ,u8 copy_u8PIN)
{
	u8 u8Local_Data = 0 ;
	 if((copy_u8PORT <= GPIOH_PORT) && (copy_u8PIN <= PIN15)){

		 get_bit( ( GPIO_bases[copy_u8PORT] -> IDR ), copy_u8PIN );

	 }
	 else{
	 }
	 return u8Local_Data ;
}


/**********************************************************************************
 *******************		 	GPIO_voidWriteData					***************
 **********************************************************************************/ 
/*
			* Function To Write Data At ODR	Value :
									 high 
									 low	
*/
void GPIO_voidWriteData(u8 copy_u8PORT ,u8 copy_u8PIN , u8 copy_u8Value )
 {
	 if((copy_u8PORT <= GPIOH_PORT) && (copy_u8PIN <= PIN15)){
		GPIO_bases[copy_u8PORT] -> ODR &= GPIO_ODR_MASK( copy_u8PIN );
		GPIO_bases[copy_u8PORT] -> ODR |= ( ( ( u32 ) copy_u8Value ) << copy_u8PIN );
	 }
	 else{
	 }
}


/**********************************************************************************
 *******************		 	GPIO_voidPinSetAltFn				***************
 **********************************************************************************/  
/*
			Function Set The AltFn		: Every Pin Need 4 Bits SO We Have High AND Low
*/
void GPIO_voidPinSetAltFn(u8 copy_u8PORT, u8 copy_u8PIN, u8 copy_u8AlT)

{
	if((copy_u8PORT <= GPIOH_PORT) && (copy_u8PIN <= PIN15) && (copy_u8AlT <= GPIO_AFR_MAX)){
		GPIO_bases[copy_u8PORT] -> AFR &= GPIO_AFR_MASK( copy_u8PIN * 4 );
		GPIO_bases[copy_u8PORT] -> AFR |= ( ( ( u64 ) copy_u8AlT ) << copy_u8PIN * 4 );
	}
}


