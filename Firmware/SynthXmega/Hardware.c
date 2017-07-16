/*
 * Hardware.c
 *
 * Created: 20/04/2017 21:20:39
 *  Author: Ryan
 */ 

 #include "Hardware.h"
 #include "drivers/port/port_driver.h"
 #include "avr/io.h"

 

void SetupLeds(void);



 void BoardInit(void)
 {
	SetupLeds();
 }

 void SetupLeds(void)
 {
	/* setup the LEDs
	* set pins as outputs
	*Set them high to turn off
	*/
	PORT_SetPinsAsOutput(&LEDPORT, LED0_bm | LED1_bm);
	PORT_SetPins(&LEDPORT, LED0_bm | LED1_bm);
 }

 
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
