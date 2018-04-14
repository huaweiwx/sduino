/*
  variant.h - Pin definition functions for generic STM8L152R
  2 February 2018 for STM8L by huaweiwx 
*/

#ifndef _VARINAT_H_
#define _VARINAT_H_

#ifndef  LED_BUILTIN
#define  LED_BUILTIN (PG2)	// pin for the buildin LED
#endif

#define NEED_TIMER_11_12
#define NEED_TIMER_31_32

#define SERIAL_PORT_MONITOR   Serial
#define SERIAL_PORT_HARDWARE  Serial

#endif
