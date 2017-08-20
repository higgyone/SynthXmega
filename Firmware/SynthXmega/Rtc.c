/*
 * Rtc.c
 *
 * Created: 13/08/2017 13:47:16
 *  Author: Ryan
 */ 

 #include "drivers/rtc/rtc_driver.h"
 #include "Hardware.h"

 /* number of cycles of 32768Hz clock in 5ms*/
 #define RTC_CYCLES_5MS 0x667
 #define RTC_CYCLES_10MS 0xCCE

 void SetupRTC(void)
 {
	/* set theRTC overflow to 5ms */
	RTC_Initialize(RTC_CYCLES_5MS, 0, 0, RTC_PRESCALER_DIV1_gc);

	/* set the interrupt level to lo */
	RTC_SetIntLevels(RTC_OVFINTLVL_HI_gc, RTC_COMPINTLVL_OFF_gc);
 }

