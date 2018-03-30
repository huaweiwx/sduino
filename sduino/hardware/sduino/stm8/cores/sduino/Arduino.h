/*
  Arduino.h - Main include file for the Arduino SDK
  Copyright (c) 2005-2013 Arduino Team.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

  Modified 2 February 2018 for STM8L by huaweiwx 
*/

#ifndef Arduino_h
#define Arduino_h

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#include "binary.h"

#include "stm8/stm8.h" /* huaweiwx*/


// FIXME: workarounds for missing features or unimplemented functions
// cancel out the PROGMEM attribute - used only for atmel CPUs
#define PROGMEM

void yield(void);

// we use pre-defined IRQ function the way wiring does
#define WIRING



#define HIGH 0x1
#define LOW  0x0

#define INPUT  			0x0
#define OUTPUT 			0x1
#define INPUT_PULLUP 	0x2
#define	OUTPUT_OD 		0x03
#define OUTPUT_FAST 	0x05
#define OUTPUT_OD_FAST 	0x07

// undefine mathlib's pi if encountered
#ifdef PI
#undef PI
#endif
#ifdef HALF_PI
#undef HALF_PI
#endif
#ifdef TWO_PI
#undef TWO_PI
#endif

#define PI 3.1415926535897932384626433832795
#define HALF_PI 1.5707963267948966192313216916398
#define TWO_PI 6.283185307179586476925286766559
#define DEG_TO_RAD 0.017453292519943295769236907684886
#define RAD_TO_DEG 57.295779513082320876798154814105
#define EULER 2.718281828459045235360287471352

#define SERIAL  0x0
#define DISPLAY 0x1

#define LSBFIRST 0
#define MSBFIRST 1

#define CHANGE 1
#define FALLING 2
#define RISING 3

// undefine stdlib's abs if encountered
#ifdef abs
#undef abs
#endif

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))
#define round(x)     ((x)>=0?(long)((x)+0.5):(long)((x)-0.5))
#define radians(deg) ((deg)*DEG_TO_RAD)
#define degrees(rad) ((rad)*RAD_TO_DEG)
#define sq(x) ((x)*(x))

#define interrupts() sei()
#define noInterrupts() cli()

#define clockCyclesPerMicrosecond() ( F_CPU / 1000000L )
#define clockCyclesPerMillisecond() ( F_CPU / 1000L )
#define clockCyclesToMicroseconds(a) ( (a) / clockCyclesPerMicrosecond() )
#define microsecondsToClockCycles(a) ( (a) * clockCyclesPerMicrosecond() )

#define lowByte(w) ((uint8_t) ((w) & 0xff))
#define highByte(w) ((uint8_t) ((w) >> 8))

#define bitRead(value, bit) (((value) >> (bit)) & 0x01)
#define bitSet(value, bit) ((value) |= (1UL << (bit)))
#define bitClear(value, bit) ((value) &= ~(1UL << (bit)))
#define bitWrite(value, bit, bitvalue) (bitvalue ? bitSet(value, bit) : bitClear(value, bit))

#define maskSet(value, mask) ((value) |= (mask))
#define maskClear(value, mask) ((value) &= ~(mask))

#ifndef _NOP
#define _NOP() do { __asm__ volatile ("nop"); } while (0)
#endif


/* for SDCC this is supposed to be "__critical{" and "}", but up to
 * sdcc version 3.6.4 it is wrongly implemented. */
/* so geht es nicht:*/
//#define BEGIN_CRITICAL		__asm__("push\tcc");__asm__("sim");
//#define END_CRITICAL		__asm__("pop\tcc");

//#define BEGIN_CRITICAL		__critical {
//#define END_CRITICAL		}
///* klappt:
#define BEGIN_CRITICAL
#define END_CRITICAL
//*/


typedef unsigned int word;

#define bit(b) (1UL << (b))

typedef unsigned char boolean;
typedef unsigned char byte;
//typedef uint8_t byte;

void init(void);
void initVariant(void);		// weak

int atexit(void (*func)());	// __attribute__((weak));
void serialEvent(void);		// weak
extern unsigned char runSerialEvent;

