   /*! \file 
 *		 main.c
 *
 * \brief
 *      main entrance to programme
 *
 * \author
 *      Ryan
 * \date 
		03/06/2017 16:45:32
 *****************************************************************************/ 
#include "Clock.h"
#include "Hardware.h"
#include "TestFunctions.h"
#include "avr/io.h"
#include "SleepXmega.h"
#include "Spi.h"
#include "LPF.h"
#include "Uart.h"
#include "MidiState.h"

 #include <util/delay.h>


 /*! \brief This is the main entrance to code.
 *
 * \param None
 *
 * \return int should never return
 */
int main(void)
{
	/* setup the clock */
	SetupClocks();

	/* setup the board */
	BoardInit();

	ClearConsole();

	//SendDDS();

	SetupAd9833();

	ResetDDS();

	//SendMidiFreq(69u);

    /* Main loop */
    while (1) 
    {
		if (SystemTimerFired)
		{
			SystemTimerFired = false;

			/* do tests */
			TestLed0();
			TestADCLPF();
			TestDAC(lpf);
			//TestPWMFreq(lpf);
			//TestSerialOut();

			//TestMidiFreq();
		}

		//TestSpi();
		//Sleep();

		if (MidiData)
		{
			MidiInput();

			MidiData = false;
		}
    }
}



