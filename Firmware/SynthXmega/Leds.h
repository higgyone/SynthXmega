  /*! \file 
 *		 Leds.c
 *
 * \brief
 *      Header file for setting turning on and off and toggling the LEDs
 *
 * \author
 *      Ryan
 * \date 
		30/07/2017 15:02:12
 *****************************************************************************/ 

#ifndef LEDS_H_
#define LEDS_H_

#include "drivers/port/port_driver.h"
#include "Hardware.h"

    /*! \brief This function turns LED0 on.
 *
 * \param None
 */
 inline void LedOn0(void)
 {
	PORT_ClearPins(&LEDPORT, LED0_bm);
 }

   /*! \brief This function turns LED0 off.
 *
 * \param None
 */
inline void LedOff0(void)
 {
	 PORT_SetPins(&LEDPORT, LED0_bm);
 }

   /*! \brief This function turns LED1 on.
 *
 * \param None
 */
 inline void LedOn1(void)
 {
	 PORT_ClearPins(&LEDPORT, LED1_bm);
 }

   /*! \brief This function turns LED1 off.
 *
 * \param None
 */
inline void LedOff1(void)
 {
	 PORT_SetPins(&LEDPORT, LED1_bm);
 }

/*! \brief This function toggles LED0.
*
* \param None
*/
inline void ToggleLed0(void)
{
	PORT_TogglePins(&LEDPORT, LED0_bm);
}

   /*! \brief This function toggles LED1.
 *
 * \param None
 */
 inline void ToggleLed1(void)
 {
	PORT_TogglePins(&LEDPORT, LED1_bm);
 }


#endif /* LEDS_H_ */