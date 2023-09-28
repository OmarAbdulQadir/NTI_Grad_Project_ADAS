/**********************************************************************************/
/***						Date: 20/9/2023	Day: Wednesday						***/
/***    RCC driver for STM32F401 a graduation project for thE NTI 	program	    ***/
/**********************************************************************************/


/************** INCLUDE MCAL**************/
		#include "../Inc/RCC/RCC_private.h"
		#include "../Inc/RCC/RCC_interface.h"
		#include "../Inc/RCC/RCC_config.h"
/*****************************************/

/************** INCLUDE HALL**************/
			

/*****************************************/

/************** INCLUDEAPP***************/


/*****************************************/





/************************************ Start_FUNCTION  ************************************/
/*
-Function To Set System CLK From preconfigurations Send :
												* ClkSrcName_t 		: RCC_HSE  RCC_HSI	RCC_PLL
												* HSESrcName_t 		: Crystal CLK From (HSE_Crystal , HSE_RC )
												* AHBPreName_t		: AHB  Prescaller ( 1 : 512 )
												* APB1PreName_t   	: APB1 Prescaller ( 1 : 16  )
												* APB2PreName_t   	: APB2_Prescaller ( 1 : 16  )
												*( M N P Q )      	: By #define


*/
void RCC_voidInitSysClock(void )
{

	// Configuring the clock source

#if		RCC_Clk_SRC == RCC_HSI
	// Set the HSI on bit to enable
	set_bit(RCC_CR, RCC_HSION_bit);
	// Wait till HSI is locked
	//while(get_bit(RCC_CR, RCC_HSIRDY_bit));

#elif	RCC_Clk_SRC == RCC_HSE
	// Set the HSE on bit enable
	set_bit(RCC_CR, RCC_HSEON_bit);
	// Wait till HSE is locked
	while(get_bit(RCC_CR, RCC_HSERDY_bit));

	#if		RCC_HSE_BYP == 1
		// Set bypass bit enable
		set_bit(RCC_CR, RCC_HSEBYP_bit);

	#endif
	
	#if		RCC_CSSON == 1
		// Set bypass bit enable
		set_bit(RCC_CR, RCC_HSEBYP_bit);

	#endif

#endif

	// Mask the clock configuration register
	RCC_PLLCFGR &= RCC_CFGR_mask;

#if		RCC_PLL_Enable == 1
	// Set PLL on bit enable
	set_bit(RCC_CR, RCC_PLLON_bit);
	// Mask PLL configuration register
	RCC_PLLCFGR &= RCC_PLLCFGR_mask;
	#if		RCC_PLLSRC == RCC_HSE
		// Select HSE as the PLL Source
		set_bit(RCC_PLLCFGR, RCC_PLLSRC_bit);
	#elif	RCC_PLLSRC == RCC_HSI
		// Select HSI as the PLL Source
		clr_bit(RCC_PLLCFGR, RCC_PLLSRC_bit);
	#endif
	// Set the PLL M value
	RCC_PLLCFGR |= RCC_PLL_M;
	// Set the PLL N value
	RCC_PLLCFGR |= (RCC_PLL_N << RCC_PLLN_bit);
	// Set the PLL P value
	RCC_PLLCFGR |= (RCC_PLL_P << RCC_PLLP_bit);
	// Select the PLL clk source
	RCC_PLLCFGR |= RCC_PLL_Clk_Src;
	// Wait till PLL is locked
	//while(get_bit(RCC_CR, RCC_PLLRDY_bit));

#else
	#if		RCC_Clk_SRC == RCC_HSI
		// Select the HSI clk source
		RCC_PLLCFGR |= RCC_HSI_Clk_Src;

	#elif	RCC_Clk_SRC == RCC_HSE
		// Select the HSE clk source
		RCC_PLLCFGR |= RCC_HSE_Clk_Src;

	#endif
#endif

	// Setting the AHP pre-scaler
	RCC_CFGR |= (RCC_HPRE << RCC_PRE_bit);
	// Setting the APB1 pre-scaler
	RCC_CFGR |= (RCC_PPRE1 << RCC_PPRE1_bit);
	// Setting the APB2 pre-scaler
	RCC_CFGR |= (RCC_PPRE2 << RCC_PPRE2_bit);

	// Enable and disable peripherals of Bus AHB1
	RCC_AHB1ENR |= RCC_AHB1LPENR_init;
	// Enable and disable peripherals of Bus AHB1
	RCC_AHB2ENR |= RCC_AHB2LPENR_init;
	// Enable and disable peripherals of Bus ABP1
	RCC_APB1ENR |= RCC_APB1LPENR_init;
	// Enable and disable peripherals of Bus ABP2
	RCC_APB2ENR |= RCC_APB2LPENR_init;
}
/*********************************************************** END_ FUNCTION   ***********************************************************/



\
/************************************ Start_FUNCTION  ************************************/
/*
- Function To Enable Peripheral :
												- BusName_t      	: The Bus Of The Peripheral ( AHB1 , AHB2 , AHB3 , APB1 , APB2 ) Every One Detect Which REG To Choice Pripheral From It
												- Copy_u8PerName 	: The Order Of Peripheral On The Selected Reg

*/
void RCC_voidEnableClock (u8 BusName, u8 Copy_u8PerName)
{
	 switch(BusName)
	 {
		case AHB1_BUS:
			set_bit(RCC_AHB1ENR, Copy_u8PerName);
		break;
		case AHB2_BUS:
			set_bit(RCC_AHB2ENR, Copy_u8PerName);
		break;
		case APB1_BUS:
			set_bit(RCC_APB1LPENR, Copy_u8PerName);
		break;
		case APB2_BUS:
			set_bit(RCC_APB2LPENR, Copy_u8PerName);
		break;
		default:

		break;
	 }
 }
/*********************************************************** END_ FUNCTION   ***********************************************************/


/************************************ Start_FUNCTION  ************************************/
/*
- Function To Disable Peripheral :
												- BusName_t      	: The Bus Of The Peripheral ( AHB1 , AHB2 , AHB3 , APB1 , APB2 ) Every One Detect Which REG To Choice Pripheral From It
												- Copy_u8PerName 	: The Order Of Peripheral On The Selected Reg
*/
void RCC_voidDisableClock (u8 BusName, u8 Copy_u8PerName)
{
	 switch(BusName)
	 {
		case AHB1_BUS:
			clr_bit(RCC_AHB1ENR, Copy_u8PerName);
		break;
		case AHB2_BUS:
			clr_bit(RCC_AHB2ENR, Copy_u8PerName);
		break;
		case APB1_BUS:
			clr_bit(RCC_APB1LPENR, Copy_u8PerName);
		break;
		case APB2_BUS:
			clr_bit(RCC_APB2LPENR, Copy_u8PerName);
		break;
		default:

		break;
	 }
}
/*********************************************************** END_ FUNCTION   ***********************************************************/
