  /*! \file 
 *		 MidiState.c
 *
 * \brief
 *      Code for working with MIDI input data and sound generation.
 *
 * \author
 *      Ryan
 * \date 
		Created: 06/09/2017 21:40:46
 *****************************************************************************/
 #include "MidiState.h"
 #include "Spi.h"
 #include "Midi2AD9833.h"
 #include "RingBuffer.h"
 #include "avr/io.h"
 #include "drivers/port/port_driver.h"
 #include "Hardware.h"

 #include <stdbool.h>

 /* global flag indicating 3 bytes of midi data are ready */
 bool MidiData = false;

 /* current note being played*/
 uint8_t currentNote = 0;
/* velocity of current note... for future use */
 uint8_t currentVelocity = 0;

 void SetWaveform(void);

  /*! \brief This function parses the midi notes to turn on or off sound.
 *
 * \param None
 *
 * \return None
 */
 void MidiInput(void)
 {
	uint8_t statusByte = 0;
	uint8_t data0 = 0;
	uint8_t data1 = 0;

	RingBufferGet(0, &statusByte);

	/* only deal with it if it is a note on: 0x90 of off: 0x80 */
	if (statusByte == 0x90 || statusByte == 0x80)
	{
		RingBufferGet(0, &data0);
		RingBufferGet(0, & data1);

		currentVelocity = data1;

		/* deal with a note on */
		if (statusByte == 0x90)
		{
			SetWaveform();
			currentNote = data0;
			SetMidiOn();
			SendMidiFreq(data0);
		}
		else
		{
			/* turn note off */
			if (currentNote == data0)
			{
				SetMidiOff();
			}
		}
	}
	else
	{
		/* not a note on or off so flush buffer */
		while (!IsRingBufferEmpty(0))
		{
			RingBufferGet(0, &statusByte);
		}
	}
 }


   /*! \brief This function sets the current waveform depending on input values.
 * Note PA1, PA3 & PA4 are input pins used. PA2 is used for DAC0
 * truth table is:
 * Pin	4|3|2|1|0
 *      -|-|-|-|-
 * SINE 1|1|X|1|X = 0x1A
 * SQ/2 1|1|X|0|X = 0x18
 * SQRE 1|0|X|1|X = 0x12
 * TRI  0|1|X|1|X = 0x0A  
 *
 * \param None
 *
 * \return None
 */
 void SetWaveform(void)
 {
	uint8_t status = PORT_GetPortValue(&WAVEPORT);

	/* set all don't care bits to 0 */
	status &= WAVEPINS_bm;

	switch (status)
	{
		case 0x18:
			WaveState = SQUAREHALF;
			break;
		case 0x12:
			WaveState = SQUARE;
			break;
		case 0x0A:
			WaveState = TRIANGLE;
			break;
		default:
			WaveState = SINE;
			break;
	}
 }