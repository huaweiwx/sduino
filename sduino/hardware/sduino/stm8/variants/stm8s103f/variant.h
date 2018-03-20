/*
  variant.h - Pins generic definition for STM8S003/103Fx
  2 February 2018 huaweiwx<huaweiwx@sina.com>
*/

#ifndef _VARINAT_H_
#define _VARINAT_H_

#ifndef LED_BUILTIN
#	define LED_BUILTIN (PB5)	  // pin for the buildin LED
#	define LED_BUILTIN_MASK 0x00 // low in on
#endif

#ifdef SUPPORT_ALTERNATE_MAPPINGS
#	define NEED_TIMER_11_12
#endif

#define SERIAL_PORT_MONITOR   Serial
#define SERIAL_PORT_HARDWARE  Serial

#endif
