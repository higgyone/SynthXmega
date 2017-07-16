/*
 * SynthBasic.c
 *
 * Created: 03/06/2017 16:45:32
 * Author : Ryan
 */ 

#include <avr/io.h>

#include "Clock.h"
#include "Hardware.h"
#include "TestFunctions.h"

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

