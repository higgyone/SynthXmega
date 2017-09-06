/*
 * MidiState.c
 *
 * Created: 06/09/2017 21:40:46
 *  Author: Ryan
 */ 
 #include "MidiState.h"
 #include "Spi.h"
 #include "Midi2AD99833.h"
 #include "RingBuffer.h"

 bool noteOn = false;
 uint8_t currentNote = 0;


 void MidiInput(void)
 {
	uint8_t statusByte = 0;
	uint8_t data0 = 0;
	uint8_t data1 = 0;

	RingBufferGet(0, &statusByte);

	if (statusByte == 0x90 || statusByte == 0x80)
	{
		RingBufferGet(0, &data0);
		RingBufferGet(0, & data1);

		/* if on get note and play it*/

		/* if off, check it is the note playing and if so turn it off */
	}
	else
	{
		while(!IsRingBufferEmpty(0))
		{
			RingBufferGet(0, &data0);
		}
	}
 }