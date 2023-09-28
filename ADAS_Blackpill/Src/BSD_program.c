/**********************************************************************************/
/***						Date: 24/9/2023	Day: Sunday							***/
/***    				Blind spot detection algorithm for ADAS Project		    ***/
/**********************************************************************************/

/*							Private includes									  */

#include "../Inc/BDS/BSD_private.h
#include "../Inc/BSD/BSD_interface.h"

/*--------------------------------------------------------------------------------*/
/*						Global variables for Ultrasonic Sensors			     	  */


extern const u8 Global_u8ReRightUS = 0;
extern const u8 Global_u8ReLeftUS  = 0;


/*--------------------------------------------------------------------------------*/
/*					Define thresholds for blind spot detection			     	  */

#define BLIND_SPOT_THRESHOLD 50

/*--------------------------------------------------------------------------------*/
/*					Global functions implementation								  */


STD_ReturnType BSD_u8Init( void )
{
	
}

void BSD_vMain( void )
{
	
	while( 1 )
	{
		 if     ( (Global_u8ReRightUS < BLIND_SPOT_THRESHOLD) &&
                  (Global_u8ReLeftUS  > BLIND_SPOT_THRESHOLD) ) {
             // Turn on right LED
        }
        else if ( (Global_u8ReRightUS  < BLIND_SPOT_THRESHOLD) &&
                  (Global_u8ReLeftUS   < BLIND_SPOT_THRESHOLD) ) {
             // Turn on two LEDs
        }
        else if ( (Global_u8ReRightUS > BLIND_SPOT_THRESHOLD) &&
                  (Global_u8ReLeftUS  < BLIND_SPOT_THRESHOLD) ) {
             // Turn on left LED
        }

        else {
             // Turn off front LEDs
        }
		
	}
}