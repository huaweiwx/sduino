//tim_32_3.h
//STM8S903K3B/T/Ux 32PINS
 

#ifndef _STM8_TIM32_3_h
#define _STM8_TIM32_3_h
#ifndef SDUINOPINS_DEF
#ifdef ARDUINO_MAIN


const uint8_t PROGMEM digital_pin_to_timer_PGM[] = {
	NOT_ON_TIMER,	 /* 0  PA1 OSC IN */
	NOT_ON_TIMER,	 /* 1  PA2 OSC OUT */
	NOT_ON_TIMER,	 /* 2  PA3 UART1_TX */
	NOT_ON_TIMER,	 /* 3  PB0 AIN0/[TIM1_CH1N] */
	NOT_ON_TIMER,	 /* 4  PB1 AIN1/[TIM1_CH2N] */
	NOT_ON_TIMER,	 /* 5  PB2 AIN2/[TIM2_CH3N] */
	NOT_ON_TIMER,	 /* 6  PB3 AIN3/[TIM1_ETR] */
	NOT_ON_TIMER,	 /* 7  PB4 I2C_SCL/[ADC_ETR]*/
	NOT_ON_TIMER,	 /* 8  PB5 PB5/I2C_SDA/[TIM1_BKIN] */
	NOT_ON_TIMER,	 /* 7  PB6 */
	NOT_ON_TIMER,	 /* 8  PB7 */
	TIMER11,		 /* 9  PC1 TIM1_CH1/UART1_CK */
	TIMER12,		 /* 10 PC2 TIM1_CH2 */
	TIMER13,		 /* 11 PC3 TIM1_CH3 */
	TIMER14,		 /* 12 PC4 TIM1_CH4 */
	NOT_ON_TIMER,	 /* 13 PC5 SPI_SCK/[TIM5_CH1]*/
	NOT_ON_TIMER,	 /* 14 PC6 SPI_MOSI/[TIM1_CH1] */
	NOT_ON_TIMER,	 /* 15 PC7 SPI_MISO/[TIM1_CH2] */
	NOT_ON_TIMER,	 /* 16 PD0 TIM1_BKIN        */
	NOT_ON_TIMER,	 /* 16 PD1 SWIM    */
	NOT_ON_TIMER,	 /* 17 PD2 TIM5_CH3/[AIN3]*/
	NOT_ON_TIMER,	 /* 18 PD3 TIM5_CH2/[AIN4]/[ADC_ETR] */
	NOT_ON_TIMER,	 /* 19 PD4 TIM5_CH1/[BEEP]/[UART1_CK] */
	NOT_ON_TIMER,	 /* 20 PD5 UART2_TX */
	NOT_ON_TIMER,	 /* 21 PD6 UART2_RX */
	NOT_ON_TIMER,	 /* 22 PD7 TLI/[TIM1_CH4] */
	NOT_ON_TIMER,	 /* 23 PE5 SPI_NSS  */
	NOT_ON_TIMER,	 /* 24 PF4 UART1_RX */
};

const uint8_t digitalPinToAnalogChannelMap[] = {
	PB0,		// A0	PB0/Ain0
	PB1,		// A1	PB1/Ain1
	PB2,		// A2	PB2/Ain2
	PB3,  	    // A3   PB3/Ain3
//	PD4,        // A4   PD4[AIN4]
};

#endif
#define digitalPinHasPWM(p)	(((p)==PC1)|((p)==PC2)|((p)==PC3)|((p)==PC4))

#endif //SDUINOPINS_DEF

#endif //_STM8_TIM32_3_h
