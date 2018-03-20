/*
  vardiant.h - Pin definition functions for Arduino
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
*/

#ifndef _VARINAT_H_
#define _VARINAT_H_


/* functional pin mapping for the STM8S105 used on the sduino-uno board.
 *
 * This pin mapping tries to reassemble the original Arduino Uno mapping
 * for the ATmega328 as closely as possible.
 */
 
 #define VARIANT_PIN_LIST \
             PIN(A,1),PIN(A,2),\
	PIN(B,0),PIN(B,1),PIN(B,2),PIN(B,3),PIN(B,4),PIN(B,5),PIN(B,6),PIN(B,7),\
	         PIN(C,1),PIN(C,2),PIN(C,3),PIN(C,4),PIN(C,5),PIN(C,6),PIN(C,7),\
	PIN(D,0),PIN(D,1),PIN(D,2),PIN(D,3),PIN(D,4),PIN(D,5),PIN(D,6),PIN(D,7),\
	PIN(F,4),\
    PIN(E,5),\

#define	PA1 0 	/* AD1 		PA1 	*/
#define	PA2 1	/* AD2 		PA2 	*/
#define	PB0 2 	/* AD0 		PB0/AIN0 [TIM1_CH1N]	*/
#define	PB1 3 	/* AD1 		PB1/AIN1 [TIM1_CH2N]	*/
#define	PB2 4	/* AD2 		PB2/AIN2 [TIM1_CH3N]	*/
#define	PB3 5 	/* AD3 		PB3/AIN3 [TIM1_ETR]	*/
#define	PB4 6	/* AD5/SCL 	PB4/AIN4 [I2C_SCL]	*/
#define	PB5 7	/* AD4/SDA 	PB5/AIN5 [I2C_SDA]	*/
#define	PB6 8 	/*          PB6 dumm*/
#define	PB7 9	/*          PB7 dumm*/
#define	PC1 10	/* IO8~		PC1 (HS)/TIM1_CH1/UART2_CK */
#define	PC2 11	/* IO23~ 	PC2 (HS)/TIM1_CH2	*/
#define	PC3 12	/* IO9~		PC3 (HS)/TIM1_CH3	*/
#define	PC4 13	/* IO10~ 	PC4 (HS)/TIM1_CH4	*/
#define	PC5 14	/* IO13/SCK 	PC5 (HS)/SPI_SCK	*/
#define	PC6 15	/* IO11/MOSI 	PC6 (HS)/SPI_MOSI	*/
#define	PC7 16	/* IO12/MISO 	PC7 (HS)/SPI_MISO	*/
#define	PD0 17	/* IO4~		PD0 (HS)/TIM3_CH2 [TIM1_BKIN]/[CLK_COO] */
#define	PD1 18	/* IO7 		PD1 (HS)/SWIM		*/
#define	PD2 19	/* IO3~		PD2 (HS)/TIM3_CH1 [TIM2_CH3] */
#define	PD3 20	/* IO6~		PD3 (HS)/TIM2_CH2/ADC_ETR */
#define	PD4 21	/* IO5~		PD4 (HS)/TIM2_CH1 [BEEP] */
#define	PD5 22	/* IO1/TX 	PD5/UART2_TX		*/
#define	PD6 23	/* IO0/RX	PD6/UART2_RX		*/
#define	PD7 24	/* IO2 		PD7/TLI [TIM1_CH4]	*/
#define	PE5 25  /* IO24/SS 	PE5/SPI_NSS		*/
#define	PF4 26  /* AREF		PF4/AIN12		*/
#define NUM_DIGITAL_PINS            27

#define NUM_ANALOG_INPUTS           9  // skipping A6 and A7, AREF is A8
#define analogInputToDigitalPin(p)  ((p < 9) ? (p) + 14 : -1)


// PWM on pins 3-6, 8-10, 14
 #define digitalPinHasPWM(p)	( ( (p)>=3 & (p)<=10 & (p)!=7 ) \
 				| (p)==14 \
 )

#define LED_BUILTIN (PC5)	// pin for the buildin LED, pin 13

//#define NO_ANALOG	0xff

// map the logical pin numbers to the physical ADC channels:  FIXME: produces rubbish for pins 20 and 21
// pin 22     -> channel 12
// pin 18,19  -> channel 5,4 (reverse order!)
// pin 14..17 -> channel 0-3
// smaller numbers are not modified but used as channel numbers directly.
#define analogPinToChannel(P) ( (P)==22 ? 12 : ( \
				(P)>=18 ? 23-(P) : ( \
				(P)>=14 ? (P)-14 : \
					  (P) \
				)))

/* alternative way to define the mapping:
#define analogPinToChannel(P) ( (P)<14 ? (P) : ( \
				(P)<18 ? (P)-14 : ( \
				(p)!=22 ? 23-(P) : \
					  12 \
				)))
*/


