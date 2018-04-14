//  variant48_1.h
//  STM8S005C6Tx 48pins
//  STM8S105C6 48pins
//  huaweiwx@sina.com 2018.4.08

#ifndef _STM8_GPIO_VARINAT48_1_h
#define _STM8_GPIO_VARINAT48_1_h

#include "stm8_pinNum.h"

#define HAVE_GPIOG
#define CHIP_PIN_LIST \
PIN(A,1), \
PIN(A,2), \
PIN(A,4), \
PIN(A,5), \
PIN(A,6), \
PIN(B,0), \
PIN(B,1), \
PIN(B,2), \
PIN(B,3), \
PIN(B,4), \
PIN(B,5), \
PIN(B,6), \
PIN(B,7), \
PIN(C,1), \
PIN(C,2), \
PIN(C,3), \
PIN(C,4), \
PIN(C,5), \
PIN(C,6), \
PIN(C,7), \
PIN(D,0), \
PIN(D,1), \
PIN(D,2), \
PIN(D,3), \
PIN(D,4), \
PIN(D,5), \
PIN(D,6), \
PIN(D,7), \
PIN(E,0), \
PIN(E,1), \
PIN(E,2), \
PIN(E,5), \
PIN(E,6), \
PIN(G,0), \
PIN(G,1),


#ifndef SDUINOPINS_DEF
#define PA1 _PA1
#define PA2 _PA2
#define PA4 _PA4
#define PA5 _PA5
#define PA6 _PA6
#define PB0 _PB0
#define PB1 _PB1
#define PB2 _PB2
#define PB3 _PB3
#define PB4 _PB4
#define PB5 _PB5
#define PB6 _PB6
#define PB7 _PB7
#define PC1 _PC1
#define PC2 _PC2
#define PC3 _PC3
#define PC4 _PC4
#define PC5 _PC5
#define PC6 _PC6
#define PC7 _PC7
#define PD0 _PD0
#define PD1 _PD1
#define PD2 _PD2
#define PD3 _PD3
#define PD4 _PD4
#define PD5 _PD5
#define PD6 _PD6
#define PD7 _PD7
#define PE0 _PE0
#define PE1 _PE1
#define PE2 _PE2
#define PE5 _PE5
#define PE6 _PE6
#define PG0 _PG0
#define PG1 _PG1

#define  _GET_PORT(pin) ((uint8_t)(pin>>3))
#define  _GET_PIN(pin)  ((uint8_t)(pin&7))
#define  _IS_VARINAT_PIN(n) (\
((n>=PA1)&&(n<=PA6))||\
((n>=PB0)&&(n<=PB5))||\
((n>=PC1)&&(n<=PC7))||\
((n>=PD0)&&(n<=PD7))||\
((n>=PE0)||(n==PE2))||\
 (n==PE5)||(n=PE6)||(n==PG0)||(n==PG1))

#define	A0	(PB0)
#define	A1	(PB1)
#define	A2	(PB2)
#define	A3	(PB3)
#define	A4	(PB4)
#define	A5	(PB5)
#define	A6	(PB6)
#define	A7	(PB7)
#define	A8	(PE7)
#define	A9	(PE6)

#define analogInputToDigitalPin(p) ((p<0)?-1:(\
									(p<=7)?(PB0+p):(\
									(p==8)?PE7:(\
									(p==9)?PE6:-1))))
#define analogPinToChannel(p)(\
 (((p)>= PB0)||((p)<=PB7))?(p)-PB0:(\
 ((p)== PE7)?8:(\
 ((p)== PE6)?9:(P))))

#endif   //SDUINOPINS_DEF

#include "utils/fastIO.h"

#ifndef SS1
#define SS1		(PE5)
#endif

#ifndef MOSI1
#define	MOSI1	(PC6)
#endif
#ifndef MISO1
#define	MISO1	(PC7)
#endif
#ifndef SCK1
#define	SCK1		(PC5)
#endif

#ifndef SDA1
#define	SDA1	(PE2)
#endif
#ifndef SCL1
#define	SCL1	(PE1)
#endif

#ifndef TX1
#define TX1	PD5
#endif
#ifndef RX1
#define RX1	PD6
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

#endif //_STM8_GPIO_VARINAT48_1_h
