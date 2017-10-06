   /*! \file 
 *		 PWM.h
 *
 * \brief
 *      Header file for PWM.c
 *
 * \author
 *      Ryan
 * \date 
		13/08/2017 14:49:28
 *****************************************************************************/ 

#ifndef PWM_H_
#define PWM_H_

#include "avr/io.h"

void SetupPWM(void);
void SetPWMAudioFreq(uint16_t adcValue);



#endif /* PWM_H_ */