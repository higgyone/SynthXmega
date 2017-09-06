 /*! \file 
 *		 TestFuncitons.c
 *
 * \brief
 *      Contains test functions for the code.
 *
 * \author
 *      Ryan
 * \date 
		16/07/2017 21:10:23
 *****************************************************************************/

 #include <util/delay.h>
 #include <stdbool.h>

 #include "Hardware.h"
 #include "drivers/adc/adc.h"
 #include "LPF.h"
 #include "drivers/port/port_driver.h"
 #include "Leds.h"
 #include "Spi.h"
 #include "PWM.h"

 uint8_t testSpiSendData[4] = {0x11, 0x22, 0x33, 0x44};

 /*! \brief This function tests the flashing of the LEDS.
 *
 * \param None
 *
 * \return None
 */
 void TestLedsFlash(void)
 {
	 LedOff0();
	 LedOn1();

	 _delay_ms(1000);

	 LedOn0();
	 LedOff1();

	 _delay_ms(1000);
 }

 /*! \brief This function flashes LED0.
 *
 * \param None
 *
 * \return None
 */
 void TestLed0(void)
 {
	ToggleLed0();
 }

 /*! \brief This function tests the ADC with breakpoint for debug output.
 *
 * \param None
 *
 * \return None
 */
 void TestADCDebugOutput(void)
 {
	uint16_t sample;
	uint32_t total = 0;

	while(total < 0xFFFF)
	{
		adc_start_conversion(&ADCA, ADC_CH0);
		adc_wait_for_interrupt_flag(&ADCA, ADC_CH0);
		sample = adc_get_unsigned_result(&ADCA, ADC_CH0) - adcOffset;

		total+= sample;
	}
 }

 /*! \brief This function tests the ADC with low pass filtering.
 *
 * \param None
 *
 * \return None
 */
 void TestADCLPF(void)
 {
	 uint16_t sample;

	adc_start_conversion(&ADCA, ADC_CH0);
	adc_wait_for_interrupt_flag(&ADCA, ADC_CH0);
	sample = adc_get_unsigned_result(&ADCA, ADC_CH0) - adcOffset;
 
	AddLPFValue(sample);
 }

 void TestSpi(void)
 {
	_delay_ms(100);
	SendSPIPacket(testSpiSendData, 4);
 }

 void TestDAC(uint16_t data)
 {
	while ( (DACA.STATUS & DAC_CH0DRE_bm ) == false ) {
		/* Blocking code waiting for empty register. */
	}

	DACA.CH0DATA = data;
 }

 void TestPWMFreq(uint16_t value)
 {
	SetPWMAudioFreq(value);
 }

 uint8_t usartCount = 0;

 void TestSerialOut(void)
 {
	usartCount++;

	if (usartCount > 50)
	{
		USARTC0.DATA = 0x29;

		while ((USARTC0.STATUS & USART_DREIF_bm) == 0)
		{
			
		}

		USARTC0.DATA = 0x30;
		usartCount = 0;
	}
 }

 void TestMidiFreq(void)
 {
	static uint8_t count = 1;
	static bool reverse = false;

	SendMidiFreq(count);

	if (count == 127)
	{
		reverse = true;
	}
	else if (count == 0)
	{
		reverse = false;
	}

	if (reverse)
	{
		count--;
	}
	else
	{
		count++;
	}
 }
