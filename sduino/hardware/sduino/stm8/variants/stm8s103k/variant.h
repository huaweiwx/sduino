/*
  variant.h - Pins generic definition  for stm8s103k3
  2 February 2018 huaweiwx<huaweiwx@sina.com>
*/

#ifndef _VARINAT_H_
#define _VARINAT_H_

#ifndef LED_BUILTIN
#	define LED_BUILTIN (PD7)	   // pin for the buildin LED, not pin 13!
#	define LED_BUILTIN_MASK 0x00  // on lever bit 0 is Low
#endif

#ifdef SUPPORT_ALTERNATE_MAPPINGS
#	define NEED_TIMER_11_12
#	define NEED_TIMER_31_32
#endif

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

