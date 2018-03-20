//#include "stm8l_tim4.h"

#ifdef  TIM4_FREE

#if (F_CPU == 16000000UL)	  
#define DELAY_COUNT (uint16_t)2000
#elif (F_CPU == 8000000UL)	
#define DELAY_COUNT (uint16_t)1000
#elif (F_CPU == 4000000UL)	
#define DELAY_COUNT (uint16_t)500
#elif (F_CPU == 2000000UL)	
#define DELAY_COUNT (uint16_t)250
#elif (F_CPU == 1000000UL)	
#define DELAY_COUNT (uint16_t)125
#endif

void delay(uint16_t ms)
{
#ifdef DELAY_COUNT
  uint16_t i;
  if ((CLK_GetSYSCLKSource() == CLK_SYSCLKSource_LSE) || (CLK_GetSYSCLKSource() == CLK_SYSCLKSource_LSI)){
	 for(;ms>0;ms--)
       __asm__("nop\n");
 
  }else{
     for(;ms>0;ms--)
        for(i=DELAY_COUNT;i>0;i--)
           __asm__("nop\n");__asm__("nop\n");__asm__("nop\n");__asm__("nop\n");__asm__("nop\n");

  }
#else
     for(;ms>0;ms--)
        for(i=DELAY_COUNT;i>0;i--)
           __asm__("nop\n");__asm__("nop\n");__asm__("nop\n");__asm__("nop\n");__asm__("nop\n");
#endif
}

void delayMicroseconds(unsigned int us) /*lse/lsi */
{ 
#ifdef DELAY_COUNT
   uint8_t i;
   uint8_t j=2;
   us = us*DELAY_COUNT/2000;
   
   for(;j>0;j--)
     for(i=us;i>0;i--)
       __asm__("nop\n");__asm__("nop\n");__asm__("nop\n");__asm__("nop\n");__asm__("nop\n");
#else
     while(i>0;i--);
#endif
}

#else //TIM4_FREE

#include "stm8_tim4.h"

#endif //TIM4_FREE


#if  defined(HSI)  
   #if (F_CPU == 16000000UL)
     #define CLK_SYSCLKDiv CLK_SYSCLKDiv_1
   #elif (F_CPU == 8000000UL)	
     #define CLK_SYSCLKDiv CLK_SYSCLKDiv_2
   #elif (F_CPU == 4000000UL)	
     #define CLK_SYSCLKDiv CLK_SYSCLKDiv_4
   #elif (F_CPU == 2000000UL)	
     #define CLK_SYSCLKDiv CLK_SYSCLKDiv_8
   #elif (F_CPU == 1000000UL)	
     #define CLK_SYSCLKDiv CLK_SYSCLKDiv_16
   #else
	  #error !F_CPU select err!	
   #endif
#elif defined(HSE)
   #if (HSE == 16)
     #if (F_CPU == 16000000UL)
       #define CLK_SYSCLKDiv CLK_SYSCLKDiv_1
     #elif (F_CPU == 8000000UL)	
       #define CLK_SYSCLKDiv CLK_SYSCLKDiv_2
     #elif (F_CPU == 4000000UL)	
       #define CLK_SYSCLKDiv CLK_SYSCLKDiv_4
     #elif (F_CPU == 2000000UL)	
       #define CLK_SYSCLKDiv CLK_SYSCLKDiv_8
     #elif (F_CPU == 1000000UL)	
       #define CLK_SYSCLKDiv CLK_SYSCLKDiv_16
     #else
 	  #error !F_CPU select err!	
     #endif
   #elif (HSE == 8)	
     #if (F_CPU == 16000000UL)
       #error HSE=8M cannot set 16M F_CPU
     #elif (F_CPU == 8000000UL)	
       #define CLK_SYSCLKDiv CLK_SYSCLKDiv_1
     #elif (F_CPU == 4000000UL)	
       #define CLK_SYSCLKDiv CLK_SYSCLKDiv_2
     #elif (F_CPU == 2000000UL)	
       #define CLK_SYSCLKDiv CLK_SYSCLKDiv_4
     #elif (F_CPU == 1000000UL)	
       #define CLK_SYSCLKDiv CLK_SYSCLKDiv_8
     #else
 	  #error !F_CPU select err!	
     #endif
    #else
	  #error !This HSE please add me!	
    #endif
#elif defined(LSE)
	  #error !This HSE please add me!	
#elif defined(LSI)
	  #error !This HSE please add me!	
#endif


void init()
{

#ifndef ENABLE_SWIM  /*selected in menu term Swin*/
	CFG->GCR = CFG_GCR_SWD;// free the SWIM pin to be used as a general I/O-Pin
#endif


// set the clock
    CLK_SYSCLKDivConfig(CLK_SYSCLKDiv);

#if defined(HSE)
  /* Select HSE as system clock source */
    CLK_SYSCLKSourceSwitchCmd(ENABLE);
    CLK_SYSCLKSourceConfig(CLK_SYSCLKSource_HSE);
    while (CLK_GetSYSCLKSource() != CLK_SYSCLKSource_HSE) {}
#elif defined(LSE)
  /* Select LSE as system clock source */
    CLK_SYSCLKSourceSwitchCmd(ENABLE);
    CLK_SYSCLKSourceConfig(CLK_SYSCLKSource_LSE);
    while (CLK_GetSYSCLKSource() != CLK_SYSCLKSource_LSE) {}
#elif defined(LSI)
  /* Select LSE as system clock source */
    CLK_SYSCLKSourceSwitchCmd(ENABLE);
    CLK_SYSCLKSourceConfig(CLK_SYSCLKSource_LSE);
    while (CLK_GetSYSCLKSource() != CLK_SYSCLKSource_LSE) {}
#endif

#ifndef  TIM4_FREE
    CLK_PeripheralClockConfig(CLK_Peripheral_TIM4, ENABLE);//STM8L 外设时钟默认关闭，需打开
	TIM4_DeInit();
	// set timer 4 prescale factor and period (typ. @16MHz: 64*250=1ms)
	TIM4_TimeBaseInit(T4PRESCALER, (uint8_t) T4PERIOD-1);
	/* Clear TIM4 update flag */
	TIM4_ClearFlag(TIM4_FLAG_UPDATE);	// TIM4->SR1 = (uint8_t)(~0x01);
	/* Enable update interrupt */
	TIM4_ITConfig(TIM4_IT_UPDATE, ENABLE);	// TIM4->IER |= (uint8_t)TIM4_IT;
	/* Enable TIM4 */
	TIM4_Cmd(ENABLE);	// TIM4->CR1 |= TIM4_CR1_CEN;
    CLK_PeripheralClockConfig(CLK_Peripheral_USART1,ENABLE);
#endif

	enableInterrupts();
}

   
