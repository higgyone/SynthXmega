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
 #include "TestFunctions.h"
 #include "drivers/spi/spi_driver.h"
 #include "Spi.h"
 #include "Rtc.h"
 #include "PWM.h"
 #include "Uart.h"
 #include "RingBuffer.h"

 #include <string.h>
 #include <util/delay.h>

int8_t adcOffset = 0;
bool SystemTimerFired = false;



void SetupLeds(void);
void SetupBackgroundTC0(void);
void SetupADC0(void);
void EnableInterrupts(void);
void SetupSpi(void);
void SetupDAC(void);

ISR(RTC_OVF_vect);

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

	//SetupBackgroundTC0();

	SetupRTC();

	SetupSpi();

	SetupDAC();

	SetupPWM();

	SetupUart();

	EnableInterrupts();
 }

  /*! \brief This function enables the interrupts for the board.
 *
 * \param None
 *
 * \return None
 */
 void EnableInterrupts(void)
 {
	/* set the lo level interrupts on */
	PMIC.CTRL |= PMIC_LOLVLEN_bm;
	PMIC.CTRL |= PMIC_HILVLEN_bm;

	/* enable global interrupts*/
	sei();
 }

   /*! \brief This function sets up background timer counter. 
 * It runs every 5ms on TCC4
 *
 * \param None
 *
 * \return None
 */
 void SetupBackgroundTC0(void)
 {
	/* set for 5ms using 32MHz clock and 1024 divider
	* 32000000/1024 = 31250 counts per second
	* every 5ms = 31250/ 200 = 156.26 = 0x9C */
	//TCC4.PERBUF = 0x9C;
	TCC4.PERBUF = 0xC35;

	/* set clock prescaler to /1024 */
	TCC4.CTRLA = (TCC4.CTRLA & ~TC4_CLKSEL_gm) | TC_CLKSEL_DIV1024_gc;

	/* set the lo level interrupt on for CCA */
	TCC4.INTCTRLB = (TCC4.INTCTRLB & ~TC_CCAINTLVL_LO_gc) | TC_CCAINTLVL_LO_gc;

	TCC4.CTRLGCLR = 0b100000;
 }


  /*! \brief This function sets up ADC0 and gets the offset value.
 * 12bit, unsigned and vref of AVcc/2
 * Input is PA0
 *
 * \param None
 *
 * \return None
 */
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
}
 
 void SetupDAC(void)
 {
	DACA.CTRLB = ( DACA.CTRLB & ~DAC_CHSEL_gm ) | DAC_CHSEL_SINGLE_gc;
	DACA.CTRLC = ( DACA.CTRLC & ~DAC_REFSEL_gm ) | DAC_REFSEL_AVCC_gc;
	DACA.CTRLA = ( DAC_CH0EN_bm | DAC_ENABLE_bm );
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

 

 /**********************************************************************/
 /*************************Interrupts***********************************/
 /**********************************************************************/

   /*! \brief This is Compare channel A for timer 4 on port C interrupt. 
 * It runs every 5ms on TCC4
 *
 * \param None
 *
 * \return None
 */
 //ISR(TCC4_CCA_vect)
 //{
	 ///* set the global flag */
	 //SystemTimerFired = true;
 //}

ISR(RTC_OVF_vect)
{
	/* set the global flag */
	SystemTimerFired = true;
}

ISR(USARTC0_RXC_vect)
{
	uint8_t rxData = USARTC0.DATA;
	uint8_t txData = 0;

	RingBufferAdd(0, &rxData);

	//USARTC0.DATA = data;

	RingBufferGet(0, &txData);

	USARTC0.DATA = txData;
}
