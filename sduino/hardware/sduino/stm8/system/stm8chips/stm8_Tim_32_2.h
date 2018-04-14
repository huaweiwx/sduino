//  tim_32_2.h
//  STM8S005K6Tx       32pins
//  STM8S105K6Bx/Tx/Ux 32pins
//  STM8S105K4Bx/Tx/Ux 32pins
//  huaweiwx@sina.com 2018.4.08
 

#ifndef _STM8_TIM32_2_h
#define _STM8_TIM32_2_h
#ifndef SDUINOPINS_DEF
#ifdef ARDUINO_MAIN

// STM8S005/105 K4/6 breakout board
//
//                      +-/\-+
//                GND 16|    |15 GND
//                 5V 17|    |14 3V3
//      PMW (D12) PC3 18|    |13 PC2  (D11) PMW
//      PMW (D13) PC4 19|    |12 PC1  (D10) PMW
//  SCK     (D14) PC5 20|    |11 PE5  (D9)      NSS
// MOSI     (D15) PC6 21|    |10 PD0  (D8)  PMW
// MISO     (D16) PC7 22|    |9  PB1  (D7)  PMW
//      PMW (D17) PD0 23|    |8  PB2  (D6)  PMW
//          (D18) PD1 24|    |7  PB3  (D5)
//      PMW (D19) PD2 25|    |6  PB4  (D4)
//      PMW (D20) PD3 26|    |5  PB5  (D3)
//      PMW (D21) PD4 27|    |4  PF4  (D2)
// TX       (D22) PD5 28|    |3  PA2  (D1)  SDL
// RX       (D23) PD6 29|    |2  PA1  (D0)  SDA
//      PMW (D24) PD7 30|    |1  NRST
//                      +----+
//

const uint8_t PROGMEM digital_pin_to_timer_PGM[] = {
	NOT_ON_TIMER,	 /* 0  PA1 OSC IN */
	NOT_ON_TIMER,	 /* 1  PA2 OSC OUT */
	NOT_ON_TIMER,	 /* 2  PB0 AIN0/[TIM1_CH1N] */
	NOT_ON_TIMER,	 /* 3  PB1 AIN1/[TIM1_CH2N] */
	NOT_ON_TIMER,	 /* 4  PB2 AIN2/[TIM2_CH3N] */
	NOT_ON_TIMER,	 /* 5  PB3 AIN3/[TIM1_ETR] */
	NOT_ON_TIMER,	 /* 6  PB4 AIN4/[I2C_SCL] */
	NOT_ON_TIMER,	 /* 7  PB5 AIN5/[I2C_SDA] */
	TIMER11,		 /* 8  PC1 TIM1_CH1/UART2_CK */
	TIMER12,		 /* 9  PC2 TIM1_CH2 */
	TIMER13,		 /* 10 PC3 TIM1_CH3 */
	TIMER14,		 /* 11 PC4 TIM1_CH4 */
	NOT_ON_TIMER,	 /* 12 PC5 SPI_SCK  */
	NOT_ON_TIMER,	 /* 13 PC6 SPI_MOSI */
	NOT_ON_TIMER,	 /* 14 PC7 SPI_MISO */
	TIMER32,		 /* 15 PD0         */
	NOT_ON_TIMER,	 /* 16 PD1 SWIM    */
	TIMER31,		 /* 17 PD2 TIM2_CH3 */
	TIMER22,		 /* 18 PD3 TIM2_CH2 / [ADC_ETR] */
	TIMER21,		 /* 19 PD4 TIM2_CH1 / [BEEP] */
	NOT_ON_TIMER,	 /* 20 PD5 UART2_TX */
	NOT_ON_TIMER,	 /* 21 PD6 UART2_RX */
	NOT_ON_TIMER,	 /* 22 PD7 TLI/[TIM1_CH4] */
	NOT_ON_TIMER,	 /* 23 PE5 SPI_NSS  */
	NOT_ON_TIMER,	 /* 24 PF4 AIN12 */
};

const uint8_t digitalPinToAnalogChannelMap[] = {
	PB0,		// A6	D8	PB0	Ain0
	PB1,		// A5	D7	PB1	Ain1
	PB2,		// A4	D6	PB2	Ain2
	PB3,  	    // A3   D5	PB3 Ain3
	PB4,		// A2	D4	PB4	Ain4
	PB5,		// A1	D3	PB5	Ain5
	PF4,		// A0	D2	PF4	Ain12
};

#endif /* ARDUINO_MAIN */
#define digitalPinHasPWM(p)	(\
((p)==PC1)|\
((p)==PC2)|\
((p)==PC3)|\
((p)==PD2)|\
((p)==PD3)|\
((P)==PD4))

#endif //SDUINOPINS_DEF
#endif //_STM8_GPIO_VARINAT32_1_h
