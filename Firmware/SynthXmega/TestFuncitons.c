/*
 * TestFuncitons.c
 *
 * Created: 16/07/2017 21:10:23
 *  Author: Ryan
 */ 

 #include <util/delay.h>

 #include "Hardware.h"

 /* test the flashing of the LEDS */
 void TestLedsFlash(void)
 {
	 LedOnOff(LED0, LedOff);
	 LedOnOff(LED1, LedOn);

	 _delay_ms(1000);

	 LedOnOff(LED0, LedOn);
	 LedOnOff(LED1, LedOff);

	 _delay_ms(1000);
 }
