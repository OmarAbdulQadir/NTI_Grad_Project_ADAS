/**********************************************************************************/
/***						Date: 29/9/2023	Day: friday							***/
/***    			Lane departure assist algorithm for ADAS Project		    ***/
/**********************************************************************************/

extern const u8 Global_u16FrRightUS;
extern const u8 Global_u16FrLeftUS;

#define Black 1
#define White 0

void LDA_vMain( void )
{
	while( 1 )
	{
		if( (Global_u16FrRightUS == Black) && (Global_u16FrLeftUS == Black) )
		{
			//action

		}
		else if( (Global_u16FrRightUS == Black) && (Global_u16FrLeftUS == White) )
		{
			//action
			
			
		}
		else if( (Global_u16FrRightUS == White) && (Global_u16FrLeftUS == Black) )
		{
			//action
			
		}
		else
		{
			//action
			
		}
	}
}