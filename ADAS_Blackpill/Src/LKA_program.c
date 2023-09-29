/**********************************************************************************/
/***						Date: 29/9/2023	Day: friday							***/
/***    			Lane keep assist algorithm for ADAS Project		            ***/
/**********************************************************************************/
#define Black 1#define White 0
void LDA_vMain( void )
{	while( 1 )
	{		
        if( (Global_u16FrRightUS == Black) && (Global_u16FrLeftUS == Black) )
		{			//action
			MDC_u8Init();		
		}
		else if( (Global_u16FrRightUS == Black) && (Global_u16FrLeftUS == White) )		
		{
			//action			
			MDC_u8Init();
			MDC_u8StartCW();			
		}		
		else if( (Global_u16FrRightUS == White) && (Global_u16FrLeftUS == Black) )
		{			//action
			MDC_u8Init();			
			MDC_u8startCCW();
		}		
		else
		{
			//action			
			MDC_u8Init();
			MDC_u8Stop();		
		}
	}
}