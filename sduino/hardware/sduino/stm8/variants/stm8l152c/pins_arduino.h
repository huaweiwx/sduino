/*
  pins_arduino.h - Pin definition functions for Arduino
  Part of Arduino - http://www.arduino.cc/

  Copyright (c) 2007 David A. Mellis

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General
  Public License along with this library; if not, write to the
  Free Software Foundation, Inc., 59 Temple Place, Suite 330,
  Boston, MA  02111-1307  USA
  
  Modified 2 February 2018 for STM8L by huaweiwx 
*/

#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#ifndef _BV
#define _BV(X) (1<<(X))
#endif


/* on the STM8L the logical pin numbers are really confusing instead
 * of beeing helpful. So maybe it is better to use these Portpin-Names
 * instead?
 */
enum portpin {
	PA0,  /*0 1             */
	PA1,  /*1 2 NRST        */
	PA2,  /*2 3 RCC_OSC_IN  */
	PA3,  /*3 4 RCC_OSC_OUT */
	PA4,  /*4 5             */
	PA5,  /*5 6             */
	PA6,  /*6 7             */
	PA7,  /*7 8             */
	PB0,  /*8 31            */
	PB1,  /*9 32            */
	PB2,  /*10 33            */
	PB3,  /*11 34            */
	PB4,  /*12 35            */
	PB5,  /*13 36            */
	PB6,  /*14 37            */
	PB7,  /*15 38            */
	PC0,  /*16 53            */
	PC1,  /*17 54            */
	PC2,  /*18 57            */
	PC3,  /*19 58            */
	PC4,  /*20 59            */
	PC5,  /*21 60            */
	PC6,  /*22 61            */
	PC7,  /*23 62            */
	PD0,  /*24 25            */
	PD1,  /*25 26            */
	PD2,  /*26 27            */
	PD3,  /*27 28            */
	PD4,  /*28 45            */
	PD5,  /*29 46            */
	PD6,  /*30 47            */
	PD7,  /*31 48            */
	PE0,  /*32 19            */
	PE1,  /*33 20            */
	PE2,  /*34 21            */
	PE3,  /*35 22            */
	PE4,  /*36 23            */
	PE5,  /*37 24            */
	PE6,  /*38 63            */
	PE7,  /*39 64            */
	PF0,  /*40 39            */
	NUM_DIGITAL_PINS,
};

#define NUM_ANALOG_INPUTS           10
#define analogInputToDigitalPin(p)  ((p < NUM_ANALOG_INPUTS) ? (p) + (NUM_DIGITAL_PINS-NUM_ANALOG_INPUTS) : -1)



// PWM on pins 3,9-11,13,25-28
// #define digitalPinHasPWM(p)	( (p)==2 | (p)==5 | (p)==6 | (p)==12 )
 #define digitalPinHasPWM(p)	( (p)==3 \
 				| (p)==9 | (p)==10 | (p)==11 \
 				| (p)==13| \
				| ( (p)>=25 & (p)<=28 ) \
 )

#define PIN_SPI_SS    (PE5)	// 27
#define PIN_SPI_MOSI  (PC6)	// 21
#define PIN_SPI_MISO  (PC7)	// 20
#define PIN_SPI_SCK   (PC5)	// 22

/* SDCC workaround: These const variables wouldn't be replaced by hard
 * constant loads. So use defines instead.
static const uint8_t SS   = PIN_SPI_SS;
static const uint8_t MOSI = PIN_SPI_MOSI;
static const uint8_t MISO = PIN_SPI_MISO;
static const uint8_t SCK  = PIN_SPI_SCK;
*/
#define SS	PIN_SPI_SS
#define	MOSI	PIN_SPI_MOSI
#define	MISO	PIN_SPI_MISO
#define	SCK	PIN_SPI_SCK

#define PIN_WIRE_SDA        (PE2)	// 16
#define PIN_WIRE_SCL        (PE1)	// 15

/* SDCC workaround
static const uint8_t SDA = PIN_WIRE_SDA;
static const uint8_t SCL = PIN_WIRE_SCL;
*/
#define	SDA	PIN_WIRE_SDA
#define	SCL	PIN_WIRE_SCL

#define PIN_LED_BUILTIN (PD0)	// sduino: pin for the buildin LED, pin 13
#define PIN_TX	(PD5)		// sduino: pin for TX line, pin 8
#define PIN_RX	(PD6)		// sduino: pin for RX line, pin 7

#define LED_BUILTIN (PD0)	// pin for the buildin LED, pin 13

