 /*! \file 
 *		 TestFuncitons.c
 *
 * \brief
 *      Contains test functions for the code.
 *
 * \author
 *      Ryan
 * \date 
		16/07/2017 21:10:23
 *****************************************************************************/

 #include <util/delay.h>

 #include "Hardware.h"

 /*! \brief This function tests the flashing of the LEDS.
 *
 * \param None
 *
 * \return None
 */
 void TestLedsFlash(void)
 {
	 LedOnOff(LED0, LedOff);
	 LedOnOff(LED1, LedOn);

	 _delay_ms(1000);

	 LedOnOff(LED0, LedOn);
	 LedOnOff(LED1, LedOff);

	 _delay_ms(1000);
 }
