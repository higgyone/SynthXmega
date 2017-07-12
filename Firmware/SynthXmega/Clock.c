/*
 * Clock.c
 *
 * Created: 03/06/2017 16:47:10
 *  Author: Ryan
 */ 

 #include <avr/io.h>

 #include "Clock.h"

 /*
 * Set the clock source to 32MHz ring oscillator with no pre-scaler
 */
 uint8_t Setup32MHzClock(void)
 {
	 /* enable the 32MHz ring oscillator*/
	 OSC.CTRL |= OSC_RC32MEN_bm;

	 /* Wait for clock to become stable */
	 do
	 {
		 
	 } while (( OSC_RC32MRDY_bm ) == 0);

	 /* Get the bits ready for 32MHz clock */
	 uint8_t clkCtrl = ( CLK.CTRL & ~CLK_SCLKSEL_gm ) | CLK_SCLKSEL_RC32M_gc;

	 /* unlock configuration change register to set clock */
	 CCP = 0xD8;

	 /* Set main clock source to 32MHz clock */
	 CLK.CTRL = clkCtrl;

	 /* check the result */
	 clkCtrl = CLK.CTRL & CLK_SCLKSEL_RC32M_gc;

	 return clkCtrl;
 }
