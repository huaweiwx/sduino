
/* calculate the best prescaler and timer period for TIM4 for millis()
 *
 * The precaler factor could be calculated from the prescaler enum by
 * bit shifting, but we want to be independent from possible irregular
 * definitions for the chose CPU type.
 */
#if (clockCyclesPerMillisecond() < 256)
# define T4PRESCALER	TIM4_PRESCALER_1
# define T4PRESCALER_FACTOR	1
#elif (clockCyclesPerMillisecond() < 512)
# define T4PRESCALER	TIM4_PRESCALER_2
# define T4PRESCALER_FACTOR	2
#elif (clockCyclesPerMillisecond() < 1024)
# define T4PRESCALER	TIM4_PRESCALER_4
# define T4PRESCALER_FACTOR	4
#elif (clockCyclesPerMillisecond() < 2048)
# define T4PRESCALER	TIM4_PRESCALER_8
# define T4PRESCALER_FACTOR	8
#elif (clockCyclesPerMillisecond() < 4096)
# define T4PRESCALER	TIM4_PRESCALER_16
# define T4PRESCALER_FACTOR	16
#elif (clockCyclesPerMillisecond() < 8192)
# define T4PRESCALER	TIM4_PRESCALER_32
# define T4PRESCALER_FACTOR	32
#elif (clockCyclesPerMillisecond() < 16384)
# define T4PRESCALER	TIM4_PRESCALER_64
# define T4PRESCALER_FACTOR	64
#elif (clockCyclesPerMillisecond() < 32768)
# define T4PRESCALER	TIM4_PRESCALER_128
# define T4PRESCALER_FACTOR	128
#else
#error "could not calculate a valid prescaler für TIM4"
#endif
#define T4PERIOD	(clockCyclesPerMillisecond()/T4PRESCALER_FACTOR)  /*16000/64 = 250*/

// the prescaler is set so that timer4 ticks every 64 clock cycles, and the
// the overflow handler is called every 250 ticks.
# define MICROSECONDS_PER_TIMER0_OVERFLOW (F_CPU/(T4PRESCALER_FACTOR*T4PERIOD))
//#define MICROSECONDS_PER_TIMER0_OVERFLOW (clockCyclesToMicroseconds(64 * 250))

// the whole number of milliseconds per timer4 overflow
#define MILLIS_INC (MICROSECONDS_PER_TIMER0_OVERFLOW / 1000)

// the fractional number of milliseconds per timer4 overflow. we shift right
// by three to fit these numbers into a byte. (for the clock speeds we care
// about - 8 and 16 MHz - this doesn't lose precision.)
#define FRACT_INC ((MICROSECONDS_PER_TIMER0_OVERFLOW % 1000) >> 3)
#define FRACT_MAX (1000 >> 3)

volatile unsigned long timer4_overflow_count;// = 0;
volatile unsigned long timer4_millis;// = 0;
static unsigned char timer4_fract;// = 0;

INTERRUPT_HANDLER(TIM4_UPD_OVF_TRG_IRQHandler, TIM4_UPD_OVF_TRG_IRQn) /* TIM4 UPD/OVF */
{
	// copy these to local variables so they can be stored in registers
	// (volatile variables must be read from memory on every access)
	unsigned long m = timer4_millis;
#if (FRACT_INC != 0)
	unsigned char f = timer4_fract;
#endif

	m += MILLIS_INC;
#if (FRACT_INC != 0)
	f += FRACT_INC;
	if (f >= FRACT_MAX) {
		f -= FRACT_MAX;
		m += 1;
	}

	timer4_fract  = f;
#endif
	timer4_millis = m;
	timer4_overflow_count++;

	/* Clear Interrupt Pending bit */
#ifdef USE_SPL
	TIM4_ClearITPendingBit(TIM4_IT_UPDATE);
#else
	TIM4->SR1 = (uint8_t)(~TIM4_IT_UPDATE);
#endif
}

unsigned long millis()
{
	unsigned long m;

	// disable interrupts while we read timer4_millis or we might get an
	// inconsistent value (e.g. in the middle of a write to timer4_millis)
	BEGIN_CRITICAL
	m = timer4_millis;
	END_CRITICAL

	return m;
}


