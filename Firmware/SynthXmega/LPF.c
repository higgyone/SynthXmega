  /*! \file 
 *		 LPF.c
 *
 * \brief
 *      Code for Low Pass Filter routine
 *
 * \author
 *      Ryan
 * \date 
		30/07/2017 14:59:12
 *****************************************************************************/ 

 #include<stdbool.h>

 #include "LPF.h"

 volatile uint16_t lpf = 0;
 uint16_t prevLpf = 0;
 bool firstRun = true;

  /*! \brief This function adds a value to the LPF.
 *
 * \param reading uint16_t ADC reading
 *
 * \return None
 */
 void AddLPFValue(uint16_t reading)
 {
	/* set the first value of the LPF if it is the first time run */ 
	if (firstRun)
	{
		lpf = reading;
		firstRun = false;
	}

	/* calculate the low pass filter value */
	lpf = alpha * prevLpf + (1 - alpha) * reading;

	/* update previous value */
	prevLpf = lpf;
 }

  /*! \brief This function resets the values in the Low Pass Filter.
 *
 * \param None
 *
 * \return None
 */
 void ResetLPF(void)
 {
	 firstRun = true;
	 lpf = 0;
	 prevLpf = 0;
 }
