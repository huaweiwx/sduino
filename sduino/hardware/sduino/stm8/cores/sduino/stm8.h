/*
  Copyright (c) 20017-2018 huaweiwx@sina.com
  for STM8L
  
  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General
  Public License along with this library; if not, write to the
  Free Software Foundation, Inc., 59 Temple Place, Suite 330,
  Boston, MA  02111-1307  USA

*/

#ifndef _STM8_H_
#define _STM8_H_

//for SDUINO 

#if defined(STM8S003)||defined(STM8S103)||defined(STM8S105)
#include <stm8s.h>

#else  /*STM8L*/

#define STM8L 1

#include <stm8l15x.h>

#define SPI SPI1
#define SPI_BaseAddress  SPI1_BASE
#define SPI_FIRSTBIT_MSB SPI_FirstBit_MSB
#define SPI_FIRSTBIT_LSB SPI_FirstBit_LSB
#define ICR  CR3

//TIM1
#define  TIM1_OCMODE_TIMING    TIM1_OCMode_Timing   
#define  TIM1_OCMODE_ACTIVE    TIM1_OCMode_Active   
#define  TIM1_OCMODE_INACTIVE  TIM1_OCMode_Inactive 
#define  TIM1_OCMODE_TOGGLE    TIM1_OCMode_Toggle   
#define  TIM1_OCMODE_PWM1      TIM1_OCMode_PWM1     
#define  TIM1_OCMODE_PWM2      TIM1_OCMode_PWM2     

#define  TIM1_OPMODE_SINGLE           TIM1_OPMode_Single    
#define  TIM1_OPMODE_REPETITIVE       TIM1_OPMode_Repetitive

#define  TIM1_CHANNEL_1        TIM1_Channel_1
#define  TIM1_CHANNEL_2        TIM1_Channel_2
#define  TIM1_CHANNEL_3        TIM1_Channel_3
#define  TIM1_CHANNEL_4        TIM1_Channel_4

#define  TIM1_COUNTERMODE_UP              TIM1_CounterMode_Up            
#define  TIM1_COUNTERMODE_DOWN            TIM1_CounterMode_Down          
#define  TIM1_COUNTERMODE_CENTERALIGNED1  TIM1_CounterMode_CenterAligned1
#define  TIM1_COUNTERMODE_CENTERALIGNED2  TIM1_CounterMode_CenterAligned2
#define  TIM1_COUNTERMODE_CENTERALIGNED3  TIM1_CounterMode_CenterAligned3
  
#define TIM1_OCPOLARITY_HIGH TIM1_OCPolarity_High
#define TIM1_OCPOLARITY_LOW  TIM1_OCPolarity_Low

#define TIM1_OCNPOLARITY_HIGH TIM1_OCNPolarity_High 
#define TIM1_OCNPOLARITY_LOW  TIM1_OCNPolarity_Low  

#define TIM1_OUTPUTSTATE_DISABLE TIM1_OutputNState_Disable
#define TIM1_OUTPUTSTATE_ENABLE  TIM1_OutputNState_Enable 

#define TIM1_BREAK_ENABLE  TIM1_BreakState_Enable 
#define TIM1_BREAK_DISABLE TIM1_BreakState_Disable

#define TIM1_BREAKPOLARITY_LOW  TIM1_BreakPolarity_Low 
#define TIM1_BREAKPOLARITY_HIGH TIM1_BreakPolarity_High

#define TIM1_AUTOMATICOUTPUT_ENABLE   TIM1_AutomaticOutput_Enable  
#define TIM1_AUTOMATICOUTPUT_DISABLE  TIM1_AutomaticOutput_Disable 

#define TIM1_LOCKLEVEL_OFF TIM1_LockLevel_Off
#define TIM1_LOCKLEVEL_1   TIM1_LockLevel_1  
#define TIM1_LOCKLEVEL_2   TIM1_LockLevel_2  
#define TIM1_LOCKLEVEL_3   TIM1_LockLevel_3  

#define TIM1_OSSISTATE_ENABLE  TIM1_OSSIState_Enable 
#define TIM1_OSSISTATE_DISABLE TIM1_OSSIState_Disable

#define TIM1_OCIDLESTATE_SET   TIM1_OCIdleState_Set   
#define TIM1_OCIDLESTATE_RESET TIM1_OCIdleState_Reset 

#define TIM1_OCNIDLESTATE_SET    TIM1_OCNIdleState_Set  
#define TIM1_OCNIDLESTATE_RESET  TIM1_OCNIdleState_Reset

#define TIM1_ICPOLARITY_RISING   TIM1_ICPolarity_Rising 
#define TIM1_ICPOLARITY_FALLING  TIM1_ICPolarity_Falling

#define TIM1_ICSELECTION_DIRECTTI    TIM1_ICSelection_DirectTI   
#define TIM1_ICSELECTION_INDIRECTTI  TIM1_ICSelection_IndirectTI 
#define TIM1_ICSELECTION_TRGI        TIM1_ICSelection_TRGI       