#define PIN_A0   (PE6)		// 28, Ain9
#define PIN_A1   (PE7)		// 29, Ain8
#define PIN_A2   (PB0)		// 30, Ain0
#define PIN_A3   (PB1)		// 31, Ain1
#define PIN_A4   (PB2)		// 32, Ain2
#define PIN_A5   (PB3)		// 33, Ain3
#define PIN_A6   (PB4)		// 34, Ain4
#define PIN_A7   (PB5)		// 35, Ain5
#define PIN_A8   (PB6)		// 36, Ain6
#define PIN_A9   (PB7)		// 37, Ain7

/* SDCC workaround
static const uint8_t A0 = PIN_A0;
static const uint8_t A1 = PIN_A1;
static const uint8_t A2 = PIN_A2;
static const uint8_t A3 = PIN_A3;
static const uint8_t A4 = PIN_A4;
*/
#define	A0	PIN_A0
#define	A1	PIN_A1
#define	A2	PIN_A2
#define	A3	PIN_A3
#define	A4	PIN_A4
#define	A5	PIN_A5
#define	A6	PIN_A6
#define	A7	PIN_A7
#define	A8	PIN_A8
#define	A9	PIN_A9

//#define NO_ANALOG	0xff

// map the logical pin numbers to the physical ADC channels:
// pin 28,29  -> channel 9,8 (reverse order!)
// pin 30..38 -> channel 0-7
// smaller numbers are not modified but used as channel numbers directly.
#define analogPinToChannel(P) ( (P)>=30 ? (P)-30 : ( \
				(P)>=28 ? 37-(P) : \
					  (P) \
				))


/*FIXME
#define digitalPinToPCICR(p)    (((p) >= 0 && (p) <= 21) ? (&PCICR) : ((uint8_t *)0))
#define digitalPinToPCICRbit(p) (((p) <= 7) ? 2 : (((p) <= 13) ? 0 : 1))
#define digitalPinToPCMSK(p)    (((p) <= 7) ? (&PCMSK2) : (((p) <= 13) ? (&PCMSK0) : (((p) <= 21) ? (&PCMSK1) : ((uint8_t *)0))))
#define digitalPinToPCMSKbit(p) (((p) <= 7) ? (p) : (((p) <= 13) ? ((p) - 8) : ((p) - 14)))

#define digitalPinToInterrupt(p)  ((p) == 2 ? 0 : ((p) == 3 ? 1 : NOT_AN_INTERRUPT))
*/

#ifdef ARDUINO_MAIN

// STM8S105C6 Discovery board

// Pin mapping for the four connectors CN1..CN4:
//
//
//			 RX          LED SCL
//		 Pin	  7   9~ 11~ 13~ 15  17
//		 Port	 PD6 PD4 PD2 PD0 PE1 PE3
//			+--------       --------+
//		 CN4	|11   9   7   5   3   1 |
//		 CN4	|12  10   8   6   4   2 |
//			+-----------------------+
//		 Port    PD7 PD5 PD3 PD1 PE0 PE2
//		 Pin	  6   8  10~ 12  14  16
//		             TX              SDA
//
// Pin Port   CN1   Port Pin		Pin Port   CN2   Port Pin
//          +-----+				 +-----+
//  -  NRST |*1  2| PA1   5		18  PG1  |12 11| PG0  19	
//  4  PA2  | 3  4| VssIO -	   MISO 20  PC7  |10  9| PC6  21 MOSI
//  -  Vss    5  6| Vcap  -		 - VddIO | 8  7  VssIO -
//  -  Vdd    7  8| VssIO -	    SCK 22  PC5  | 6  5  PC4  23~
//  3~ PA3  | 9 10| PA4   2		24~ PC3  | 4  3| PC2  25~
//  1  PA5  |11 12| PA6   0		26~ PC1  | 2 *1| PE5  27 SS
//          +-----+				 +-----+
//
//			     A8  A6  A4  A2  A0
//		 Pin	  -  36  34  32  30  28
//		 Port	 VssAPB6 PB4 PB2 PB0 PE6
//			+-----------------------+
//		 CN3	| 2   4   6   8  10  12 |
//		 CN3	| 1   3   5   7   9  11 |
//			+--------       --------+
//		 Port	 VddAPB7 PB5 PB3 PB1 PE7
//		 Pin	  -  37  35  33  31  29
//			     A9  A7  A5  A3  A1

// these arrays map port names (e.g. port B) to the
// appropriate addresses for various functions (e.g. reading
// and writing)
const uint16_t PROGMEM port_to_mode_PGM[] = {
	NOT_A_PORT,
	GPIOA_BASE+2,
	GPIOB_BASE+2,
	GPIOC_BASE+2,
	GPIOD_BASE+2,
	GPIOE_BASE+2,
	GPIOF_BASE+2,
/*
	(uint16_t) &GPIOA->DDR,
	(uint16_t) &GPIOB->DDR,
	(uint16_t) &GPIOC->DDR,
	(uint16_t) &GPIOD->DDR,
*/
};

