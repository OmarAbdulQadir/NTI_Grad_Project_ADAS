/**********************************************************************************/
/***						Date: 24/9/2023	Day: Sunday							***/
/***    				Blind spot detection algorithm for ADAS Project		    ***/
/**********************************************************************************/

/*							Private includes									  */

#include "../Inc/BSD/BSD_private.h"
#include "../Inc/BSD/BSD_interface.h"

/*--------------------------------------------------------------------------------*/
/*						Global variables for Ultrasonic Sensors			     	  */


extern const u8 Global_u8ReRightUS;
extern const u8 Global_u8ReLeftUS;


/*--------------------------------------------------------------------------------*/
/*					Define thresholds for blind spot detection			     	  */

#define BLIND_SPOT_THRESHOLD 50

/*--------------------------------------------------------------------------------*/
/*					Global functions implementation								  */


void BSD_vMain( void )
{
	
	while( 1 )
	{
		 if     ( (Global_u8ReRightUS < BLIND_SPOT_THRESHOLD) &&
                  (Global_u8ReLeftUS  > BLIND_SPOT_THRESHOLD) ) {
             // Turn on right LED
             STD_ReturnType LED_u8Init( LED_Right_CHANNEL );
             STD_ReturnType LED_u8On( LED_Right_CHANNEL );
        }
        else if ( (Global_u8ReRightUS  < BLIND_SPOT_THRESHOLD) &&
                  (Global_u8ReLeftUS   < BLIND_SPOT_THRESHOLD) ) {
             // Turn on two LEDs
             STD_ReturnType LED_u8Init( LED_Right_CHANNEL );
             STD_ReturnType LED_u8Init( LED_Left_CHANNEL );
			 
			 STD_ReturnType LED_u8On( LED_Right_CHANNEL );
             STD_ReturnType LED_u8On( LED_Left_CHANNEL );			 
        }
        else if ( (Global_u8ReRightUS > BLIND_SPOT_THRESHOLD) &&
                  (Global_u8ReLeftUS  < BLIND_SPOT_THRESHOLD) ) {
             // Turn on left LED
             STD_ReturnType LED_u8Init( LED_Left_CHANNEL );
             STD_ReturnType LED_u8On( LED_Left_CHANNEL );			 
        }

        else {
             // Turn off front LEDs
             STD_ReturnType LED_u8Init( LED_Right_CHANNEL );
             STD_ReturnType LED_u8Init( LED_Left_CHANNEL );
			 
			 STD_ReturnType LED_u8Off( LED_Right_CHANNEL );
             STD_ReturnType LED_u8Off( LED_Left_CHANNEL );
        }
		
	}
}

