/*
  variant.h Pins generic definition for STM8S105K
  2 February 2018 by  huaweiwx<huaweiwx@sina.com>
*/

#ifndef _VARINAT_H_
#define _VARINAT_H_

#ifndef LED_BUILTIN
#	define LED_BUILTIN (PE5)	// pin for the buildin LED, can be replace by board.txt
#	define LED_BUILTIN_MASK 0x00  // on lever bit 0 is Low
#endif

#ifdef SUPPORT_ALTERNATE_MAPPINGS
#	define NEED_TIMER_11_12
#	define NEED_TIMER_31_32
#endif

// These serial port names are intended to allow libraries and architecture-neutral
// sketches to automatically default to the correct port name for a particular type
// of use.  For example, a GPS module would normally connect to SERIAL_PORT_HARDWARE_OPEN,
// the first hardware serial port whose RX/TX pins are not dedicated to another use.
//
// SERIAL_PORT_MONITOR        Port which normally prints to the Arduino Serial Monitor
// SERIAL_PORT_USBVIRTUAL     Port which is USB virtual serial
// SERIAL_PORT_LINUXBRIDGE    Port which connects to a Linux system via Bridge library
// SERIAL_PORT_HARDWARE       Hardware serial port, physical RX & TX pins.
// SERIAL_PORT_HARDWARE_OPEN  Hardware serial ports which are open for use.  Their RX & TX
//                            pins are NOT connected to anything by default.

#define SERIAL_PORT_MONITOR   Serial
#define SERIAL_PORT_HARDWARE  Serial

#endif