void pinMode(uint8_t pin, uint8_t mode);
void digitalWrite(uint8_t pin, uint8_t val);
void digitalToggle(uint8_t pin);
int  digitalRead(uint8_t pin);
int  analogRead(uint8_t pin);
void analogReference(uint8_t mode);
void analogWrite(uint8_t pin, int val);

#ifdef STM8S
unsigned long millis(void);
unsigned long micros(void);
void delay(unsigned long ms);
#else
void delay(uint16_t ms);
#endif
void delayMicroseconds(unsigned int us);
unsigned long pulseIn(uint8_t pin, uint8_t state, unsigned long timeout);
unsigned long pulseInLong(uint8_t pin, uint8_t state, unsigned long timeout);

void shiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, uint8_t val);
uint8_t shiftIn(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder);

void attachInterrupt(uint8_t, void (*)(void), int mode);
void detachInterrupt(uint8_t);

void setup(void);
void loop(void);

// Get the bit location within the hardware port of the given virtual pin.
// This comes from the pins_*.c file for the active board configuration.

#define analogInPinToBit(P) (P)

// On the ATmega1280, the addresses of some of the port registers are
// greater than 255, so we can't store them in uint8_t's.

//extern const uint16_t port_to_mode_PGM[];
//extern const uint16_t PROGMEM port_to_input_PGM[];
extern const uint16_t PROGMEM port_to_output_PGM[];

extern const uint8_t PROGMEM digital_pin_to_port_PGM[];
extern const uint8_t PROGMEM digital_pin_to_bit_PGM[];
extern const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[];
extern const uint8_t PROGMEM digital_pin_to_timer_PGM[];

#ifdef SUPPORT_ALTERNATE_MAPPINGS
// helper function for STM8S: switch to the alternate pin functions
void alternateFunction(uint8_t val);
#endif

#include "stm8/pins_arduino.h"

// Get the bit location within the hardware port of the given virtual pin.
// This comes from the pins_*.c file for the active board configuration.
//

#ifdef  SDUINOPINS_DEF 
#define digitalPinToPort(P)    (digital_pin_to_port_PGM[(P)])
#define digitalPinToBitMask(P) (digital_pin_to_bit_mask_PGM[(P)])
#define digitalPinToTimer(P)   (digital_pin_to_timer_PGM[(P)])
#define getPinBase(P)          (port_to_output_PGM[(P)])
#define analogInPinToBit(P)    (P)
#else
///*sduino pins genterc define: port: bit 6543 pin: bit 210 for save memorys */
#define digitalPinToPort(P)    ((uint8_t)(((P)>>3) & 0xf))
#define digitalPinToPin(P)     ((uint8_t)((P)&0x07))
#define digitalPinToBitMask(P) (1<<(digitalPinToPin(P)))
#define digitalPinToTimer(P)   (digital_pin_to_timer_PGM[(P)])
#define analogInPinToBit(P)    (P)
#define getPinBase(P)          (uint16_t)(GPIOA_BaseAddress+digitalPinToPort(P)*5)
#endif

#define portOutputRegister(P)  ((volatile uint8_t *)(getPinBase(P)))
#define portInputRegister(P)   ((volatile uint8_t *)(getPinBase(P)+1))
#define portModeRegister(P)    ((volatile uint8_t *)(getPinBase(P)+2))
#define portCR1Register(P)     ((volatile uint8_t *)(getPinBase(P)+3))
#define portCR2Register(P)     ((volatile uint8_t *)(getPinBase(P)+4))



//FIXME#include "WCharacter.h"
//FIXME#include "WString.h"
#include "HardwareSerial.h"

//uint16_t makeWord(uint16_t w);
//uint16_t makeWord(byte h, byte l);

//#define word(...) makeWord(__VA_ARGS__)

unsigned long pulseIn(uint8_t pin, uint8_t state, unsigned long timeout);
unsigned long pulseInLong(uint8_t pin, uint8_t state, unsigned long timeout);

void tone(uint8_t _pin, unsigned int frequency, unsigned long duration);
void noTone(uint8_t _pin);

// WMath prototypes
long random(long howbig);
long random_minmax(long howsmall, long howbig);
void randomSeed(unsigned long seed);
long map(long x, long in_min, long in_max, long out_min, long out_max);

inline unsigned int makeWord(unsigned char h, unsigned char l) { return (h << 8) | l; }


#endif //Arduino_h