#define TIM1_ICPSC_DIV1  TIM1_ICPSC_DIV1 
#define TIM1_ICPSC_DIV2  TIM1_ICPSC_DIV2 
#define TIM1_ICPSC_DIV4  TIM1_ICPSC_DIV4 
#define TIM1_ICPSC_DIV8  TIM1_ICPSC_DIV8 

//TIM2
#define  TIM2_PRESCALER_1      TIM2_Prescaler_1
#define  TIM2_PRESCALER_2      TIM2_Prescaler_2
#define  TIM2_PRESCALER_4      TIM2_Prescaler_4
#define  TIM2_PRESCALER_8      TIM2_Prescaler_8
#define  TIM2_PRESCALER_16     TIM2_Prescaler_16
#define  TIM2_PRESCALER_32     TIM2_Prescaler_32
#define  TIM2_PRESCALER_64     TIM2_Prescaler_64
#define  TIM2_PRESCALER_128    TIM2_Prescaler_128
#define  TIM2_PRESCALER_256    TIM2_Prescaler_256
#define  TIM2_PRESCALER_512    TIM2_Prescaler_512
#define  TIM2_PRESCALER_1024   TIM2_Prescaler_1024
#define  TIM2_PRESCALER_2048   TIM2_Prescaler_2048
#define  TIM2_PRESCALER_4096   TIM2_Prescaler_4096
#define  TIM2_PRESCALER_8192   TIM2_Prescaler_8192
#define  TIM2_PRESCALER_16384  TIM2_Prescaler_16384
#define  TIM2_PRESCALER_32768  TIM2_Prescaler_32768

#define  TIM2_OCMODE_TIMING    TIM2_OCMode_Timing  
#define  TIM2_OCMODE_ACTIVE    TIM2_OCMode_Active  
#define  TIM2_OCMODE_INACTIVE  TIM2_OCMode_Inactive
#define  TIM2_OCMODE_TOGGLE    TIM2_OCMode_Toggle  
#define  TIM2_OCMODE_PWM1      TIM2_OCMode_PWM1    
#define  TIM2_OCMODE_PWM2      TIM2_OCMode_PWM2

/*CCMR*/
#define  TIM2_CCMR_ICxPSC      TIM_CCMR_ICxPSC  
#define  TIM2_CCMR_ICxF        TIM_CCMR_ICxF
#define  TIM2_CCMR_OCM         TIM_CCMR_OCM  
#define  TIM2_CCMR_OCxPE       TIM_CCMR_OCxPE
#define  TIM2_CCMR_CCxS        TIM_CCMR_CCxS

/*CCER1*/
#define  TIM2_CCER1_CC2P   		TIM_CCER1_CC2P
#define  TIM2_CCER1_CC2E   		TIM_CCER1_CC2E
#define  TIM2_CCER1_CC1P   		TIM_CCER1_CC1P
#define  TIM2_CCER1_CC1E   		TIM_CCER1_CC1E

/*CR*/
#define TIM2_CR1_ARPE   	   TIM_CR1_ARPE
#define TIM2_CR1_OPM    	   TIM_CR1_OPM 
#define TIM2_CR1_URS    	   TIM_CR1_URS
#define TIM2_CR1_UDIS   	   TIM_CR1_UDIS	 
#define TIM2_CR1_CEN    	   TIM_CR1_CEN 
                                
                                 

#define  TIM2_OPMODE_SINGLE           TIM2_OPMode_Single    
#define  TIM2_OPMODE_REPETITIVE       TIM2_OPMode_Repetitive

#define  TIM2_PSCRELOADMODE_UPDATE     TIM2_PSCReloadMode_Update   
#define  TIM2_PSCRELOADMODE_IMMEDIATE  TIM2_PSCReloadMode_Immediate

#define  TIM2_UPDATESOURCE_GLOBAL      TIM2_UpdateSource_Global 
#define  TIM2_UPDATESOURCE_REGULAR     TIM2_UpdateSource_Regular

#define  TIM2_EVENTSOURCE_UPDATE  	   TIM2_EventSource_Update

#define	 TIM2_FLAG_UPDATE       	   TIM2_FLAG_Update

#define	 TIM2_IT_UPDATE	               TIM2_IT_Update


