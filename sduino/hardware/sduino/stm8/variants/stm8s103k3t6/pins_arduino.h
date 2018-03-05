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

/* on the STM8S the logical pin numbers are really confusing instead
 * of beeing helpful. So maybe it is better to use these Portpin-Names
 * instead?
 */
enum portpin {
	PA1, /* 0  PA1 OSC IN */
	PA2, /* 1  PA2 OSC OUT */
	PA3, /* 2  PA3 SPI_NSS/TIM2_CH3*/
	PF4, /* 3  PF4 */
    PB7, /* 4  PB7 */
    PB6, /* 5  PB6 */
	PB5, /* 6  PB5 I2C_SDA */
	PB4, /* 7  PB4 I2C_SCL */
	PB3, /* 8  PB3 AIN3/TIM1_ETR */
	PB2, /* 9  PB2 AIN2/TIM1_CH3N */
	PB1, /* 10  PB1 AIN1/TIM1_CH2N */
	PB0, /* 11  PB0 AIN0/TIM1_CH1N */
	PE5, /* 12  PE5 SPI_NSS */
	PC1, /* 13 PC1 TIM1_CH1 / UART1_CK */
	PC2, /* 14 PC2 TIM1_CH2 */
	PC3, /* 15 PC3 TIM1_CH3 */
	PC4, /* 16 PC4 TIM1_CH4/CLK_CCO */
	PC5, /* 17 PC5 SPI_SCK */
	PC6, /* 18 PC6 SPI_MOSI */
	PC7, /* 19 PC7 SPI_MISO */
	PD0, /* 20 PD0 TIM1_BKIN/CLK_CCO]*/
	PD1, /* 21 PD1 SWIM */
	PD2, /* 22 PD2 [TIM2_CH3] */
	PD3, /* 23 PD3 TIM2_CH2/ADC_ETR */
	PD4, /* 24 PD4 TIM2_CH1/BEEP*/
	PD5, /* 25 PD5 UART1_TX */
	PD6, /* 26 PD6 UART1_RX */
	PD7, /* 27 PD7 TLI/[TIM1_CH4] */
	NUM_DIGITAL_PINS,
};


#define NUM_ANALOG_INPUTS           12
#define analogInputToDigitalPin(p)  ((p < NUM_ANALOG_INPUTS) ? (p) + 2 : -1)



// PWM on pins 12-13,13,25-28
 // using alternate functions adds 3 more PWM pins, total of 7 PWM pins
 #define digitalPinHasPWM(p)	((p)==2 |((p)>=9&(p)<=11) | ((p)>=13&(p)<=16) | ((p)>=22&(p)<=24) | (p)==27)


#define PIN_SPI_SS    (PE5)	// 11
#define PIN_SPI_MOSI  (PC6)	// 15
#define PIN_SPI_MISO  (PC7)	// 16
#define PIN_SPI_SCK   (PC5)	// 14

/* SDCC workaround: These const variables wouldn't be replaced by hard
 * constant loads. So use defines instead.
static const uint8_t SS   = PIN_SPI_SS;
static const uint8_t MOSI = PIN_SPI_MOSI;
static const uint8_t MISO = PIN_SPI_MISO;
static const uint8_t SCK  = PIN_SPI_SCK;
*/
#define SS	    PIN_SPI_SS
#define	MOSI	PIN_SPI_MOSI
#define	MISO	PIN_SPI_MISO
#define	SCK	    PIN_SPI_SCK

#define PIN_WIRE_SDA        (PB5)	// 3
#define PIN_WIRE_SCL        (PB4)	// 4

/* SDCC workaround
static const uint8_t SDA = PIN_WIRE_SDA;
static const uint8_t SCL = PIN_WIRE_SCL;
*/
#define	SDA	PIN_WIRE_SDA
#define	SCL	PIN_WIRE_SCL

#define LED_BUILTIN (PD7)	// pin for the buildin LED, pin 13
#define PIN_TX	(PD5)		// sduino: pin for TX line, pin 8
#define PIN_RX	(PD6)		// sduino: pin for RX line, pin 7

#define	A0	(PB3)
#define	A1	(PB2)
#define	A2	(PB1)
#define	A3	(PB0)

//#define NO_ANALOG	0xff

// values 0..3: ADC channel number, no conversion
// values 6..15: digital pin numbers, convert to ADC channel number
#define analogPinToChannel(P) (	(((P)>=A3) &&((P)<A0)) ? A3-(P) : ( \
								(P)<=3 ? (P) : ( \
								(0xff) \
								)))
extern const uint8_t digitalPinToAnalogChannelMap[];

