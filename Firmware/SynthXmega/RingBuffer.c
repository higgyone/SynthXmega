  /*! \file 
 *		 RingBuffer.c
 *
 * \brief
 *      Ring buffer for midi input
 *		based on: http://www.simplyembedded.org/tutorials/interrupt-free-ring-buffer/
 *		Copyright (c) 2015, simplyembedded.org
 *
 * \author
 *      Ryan
 * \date 
		02/09/2017 22:08:10
 *****************************************************************************/ 

 #include "RingBuffer.h"
 #include "avr/io.h"
 #include <string.h>

 /* Ring buffer parameters */
 struct ringBuffer
 {
	/* size of each element */ 
	 uint8_t sizeElems;
	 /* number of elements in buffer */
	 uint8_t numElems;
	 uint8_t *buffer;
	 volatile uint8_t head;
	 volatile uint8_t tail;
 };

 static struct ringBuffer ringBuff[RING_BUFFER_MAX];

 static int8_t RingBufferEmpty(struct ringBuffer *rb);
 static int8_t RingBufferFull(struct ringBuffer *rb);
 static int8_t RingBufferCount(struct ringBuffer *rb);

  /*! \brief This function initialises a ring buffer.
 *
 * \param	ringBuffDescriptor *rbd which ring buffer to use
 *			ringBuffAttr *attr attribures of the ring buffer
 *
 * \return int8_t -1 if failed to setup buffer
 */
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
 
  /*! \brief This checks if the ring buffer is full.
 *
 * \param	struct ringBuffer *rb ring buffer parameters
 *
 * \return int8_t 1 if full otherwise 0
 */
 static int8_t RingBufferFull(struct ringBuffer *rb)
 {
	return ((rb->head - rb->tail) == rb->numElems) ? 1 : 0;
 }

  /*! \brief This checks if the ring buffer is empty.
 *
 * \param	struct ringBuffer *rb ring buffer parameters
 *
 * \return int8_t 1 if empty otherwise 0
 */
 static int8_t RingBufferEmpty(struct ringBuffer *rb)
 {
	return ((rb->head - rb->tail) == 0U) ? 1 : 0;
 }

  /*! \brief This checks the number of spaces available before wrap around
 *
 * \param	struct ringBuffer *rb ring buffer parameters
 *
 * \return int8_t number of elements remaining to be filled before wrap around
 */
 static int8_t RingBufferCount(struct ringBuffer *rb)
 {
	return (rb->head - rb->tail);
 }

   /*! \brief Public function to checks the number of spaces available before wrap around
 *
 * \param	struct ringBuffDescriptor rbd ring buffer parameters
 *
 * \return int8_t number of elements remaining to be filled before wrap around
 */
 int8_t GetRingBuffCount(ringBuffDescriptor rbd)
 {
	return RingBufferCount(&ringBuff[rbd]);
 }

 /*! \brief Public function to check if the ring buffer is empty.
 *
 * \param	struct ringBuffDescriptor rbd ring buffer parameters
 *
 * \return int8_t 1 if empty otherwise 0
 */
 int8_t IsRingBufferEmpty(ringBuffDescriptor rbd)
 {
	return RingBufferEmpty(&ringBuff[rbd]);
 }

   /*! \brief Public function to check if the ring buffer is full.
 *
 * \param	struct ringBuffDescriptor rbd ring buffer parameters
 *
 * \return int8_t 1 if full otherwise 0
 */
 int8_t IsRingBufferFull(ringBuffDescriptor rbd)
 {
	 return RingBufferFull(&ringBuff[rbd]);
 }

  /*! \brief Public function to add data to the ring buffer
 *
 * \param	struct ringBufferDescriptor rbd ring buffer parameters
 *			const void *data data to add
 *
 * \return int8_t -1 if error
 */
 int8_t RingBufferAdd(ringBuffDescriptor rbd, const void *data)
 {
	int8_t error = 0;

	if ((rbd < RING_BUFFER_MAX) 
		&& (RingBufferFull(&ringBuff[rbd])) == 0)
	{
	/* find to offset into the buffer to add the data byte and copy it in*/
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

  /*! \brief Public function to get data from the ring buffer
 *
 * \param	struct ringBufferDescriptor rbd ring buffer parameters
 *			const void *data data out
 *
 * \return int8_t -1 if error
 */
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