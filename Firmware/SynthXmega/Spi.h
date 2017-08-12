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

#endif /* SPI_H_ */