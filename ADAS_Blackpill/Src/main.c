

#include "../Inc/RCC/RCC_interface.h"
#include "../Inc/GPIO/GPIO_interface.h"
#include "../Inc/NVIC/NVIC_interface.h"
#include "../Inc/UART/UART_interface.h"

void Callback_test( void );

/*  Temporary Global Variables  */
u16 Global_u16ReRightUS = 0;
u16 Global_u16ReLeftUS  = 0;
u16 Global_u16FrRightUS = 0;
u16 Global_u16FrLeftUS  = 0;
u8* Recived_UART_ptr;

int main( void )
{
	u8 Recived_UART[2] = { 0 };
	Recived_UART_ptr = &Recived_UART;
	RCC_voidInitSysClock();
	GPIO_voidSetPinMode(GPIOA_PORT, PIN9, MODE_ALTF);
	GPIO_voidPinSetAltFn(GPIOA_PORT, PIN9, 0x07);
	GPIO_voidSetPinMode(GPIOA_PORT, PIN10, MODE_ALTF);
	GPIO_voidPinSetAltFn(GPIOA_PORT, PIN10, 0x07);
	NVIC_u8EnableIRQ(NVIC_IRQ_ID_USART1);
	UART_u8Init(UART1ID);
	UART_u8SetCallback(UART1ID, Callback_test);


	/* Loop forever */
	while( 1 )
	{
		UART_u8SendByte(UART1ID, 0x42);
		UART_u8SendByte(UART1ID, 0x43);
	}
	return 0;
}

void Callback_test( void )
{
	static u8 index = 0;
	if(index == 2)
		index = 0;
	UART_u8ReceiveByte(UART1ID, Recived_UART_ptr+index);
	index++;
}