unsigned long micros()
{
#ifdef USE_SPL
	unsigned long m;
	uint8_t t;

	BEGIN_CRITICAL
	m = timer4_overflow_count;
	t = TIM4_GetCounter();

	// check if a fresh update event is still pending
	// if (TIM4->SR1 & 0x01)
	if ((TIM4_GetFlagStatus(TIM4_IT_UPDATE)==SET) && (t < (T4PERIOD-1)))
		m++;
	END_CRITICAL

//	return ((m << 8) + t) * (64 / clockCyclesPerMicrosecond());
//	return ((m*250+t) * (64/16) );	// FIXME: use calculated value
	m *= T4PERIOD;
	m += t;
//	m <<= 2;
	m *= ((T4PRESCALER_FACTOR*1000000L)/(F_CPU));
	return m;
#else
	unsigned long m;
	uint8_t t;

	BEGIN_CRITICAL
	m = timer4_overflow_count;
	t = TIM4->CNTR;

	// check if a fresh update event is still pending
	// if (TIM4->SR1 & 0x01)
	if ((TIM4->SR1 & (uint8_t)TIM4_IT_UPDATE) && (t < (T4PERIOD-1)))
		m++;
	END_CRITICAL

//	return ((m << 8) + t) * (64 / clockCyclesPerMicrosecond());
//	return ((m*250+t) * (64/16) );	// FIXME: use calculated value
	m *= T4PERIOD;
	m += t;
//	m <<= 2;
	m *= ((T4PRESCALER_FACTOR*1000000L)/(F_CPU));
	return m;
#endif
}


/**
 * Delay for the given number of milliseconds.
 *
 * Do a busy wait. Using the lower 16 bits of micros() is enough, as the
 * difference between the start time and the current time will never be much
 * higher than 1000.
 *
 * Using unsigned values is helpful here. This way value wrap-arounds between
 * start and now do not result in negative values but in the wanted absolute
 * difference. The magic of modulo-arithmethics.
 */
void delay(unsigned long ms)
{
	uint16_t start, now;

	start = (uint16_t) micros();	// use the lower 16 bits

	while (ms > 0) {
		yield();
		now = (uint16_t) micros();	// use the lower 16 bits
		while ( (ms > 0) && ((uint16_t)(now-start) >= 1000) ) {
			ms--;
			start += 1000;
		}
	}
}


/**
 *  Delay for the given number of microseconds.
 *
 *  Assumes a 1, 8, 12, 16, 20 or 24 MHz clock.
 */
