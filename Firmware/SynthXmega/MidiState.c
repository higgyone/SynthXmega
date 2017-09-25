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
 #include "avr/io.h"

 #include <stdbool.h>

 bool MidiData = false;

 bool noteOn = false;
 uint8_t currentNote = 0;
 uint8_t prevNote = 0;
 uint8_t currentVelocity = 0;


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

		currentVelocity = data1;

		if (statusByte == 0x90)
		{
			currentNote = data0;
			noteOn = true;
			SetMidiOn();
			SendMidiFreq(data0);
		}
		else
		{
			if (currentNote == data0)
			{
				noteOn = false;
				SetMidiOff();
			}
		}
	}
	else
	{
		// flush buffer
		while (!IsRingBufferEmpty(0))
		{
			RingBufferGet(0, &statusByte);
		}
	}
 }