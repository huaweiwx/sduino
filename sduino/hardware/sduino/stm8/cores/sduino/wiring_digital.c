/*
  wiring_digital.c - digital input and output functions
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

  Modified 28 September 2010 by Mark Sproul

  Modified 2 February 2018 for STM8L by huaweiwx 
*/

#define ARDUINO_MAIN
#include "wiring_private.h"


/* this typedef is a SDCC wordaround.
 * Defining this a type instead of defining an array of (unsigned char *)
 * keeps SDCC from storing the array in the xinit segment and copy it to RAM
 * at runtime.
 */
typedef unsigned char *uc_p;

/* timer capture/compare mode register to control PWM mode */
const uc_p ccmrx[NUM_TIMERS]={
#ifdef NEED_TIMER_11_12
	TIM1->CCMR1,	/* for TIMER11 */
	TIM1->CCMR2,	/* for TIMER12 */
#endif
	TIM1->CCMR3,	/* for TIMER13 */
	TIM1->CCMR4,	/* for TIMER14 */
	TIM2->CCMR1,	/* for TIMER21 */
	TIM2->CCMR2,	/* for TIMER22 */
#ifdef NEED_TIMER_23  /*STM8L TIM2 not CCMR3*/
	TIM2->CCMR3,	/* for TIMER23 */
#endif
	
#ifdef NEED_TIMER_31_32
	TIM3->CCMR1,	/* for TIMER31 */
	TIM3->CCMR2	/* for TIMER32 */
#endif
};

void pinMode(uint8_t pin, uint8_t mode)
{
#ifndef SDUINOPINS_DEF
	uint8_t bit =  (1 << (pin & 0x07));
	volatile GPIO_TypeDef *gpio;
	gpio = (GPIO_TypeDef *) ((uint16_t)(GPIOA_BaseAddress+ (pin>>3)*5));
#else
	uint8_t bit =  digitalPinToBitMask(pin);
	uint8_t port = digitalPinToPort(pin);
	volatile GPIO_TypeDef *gpio;
    if(pin >= NUM_DIGITAL_PINS)	return;  
//	if (port == NOT_A_PORT) return;
	gpio = (GPIO_TypeDef *) portOutputRegister(port);
#endif

	BEGIN_CRITICAL
	if (mode == INPUT) {
		gpio->CR2 &= ~bit;	// first: deactivate interrupt
		gpio->CR1 &= ~bit;	// release top side
		gpio->DDR &= ~bit;	// now set direction
	} else if (mode == INPUT_PULLUP) {
		gpio->CR2 &= ~bit;	// first: deactivate interrupt
		gpio->DDR &= ~bit;	// set direction before
		gpio->CR1 |=  bit;	// activating the pull up
	} else if (mode == OUTPUT_FAST) {// output push-pull, fast
		gpio->CR1 |=  bit;
		gpio->DDR |=  bit;	// direction before setting CR2 to
		gpio->CR2 |=  bit;	// avoid accidental interrupt
	} else if (mode == OUTPUT_OD_FAST) {	// output open drain, fast
		gpio->CR1 &= ~bit;
		gpio->DDR |=  bit;	// direction before setting CR2 to
		gpio->CR2 |=  bit;	// avoid accidental interrupt
	} else if (mode == OUTPUT_OD) {	// output open drain, slow
		gpio->CR1 &= ~bit;
		gpio->CR2 &= ~bit;
		gpio->DDR |=  bit;
	} else {			// output push-pull, slow
		gpio->CR1 |=  bit;
		gpio->CR2 &= ~bit;
		gpio->DDR |=  bit;
	}
	END_CRITICAL
}

static void turnOffPWM(uint8_t timer)
{
	*((unsigned char *) ccmrx[timer-1]) &= ~TIM1_CCMR_OCM;
}


void digitalWrite(uint8_t pin, uint8_t val)
{
	volatile uint8_t *out;
	
#ifndef SDUINOPINS_DEF
	uint8_t bit =  (1 << (pin & 0x07));
	out = (volatile uint8_t *) ((uint16_t)(GPIOA_BaseAddress+ (pin>>3)*5));
#else
	uint8_t timer = digitalPinToTimer(pin);
	uint8_t bit =  digitalPinToBitMask(pin);
	uint8_t port = digitalPinToPort(pin);

    if(pin >= NUM_DIGITAL_PINS)	return;  
	// If the pin that support PWM output, we need to turn it off
	// before doing a digital write.
	if (timer != NOT_ON_TIMER) {
		turnOffPWM(timer);
	}
	out = portOutputRegister(port);
#endif

	BEGIN_CRITICAL
	if (val == LOW) {
		*out &= ~bit;
	} else {
		*out |= bit;
	}
	END_CRITICAL
}

void digitalToggle(uint8_t pin)
{
	volatile uint8_t *out;
	
#ifndef SDUINOPINS_DEF
	uint8_t bit =  (1 << (pin & 0x07));
	out = (volatile uint8_t *) ((uint16_t)(GPIOA_BaseAddress+ (pin>>3)*5));
#else
	uint8_t bit =  digitalPinToBitMask(pin);
	uint8_t port = digitalPinToPort(pin);
    if(pin >= NUM_DIGITAL_PINS)	return;  

	out = portOutputRegister(port);
#endif

 	*out ^= bit;
}

int digitalRead(uint8_t pin)
{
	volatile uint8_t *in;
	
#ifndef SDUINOPINS_DEF
	uint8_t bit =  (1 << (pin & 0x07));
	in = (volatile uint8_t *) ((uint16_t)(GPIOA_BaseAddress+1+ (pin>>3)*5));
#else
	uint8_t timer = digitalPinToTimer(pin);
	uint8_t bit =  digitalPinToBitMask(pin);
	uint8_t port = digitalPinToPort(pin);

    if(pin >= NUM_DIGITAL_PINS)	return;  
	// If the pin that support PWM output, we need to turn it off
	// before doing a digital write.
	if (timer != NOT_ON_TIMER) {
		turnOffPWM(timer);
	}
	in = portInputRegister(port);
#endif

	if (*in & bit) return HIGH;
	return LOW;
}
