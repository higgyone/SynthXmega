/*
 * PWM.c
 *
 * Created: 13/08/2017 14:49:02
 *  Author: Ryan
 */ 

 #include "PWM.h"
#include "avr/io.h"
#include "avr/interrupt.h"

 void SetupPWM(void)
 {
	/* set port C pin 0 to output */
	PORTC.DIRSET = PIN0_bm;

	/* set for 5ms using 32MHz clock and 1024 divider
	* 32000000/1024 = 31250 counts per second
	* 1 count every 32us 
	* PERBUF is 16bit 65536 max*/
	//TCC4.PERBUF = 0xC35;

	/* set clock prescaler to /1024 */
	TCC4.CTRLA = (TCC4.CTRLA & ~TC4_CLKSEL_gm) | TC_CLKSEL_DIV256_gc;

	/* set the lo level interrupt on for CCA */
	TCC4.INTCTRLB = (TCC4.INTCTRLB & ~TC_CCAINTLVL_LO_gc) | TC_CCAINTLVL_LO_gc;

	/* start timer */
	TCC4.CTRLGCLR = TC4_STOP_bm;

	/* set single slope operation */
	TCC4.CTRLB = ( TCC4.CTRLB & ~TC4_WGMODE_gm ) | TC_WGMODE_SINGLESLOPE_gc;

	/* set compare value */
	//TCC4.CCABUF = 0x61A;

	/* Enable output compare */
	TCC4.CTRLE |= TC_CCAMODE_COMP_gc;
 }

 void SetPWMAudioFreq(uint16_t adcValue)
 {
	/* freq range from: 
	*  0Hz -> ADC value of 0 gives PERBUF = 31250
	*  to
	*  20kHz -> ADC value of 4095 gives PERBUF = 2 */

	/* roughly 7.6 counts per ADC value. Period max in one second / ADC range
	* 31250/4095 = 7.6 */

	/* don't let value go above ADC 12bit range */
	uint16_t adcBitRange = adcValue & 0xFFF;

	/* this gives 1Hz to 200Hz LFO */
	uint16_t max = (adcBitRange - 35 ) * 8;

	/* set the freq */
	TCC4.PERBUF = max;

	/* set 50/50 duty cycle */
	TCC4.CCABUF = max/2;

 }