/*
  variant.h - Pin definition functions for generic STM8L152R
  2 February 2018 for STM8L by huaweiwx 
*/

#ifndef _VARINAT_H_
#define _VARINAT_H_

#define  BEEP PA0
#define  TD1 PG2
#define  LED_BUILTIN		(PG2)	// pin for the buildin LED
#define  LED_BUILTIN_MASK	0x00

#define BOARD_NR_KEY        2
#define BOTTON              PF1
#define BOTTON1             PF0
#define BOTTON_MASK         0x00


#define SERIAL_PORT_MONITOR   Serial
#define SERIAL_PORT_HARDWARE  Serial

#endif
