//  tim_20_1.h
//  STM8S003F3Px/Ux    20 pins
//  STM8S103F3Px/Mx/Ux 20pins
//  huaweiwx@sina.com 2018.4.08
 

#ifndef _STM8_TIM20_1_h
#define _STM8_TIM20_1_h
#ifndef SDUINOPINS_DEF
#ifdef ARDUINO_MAIN

// STM8S103F3P6 breakout board
//
//                       +-\/-+
// PWM      (D 13) PD4  1|    |20  PD3 (D 12, AI 2) PWM
// TX (D 14, AI 3) PD5  2|    |19  PD2 (D 11, AI 1)
// RX (D 15, AI 4) PD6  3|    |18  PD1 (D 10)       SWIM
//                NRST  4|    |17  PC7 (D 9)   MISO/PWM+
//           (D 0) PA1  5|    |16  PC6 (D 8)   MOSI/PWM+
//           (D 1) PA2  6|    |15  PC5 (D 7)    SCK
//                 GND  7|    |14  PC4 (D 6, AI 0)  PWM
//                Vcap  8|    |13  PC3 (D 5)        PWM
//                 Vdd  9|    |12  PB4 (D 4)        SCL
// PWM       (D 2) PA3 10|    |11  PB5 (D 3)   LED, SDA
//                       +----+
//
// (PWM+ indicates the additional PWM pins on alternate
// function pins)

const uint8_t PROGMEM digital_pin_to_timer_PGM[] = {
	NOT_ON_TIMER, //PA1
	NOT_ON_TIMER, //PA2
	TIMER53,	  //PA3
	NOT_ON_TIMER, //PB4
	NOT_ON_TIMER, //PB5
	TIMER13,	  //PC3
	TIMER14,	  //PC4
	NOT_ON_TIMER, //PC5
	NOT_ON_TIMER, //PC6
	NOT_ON_TIMER, //PC7
	NOT_ON_TIMER, //PD1
	NOT_ON_TIMER, //PD2
	TIMER52,	  //PD3
	TIMER51,	  //PD4
	NOT_ON_TIMER, //PD5
	NOT_ON_TIMER, //PD6
};

#define NO_ANALOG	0xff
const uint8_t digitalPinToAnalogChannelMap[] = {
	2,		    //  A0	D6	PC4	Ain2
	NO_ANALOG,	//	D7	PC5
	NO_ANALOG,	//	D8	PC6
	NO_ANALOG,	//	D9	PC7
	NO_ANALOG,	//	D10	PD1
	3,		    //  A1	D11	PD2	Ain3
	4,		    //  A2	D12	PD3	Ain4
	NO_ANALOG,	//	D13	PD4
	5,		    //  A3	D14	PD5	Ain5
	6		    //  A4	D15	PD6	Ain6
};

#endif /* ARDUINO_MAIN */

#define digitalPinHasPWM(p)	(((p)==PA3)|((p)==PC3)|((p)==PC4)|((p)==PC5)|((p)==PD3)|((p)==PD4))

#endif //SDUINOPINS_DEF

#endif /* ARDUINO_MAIN */

#endif //_STM8_TIM20_1_h
