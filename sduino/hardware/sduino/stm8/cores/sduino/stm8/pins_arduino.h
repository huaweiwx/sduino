/*
  pins_arduino.h  - Pin definition functions for Arduino
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

#ifndef _PINS_ARDUINO_h_
#define _PINS_ARDUINO_h_

#ifndef _BV
#  define _BV(X) (1<<(X))
#endif

#define NOT_A_PIN  0xff
#define NOT_A_PORT 0xff

#define NOT_AN_INTERRUPT -1


enum {
    NOT_ON_TIMER = 0,
    TIMER11,
    TIMER12,
    TIMER13,
    TIMER14,
    TIMER21,
    TIMER22,
    TIMER23,
    TIMER31,
    TIMER32,
    NUM_TIMERS
};

#ifdef ARDUINO_MAIN
#define PA 0
#define PB 1
#define PC 2
#define PD 3
#define PE 4
#define PF 5
#define PG 6
#define PH 7
//#define PI 8  /*PI is const 3.14..........*/

#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3
#define PORTE 4
#define PORTF 5
#define PORTG 6
#define PORTH 7
#define PORTI 8
#endif

#include "variant.h"

#ifdef VARIANT_PIN_LIST
  #define SDUINOPINS_DEF
  #define PIN_LIST VARIANT_PIN_LIST
#else
  #define PIN_LIST CHIP_PIN_LIST	
#endif

#include "stm8_build_defines.h"

#ifdef ARDUINO_MAIN
#ifdef  SDUINOPINS_DEF
// these arrays map port names (e.g. port B) to the
// appropriate addresses for various functions (e.g. reading and writing)
 
const uint16_t PROGMEM port_to_output_PGM[] = {
	GPIOA_BaseAddress,
	GPIOB_BaseAddress,
	GPIOC_BaseAddress,
	GPIOD_BaseAddress,
	GPIOE_BaseAddress,
	GPIOF_BaseAddress,
#if   defined(HAVE_GPIOI)
	GPIOG_BaseAddress,
	GPIOH_BaseAddress,
	GPIOI_BaseAddress,
#elif defined(HAVE_GPIOG)
	GPIOG_BaseAddress,
#  endif	
};

#  define PIN(a, b) PORT##a
const uint8_t PROGMEM digital_pin_to_port_PGM[] = {
	PIN_LIST
};
#  undef PIN

#  define PIN(a, b) (uint8_t)_BV(b)
const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[] = {
	PIN_LIST
};
#  undef PIN

#endif //end  SDUINOPINS_DEF

#endif //end  ARDUINO_MAIN

#endif //_PINS_ARDUINO_h_