/*FIXME
#define digitalPinToPCICR(p)    (((p) >= 0 && (p) <= 21) ? (&PCICR) : ((uint8_t *)0))
#define digitalPinToPCICRbit(p) (((p) <= 7) ? 2 : (((p) <= 13) ? 0 : 1))
#define digitalPinToPCMSK(p)    (((p) <= 7) ? (&PCMSK2) : (((p) <= 13) ? (&PCMSK0) : (((p) <= 21) ? (&PCMSK1) : ((uint8_t *)0))))
#define digitalPinToPCMSKbit(p) (((p) <= 7) ? (p) : (((p) <= 13) ? ((p) - 8) : ((p) - 14)))
#define digitalPinToInterrupt(p)  ((p) == 2 ? 0 : ((p) == 3 ? 1 : NOT_AN_INTERRUPT))
*/

#ifdef ARDUINO_MAIN

// STM8S103F3 blue board
//     
//                     o----+
//              NRST  1|    |32  PD7 (D 27) LED PWM
//         (D 0) PA1  2|    |31  PD6 (D 26) RX
//         (D 1) PA2  3|    |30  PD5 (D 25) TX
//                    4|    |29  PD4 (D 24) PMW
//                    5|    |28  PD3 (D 23) PMW
//                    6|    |27  PD2 (D 22) PMW
//         (D 2) PA3  7|    |26  PD1 (D 12)
//         (D 3) PF4  8|    |25  PD0 (D 20)
//     
//     
//         (D 4) PB7  9|    |24  PC7 (D 19) MISO
//         (D 5) PB6 10|    |23  PC6 (D 18) MOSI  
// SDA     (D 6) PB5 11|    |22  PC5 (D 17) SCK
// SCL     (D 7) PB4 12|    |21  PC4 (D 16) PMW
// PMW (A0, D 8) PB3 13|    |20  PC3 (D 15) PMW 
// PMW (A1, D 9) PB2 14|    |19  PC2 (D 14) PMW 
// PMW (A2, D10) PB1 15|    |18  PC1 (D 13) PMW 
// PMW (A3, D11) PB0 16|    |17  PE5 (D 12) NSS
//                     +----+

// these arrays map port names (e.g. port B) to the
// appropriate addresses for various functions (e.g. reading
// and writing)
const uint16_t PROGMEM port_to_mode_PGM[] = {
	NOT_A_PORT,
	GPIOA_BaseAddress+2,
	GPIOB_BaseAddress+2,
	GPIOC_BaseAddress+2,
	GPIOD_BaseAddress+2,
	GPIOE_BaseAddress+2,
	GPIOF_BaseAddress+2,
/*
	(uint16_t) &GPIOA->DDR,
	(uint16_t) &GPIOB->DDR,
	(uint16_t) &GPIOC->DDR,
	(uint16_t) &GPIOD->DDR,
*/
};

const uint16_t PROGMEM port_to_output_PGM[] = {
	NOT_A_PORT,
	GPIOA_BaseAddress,
	GPIOB_BaseAddress,
	GPIOC_BaseAddress,
	GPIOD_BaseAddress,
	GPIOE_BaseAddress,
	GPIOF_BaseAddress,
/*
	(uint16_t) &GPIOA->ODR,
	(uint16_t) &GPIOB->ODR,
	(uint16_t) &GPIOC->ODR,
	(uint16_t) &GPIOD->ODR,
*/
};

const uint16_t PROGMEM port_to_input_PGM[] = {
	NOT_A_PORT,
	GPIOA_BaseAddress+1,
	GPIOB_BaseAddress+1,
	GPIOC_BaseAddress+1,
	GPIOD_BaseAddress+1,
	GPIOE_BaseAddress+1,
	GPIOF_BaseAddress+1,
/*
	(uint16_t) &GPIOA->IDR,
	(uint16_t) &GPIOB->IDR,
	(uint16_t) &GPIOC->IDR,
	(uint16_t) &GPIOD->IDR,
*/
};

const uint8_t PROGMEM digital_pin_to_port_PGM[] = {
	PA, /* 0  PA1 OSC IN */
	PA, /* 1  PA2 OSC OUT */
	PA, /* 2  PA3 SPI_NSS/TIM2_CH3*/
	PF, /* 3  PF4 */
	PB, /* 4  PB7 */
	PB, /* 5  PB6 */
	PB, /* 6  PB5 I2C_SDA */
	PB, /* 7  PB4 I2C_SCL */
	PB, /* 8  PB3 AIN3/TIM1_ETR */
	PB, /* 9  PB2 AIN2/TIM1_CH3N */
	PB, /* 10 PB1 AIN1/TIM1_CH2N */
	PB, /* 11 PB0 AIN0/TIM1_CH1N */
	PE, /* 12 PE5 SPI_NSS */
	PC, /* 13 PC1 TIM1_CH1 / UART1_CK */
	PC, /* 14 PC2 TIM1_CH2 */
	PC, /* 15 PC3 TIM1_CH3 */
	PC, /* 16 PC4 TIM1_CH4/CLK_CCO */
	PC, /* 17 PC5 SPI_SCK */
	PC, /* 18 PC6 SPI_MOSI */
	PC, /* 19 PC7 SPI_MISO */
	PD, /* 20 PD0 TIM1_BKIN/CLK_CCO]*/
	PD, /* 21 PD1 SWIM */
	PD, /* 22 PD2 [TIM2_CH3] */
	PD, /* 23 PD3 TIM2_CH2/ADC_ETR */
	PD, /* 24 PD4 TIM2_CH1/BEEP*/
	PD, /* 25 PD5 UART1_TX */
	PD, /* 26 PD6 UART1_RX */
	PD, /* 27 PD7 TLI/[TIM1_CH4] */
};

