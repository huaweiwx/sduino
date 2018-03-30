//#include "stm8l_tim4.h"

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
uint16_t i;
#ifndef DELAY_COUNT
  for(;ms>0;ms--){
        __asm__("nop\n");__asm__("nop\n");__asm__("nop\n");__asm__("nop\n");__asm__("nop\n");
  }
#else
  for(;ms>0;ms--)
      for(i=DELAY_COUNT;i>0;i--)
          __asm__("nop\n");
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

//#include "stm8_tim4.h"

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

#include "stm8/stm8_tim4.h"

void init()
{
#ifndef ENABLE_SWIM  /*selected in menu term Swin*/
	CFG->GCR = CFG_GCR_SWD;// free the SWIM pin to be used as a general I/O-Pin
#endif
    
	SYSCFG_REMAPDeInit_M(); /*Deinitializes the Remapping registers to their default reset values.*/

// set the clock
    CLK_SYSCLKDivConfig_M(CLK_SYSCLKDiv);

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

    TIME4_int(T4PERIOD-1);
    enableInterrupts();
}

   