const uint16_t PROGMEM port_to_output_PGM[] = {
	NOT_A_PORT,
	GPIOA_BASE,
	GPIOB_BASE,
	GPIOC_BASE,
	GPIOD_BASE,
	GPIOE_BASE,
	GPIOF_BASE,
/*
	(uint16_t) &GPIOA->ODR,
	(uint16_t) &GPIOB->ODR,
	(uint16_t) &GPIOC->ODR,
	(uint16_t) &GPIOD->ODR,
*/
};

const uint16_t PROGMEM port_to_input_PGM[] = {
	NOT_A_PORT,
	GPIOA_BASE+1,
	GPIOB_BASE+1,
	GPIOC_BASE+1,
	GPIOD_BASE+1,
	GPIOE_BASE+1,
	GPIOE_BASE+1,
/*
	(uint16_t) &GPIOA->IDR,
	(uint16_t) &GPIOB->IDR,
	(uint16_t) &GPIOC->IDR,
	(uint16_t) &GPIOD->IDR,
*/
};

const uint8_t PROGMEM digital_pin_to_port_PGM[] = {
	PA,  /*0  PA0 1  		    */
	PA,  /*1  PA1 2 NRST        */
	PA,  /*2  PA2 3 RCC_OSC_IN  */
	PA,  /*3  PA3 4 RCC_OSC_OUT */
	PA,  /*4  PA4 5             */
	PA,  /*5  PA5 6             */
	PA,  /*6  PA6 7             */
	PA,  /*7  PA7 8             */
	PB,  /*8  PB0 31            */
	PB,  /*9  PB1 32            */
	PB,  /*10 PB2 33            */
	PB,  /*11 PB3 34            */
	PB,  /*12 PB4 35            */
	PB,  /*13 PB5 36            */
	PB,  /*14 PB6 37            */
	PB,  /*15 PB7 38            */
	PC,  /*16 PC0 53            */
	PC,  /*17 PC1 54            */
	PC,  /*18 PC2 57            */
	PC,  /*19 PC3 58            */
	PC,  /*20 PC4 59            */
	PC,  /*21 PC5 60            */
	PC,  /*22 PC6 61            */
	PC,  /*23 PC7 62            */
	PD,  /*24 PD0 25            */
	PD,  /*25 PD1 26            */
	PD,  /*26 PD2 27            */
	PD,  /*27 PD3 28            */
	PD,  /*28 PD4 45            */
	PD,  /*29 PD5 46            */
	PD,  /*30 PD6 47            */
	PD,  /*31 PD7 48            */
	PE,  /*32 PE0 19            */
	PE,  /*33 PE1 20            */
	PE,  /*34 PE2 21            */
	PE,  /*35 PE3 22            */
	PE,  /*36 PE4 23            */
	PE,  /*37 PE5 24            */
	PE,  /*38 PE6 63            */
	PE,  /*39 PE7 64            */
	PF,  /*40 PF0 39            */
};

const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[] = {
	_BV(0),  /*0  PA0 1  		    */
	_BV(1),  /*1  PA1 2 NRST        */
	_BV(2),  /*2  PA2 3 RCC_OSC_IN  */
	_BV(3),  /*3  PA3 4 RCC_OSC_OUT */
	_BV(4),  /*4  PA4 5             */
	_BV(5),  /*5  PA5 6             */
	_BV(6),  /*6  PA6 7             */
	_BV(7),  /*7  PA7 8             */
	_BV(0),  /*8  PB0 31            */
	_BV(1),  /*9  PB1 32            */
	_BV(2),  /*10 PB2 33            */
	_BV(3),  /*11 PB3 34            */
	_BV(4),  /*12 PB4 35            */
	_BV(5),  /*13 PB5 36            */
	_BV(6),  /*14 PB6 37            */
	_BV(7),  /*15 PB7 38            */
	_BV(0),  /*16 PC0 53            */
	_BV(1),  /*17 PC1 54            */
	_BV(2),  /*18 PC2 57            */
	_BV(3),  /*19 PC3 58            */
	_BV(4),  /*20 PC4 59            */
	_BV(5),  /*21 PC5 60            */
	_BV(6),  /*22 PC6 61            */
	_BV(7),  /*23 PC7 62            */
	_BV(0),  /*24 PD0 25            */
	_BV(1),  /*25 PD1 26            */
	_BV(2),  /*26 PD2 27            */
	_BV(3),  /*27 PD3 28            */
	_BV(4),  /*28 PD4 45            */
	_BV(5),  /*29 PD5 46            */
	_BV(6),  /*30 PD6 47            */
	_BV(7),  /*31 PD7 48            */
	_BV(0),  /*32 PE0 19            */
	_BV(1),  /*33 PE1 20            */
	_BV(2),  /*34 PE2 21            */
	_BV(3),  /*35 PE3 22            */
	_BV(4),  /*36 PE4 23            */
	_BV(5),  /*37 PE5 24            */
	_BV(6),  /*38 PE6 63            */
	_BV(7),  /*39 PE7 64            */
	_BV(0),  /*40 PF0 39            */
};

