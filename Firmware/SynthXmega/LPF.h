 /*! \file 
 *		 LPF.h
 *
 * \brief
 *      Header file for Low Pass Filter routine
 *
 * \author
 *      Ryan
 * \date 
		24/07/2017 21:39:47
 *****************************************************************************/ 

#ifndef LPF_H_
#define LPF_H_

#include "avr/io.h"
 
/* alpha factor for low pass filer*/
#define alpha 0.7

/* macro to get the current LPF value */
#define GetLPF() lpf

/* current LPF value */
extern volatile uint16_t lpf;

void AddLPFValue(uint16_t reading);
void ResetLPF(void);

#endif /* LPF_H_ */