

#include "../Inc/RCC/RCC_interface.h"
#include "../Inc/MDC/MDC_interface.h"

/*  Temporary Global Variables  */
u8 Global_u8ReRightUS = 0;
u8 Global_u8ReLeftUS  = 0;

int main( void )
{
	RCC_voidInitSysClock();
	MDC_u8Init(3);
	MDC_u8Init(MDC_STEERING_CHANNEL);
	MDC_u8StartCW(MDC_MOTION_CHANNEL, 50);
	MDC_u8StartCCW(MDC_STEERING_CHANNEL, 50);
	MDC_u8Init(MDC_STEERING_CHANNEL);
	MDC_u8Stop(MDC_STEERING_CHANNEL);

	/* Loop forever */
	while( 1 )
	{

	}
	return 0;
}
