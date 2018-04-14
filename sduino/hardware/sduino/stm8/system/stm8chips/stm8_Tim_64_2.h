//  tim64_2.h
//  STM8L152R6/8 64pins
//  huaweiwx@sina.com 2018.4.08

#ifndef _STM8_TIM_h
#define _STM8_TIM_h
#ifndef SDUINOPINS_DEF
#ifdef ARDUINO_MAIN

const uint8_t PROGMEM digital_pin_to_timer_PGM[] = {
	NOT_ON_TIMER,   /*0  PA0  1            */
	NOT_ON_TIMER,   /*1  PA1  2 NRST       */
	NOT_ON_TIMER,   /*2  PA2  3 RCC_OSC_IN */
	NOT_ON_TIMER,   /*3  PA3  4 RCC_OSC_OUT*/
	NOT_ON_TIMER,   /*4  PA4  5            */
	NOT_ON_TIMER,   /*5  PA5  6            */
	NOT_ON_TIMER,   /*6  PA6  7            */
	NOT_ON_TIMER,   /*7  PA7  8            */
  	TIMER21,		/*8  PB0  31           */
  	TIMER31,		/*9  PB1  32           */	
  	TIMER22,		/*10 PB2 33            */
	NOT_ON_TIMER,   /*11 PB3 34            */
	NOT_ON_TIMER,   /*12 PB4 35            */
    NOT_ON_TIMER,   /*13 PB5 36            */
	NOT_ON_TIMER,   /*14 PB6 37            */
	NOT_ON_TIMER,   /*15 PB7 38            */
  	NOT_ON_TIMER,	/*16 PC0 53            */
  	NOT_ON_TIMER,	/*17 PC1 54            */
  	NOT_ON_TIMER,	/*18 PC2 57            */
  	NOT_ON_TIMER,	/*19 PC3 58            */
  	NOT_ON_TIMER,	/*20 PC4 59            */
  	NOT_ON_TIMER,	/*21 PC5 60            */
  	NOT_ON_TIMER,	/*22 PC6 61            */
  	NOT_ON_TIMER,	/*23 PC7 62            */
  	TIMER32,		/*24 PD0 25            */
    NOT_ON_TIMER,	/*25 PD1 26            */
  	TIMER11,		/*26 PD2 27            */
    NOT_ON_TIMER,	/*27 PD3 28            */
  	TIMER12,		/*28 PD4 45            */ 
  	TIMER13,		/*29 PD5 46            */
  	NOT_ON_TIMER,	/*30 PD6 47            */
  	NOT_ON_TIMER,	/*31 PD7 48            */
    NOT_ON_TIMER,	/*32 PE0 19 TIMER52           */
  	NOT_ON_TIMER,	/*33 PE1 20            */
  	NOT_ON_TIMER,	/*34 PE2 21            */
  	NOT_ON_TIMER,	/*35 PE3 22            */
  	NOT_ON_TIMER,	/*36 PE4 23            */
  	NOT_ON_TIMER,	/*37 PE5 24            */
  	NOT_ON_TIMER,	/*38 PE6 63            */
  	NOT_ON_TIMER,  	/*39 PE7 64            */
  	NOT_ON_TIMER,	/*40 PF0 39            */
  	NOT_ON_TIMER,	/*41 PF1 40            */
//					     PF2
//					     PF3
  	NOT_ON_TIMER,	/*42 PF4 41            */
  	NOT_ON_TIMER,	/*43 PF5 42            */
  	NOT_ON_TIMER,	/*44 PF6 43            */
  	NOT_ON_TIMER,	/*45 PF7 44            */
  	NOT_ON_TIMER,	/*46 PG0 14            */
  	NOT_ON_TIMER,	/*47 PG1 15            */
	NOT_ON_TIMER,	/*48 PG2 16            */
	NOT_ON_TIMER, 	/*49 PG3 17            */
	NOT_ON_TIMER,	/*50 PG4 49            */
	NOT_ON_TIMER,  	/*51 PG5 50            */
	NOT_ON_TIMER,	/*52 PG6 51            */
	NOT_ON_TIMER,	/*53 PG7 52            */
};

#endif

#define digitalPinHasPWM(p)	(((p)==PB0)|((p)==PB1)|((p)==PB2)|((p)==PD0)|((p)==PD2)|((p)==PD4)|((p)==PD5))

#endif //SDUINOPINS_DEF

#endif //_STM8_TIM64_1_h