const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[] = {
	_BV(1), /* 0  PA1 OSC IN */
	_BV(2), /* 1  PA2 OSC OUT */
	_BV(3), /* 2  PA3 SPI_NSS/TIM2_CH3*/
	_BV(4), /* 3  PF4 */
	_BV(7), /* 4  PB7 */
	_BV(6), /* 5  PB6 */
	_BV(5), /* 6  PB5 I2C_SDA */
	_BV(4), /* 7  PB4 I2C_SCL */
	_BV(3), /* 8  PB3 AIN3/TIM1_ETR */
	_BV(2), /* 9  PB2 AIN2/TIM1_CH3N */
	_BV(1), /* 10 PB1 AIN1/TIM1_CH2N */
	_BV(0), /* 11 PB0 AIN0/TIM1_CH1N */
	_BV(5), /* 12 PE5 SPI_NSS */
	_BV(1), /* 13 PC1 TIM1_CH1 / UART1_CK */
	_BV(2), /* 14 PC2 TIM1_CH2 */
	_BV(3), /* 15 PC3 TIM1_CH3 */
	_BV(4), /* 16 PC4 TIM1_CH4/CLK_CCO */
	_BV(5), /* 17 PC5 SPI_SCK */
	_BV(6), /* 18 PC6 SPI_MOSI */
	_BV(7), /* 19 PC7 SPI_MISO */
	_BV(0), /* 20 PD0 TIM1_BKIN/CLK_CCO]*/
	_BV(1), /* 21 PD1 SWIM */
	_BV(2), /* 22 PD2 [TIM2_CH3] */
	_BV(3), /* 23 PD3 TIM2_CH2/ADC_ETR */
	_BV(4), /* 24 PD4 TIM2_CH1/BEEP*/
	_BV(5), /* 25 PD5 UART1_TX */
	_BV(6), /* 26 PD6 UART1_RX */
	_BV(7), /* 27 PD7 TLI/[TIM1_CH4] */
};

const uint8_t PROGMEM digital_pin_to_timer_PGM[] = {
	NOT_ON_TIMER,	/* 0  PA1 OSC IN */
	NOT_ON_TIMER,	/* 1  PA2 OSC OUT */
	TIMER23,		/* 2  PA3 SPI_NSS/TIM2_CH3*/
	NOT_ON_TIMER,	/* 3  PF4 */
	NOT_ON_TIMER,	/* 4  PB7 */
	NOT_ON_TIMER,	/* 5  PB6 */
	NOT_ON_TIMER,	/* 6  PB5 I2C_SDA */
	NOT_ON_TIMER,	/* 7  PB4 I2C_SCL */
	NOT_ON_TIMER,	/* 8  PB3 AIN3/TIM1_ETR */
	TIMER13,		/* 9  PB2 AIN2/TIM1_CH3N */
	TIMER12,		/* 10 PB1 AIN1/TIM1_CH2N */
	TIMER11,		/* 11 PB0 AIN0/TIM1_CH1N */
	NOT_ON_TIMER,	/* 12 PE5 SPI_NSS */
	TIMER11,		/* 13 PC1 TIM1_CH1 / UART1_CK */
	TIMER12,		/* 14 PC2 TIM1_CH2 */
	TIMER13,		/* 15 PC3 TIM1_CH3 */
	TIMER14,		/* 16 PC4 TIM1_CH4/CLK_CCO */
	NOT_ON_TIMER,	/* 17 PC5 SPI_SCK */
	NOT_ON_TIMER,	/* 18 PC6 SPI_MOSI */
	NOT_ON_TIMER,	/* 19 PC7 SPI_MISO */
	NOT_ON_TIMER,	/* 20 PD0 TIM1_BKIN/CLK_CCO]*/
	NOT_ON_TIMER,	/* 21 PD1 SWIM */
	TIMER23,		/* 22 PD2 [TIM2_CH3] */
	TIMER22,		/* 23 PD3 TIM2_CH2/ADC_ETR */
	TIMER21,		/* 24 PD4 TIM2_CH1/BEEP*/
	NOT_ON_TIMER,	/* 25 PD5 UART1_TX */
	NOT_ON_TIMER,	/* 26 PD6 UART1_RX */
	TIMER14,		/* 27 PD7 TLI/[TIM1_CH4] */
};

#endif

#define NEED_TIMER_11_12
//#define NEED_TIMER_31_32

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

