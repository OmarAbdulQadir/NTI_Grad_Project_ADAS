

#include "../Inc/RCC/RCC_interface.h"
#include "../Inc/GPIO/GPIO_interface.h"
#include "../Inc/ICU/ICU_interface.h"

int main( void )
{

	RCC_voidInitSysClock();
	GPIO_voidSysInit();
	GPIO_voidSetPinMode(GPIOA_PORT, PIN0, MODE_ALTF);
	GPIO_voidPinSetAltFn(GPIOA_PORT, PIN0, (0b0010u));
	GPIO_voidSetPinMode(GPIOA_PORT, PIN1, MODE_ALTF);
	GPIO_voidPinSetAltFn(GPIOA_PORT, PIN1, (0b0010u));
	GPIO_voidSetPinMode(GPIOA_PORT, PIN2, MODE_ALTF);
	GPIO_voidPinSetAltFn(GPIOA_PORT, PIN2, (0b0010u));
	ICU_u8Init(TIMER5ID);
    ICU_u8StartTim(TIMER5ID);
    ICU_u8StartCh(TIMER5ID, CH1ID);
    ICU_u8StartCh(TIMER5ID, CH2ID);
    ICU_u8StartCh(TIMER5ID, CH3ID);


	/* Loop forever */
	while( 1 )
	{
	}
	return 0;
}
