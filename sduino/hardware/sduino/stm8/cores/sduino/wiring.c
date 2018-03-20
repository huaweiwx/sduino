/*
  wiring.c - Partial implementation of the Wiring API for the ATmega8.
  Part of Arduino - http://www.arduino.cc/

  Copyright (c) 2005-2006 David A. Mellis

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
#include "Arduino.h"
#include "wiring_private.h"

/**
 * Delay for the given number of milliseconds.
 *
 * Do a busy wait. Using the lower 16 bits of micros() is enough, as the
 * difference between the start time and the current time will never be much
 * higher than 1000.
 *
 * Using unsigned values is helpful here. This way value wrap-arounds between
 * start and now do not result in negative values but in the wanted absolute
 * difference. The magic of modulo-arithmethics.
 */

#ifdef SUPPORT_ALTERNATE_MAPPINGS
/**
 * Helper function for STM8: Switch to the alternate pin functions
 *
 * a) flexible function: supports switching diffent AFR bits for
 * multiple set of pins. Not needed for stm8s103, but might be useful
 * for bigger parts.
 */
/*
void alternateFunction(uint8_t pin, uint8_t val)
{
	uint16_t optionbyte;
	uint8_t	afr;

	afr = digitalPinToAFR(pin);
	if (afr>7) return;	// ignore request on invalid pin

	optionbyte = FLASH_ReadOptionByte(OPT->OPT2);

	// flip the bit if the current state differs from requested state
	if ( ((optionbyte & (1<<afr) == 0) ^ (val==0) )
		FLASH_ProgramOptionByte(OPT->OPT2, (optionbyte&0xff)^(1<<afr));
	}
}
*/

/**
 * Helper function for STM8: Switch to the alternate pin functions
 *
 * b) simplified function: supports only bit AFR0 to switch pins C5, C6 and C7
 * from GPIO/SPI (default function) to PWM support (alternate function).
 */
void alternateFunction(uint8_t val)
{
	uint16_t optionbyte;

	optionbyte = FLASH_ReadOptionByte(0x4803) >> 8;
//	optionbyte = FLASH_ReadOptionByte(OPT->OPT2) >> 8;

	// flip the bit if the current state differs from requested state
	if ( (optionbyte & (1<<0) == 0) ^ (val==0) ) {
		FLASH_Unlock(FLASH_MEMTYPE_DATA);
//		FLASH_ProgramOptionByte(OPT->OPT2, (optionbyte&0xff)^(1<<0));
		FLASH_ProgramOptionByte(0x4803, optionbyte^(1<<0));
		FLASH_Lock(FLASH_MEMTYPE_DATA);
	}
}
#endif

#if defined(STM8S)
# include "stm8/stm8s_ini.h"
#elif defined(STM8L)
# include "stm8/stm8l_ini.h"
#endif