void delayMicroseconds(unsigned int us)
{
	// call = 4 cycles, return = 4 cycles, arg access = ? cycles
//	while (us--);

#if F_CPU <= 1000000UL
#warning "1m"
	us <<= 3;	// adjust loop counter for low clock rates
# define LOG_CLOCK (F_CPU*8)
#elsif F_CPU <= 2000000UL
#warning "2m"
	us <<= 2;	// adjust loop counter for low clock rates
# define LOG_CLOCK 8000000UL	//(F_CPU*4)
#elsif F_CPU <= 4000000UL
#warning "3m"
	us <<= 1;	// adjust loop counter for low clock rates
# define LOG_CLOCK (F_CPU*2)
#else
//#warning "else"
# define LOG_CLOCK (F_CPU * 1)
//# define LOG_CLOCK 16000000UL
#endif

	// 13 + (7+nop)*us
	unsigned int i;
	for (i=us; i; i--) {
#if LOG_CLOCK >=7500000UL
		__asm__("nop");	// 7.5..8.5MHz -> 8 cyc/loop
#endif
#if LOG_CLOCK >=8500000UL
		__asm__("nop");	// 8.5..9.5MHz -> 9 cyc/loop
#endif
#if LOG_CLOCK >=9500000UL
		__asm__("nop");	// 9.5..10.5MHz -> 10 cyc/loop
#endif
#if LOG_CLOCK >=10500000UL
		__asm__("nop");	// 10.5..11.5MHz -> 11 cyc/loop
#endif
#if LOG_CLOCK >=11500000UL
		__asm__("nop");	// 11.5..12.5MHz -> 12 cyc/loop
#endif
	}

	// 25 Grundbedarf incl. call/ret, 7 pro einfachen Schleifendurchlauf
	// => t= 25 + 7*us bzs. 25 + 14*us
#if F_CPU >=10000000UL
//	for (i=us; i; i--);
#endif
/*FIXME: Zeitdauer nicht ausgezählt. Das kommt raus:

                                    283 ;	wiring.c: 124: while (us--);// __asm__ ("nop");
      00818B 16 03            [ 2]  284 	ldw	y, (0x03, sp)
      00818D                        285 00101$:
      00818D 93               [ 1]  286 	ldw	x, y
      00818E 90 5A            [ 2]  287 	decw	y
      008190 5D               [ 2]  288 	tnzw	x
      008191 26 FA            [ 1]  289 	jrne	00101$
      008193 81               [ 4]  290 	ret

	Aufruf und Test: 10 + 6 für 0. Durchlauf = 16
	Pro Durchlauf: 6
*/
#if 0
//FIXME
	// call = 4 cycles + 2 to 4 cycles to init us(2 for constant delay, 4 for variable)

	// calling avrlib's delay_us() function with low values (e.g. 1 or
	// 2 microseconds) gives delays longer than desired.
	//delay_us(us);
#if F_CPU >= 24000000L
	// for the 24 MHz clock for the aventurous ones, trying to overclock

	// zero delay fix
	if (!us) return; //  = 3 cycles, (4 when true)

	// the following loop takes a 1/6 of a microsecond (4 cycles)
	// per iteration, so execute it six times for each microsecond of
	// delay requested.
	us *= 6; // x6 us, = 7 cycles

	// account for the time taken in the preceeding commands.
	// we just burned 22 (24) cycles above, remove 5, (5*4=20)
	// us is at least 6 so we can substract 5
	us -= 5; //=2 cycles

#elif F_CPU >= 20000000L
	// for the 20 MHz clock on rare Arduino boards

	// for a one-microsecond delay, simply return.  the overhead
	// of the function call takes 18 (20) cycles, which is 1us
	__asm__ __volatile__ (
		"nop" "\n\t"
		"nop" "\n\t"
		"nop" "\n\t"
		"nop"); //just waiting 4 cycles
	if (us <= 1) return; //  = 3 cycles, (4 when true)

	// the following loop takes a 1/5 of a microsecond (4 cycles)
	// per iteration, so execute it five times for each microsecond of
	// delay requested.
	us = (us << 2) + us; // x5 us, = 7 cycles

	// account for the time taken in the preceeding commands.
	// we just burned 26 (28) cycles above, remove 7, (7*4=28)
	// us is at least 10 so we can substract 7
	us -= 7; // 2 cycles

#elif F_CPU >= 16000000L
	// for the 16 MHz clock on most Arduino boards

	// for a one-microsecond delay, simply return.  the overhead
	// of the function call takes 14 (16) cycles, which is 1us
	if (us <= 1) return; //  = 3 cycles, (4 when true)

	// the following loop takes 1/4 of a microsecond (4 cycles)
	// per iteration, so execute it four times for each microsecond of
	// delay requested.
	us <<= 2; // x4 us, = 4 cycles

	// account for the time taken in the preceeding commands.
	// we just burned 19 (21) cycles above, remove 5, (5*4=20)
	// us is at least 8 so we can substract 5
	us -= 5; // = 2 cycles,

#elif F_CPU >= 12000000L
	// for the 12 MHz clock if somebody is working with USB

	// for a 1 microsecond delay, simply return.  the overhead
	// of the function call takes 14 (16) cycles, which is 1.5us
	if (us <= 1) return; //  = 3 cycles, (4 when true)

	// the following loop takes 1/3 of a microsecond (4 cycles)
	// per iteration, so execute it three times for each microsecond of
	// delay requested.
	us = (us << 1) + us; // x3 us, = 5 cycles

	// account for the time taken in the preceeding commands.
	// we just burned 20 (22) cycles above, remove 5, (5*4=20)
	// us is at least 6 so we can substract 5
	us -= 5; //2 cycles

#elif F_CPU >= 8000000L
	// for the 8 MHz internal clock

	// for a 1 and 2 microsecond delay, simply return.  the overhead
	// of the function call takes 14 (16) cycles, which is 2us
	if (us <= 2) return; //  = 3 cycles, (4 when true)

	// the following loop takes 1/2 of a microsecond (4 cycles)
	// per iteration, so execute it twice for each microsecond of
	// delay requested.
	us <<= 1; //x2 us, = 2 cycles

	// account for the time taken in the preceeding commands.
	// we just burned 17 (19) cycles above, remove 4, (4*4=16)
	// us is at least 6 so we can substract 4
	us -= 4; // = 2 cycles

#else
	// for the 1 MHz internal clock (default settings for common Atmega microcontrollers)

	// the overhead of the function calls is 14 (16) cycles
	if (us <= 16) return; //= 3 cycles, (4 when true)
	if (us <= 25) return; //= 3 cycles, (4 when true), (must be at least 25 if we want to substract 22)

	// compensate for the time taken by the preceeding and next commands (about 22 cycles)
	us -= 22; // = 2 cycles
	// the following loop takes 4 microseconds (4 cycles)
	// per iteration, so execute it us/4 times
	// us is at least 4, divided by 4 gives us 1 (no zero delay bug)
	us >>= 2; // us div 4, = 4 cycles
	

#endif

	// busy wait
	__asm__ __volatile__ (
		"1: sbiw %0,1" "\n\t" // 2 cycles
		"brne 1b" : "=w" (us) : "0" (us) // 2 cycles
	);
	// return = 4 cycles
#endif
}
