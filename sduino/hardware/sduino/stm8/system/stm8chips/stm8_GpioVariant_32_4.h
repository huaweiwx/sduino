//variant32_4.h
//STM8L152C4/6/8 32pins


#ifndef _STM8_GPIO_VARINAT32_4_h
#define _STM8_GPIO_VARINAT32_4_h

#include "stm8_pinNum.h"

#define CHIP_PIN_LIST \
#define CHIP_PIN_LIST\
	PIN(A,0)		  PIN(A,2),PIN(A,3),PIN(A,4),PIN(A,5),PIN(A,6),\
	PIN(B,0),PIN(B,1),PIN(B,2),PIN(B,3),PIN(B,4),PIN(B,5),PIN(B,6),PIN(B,7),\
	PIN(C,0),PIN(C,1),PIN(C,2),PIN(C,3),PIN(C,4),PIN(C,5),PIN(C,6),\
		     PIN(D,1),PIN(D,2),PIN(D,3),PIN(D,4),PIN(D,5),PIN(D,6),PIN(D,7),

#ifndef SDUINOPINS_DEF
#define PA0 _PA0
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

#define PD1 _PD1
#define PD2 _PD2
#define PD3 _PD3
#define PD4 _PD4
#define PD5 _PD5
#define PD6 _PD6
#define PD7 _PD7


#define  _GET_PORT(pin) ((uint8_t)(pin>>3))
#define  _GET_PIN(pin)  ((uint8_t)(pin&7))
#define  _IS_VARINAT_PIN(n) (\
(n==PA0)||\
((n>=PA2)||(n<=PA6))||\
((n>=PB0)&&(n<=PB7))||\
((n>=PC1)&&(n<=PC6))||\
((n>=PD1)&&(n<=PD7)))

#define	A0	(PA6)
#define	A1	(PA5)
#define	A2	(PA4)
//#define	A3	(PB1)
#define	A4	(PC4)
#define	A5	(PC3)
#define	A6	(PC2)
#define	A7	(PD7)
#define	A8	(PD6)
#define	A9	(PD5)
#define	A10	(PD4)
#define	A11	(PB7)
#define	A12	(PB6)
#define	A13	(PB5)
#define	A14	(PB4)
#define	A15	(PB3)
#define	A16	(PB2)
#define	A17	(PB1)
#define	A18	(PB0)
#define	A19	(PD3)
#define	A20	(PD2)
#define	A21	(PD1)

#define analogInputToDigitalPin(p) ((p<0)?-1:(\
									(p<=2)?(PA4-p+2):(\
									(p==3)? -1   :(\
									(p<=6)?(PC2-p+6) :(\
									(p<=10)?(PD4-p+10) :(\
									(p<=18)?(PB0-p+18) :(\
									(p<=21)?(PD1-p+21) :-1)))))))
#define analogPinToChannel(p) (p)

#endif   //SDUINOPINS_DEF

#include "utils/fastIO.h"

//default define can be overloader by variat.h
#ifndef SS1
#define SS1	    (PB4)
#endif

#ifndef MOSI1
#define	MOSI1 (PB6)
#endif
#ifndef MISO1
#define	MISO1 (PB7)
#endif
#ifndef SCK1
#define	SCK1	 (PB5)
#endif

#ifndef SDA1
#define	SDA1	(PC0)
#endif
#ifndef SCL1
#define	SCL1	(PC1)
#endif

#ifndef TX1
#define TX1	(PC3)
#endif

#ifndef RX1
#define RX1	(PC2)
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

#endif //_STM8_GPIO_VARINAT32_4_h