//TIM3
#define  TIM3_PRESCALER_1      TIM3_Prescaler_1
#define  TIM3_PRESCALER_2      TIM3_Prescaler_2
#define  TIM3_PRESCALER_4      TIM3_Prescaler_4
#define  TIM3_PRESCALER_8      TIM3_Prescaler_8
#define  TIM3_PRESCALER_16     TIM3_Prescaler_16
#define  TIM3_PRESCALER_32     TIM3_Prescaler_32
#define  TIM3_PRESCALER_64     TIM3_Prescaler_64
#define  TIM3_PRESCALER_128    TIM3_Prescaler_128
#define  TIM3_PRESCALER_256    TIM3_Prescaler_256
#define  TIM3_PRESCALER_512    TIM3_Prescaler_512
#define  TIM3_PRESCALER_1024   TIM3_Prescaler_1024
#define  TIM3_PRESCALER_2048   TIM3_Prescaler_2048
#define  TIM3_PRESCALER_4096   TIM3_Prescaler_4096
#define  TIM3_PRESCALER_8192   TIM3_Prescaler_8192
#define  TIM3_PRESCALER_16384  TIM3_Prescaler_16384
#define  TIM3_PRESCALER_32768  TIM3_Prescaler_32768

#define  TIM3_OCMODE_TIMING    TIM3_OCMode_Timing  
#define  TIM3_OCMODE_ACTIVE    TIM3_OCMode_Active  
#define  TIM3_OCMODE_INACTIVE  TIM3_OCMode_Inactive
#define  TIM3_OCMODE_TOGGLE    TIM3_OCMode_Toggle  
#define  TIM3_OCMODE_PWM1      TIM3_OCMode_PWM1    
#define  TIM3_OCMODE_PWM2      TIM3_OCMode_PWM2

#define  TIM3_CCMR_ICxPSC      TIM_CCMR_ICxPSC  
#define  TIM3_CCMR_ICxF        TIM_CCMR_ICxF
#define  TIM3_CCMR_OCM         TIM_CCMR_OCM  
#define  TIM3_CCMR_OCxPE       TIM_CCMR_OCxPE
#define  TIM3_CCMR_CCxS        TIM_CCMR_CCxS

/*CCER1*/
#define  TIM3_CCER1_CC2P   		TIM_CCER1_CC2P
#define  TIM3_CCER1_CC2E   		TIM_CCER1_CC2E
#define  TIM3_CCER1_CC1P   		TIM_CCER1_CC1P
#define  TIM3_CCER1_CC1E   		TIM_CCER1_CC1E
                          
#define  TIM3_CR1_ARPE   	   TIM_CR1_ARPE
#define  TIM3_CR1_OPM    	   TIM_CR1_OPM 
#define  TIM3_CR1_URS    	   TIM_CR1_URS
#define  TIM3_CR1_UDIS   	   TIM_CR1_UDIS	 
#define  TIM3_CR1_CEN    	   TIM_CR1_CEN 

//TIM4
#define  TIM4_PRESCALER_1      TIM4_Prescaler_1
#define  TIM4_PRESCALER_2      TIM4_Prescaler_2
#define  TIM4_PRESCALER_4      TIM4_Prescaler_4
#define  TIM4_PRESCALER_8      TIM4_Prescaler_8
#define  TIM4_PRESCALER_16     TIM4_Prescaler_16
#define  TIM4_PRESCALER_32     TIM4_Prescaler_32
#define  TIM4_PRESCALER_64     TIM4_Prescaler_64
#define  TIM4_PRESCALER_128    TIM4_Prescaler_128
#define  TIM4_PRESCALER_256    TIM4_Prescaler_256
#define  TIM4_PRESCALER_512    TIM4_Prescaler_512
#define  TIM4_PRESCALER_1024   TIM4_Prescaler_1024
#define  TIM4_PRESCALER_2048   TIM4_Prescaler_2048
#define  TIM4_PRESCALER_4096   TIM4_Prescaler_4096
#define  TIM4_PRESCALER_8192   TIM4_Prescaler_8192
#define  TIM4_PRESCALER_16384  TIM4_Prescaler_16384
#define  TIM4_PRESCALER_32768  TIM4_Prescaler_32768

#define  TIM4_OPMODE_SINGLE           TIM4_OPMode_Single    
#define  TIM4_OPMODE_REPETITIVE       TIM4_OPMode_Repetitive

#define  TIM4_PSCRELOADMODE_UPDATE     TIM4_PSCReloadMode_Update   
#define  TIM4_PSCRELOADMODE_IMMEDIATE  TIM4_PSCReloadMode_Immediate

#define  TIM4_UPDATESOURCE_GLOBAL      TIM4_UpdateSource_Global 
#define  TIM4_UPDATESOURCE_REGULAR     TIM4_UpdateSource_Regular

#define  TIM4_EVENTSOURCE_UPDATE  	   TIM4_EventSource_Update

#define	 TIM4_FLAG_UPDATE       	   TIM4_FLAG_Update

#define	 TIM4_IT_UPDATE	               TIM4_IT_Update

//ADC
#define CSR 			SR
#define ADC1_CR1_ADON	ADC_CR1_ADON

#define ADC1_FLAG_EOC   ADC_FLAG_EOC
#define ADC1_FLAG_AWD   ADC_FLAG_AWD
#define ADC1_FLAG_OVR   ADC_FLAG_OVER


#endif

#endif
