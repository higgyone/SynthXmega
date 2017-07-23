 /*! \file 
 *		 Hardware.c
 *
 * \brief
 *      Code for setting up the hardware elements of the board
 *
 * \author
 *      Ryan
 * \date 
		20/04/2017 21:20:39
 *****************************************************************************/ 

 #include "Hardware.h"
 #include "drivers/port/port_driver.h"
 #include "drivers/adc/adc.h"
 #include "avr/io.h"

 #include <string.h>

 int8_t adcOffset;

void SetupLeds(void);


 /*! \brief This function runs the initialization routine for the board.
 *
 * \param None
 *
 * \return None
 */
 void BoardInit(void)
 {
	SetupLeds();

	SetupADC0();
 }

 void SetupADC0(void)
 {
	struct adc_config adcConfig;
	struct adc_channel_config adcChConf0;

	/* clear the struct*/
	memset(&adcConfig, 0, sizeof(struct adc_config));
	memset(&adcChConf0, 0, sizeof(struct adc_channel_config));

	/* set for unsigned, 12bit resolution and Vref of AVcc/2*/
	adc_set_conversion_parameters(&adcConfig, ADC_SIGN_OFF, ADC_RES_12, ADC_REF_VCCDIV2);

	/* don't need a fast sampling clock as wont be twiddling knob fast*/
	adc_set_clock_rate(&adcConfig, 750000UL);

	/* set high current limit on adc as wont be using it fast therefore limit current*/
	adc_set_current_limit(&adcConfig, ADC_CURRENT_LIMIT_HIGH);

	/* write the config and Cal data*/
	adc_write_configuration(&ADCA, &adcConfig);

	/* get offset value for ADC A*/
	adcch_set_input(&adcChConf0, ADCCH_POS_PIN1, ADCCH_NEG_PIN1, 1);

	adcch_write_configuration(&ADCA, ADC_CH0, &adcChConf0);

	adc_enable(&ADCA);

	/* wait until voltage is stable, which takes 1 conversion*/
	adc_start_conversion(&ADCA, ADC_CH0);
	adc_wait_for_interrupt_flag(&ADCA, ADC_CH0);

	/* get offset value*/
	adc_start_conversion(&ADCA, ADC_CH0);
	adc_wait_for_interrupt_flag(&ADCA, ADC_CH0);
	adcOffset = adc_get_result(&ADCA, 0);

	adc_disable(&ADCA);

	/* set PortA Pin 0 as ADC input single ended */
	adcch_set_input(&adcChConf0, ADCCH_POS_PIN0, ADCCH_NEG_NONE, 1);
	adcch_write_configuration(&ADCA, ADC_CH0, &adcChConf0);

	/* set free running on channel 1*/
	adc_set_conversion_trigger(&adcConfig, ADC_TRIG_FREERUN, 1, 0);
	adc_write_configuration(&ADCA, &adcConfig);

	adc_enable(&ADCA);

	uint16_t sample;
	uint32_t total;

	while(total < 0xFFFF)
	{
		adc_start_conversion(&ADCA, ADC_CH0);
		adc_wait_for_interrupt_flag(&ADCA, ADC_CH0);
		sample = adc_get_unsigned_result(&ADCA, ADC_CH0) - adcOffset;

		total+= sample;
	}

 }

  /*! \brief This function sets up the LED pins on the board.
 *
 * \param None
 *
 * \return None
 */
 void SetupLeds(void)
 {
	/* setup the LEDs
	* set pins as outputs
	*Set them high to turn off
	*/
	PORT_SetPinsAsOutput(&LEDPORT, LED0_bm | LED1_bm);
	PORT_SetPins(&LEDPORT, LED0_bm | LED1_bm);
 }

  /*! \brief This function turns the specified LED on or off.
 *
 * \param led   LED to turn on or off
 * \param state State to set LED
 */
 void LedOnOff(Led_t led, LedState_t state)
 {
	if (led == LED0)
	{
		if (state == LedOn)
		{
			PORT_ClearPins(&LEDPORT, LED0_bm);
		}
		else
		{
			PORT_SetPins(&LEDPORT, LED0_bm);
		}	
	}
	else
	{
		if (state == LedOn)
		{
			PORT_ClearPins(&LEDPORT, LED1_bm);
		}
		else
		{
			PORT_SetPins(&LEDPORT, LED1_bm);
		}
	}
 }
