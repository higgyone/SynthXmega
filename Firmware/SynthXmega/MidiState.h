  /*! \file 
 *		 MidiState.h
 *
 * \brief
 *      Header file for MidiState.c
 *
 * \author
 *      Ryan
 * \date 
		06/09/2017 21:41:04
 *****************************************************************************/


#ifndef MIDISTATE_H_
#define MIDISTATE_H_

#include "avr/io.h"
#include <stdbool.h>

bool MidiData;
void MidiInput(void);


#endif /* MIDISTATE_H_ */