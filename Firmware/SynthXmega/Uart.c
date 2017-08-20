/*

 * Uart.c
 *
 * Created: 20/08/2017 16:02:44
 *  Author: Ryan
 */ 

  #include "Hardware.h"
  #include "avr/io.h"

 void SetupUart(void)
 {
	/* set pin 3 port c to output as it is Tx */ 
	PORTC.DIRSET = PIN3_bm;

	/* set pin 2 port c to input as it is rx */
	PORTC.DIRCLR = PIN2_bm;

	/* set the USART with 8 bits, no parity and one stop bit */
	USARTC0.CTRLC = USART_CHSIZE_8BIT_gc | USART_PMODE_DISABLED_gc ;

	/* set interrupt level to lo*/
	USARTC0.CTRLA = (USARTC0.CTRLA & ~USART_RXCINTLVL_gm) | USART_RXCINTLVL_LO_gc;

	/* set baud rate to MIDI 31250bps 
	* fPer = 32MHz
	* fBaud = 31250 (for midi)
	* BSCALE = 0
	* BSEL = fPer/((2^BSCALE)*16*fBaud) - 1
	* 63 = 32MHz/(1*16*31250) - 1 = 0x3F*/
	USARTC0.BAUDCTRLA = 0x3F;

	/* enable Rx */
	USARTC0.CTRLB |= USART_RXEN_bm;

	/* enable Tx */
	USARTC0.CTRLB |= USART_TXEN_bm;
 }