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

	 } while ( CLKSYS_IsReady( OSC_RC32MRDY_bm ) == 0 );

	 CLKSYS_Main_ClockSource_Select( CLK_SCLKSEL_RC32M_gc );
 }

