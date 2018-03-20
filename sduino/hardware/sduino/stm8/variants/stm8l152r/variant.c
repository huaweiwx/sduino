/*
  variant.c  for stm8l
  Copyright (c) 2018 huaweiwx <huaweiwx@sina.com>

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

#include "wiring_private.h"

#if (clockCyclesPerMillisecond() < 256)
# define T4PRESCALER	TIM4_PRESCALER_1
# define T4PRESCALER_FACTOR	1
#elif (clockCyclesPerMillisecond() < 512)
# define T4PRESCALER	TIM4_PRESCALER_2
# define T4PRESCALER_FACTOR	2
#elif (clockCyclesPerMillisecond() < 1024)
# define T4PRESCALER	TIM4_PRESCALER_4
# define T4PRESCALER_FACTOR	4
#elif (clockCyclesPerMillisecond() < 2048)
# define T4PRESCALER	TIM4_PRESCALER_8
# define T4PRESCALER_FACTOR	8
#elif (clockCyclesPerMillisecond() < 4096)
# define T4PRESCALER	TIM4_PRESCALER_16
# define T4PRESCALER_FACTOR	16
#elif (clockCyclesPerMillisecond() < 8192)
# define T4PRESCALER	TIM4_PRESCALER_32
# define T4PRESCALER_FACTOR	32
#elif (clockCyclesPerMillisecond() < 16384)
# define T4PRESCALER	TIM4_PRESCALER_64
# define T4PRESCALER_FACTOR	64
#elif (clockCyclesPerMillisecond() < 32768)
# define T4PRESCALER	TIM4_PRESCALER_128
# define T4PRESCALER_FACTOR	128
#else
#error "could not calculate a valid prescaler für TIM4"
#endif
#define T4PERIOD	(clockCyclesPerMillisecond()/T4PRESCALER_FACTOR)

void init1()
{
#ifndef ENABLE_SWIM  /*selected in menu term Swin*/
  CFG->GCR = CFG_GCR_SWD; // free the SWIM pin to be used as a general I/O-Pin
#endif

  // set the clock to 16 MHz
  CLK_HSICmd(ENABLE);//开始内部高频RC
  CLK_SYSCLKSourceConfig(CLK_SYSCLKSource_HSI);//HSI为系统时钟
  CLK->CKDIVR = 0;
	
	// set timer 4 prescale factor and period (typ. @16MHz: 64*250=1ms)
	TIM4_TimeBaseInit(T4PRESCALER, (uint8_t) T4PERIOD-1);
	/* Clear TIM4 update flag */
	TIM4_ClearFlag(TIM4_FLAG_UPDATE);	// TIM4->SR1 = (uint8_t)(~0x01);
	/* Enable update interrupt */
	TIM4_ITConfig(TIM4_IT_UPDATE, ENABLE);	// TIM4->IER |= (uint8_t)TIM4_IT;
	/* Enable TIM4 */
	TIM4_Cmd(ENABLE);	// TIM4->CR1 |= TIM4_CR1_CEN;

  // timers 1 and 2 are used for phase-correct hardware pwm
  // this is better for motors as it ensures an even waveform
  // note, however, that fast pwm mode can achieve a frequency of up
  // 8 MHz (with a 16 MHz clock) at 50% duty cycle
  enableInterrupts();
}