const uint8_t PROGMEM digital_pin_to_timer_PGM[] = {
	NOT_ON_TIMER,   /*0  PA0 1  		   */
	NOT_ON_TIMER,   /*1  PA1 2 NRST        */
	NOT_ON_TIMER,   /*2  PA2 3 RCC_OSC_IN  */
	NOT_ON_TIMER,   /*3  PA3 4 RCC_OSC_OUT */
	NOT_ON_TIMER,   /*4  PA4 5             */
	NOT_ON_TIMER,   /*5  PA5 6             */
	NOT_ON_TIMER,   /*6  PA6 7             */
	NOT_ON_TIMER,   /*7  PA7 8             */
  	TIMER21,		/*8  PB0 31            */
  	TIMER31,		/*9  PB1 32            */	
  	TIMER22,		/*10 PB2 33            */
	NOT_ON_TIMER,   /*11 PB3 34            */
	NOT_ON_TIMER,   /*12 PB4 35            */
    NOT_ON_TIMER,   /*13 PB5 36            */
	NOT_ON_TIMER,   /*14 PB6 37            */
	NOT_ON_TIMER,   /*15 PB7 38            */
  	NOT_ON_TIMER,	/*16 PC0 53            */
  	NOT_ON_TIMER,	/*17 PC1 54            */
  	NOT_ON_TIMER,	/*18 PC2 57            */
  	NOT_ON_TIMER,	/*19 PC3 58            */
  	NOT_ON_TIMER,	/*20 PC4 59            */
  	NOT_ON_TIMER,	/*21 PC5 60            */
  	NOT_ON_TIMER,	/*22 PC6 61            */
  	NOT_ON_TIMER,	/*23 PC7 62            */
  	TIMER32,		/*24 PD0 25            */
    NOT_ON_TIMER,	/*25 PD1 26            */
  	TIMER11,		/*26 PD2 27            */
    NOT_ON_TIMER,	/*27 PD3 28            */
  	TIMER12,		/*28 PD4 45            */ 
  	TIMER13,		/*29 PD5 46            */
  	NOT_ON_TIMER,	/*30 PD6 47            */
  	NOT_ON_TIMER,	/*31 PD7 48            */
/* TIMER52,*/    NOT_ON_TIMER,   /*32 PE0 19            */
  	NOT_ON_TIMER,	/*33 PE1 20            */
  	NOT_ON_TIMER,	/*34 PE2 21            */
  	NOT_ON_TIMER,	/*35 PE3 22            */
  	NOT_ON_TIMER,	/*36 PE4 23            */
  	NOT_ON_TIMER,	/*37 PE5 24            */
  	NOT_ON_TIMER,	/*38 PE6 63            */
  	NOT_ON_TIMER,  	/*39 PE7 64            */
  	NOT_ON_TIMER,	/*40 PF0 39            */
};

#endif  // ARDUINO_MAIN

#define NEED_TIMER_11_12
#define NEED_TIMER_31_32

// These serial port names are intended to allow libraries and architecture-neutral
// sketches to automatically default to the correct port name for a particular type
// of use.  For example, a GPS module would normally connect to SERIAL_PORT_HARDWARE_OPEN,
// the first hardware serial port whose RX/TX pins are not dedicated to another use.
//
// SERIAL_PORT_MONITOR        Port which normally prints to the Arduino Serial Monitor
//
// SERIAL_PORT_USBVIRTUAL     Port which is USB virtual serial
//
// SERIAL_PORT_LINUXBRIDGE    Port which connects to a Linux system via Bridge library
//
// SERIAL_PORT_HARDWARE       Hardware serial port, physical RX & TX pins.
//
// SERIAL_PORT_HARDWARE_OPEN  Hardware serial ports which are open for use.  Their RX & TX
//                            pins are NOT connected to anything by default.
#define SERIAL_PORT_MONITOR   Serial
#define SERIAL_PORT_HARDWARE  Serial

#endif
