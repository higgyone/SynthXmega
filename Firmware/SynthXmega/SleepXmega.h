  /*! \file 
 *		 SleepXmega.c
 *
 * \brief
 *      Header file for setting the micro to sleep
 *
 * \author
 *      Ryan
 * \date 
		30/07/2017 16:06:00
 *****************************************************************************/ 

#ifndef SLEEPXMEGA_H_
#define SLEEPXMEGA_H_

#include <avr/sleep.h>
#include <avr/interrupt.h>

/*! \brief This code to enter sleep state.
*
* \param None
*
* \return None
*/
inline void Sleep(void)
{
	/* enter sleep mode when not in use */
	set_sleep_mode(SLEEP_MODE_IDLE);
	cli();
	sleep_enable();
	sei();
	sleep_cpu();
	sleep_disable();
}

#endif /* SLEEPXMEGA_H_ */