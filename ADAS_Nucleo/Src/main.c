
#include "../Inc/RCC/RCC_interface.h"
#include "../Inc/GPIO/GPIO_interface.h"
#include "../Inc/PWM/PWM_interface.h"

int main(void) {
	RCC_voidInitSysClock();
	RCC_voidEnableClock(AHB1_BUS, RCC_GPIOBEN_bit);
	RCC_voidEnableClock(APB1_BUS, RCC_TIM3EN_bit);
	RCC_voidEnableClock(APB1_BUS, RCC_TIM4EN_bit);

	GPIO_voidSysInit();
	GPIO_voidSetPinMode(GPIOB_PORT, PIN1, MODE_ALTF);
	GPIO_voidPinSetAltFn(GPIOB_PORT, PIN1, (0b0010u));
	GPIO_voidSetPinMode(GPIOB_PORT, PIN9, MODE_ALTF);
	GPIO_voidPinSetAltFn(GPIOB_PORT, PIN9, (0b0010u));

	PWM_u8Init(TIM3_ID);
	PWM_u8Init(TIM4_ID);

	PWM_u8Start(TIM3_ID, 10);
	PWM_u8Start(TIM4_ID, 50);
	u16 i;
	for(i=0; i<500000; i++);
	PWM_u8Stop(TIM4_ID);

	/* Loop forever */
	while (1) {

	}
	return 0;
}
