 /*! \file 
 *		 Hardware.h
 *
 * \brief
 *      Header file for Hardware.c
 *
 * \author
 *      Ryan
 * \date 
		20/04/2017 21:21:05
 *****************************************************************************/ 
#ifndef HARDWARE_H_
#define HARDWARE_H_

#include <stdbool.h>
#include "avr/io.h"

#define LED0_PIN	4
#define LED1_PIN	5
#define LED0_bm		0x10
#define LED1_bm		0x20
#define LEDPORT		PORTD
#define WAVEPORT	PORTA
/* PA [1,3,4] */
#define WAVEPINS_bm	0x1A

extern int8_t adcOffset;
extern bool SystemTimerFired;


void BoardInit(void);


#endif /* HARDWARE_H_ */