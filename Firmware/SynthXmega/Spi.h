 /*! \file 
 *		 Spi.h
 *
 * \brief
 *      Header file for Spi.h
 *
 * \author
 *      Ryan
 * \date 
		08/08/2017 21:41:22
 *****************************************************************************/


#ifndef SPI_H_
#define SPI_H_

void SetupSpi(void);
void SendSPIPacket(const uint8_t *transmitData, uint8_t bytesToTransceive);
void SendDDS(void);
void SendMidiFreq(uint8_t freq);
void ResetDDS(void);
void SetupAd9833(void);
void SetMidiOff(void);
void SetMidiOn(void);

#endif /* SPI_H_ */