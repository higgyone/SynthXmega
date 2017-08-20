  /*! \file 
 *		 Clock.c
 *
 * \brief
 *      Code for setting up the Clock rate
 *
 * \author
 *      Ryan
 * \date 
		03/06/2017 16:47:10
 *****************************************************************************/ 
 
 #include "Clock.h"
 #include "drivers/clock/clksys_driver.h"

 void Setup32MHzClock(void);
 void Setup32KHzClock(void);

 void SetupClocks(void)
 {
	Setup32MHzClock();
	Setup32KHzClock();
 }

  /*! \brief This function sets up the clock speed on the board.
  * Setup and get the 32MHz clock running  with no prescaler
 *
 * \param None
 *
 * \return None
 */
 void Setup32MHzClock(void)
 {
	 CLKSYS_Enable( OSC_RC32MEN_bm );
	 
	 do 
	 {
		/* wait for clock to be ready */
	 } while ( CLKSYS_IsReady( OSC_RC32MRDY_bm ) == 0 );

	 CLKSYS_Main_ClockSource_Select( CLK_SCLKSEL_RC32M_gc );
 }

 void Setup32KHzClock(void)
 {
	/* turn on the 32KHz clock for RTC */
	OSC.CTRL |= OSC_RC32KEN_bm;

	do 
	{
		/* Wait for the 32kHz oscillator to stabilize. */
	} while ( ( OSC.STATUS & OSC_RC32KRDY_bm ) == 0);

	/* set to 32KHz and enable it */
	CLK.RTCCTRL = CLK_RTCSRC_RCOSC32_gc | CLK_RTCEN_bm;

	do 
	{
		/* Wait until RTC is not busy. */
	} while ( RTC.STATUS & RTC_SYNCBUSY_bm );
 } 

