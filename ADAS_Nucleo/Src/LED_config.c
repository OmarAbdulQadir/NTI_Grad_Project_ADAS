/*
 * LED_config.c
 *
 *  Created on: Oct 1, 2023
 *
 */

/*							Private includes									  */
#include "../Inc/LED/LED_config.h"

// Configuration for LEDs
LED_Channel_ID LED_Channels[LED_NO_CHANNELS] =
{ { LedRight_PORTID,
	LedRight_PINID  },
  { LedLeft_PORTID,
    LedLeft_PINID   }
};


