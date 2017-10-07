  /*! \file 
 *		 RingBuffer.h
 *
 * \brief
 *      Header file for RingBuffer.h
 *		based on: http://www.simplyembedded.org/tutorials/interrupt-free-ring-buffer/
 *		Copyright (c) 2015, simplyembedded.org
 *
 * \author
 *      Ryan
 * \date 
		02/09/2017 22:08:25
 *****************************************************************************/ 

#ifndef RINGBUFFER_H_
#define RINGBUFFER_H_

#include "avr/io.h"

typedef struct  
{
	/* size of each element */
	uint8_t sizeElems;
	/* number of elements */
	uint8_t numElems;
	/* pointer to data buffer */
	void *buffer;
} ringBuffAttr;

 /* index of initialized ring buffer */
 typedef uint8_t ringBuffDescriptor;

#define RING_BUFFER_MAX	1

int8_t RingBufferSetup(ringBuffDescriptor *rbd, ringBuffAttr *attr);
int8_t RingBufferAdd(ringBuffDescriptor rbd, const void *data);
int8_t RingBufferGet(ringBuffDescriptor rbd, void *data);
int8_t IsRingBufferFull(ringBuffDescriptor rbd);
int8_t IsRingBufferEmpty(ringBuffDescriptor rbd);
int8_t GetRingBuffCount(ringBuffDescriptor rbd);


#endif /* RINGBUFFER_H_ */