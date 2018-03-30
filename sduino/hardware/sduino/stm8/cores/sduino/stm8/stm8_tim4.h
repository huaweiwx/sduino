
/* calculate the best prescaler and timer period for TIM4 for millis()
 *
 * The precaler factor could be calculated from the prescaler enum by
 * bit shifting, but we want to be independent from possible irregular
 * definitions for the chose CPU type.
 */
#if (clockCyclesPerMillisecond() < 256)
# define T4PRESCALER	TIM4_PRESCALER_2
# define T4PRESCALER_FACTOR	2
#elif (clockCyclesPerMillisecond() < 512)
# define T4PRESCALER	TIM4_PRESCALER_4
# define T4PRESCALER_FACTOR	4
#elif (clockCyclesPerMillisecond() < 1024)
# define T4PRESCALER	TIM4_PRESCALER_8
# define T4PRESCALER_FACTOR	8
#elif (clockCyclesPerMillisecond() < 2048)
# define T4PRESCALER	TIM4_PRESCALER_16
# define T4PRESCALER_FACTOR	16
#elif (clockCyclesPerMillisecond() < 4096)
# define T4PRESCALER	TIM4_PRESCALER_32
# define T4PRESCALER_FACTOR	32
#elif (clockCyclesPerMillisecond() < 8192)
# define T4PRESCALER	TIM4_PRESCALER_64
# define T4PRESCALER_FACTOR	64
#elif (clockCyclesPerMillisecond() < 16384)
# define T4PRESCALER	TIM4_PRESCALER_128
# define T4PRESCALER_FACTOR	128
#else
#error "could not calculate a valid prescaler für TIM4"
#endif

#define T4PERIOD	(clockCyclesPerMillisecond()/T4PRESCALER_FACTOR)  /*16000/128 = 125*/

// the prescaler is set so that timer4 ticks every 64 clock cycles, and the
// the overflow handler is called every 125 ticks.
# define MICROSECONDS_PER_TIMER0_OVERFLOW (F_CPU/(T4PRESCALER_FACTOR*T4PERIOD))
//#define MICROSECONDS_PER_TIMER0_OVERFLOW (clockCyclesToMicroseconds(64 * 250))

// the whole number of milliseconds per timer4 overflow
#define MILLIS_INC (MICROSECONDS_PER_TIMER0_OVERFLOW / 1000)

// the fractional number of milliseconds per timer4 overflow. we shift right
// by three to fit these numbers into a byte. (for the clock speeds we care
// about - 8 and 16 MHz - this doesn't lose precision.)
#define FRACT_INC ((MICROSECONDS_PER_TIMER0_OVERFLOW % 1000) >> 3)
#define FRACT_MAX (1000 >> 3)


void TIME4_int(uint8_t preiod){

#ifdef STM8L	
    CLK_PeripheralClockConfig(CLK_Peripheral_TIM4, ENABLE);
#endif	
  /* TIM4 configuration:
   - TIM4CLK is set to 16 MHz, the TIM4 Prescaler is equal to 128 so the TIM1 counter
   clock used is 16 MHz / 128 = 125 000 Hz
  - With 125 000 Hz we can generate time base:
      max time base is 2.048 ms if TIM4_PERIOD = 255 --> (255 + 1) / 125000 = 2.048 ms
      min time base is 0.016 ms if TIM4_PERIOD = 1   --> (  1 + 1) / 125000 = 0.016 ms
  - In this example we need to generate a time base equal to 1 ms
   so TIM4_PERIOD = (0.001 * 125000 - 1) = 124 */
    //CLK_PeripheralClockConfig((CLK_Peripheral_TypeDef)CLK_Peripheral_TIM4, ENABLE);
    CLK->PCKENR1 |= CLK_PCKENR1_TIM4;//

    /* Time base configuration */
    //TIM4_TimeBaseInit(TIM4_Prescaler_128, 124);//1ms period
    /* Set the Autoreload value */
    TIM4->ARR = (uint8_t)(preiod);
    /* Set the Prescaler value */
    TIM4->PSCR = (uint8_t)(TIM4_Prescaler_128);
    /* Generate an update event to reload the Prescaler value immediately */
    TIM4->EGR = TIM4_EventSource_Update;



    /* Clear TIM4 update flag */
    //TIM4_ClearFlag(TIM4_FLAG_Update);
    TIM4->SR1 = (uint8_t)(~((uint8_t)TIM4_FLAG_Update));

  
  
    /* Enable update interrupt */
    //TIM4_ITConfig(TIM4_IT_Update, ENABLE);
    TIM4->IER |= (uint8_t)TIM4_IT_Update;
    
    /* enable interrupts */
    enableInterrupts();

    /* Enable TIM4 */
    //TIM4_Cmd(ENABLE);
    TIM4->CR1 |= TIM4_CR1_CEN ;
}

__IO uint32_t timer4_overflow_count;
 void  systic_callback(void);
//INTERRUPT_HANDLER(TIM4_UPD_OVF_TRG_IRQHandler, TIM4_UPD_OVF_TRG_IRQn) /* TIM4 UPD/OVF */
void TIM4_UPD_OVF_TRG_IRQHandler(void) __interrupt(TIM4_UPD_OVF_TRG_IRQn)
{
	TIM4->SR1 = (uint8_t)(~TIM2_IT_Update);
    timer4_overflow_count++;
    systic_callback();	
}
