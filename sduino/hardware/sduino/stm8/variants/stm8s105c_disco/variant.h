/*
  variant.h - Pin definition functions for Arduino
*/

#ifndef _VARINAT_H_
#define _VARINAT_H_

/* on the STM8S the logical pin numbers are really confusing instead
 * of beeing helpful. So maybe it is better to use these Portpin-Names
 * instead?
 */
#define VARIANT_PIN_LIST \
PIN(A,6),PIN(A,5),PIN(A,4),PIN(A,3),PIN(A,2),PIN(A,1),\
PIN(D,7),PIN(D,6),PIN(D,5),PIN(D,4),PIN(D,3),PIN(D,2),PIN(D,1),PIN(D,0),\
PIN(E,0),PIN(E,1),PIN(E,2),PIN(E,3),\
PIN(G,1),PIN(G,0),\
PIN(C,7),PIN(C,6),PIN(C,5),PIN(C,4),PIN(C,3),PIN(C,2),PIN(C,1),\
PIN(E,5),PIN(E,6),PIN(E,7),\
PIN(B,0),PIN(B,1),PIN(B,2),PIN(B,3),PIN(B,5),PIN(B,4),PIN(B,6),PIN(B,7),\

#define	PA6		0
#define	PA5		1
#define	PA4		2
#define	PA3		3
#define	PA2		4
#define	PA1		5
#define	PD7		6
#define	PD6		7
#define	PD5		8
#define	PD4		9
#define	PD3		10
#define	PD2		11
#define	PD1		12
#define	PD0		13
#define	PE0		14
#define	PE1		15
#define	PE2		16
#define	PE3		17
#define	PG1		18
#define	PG0		19
#define	PC7		20
#define	PC6		21
#define	PC5		22
#define	PC4		23
#define	PC3		24
#define	PC2		25
#define	PC1		26
#define	PE5		27
#define	PE6		28
#define	PE7		29
#define	PB0		30
#define	PB1		31
#define	PB2		32
#define	PB3		33
#define	PB4		34
#define	PB5		35
#define	PB6		36
#define	PB7		37

#define NUM_DIGITAL_PINS            38
#define NUM_ANALOG_INPUTS           10
#define analogInputToDigitalPin(p)  ((p < NUM_ANALOG_INPUTS) ? (p) + (NUM_DIGITAL_PINS-NUM_ANALOG_INPUTS) : -1)



// PWM on pins 3,9-11,13,25-28
// #define digitalPinHasPWM(p)	( (p)==2 | (p)==5 | (p)==6 | (p)==12 )
 #define digitalPinHasPWM(p)	( (p)==3 \
 				| (p)==9 | (p)==10 | (p)==11 \
 				| (p)==13| \
				| ( (p)>=25 & (p)<=28 ) \
 )


#define LED_BUILTIN (PD0)	// pin for the buildin LED, pin 13


#define analogPinToChannel(P) ( (P)>=30 ? (P)-30 : ( \
				(P)>=28 ? 37-(P) : \
					  (P) \
				))


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

const uint8_t PROGMEM digital_pin_to_timer_PGM[] = {
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	TIMER23,	// 3
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	TIMER21,	// 9
	TIMER22,	// 10
	TIMER31,	// 11
	NOT_ON_TIMER,
	TIMER32,	// 13
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	TIMER14,	// 23
	TIMER13,	// 24
	TIMER12,	// 25
	TIMER11,	// 26
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
};

#endif

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
