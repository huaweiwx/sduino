//  variant48_1.h
//  STM8S208MBTx 80pins
//  STM8S208MBTx 80pins
//  huaweiwx@sina.com 2018.4.08

#ifndef _STM8_GPIO_VARINAT48_1_h
#define _STM8_GPIO_VARINAT48_1_h

#include "stm8_pinNum.h"
#define HAVE_GPIOI
#define CHIP_PIN_LIST\
			  PIN(A,1), PIN(A,2), PIN(A,3), PIN(A,4), PIN(A,5), PIN(A,6),\
	PIN(B,0), PIN(B,1), PIN(B,2), PIN(B,3), PIN(B,4), PIN(B,5), PIN(B,6), PIN(B,7),\
	PIN(C,0), PIN(C,1), PIN(C,2), PIN(C,3), PIN(C,4), PIN(C,5), PIN(C,6), PIN(C,7),\
	PIN(D,0), PIN(D,1), PIN(D,2), PIN(D,3), PIN(D,4), PIN(D,5), PIN(D,6), PIN(D,7),\
	PIN(E,0), PIN(E,1), PIN(E,2), PIN(E,3), PIN(E,4), PIN(E,5), PIN(E,6), PIN(E,7),\
	PIN(F,0),                     PIN(F,3), PIN(F,4), PIN(F,5), PIN(F,6), PIN(F,7),\
	PIN(G,0), PIN(G,1), PIN(G,2), PIN(G,3), PIN(G,4), PIN(G,5), PIN(G,6), PIN(G,7),\
	PIN(H,0), PIN(H,1), PIN(H,2), PIN(H,3), PIN(H,4), PIN(H,5), PIN(H,6), PIN(H,7),\
	PIN(I,0), PIN(I,1), PIN(I,2), PIN(I,3), PIN(I,4), PIN(I,5), PIN(I,6), PIN(I,7),

#ifndef SDUINOPINS_DEF
#define PA1 _PA1
#define PA2 _PA2
#define PA3 _PA3
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
#define PC0 _PC0
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
#define PE3 _PE3
#define PE4 _PE4
#define PE5 _PE5
#define PE6 _PE6
#define PE7 _PE7
#define PF0 _PF0
#define PF3 _PF3
#define PF4 _PF4
#define PF5 _PF5
#define PF6 _PF6
#define PF7 _PF7
#define PG0 _PG0
#define PG1 _PG1
#define PG2 _PG2
#define PG3 _PG3
#define PG4 _PG4
#define PG5 _PG5
#define PG6 _PG6
#define PG7 _PG7
#define PH0 _PH0
#define PH1 _PH1
#define PH2 _PH2
#define PH3 _PH3
#define PH4 _PH4
#define PH5 _PH5
#define PH6 _PH6
#define PH7 _PH7
#define PI0 _PI0
#define PI1 _PI1
#define PI2 _PI2
#define PI3 _PI3
#define PI4 _PI4
#define PI5 _PI5
#define PI6 _PI6
#define PI7 _PI7

#define  _GET_PORT(pin) ((uint8_t)(pin>>3))
#define  _GET_PIN(pin)  ((uint8_t)(pin&7))
#define  _IS_VARINAT_PIN(n) (\
((n>=PA1)&&(n<=PA6))||\
((n>=PB0)&&(n<=PB7))||\
((n>=PC0)&&(n<=PC7))||\
((n>=PD0)&&(n<=PD7))||\
((n>=PE0)||(n<=PE7))||\
 (n==PF0)||\
((n>=PF3)||(n<=PF7))||\
((n>=PG0)||(n<=PG7))||\
((n>=PH0)||(n<=PH7))||\
((n>=PI0)||(n<=PI7)))

#define analogInputToDigitalPin(p) ((p<0)?-1:(\
									(p<=2)?(PA6-p):(\
									(p==3)?PC7:(\
									(p<=6)?(PC4-p+4):(\
									(p<=10)?(PD7-p+7):(\
									(p<=18)?(PB7-p+11):(\
									(p<=22)?(PD3-p+19):(\
									(p==23)?PE5:(\
									(p<=25)?(PF0+p-24):-1)))))))))


#define analogPinToChannel(p) (p)

#endif   //SDUINOPINS_DEF

#include "utils/fastIO.h"

#define SS1   	(PE5)
#define	MOSI1	(PC6)
#define	MISO1	(PC7)
#define	SCK1		(PC5)

#define	SDA1	(PE2)
#define	SCL1	(PE1)

#define TX1	PD5
#define RX1	PD6

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
