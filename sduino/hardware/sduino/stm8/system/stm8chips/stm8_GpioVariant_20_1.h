//variant20_1.h
//STM8S003F3Px/Ux    20 pins
//STM8S103F3Px/Mx/Ux 20pins
 

#ifndef _STM8_GPIO_VARINAT20_1_h
#define _STM8_GPIO_VARINAT20_1_h

#include "stm8_pinNum.h"

#define CHIP_PIN_LIST \
PIN(A,1), \
PIN(A,2), \
PIN(A,3), \
PIN(B,4), \
PIN(B,5), \
PIN(C,3), \
PIN(C,4), \
PIN(C,5), \
PIN(C,6), \
PIN(C,7), \
PIN(D,1), \
PIN(D,2), \
PIN(D,3), \
PIN(D,4), \
PIN(D,5), \
PIN(D,6),


#ifndef SDUINOPINS_DEF
#define   PA1  _PA1
#define   PA2  _PA2
#define   PA3  _PA3
#define   PB4  _PB4
#define   PB5  _PB5
#define   PC3  _PC3
#define   PC4  _PC4
#define   PC5  _PC5
#define   PC6  _PC6
#define   PC7  _PC7
#define   PD1  _PD1
#define   PD2  _PD2
#define   PD3  _PD3
#define   PD4  _PD4
#define   PD5  _PD5
#define   PD6  _PD6

#define  _GET_PORT(pin) ((uint8_t)(pin>>3))
#define  _GET_PIN(pin)  ((uint8_t)(pin&7))
#define  _IS_VARINAT_PIN(n) ( \
((n>=PA1)||(n<=PA3))||\
 (n==PB4)||(n==PB5) ||\
((n>=PC3)||(n<=PC7))||\
((n>=PD1)||(n<=PD6)))


#define	NUM_DIGITAL_PINS 16

#define	A2	(PC4)
#define	A3	(PD2)
#define	A4	(PD3)
#define	A5	(PD5)
#define	A6	(PD6)

#define analogInputToDigitalPin(p) (\
((p)<2)?0xff:(\
((p)==2)?PC4:(\
((p)<=4)?(PD2+(p)-3):(\
((p)<=6)?(PD5+(p)-5):0xff))))

#define analogPinToChannel(p) (p)

#endif   //SDUINOPINS_DEF

#include "utils/fastIO.h"

//default define can be overloader by variat.h
#ifndef SS1
#define SS1	 (PA3)
#endif
#ifndef MOSI1
#define	MOSI1 (PC6)
#endif
#ifndef MISO1
#define	MISO1 (PC7)
#endif
#ifndef SCK1
#define	SCK1	 (PC5)
#endif

#ifndef SDA1
#define	SDA1	(PB5)
#endif
#ifndef SCL1
#define	SCL1	(PB4)
#endif

#ifndef TX1
#define TX1	PD
#endif
#ifndef RX1
#define RX1	PD
#endif

#ifndef SS
#define SS	SS1
#endif
#ifndef MOSI
#define	MOSI MOSI1
#endif
#ifndef MISO
#define	MISO MISO1
#endif
#ifndef SCK
#define	SCK	SCK1
#endif
#ifndef SDA
#define	SDA	SDA1
#endif
#ifndef SCL
#define	SCL	SCL1
#endif
#ifndef TX
#define TX	TX1
#endif
#ifndef RX
#define RX	RX1
#endif

#endif //_STM8_GPIO_VARINAT20_1_h
