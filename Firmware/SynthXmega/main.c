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

 /*! \brief This is the main entrance to code.
 *
 * \param None
 *
 * \return int should never return
 */
int main(void)
{
	/* setup the clock */
	Setup32MHzClock();

	/* setup the board */
	BoardInit();


    /* Replace with your application code */
    while (1) 
    {
		TestLedsFlash();
    }
}

