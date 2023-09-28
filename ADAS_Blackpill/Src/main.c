

#include "../Inc/RCC/RCC_interface.h"
#include "../Inc/GPIO/GPIO_interface.h"
#include "../Inc/NVIC/NVIC_interface.h"

/*  Temporary Global Variables  */
u8 Global_u8ReRightUS = 0;
u8 Global_u8ReLeftUS  = 0;

int main( void )
{

	RCC_voidInitSysClock();
	GPIO_voidSysInit();
	NVIC_u8EnableIRQ(NVIC_IRQ_ID_USART1);
	NVIC_u8SetPriority(NVIC_IRQ_ID_USART1, NVIC_PRIORITY_4);
	u8 P= 0;
	NVIC_u8GetPriority(NVIC_IRQ_ID_USART1, &P);
	//NVIC_u8SetPendingIRQ(NVIC_IRQ_ID_USART1);
	NVIC_u8DisableIRQ(NVIC_IRQ_ID_USART1);


	/* Loop forever */
	while( 1 )
	{
	}
	return 0;
}
