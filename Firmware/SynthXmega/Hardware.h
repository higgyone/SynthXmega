/*
 * Hardware.h
 *
 * Created: 20/04/2017 21:21:05
 *  Author: Ryan
 */ 


#ifndef HARDWARE_H_
#define HARDWARE_H_

#define LED0_PIN	4
#define LED1_PIN	5
#define LED0_bm		0x10
#define LED1_bm		0x20
#define LEDPORT		PORTD


 typedef enum 
{
	LedOn,
	LedOff
}LedState_t;

typedef enum  
{
	LED0,
	LED1
}Led_t;

void BoardInit(void);
void LedOnOff(Led_t led, LedState_t state);


#endif /* HARDWARE_H_ */