/*
 * RingBuffer.c
 *
 * Created: 02/09/2017 22:08:10
 *  Author: Ryan
 * based on: http://www.simplyembedded.org/tutorials/interrupt-free-ring-buffer/
 * Copyright (c) 2015, simplyembedded.org
 */ 

 #include "RingBuffer.h"
 #include "avr/io.h"
 #include <string.h>

 struct ringBuffer
 {
	 uint8_t sizeElems;
	 uint8_t numElems;
	 uint8_t *buffer;
	 volatile uint8_t head;
	 volatile uint8_t tail;
 };

 static struct ringBuffer ringBuff[RING_BUFFER_MAX];

 static int8_t RingBufferEmpty(struct ringBuffer *rb);
 static int8_t RingBufferFull(struct ringBuffer *rb);

 int8_t RingBufferSetup(ringBuffDescriptor *rbd, ringBuffAttr *attr)
 {
	static int8_t index = 0;
	int8_t error = -1;

	if ((index < RING_BUFFER_MAX) 
		&& (rbd != NULL) 
		&& (attr != NULL))
	{
		if((attr->buffer != NULL) 
		&& (attr->sizeElems > 0))
		{
			/* check size of buffer is power of 2 for code efficiency*/
			if (((attr->numElems - 1) & attr->numElems) == 0)
			{
				ringBuff[index].head = 0;
				ringBuff[index].tail = 0;
				ringBuff[index].buffer = attr->buffer;
				ringBuff[index].sizeElems = attr->sizeElems;
				ringBuff[index].numElems = attr->numElems;

				*rbd = index++;
				error = 0;
			}
		}
	}

	return error;
 }
 
 static int8_t RingBufferFull(struct ringBuffer *rb)
 {
	return ((rb->head - rb->tail) == rb->numElems) ? 1 : 0;
 }

 static int8_t RingBufferEmpty(struct ringBuffer *rb)
 {
	return ((rb->head - rb->tail) == 0U) ? 1 : 0;
 }

 int8_t IsRingBufferEmpty(ringBuffDescriptor rbd)
 {
	return RingBufferEmpty(&ringBuff[rbd]);
 }

 int8_t IsRingBufferFull(ringBuffDescriptor rbd)
 {
	 return RingBufferFull(&ringBuff[rbd]);
 }

 int8_t RingBufferAdd(ringBuffDescriptor rbd, const void *data)
 {
	int8_t error = 0;

	if ((rbd < RING_BUFFER_MAX) 
		&& (RingBufferFull(&ringBuff[rbd])) == 0)
	{
		const uint8_t offset = (ringBuff[rbd].head & (ringBuff[rbd].numElems - 1)) * ringBuff[rbd].sizeElems;
		memcpy(&(ringBuff[rbd].buffer[offset]), data, ringBuff[rbd].sizeElems);
		ringBuff[rbd].head++;
	}
	else
	{
		error = -1;
	}

	return error;
 }

 int8_t RingBufferGet(ringBuffDescriptor rbd, void *data)
 {
	int8_t error = 0;

	if ((rbd < RING_BUFFER_MAX) 
		&& (RingBufferEmpty(&ringBuff[rbd])) == 0)
	{
		const uint8_t offset = (ringBuff[rbd].tail & (ringBuff[rbd].numElems - 1)) * ringBuff[rbd].sizeElems;
		memcpy(data, &(ringBuff[rbd].buffer[offset]), ringBuff[rbd].sizeElems);
		ringBuff[rbd].tail++;
	}
	else
	{
		error = -1;
	}
	
	return error;
 }