/*FIXME
#define digitalPinToPCICR(p)    (((p) >= 0 && (p) <= 21) ? (&PCICR) : ((uint8_t *)0))
#define digitalPinToPCICRbit(p) (((p) <= 7) ? 2 : (((p) <= 13) ? 0 : 1))
#define digitalPinToPCMSK(p)    (((p) <= 7) ? (&PCMSK2) : (((p) <= 13) ? (&PCMSK0) : (((p) <= 21) ? (&PCMSK1) : ((uint8_t *)0))))
#define digitalPinToPCMSKbit(p) (((p) <= 7) ? (p) : (((p) <= 13) ? ((p) - 8) : ((p) - 14)))

#define digitalPinToInterrupt(p)  ((p) == 2 ? 0 : ((p) == 3 ? 1 : NOT_AN_INTERRUPT))
*/

#ifdef ARDUINO_MAIN

// STMicroelectronics STM8S105K6T, -K6U
//
//                    pwm         PWM PWM PWM     PWM
//                    D2  D0  D1  D5  D6  D3  D7  D4
//                    PD7 PD6 PD5 PD4 PD3 PD2 PD1 PD0
//                    32  31  30  29  28  27  26  25
//                  +--------------------------------+
//          NRST  1 | o                              | 24  PC7  D12
//                  |                                |
//           PA1  2 |                                | 23  PC6  D11
//                  |                                |
//           PA2  3 |                                | 22  PC5  D13
//                  |                                |
//           VSS  4 |                                | 21  PC4  D10  PWM
//                  |                                |
//          VCAP  5 |                                | 20  PC3  D9   PWM
//                  |                                |
//           VDD  6 |                                | 19  PC2  D23  PWM
//                  |                                |
//         VDDIO  7 |                                | 18  PC1  D8   PWM
//                  |                                |
// AREF/A8   PF4  8 |                                | 17  PE5  D24
//                  +--------------------------------+
//                     9  10  11  12  13  14  15  16
//                  VDDA VSSA PB5 PB4 PB3 PB2 PB1 PB0
//                            A4  A5  A3  A2  A1  A0
//                                        pwm pwm pwm
//
// (PWM: always available as PWM)
// (pwm: PWM as alternate function -- en-/disabled for all such pins at once)

const uint8_t PROGMEM digital_pin_to_timer_PGM[] = {
	NOT_ON_TIMER,  /* 0  PA1	*/
	NOT_ON_TIMER,  /* 1  PA2	*/
	NOT_ON_TIMER,  /* 2  PB0/AIN0 [TIM1_CH1N]	*/
	NOT_ON_TIMER,  /* 3  PB1/AIN1 [TIM1_CH2N]	*/
	NOT_ON_TIMER,  /* 4  PB2/AIN2 [TIM1_CH3N]	*/
	NOT_ON_TIMER,  /* 5  PB3/AIN3 [TIM1_ETR]	*/
	NOT_ON_TIMER,  /* 6  PB4/AIN4 [I2C_SCL]	*/
	NOT_ON_TIMER,  /* 7  PB5/AIN5 [I2C_SDA]	*/
	NOT_ON_TIMER,  /* 8  PB6 dumm*/
	NOT_ON_TIMER,  /* 9  PB7 dumm*/
	TIMER11,	   /* 10 PC1 (HS)/TIM1_CH1/UART2_CK */
	TIMER12,	   /* 11 PC2 (HS)/TIM1_CH2	*/
	TIMER13,	   /* 12 PC3 (HS)/TIM1_CH3	*/
	TIMER14,	   /* 13 PC4 (HS)/TIM1_CH4	*/
	NOT_ON_TIMER,  /* 14 PC5 (HS)/SPI_SCK	*/
	NOT_ON_TIMER,  /* 15 PC6 (HS)/SPI_MOSI	*/
	NOT_ON_TIMER,  /* 16 PC7 (HS)/SPI_MISO	*/
	TIMER32,	   /* 17 PD0 (HS)/TIM3_CH2 [TIM1_BKIN]/[CLK_COO] */
	NOT_ON_TIMER,  /* 18 PD1 (HS)/SWIM		*/
	TIMER31,	   /* 19 PD2 (HS)/TIM3_CH1 [TIM2_CH3] */
	TIMER22,	   /* 20 PD3 (HS)/TIM2_CH2/ADC_ETR */
	TIMER21,	   /* 21 PD4 (HS)/TIM2_CH1 [BEEP] */
	NOT_ON_TIMER,  /* 22 PD5/UART2_TX		*/
	NOT_ON_TIMER,  /* 23 PD6/UART2_RX		*/
	NOT_ON_TIMER,  /* 24 PD7/TLI [TIM1_CH4]	*/
	NOT_ON_TIMER,  /* 25 PE5/SPI_NSS		*/
	NOT_ON_TIMER,  /* 26 PF4/AIN12		*/
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
