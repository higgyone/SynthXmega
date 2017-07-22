 /*! \file 
 *		 Hardware.c
 *
 * \brief
 *      Code for setting up the hardware elements of the board
 *
 * \author
 *      Ryan
 * \date 
		20/04/2017 21:20:39
 *****************************************************************************/ 

 #include "Hardware.h"
 #include "drivers/port/port_driver.h"
 #include "avr/io.h"

void SetupLeds(void);


 /*! \brief This function runs the initialization routine for the board.
 *
 * \param None
 *
 * \return None
 */
 void BoardInit(void)
 {
	SetupLeds();
 }

  /*! \brief This function sets up the LED pins on the board.
 *
 * \param None
 *
 * \return None
 */
 void SetupLeds(void)
 {
	/* setup the LEDs
	* set pins as outputs
	*Set them high to turn off
	*/
	PORT_SetPinsAsOutput(&LEDPORT, LED0_bm | LED1_bm);
	PORT_SetPins(&LEDPORT, LED0_bm | LED1_bm);
 }

  /*! \brief This function turns the specified LED on or off.
 *
 * \param led   LED to turn on or off
 * \param state State to set LED
 */
 void LedOnOff(Led_t led, LedState_t state)
 {
	if (led == LED0)
	{
		if (state == LedOn)
		{
			PORT_ClearPins(&LEDPORT, LED0_bm);
		}
		else
		{
			PORT_SetPins(&LEDPORT, LED0_bm);
		}	
	}
	else
	{
		if (state == LedOn)
		{
			PORT_ClearPins(&LEDPORT, LED1_bm);
		}
		else
		{
			PORT_SetPins(&LEDPORT, LED1_bm);
		}
	}
 }
