 /*! \file 
 *		 Spi.c
 *
 * \brief
 *      Code for doing SPI tasks.
 *
 * \author
 *      Ryan
 * \date 
		08/08/2017 21:41:22
 *****************************************************************************/
 #include <util/delay.h>

#include "drivers/spi/spi_driver.h"
#include "avr/io.h"
#include "Midi2AD9833.h"
#include "Spi.h"

/*! \brief The number of test data bytes. */
#define NUM_BYTES     4

/*! \brief SPI Data packet */
SPI_DataPacket_t dataPacket;

/*! \brief Test data to send from master. */
uint8_t masterSendData[NUM_BYTES] = {0x11, 0x22, 0x33, 0x44};

/*! \brief Data received from slave. */
uint8_t masterReceivedData[NUM_BYTES];

/*! \brief SPI master module on PORT C. */
SPI_Master_t spiMasterC;

#define NUM_SPI_BYTES 2
uint8_t ddsEnterReset[NUM_SPI_BYTES] = {0x21, 0x00};

//uint8_t ddsFreq0[NUM_SPI_BYTES] = {0x50, 0xc7}; // 400hz
uint8_t ddsFreq0[NUM_SPI_BYTES] = {0x69, 0xf1}; // 1khz
uint8_t	ddsFreq1[NUM_SPI_BYTES] = {0x40, 0x00};

uint8_t ddsOffFreq[NUM_SPI_BYTES] = {0x40, 0x01};

uint8_t ddsPhase0[NUM_SPI_BYTES] = {0xC0, 0x00};

uint8_t ddsExitReset[NUM_SPI_BYTES] = {0x20, 0x00};

uint8_t ddsSineWave[NUM_SPI_BYTES] = {0x20, 0x00};
uint8_t ddsTriangleWave[NUM_SPI_BYTES] = {0x20, 0x02};
uint8_t ddsSquareWave[NUM_SPI_BYTES] = {0x20, 0x28};
uint8_t ddsSquareWaveHalf[NUM_SPI_BYTES] = {0x20, 0x20};

uint8_t ddsAll[12]  ={0x21, 0x00, 0x50, 0xc7, 0x40, 0x00, 0xC0, 0x00, 0x20, 0x00};



volatile uint8_t WaveState = SINE;


void SendSPIPacket(const uint8_t *transmitData, uint8_t bytesToTransceive)
{
	/* Create data packet (SS to slave by PC4). */
	SPI_MasterCreateDataPacket(&dataPacket,
	transmitData,
	masterReceivedData,
	bytesToTransceive,
	&PORTC,
	PIN4_bm);

	/* Transceive packet. */
	SPI_MasterTransceivePacket(&spiMasterC, &dataPacket);

}


void SetupSpi(void)
 {
	/*  Hardware setup:
	*	For DDS IC, no MISO
	*    - Connect PC4 to PD4 (SS)
	*    - Connect PC5 to PD5 (MOSI)
	*    - Connect PC7 to PD7 (SCK)
	*/

	/* set PortC pin 4 as SS with wired AND and pullup */
	PORTC.DIRSET |= PIN4_bm;
	PORTC.PIN4CTRL = PORT_OPC_WIREDANDPULL_gc;

	/* set SS output to high */
	PORTC.OUTSET |= PIN4_bm;

	/* instantiate pointer to ss port */
	PORT_t *ssPort = &PORTC;

	/* initialize spi on port C*/
	SPI_MasterInit(&spiMasterC,
					&SPIC,
					&PORTC,
					false,
					SPI_MODE_2_gc,
					SPI_INTLVL_OFF_gc,
					false,
					SPI_PRESCALER_DIV128_gc);
 }

 void SetupAd9833(void)
 {
	uint8_t freq0[2] = {Midi2AD9833[0][2], Midi2AD9833[0][3]};
	uint8_t freq1[2] = {Midi2AD9833[0][0], Midi2AD9833[0][1]};
	
	SendSPIPacket(ddsEnterReset, NUM_SPI_BYTES);
	SendSPIPacket(freq0, NUM_SPI_BYTES);
	SendSPIPacket(freq1, NUM_SPI_BYTES);
	SendSPIPacket(ddsPhase0, NUM_SPI_BYTES);
	SendSPIPacket(ddsExitReset, NUM_SPI_BYTES);
 }

 void ResetDDS(void)
 {
	 SendSPIPacket(ddsEnterReset, NUM_SPI_BYTES);
	 SendSPIPacket(ddsExitReset, NUM_SPI_BYTES);
 }

void SetMidiOn(void)
{
	switch (WaveState)
	{
		case SINE:
			ResetDDS();
			break;
		case TRIANGLE:
			SendSPIPacket(ddsTriangleWave, NUM_SPI_BYTES);
			break;
		case SQUARE:
			SendSPIPacket(ddsSquareWave, NUM_SPI_BYTES);
			break;
		case SQUAREHALF:
			SendSPIPacket(ddsSquareWaveHalf, NUM_SPI_BYTES);
			break;
		default:
			ResetDDS();
			break;
	}
}

void SendMidiFreq(uint8_t freq)
{
	uint8_t freq0[2] = {Midi2AD9833[freq][2], Midi2AD9833[freq][3]};
	uint8_t freq1[2] = {Midi2AD9833[freq][0], Midi2AD9833[freq][1]};
	
	SendSPIPacket(freq0, NUM_SPI_BYTES);
	SendSPIPacket(freq1, NUM_SPI_BYTES);
	SendSPIPacket(ddsPhase0, NUM_SPI_BYTES);
}


void SetMidiOff(void)
{
	SendSPIPacket(ddsEnterReset, NUM_SPI_BYTES);
}

void SetTriangle(void)
{
	WaveState = TRIANGLE;
}

void SetSine(void)
{
	WaveState = SINE;
}

void SetSquare(void)
{
	WaveState = SQUARE;
}

void SetSquareHalf(void)
{
	WaveState = SQUAREHALF;
}