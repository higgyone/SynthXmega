/*
 * Hardware.h
 *
 * Created: 20/04/2017 21:21:05
 *  Author: Ryan
 */ 


#ifndef HARDWARE_H_
#define HARDWARE_H_

#include <stdbool.h>
#include "avr/io.h"

#define LED0_PIN	4
#define LED1_PIN	5
#define LED0_bm		0x10
#define LED1_bm		0x20
#define LEDPORT		PORTD

extern int8_t adcOffset;
extern bool SystemTimerFired;


void BoardInit(void);


#endif /* HARDWARE_H_ */