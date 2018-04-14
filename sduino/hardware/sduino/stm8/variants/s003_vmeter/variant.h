/*
  variant.h - Pins generic definition for STM8S003/103Fx
  2 February 2018 huaweiwx<huaweiwx@sina.com>
*/

#ifndef _VARINAT_H_
#define _VARINAT_H_

//3digits 7seg
#define SEG_A  PC4
#define SEG_B  PB5
#define SEG_C  PC7
#define SEG_D  PD1
#define SEG_E  PD3
#define SEG_F  PC3
#define SEG_G  PB4
#define SEG_DP PD2
#define DIG_1  PC6
#define DIG_2  PC5
#define DIG_3  PA3

#define ANALOG_BUILTIN  PD6
#define ANALOG_10DIV      307


#define LED_BUILTIN  SEG_A	  // pin for the buildin LED

#ifdef SUPPORT_ALTERNATE_MAPPINGS
#	define NEED_TIMER_11_12
#endif

#define SERIAL_PORT_MONITOR   Serial
#define SERIAL_PORT_HARDWARE  Serial

#endif
