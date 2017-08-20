/*
 * PWM.h
 *
 * Created: 13/08/2017 14:49:28
 *  Author: Ryan
 */ 


#ifndef PWM_H_
#define PWM_H_

#include "avr/io.h"

void SetupPWM(void);
void SetPWMAudioFreq(uint16_t adcValue);



#endif /* PWM_H_ */