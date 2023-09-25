

#include "../Inc/RCC/RCC_interface.h"
#include "../Inc/GPIO/GPIO_interface.h"
#include "../Inc/ICU/ICU_interface.h"

int main( void )
{
	RCC_voidInitSysClock();
	GPIO_voidSysInit();
	ICU_u8Init(TIMER2ID);
    /* Loop forever */
	while( 1 )
	{

	}
	return 0;
}
