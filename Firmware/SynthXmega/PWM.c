  /*! \file 
 *		 PWM.c
 *
 * \brief
 *      ***Deprecated, this is currently not being used but for reference***
 *		PWM output depending on ADC value to create LFO between 1 & 200Hz at 50/50 duty cycle
 *		Doesn't really work and probably going to use hardware LFO
 *
 * \author
 *      Ryan
 * \date 
		13/08/2017 14:49:02
 *****************************************************************************/ 

#include "PWM.h"
#include "avr/io.h"
#include "avr/interrupt.h"

 /*! \brief This function sets up PWM output on PC0 using TCC4
 *
 * \param None
 *
 * \return None
 */
 void SetupPWM(void)
 {
	/* set port C pin 0 to output */
	PORTC.DIRSET = PIN0_bm;

	/* set clock prescaler to /1024 */
	TCC4.CTRLA = (TCC4.CTRLA & ~TC4_CLKSEL_gm) | TC_CLKSEL_DIV256_gc;

	/* set the lo level interrupt on for CCA */
	TCC4.INTCTRLB = (TCC4.INTCTRLB & ~TC_CCAINTLVL_LO_gc) | TC_CCAINTLVL_LO_gc;

	/* start timer */
	TCC4.CTRLGCLR = TC4_STOP_bm;

	/* set single slope operation */
	TCC4.CTRLB = ( TCC4.CTRLB & ~TC4_WGMODE_gm ) | TC_WGMODE_SINGLESLOPE_gc;

	/* Enable output compare */
	TCC4.CTRLE |= TC_CCAMODE_COMP_gc;
 }

  /*! \brief This function sets the PWN frequency based on ADC value
 * to output a LFO between 1 and 200Hz with 50/50 duty cycle.
 *
 * ***Somewhat deprecated as it doesn't really work and may not go down this road for LFO ***
 *
 * \param None
 *
 * \return None
 */
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