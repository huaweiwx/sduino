//  tim_32_1.h
//  STM8S003K3Tx        32 pins
//  STM8S103K3Bx/Tx/Ux  32pins
//  huaweiwx@sina.com 2018.4.08
 

#ifndef _STM8_TIM32_1_h
#define _STM8_TIM32_1_h

#ifndef SDUINOPINS_DEF
#ifdef ARDUINO_MAIN

// STM8S103K3 blue board
//     
//                o----+
//         NRST  1|    |32  PD7  LED PWM
//          PA1  2|    |31  PD6  RX
//          PA2  3|    |30  PD5  TX
//               4|    |29  PD4  PMW
//               5|    |28  PD3  PMW
//               6|    |27  PD2  PMW
//          PA3  7|    |26  PD1 
//          PF4  8|    |25  PD0 
//                              
//                              
//          PB7  9|    |24  PC7  MISO
//          PB6 10|    |23  PC6  MOSI  
// SDA      PB5 11|    |22  PC5  SCK
// SCL      PB4 12|    |21  PC4  PMW
// PMW (A0, PB3 13|    |20  PC3  PMW 
// PMW (A1, PB2 14|    |19  PC2  PMW 
// PMW (A2, PB1 15|    |18  PC1  PMW 
// PMW (A3, PB0 16|    |17  PE5  NSS
//                     +----+

const uint8_t PROGMEM digital_pin_to_timer_PGM[] = {
	NOT_ON_TIMER,	/* 0  PA1 OSC IN */
	NOT_ON_TIMER,	/* 1  PA2 OSC OUT */
	NOT_ON_TIMER,	/* 2  PA3 SPI_NSS/TIM2_CH3*/
	NOT_ON_TIMER,	/* 3  PB0 AIN0/TIM1_CH1N */
	NOT_ON_TIMER,	/* 4  PB1 AIN1/TIM1_CH2N */
	NOT_ON_TIMER,	/* 5  PB2 AIN2/TIM1_CH3N */
	NOT_ON_TIMER,	/* 6  PB3 AIN3/TIM1_ETR */
	NOT_ON_TIMER,	/* 7  PB4 I2C_SCL */
	NOT_ON_TIMER,	/* 8  PB5 I2C_SDA */
	NOT_ON_TIMER,	/* 9  PB6 */
	NOT_ON_TIMER,	/* 10 PB7 */
	TIMER11,		/* 11 PC1 TIM1_CH1 / UART1_CK */
	TIMER12,		/* 12 PC2 TIM1_CH2 */
	TIMER13,		/* 13 PC3 TIM1_CH3 */
	TIMER14,		/* 14 PC4 TIM1_CH4/CLK_CCO */
	NOT_ON_TIMER,	/* 15 PC5 SPI_SCK */
	NOT_ON_TIMER,	/* 16 PC6 SPI_MOSI */
	NOT_ON_TIMER,	/* 17 PC7 SPI_MISO */
	NOT_ON_TIMER,	/* 18 PD0 TIM1_BKIN/CLK_CCO]*/
	NOT_ON_TIMER,	/* 19 PD1 SWIM */
	TIMER23,		/* 20 PD2 [TIM2_CH3] */
	TIMER22,		/* 21 PD3 TIM2_CH2/ADC_ETR */
	TIMER21,		/* 22 PD4 TIM2_CH1/BEEP*/
	NOT_ON_TIMER,	/* 23 PD5 UART1_TX */
	NOT_ON_TIMER,	/* 24 PD6 UART1_RX */
	NOT_ON_TIMER,	/* 25 PD7 TLI/[TIM1_CH4] */
	NOT_ON_TIMER,	/* 26 PE5 SPI_NSS */
	NOT_ON_TIMER,	/* 27 PF4 */
};

#endif /* ARDUINO_MAIN */
#define digitalPinHasPWM(p)	(\
((p)==PA3)|\
((p)==PB0)|\
((p)==PB1)|\
((p)==PB2)|\
((p)==PC1)|\
((p)==PC2)|\
((p)==PC3)|\
((p)==PD2)|\
((p)==PD3)|\
((P)==PD4))

#endif //SDUINOPINS_DEF
#endif //_STM8_GPIO_VARINAT32_1_h
