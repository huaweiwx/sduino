/**
  ******************************************************************************
  * @file    stm8x_fastIO.h
  * @author  huaweiwx@sina.com
  * @version V18.1
  * @date    14-April-2018
  * @brief   This file contains aliases definition for the STM8s  constants 
  *          macros and functions maintained for legacy purpose.
  ******************************************************************************
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
#ifndef _STM8_FASTIO_H_
#define _STM8_FASTIO_H_

#ifndef ARDUINO_ARCH_STM8
#  error !STM8 only!  other add me here 
#endif

#define FASTIO_PORTPIN			    STM8_GPIO_ASSIGN
#define FASTIO_PORTPIN_POLARITY		STM8_GPIO_ASSIGN_POLARITY
#define FASTIO			STM8_GNAME_ASSIGN
#define FASTIO_POLARITY	STM8_GNAME_ASSIGN_POLARITY


#define GPIO_SETMODE_IN(p,n)		(GPIO##p->DDR &= ~_BV(n))
#define GPIO_SETMODE_OUT(p,n)	    (GPIO##p->DDR |=  _BV(n))
#define GPIO_SETMODE_INPUT(p,n)	do\
{\
  GPIO##p->CR2 &= ~_BV(n);\
  GPIO##p->CR1 &= ~_BV(n));\
  GPIO##p->DDR &= ~_BV(n));\
}while(0)

#define GPIO_SETMODE_INPUT_I(p,n) do\
{\
	GPIO##p->DDR &= ~_BV(n);\
	GPIO##p->CR1 &= ~_BV(n));\
	GPIO##p->CR2 |=  _BV(n);\
}while(0)

#define GPIO_SETMODE_INPUT_UP(p,n)	do\
{\
	GPIO##p->CR2 &= ~_BV(n);\
	GPIO##p->DDR &= ~_BV(n);\
	GPIO##p->CR1 |=  _BV(n));\
}while(0)
	
#define GPIO_SETMODE_INPUT_UPI(p,n)	do\
{\
	GPIO##p->DDR &= ~_BV(n);\
	GPIO##p->CR1 |=  _BV(n);\
	GPIO##p->CR2 |=  _BV(n);\
}while(0)

#define GPIO_SETMODE_OUTPUT(p,n) do\
{\
	GPIO##p->CR1 |=  _BV(n);\
	GPIO##p->CR2 &= ~_BV(n);\
	GPIO##p->DDR |=  _BV(n);\
}while(0)
	
#define GPIO_SETMODE_OUTPUT_OD(p,n)	do\
{\
	GPIO##p->CR1 &= ~_BV(n);\
	GPIO##p->CR2 &= ~_BV(n);\
	GPIO##p->DDR |=  _BV(n);\
}while(0)
	
#define GPIO_SETMODE_OUTPUT_ODI(p,n) do\
{\
	GPIO##p->CR1 &= ~_BV(n);\
	GPIO##p->DDR |=  _BV(n);\
	GPIO##p->CR2 |=  _BV(n);\
}while(0)

#define GPIO_SETMODE_OUTPUT_PPI(p,n) do\
{\
	GPIO##p->DDR |=  _BV(n);\
	GPIO##p->CR1 |=  _BV(n);\
	GPIO##p->CR2 |=  _BV(n);\
}while(0)

#define STM8_GPIO_ASSIGN(A, C) \
static  void   P##A##C##_Set(void)            {GPIO##A->ODR |=  _BV( C);}\
static  void   P##A##C##_Clr(void)            {GPIO##A->ODR &= ~_BV( C);}\
static  void   P##A##C##_Toggle(void)         {GPIO##A->ODR ^=  _BV( C);}\
static  void   P##A##C##_MakeOut(void)        {GPIO##A->DDR |=  _BV( C);}\
static  void   P##A##C##_MakeIn(void)         {GPIO##A->DDR &= ~_BV( C);}\
static  void   P##A##C##_SetCR1(void)         {GPIO##A->CR1 |=  _BV( C);}\
static  void   P##A##C##_ClrCR1(void)         {GPIO##A->CR1 &= ~_BV( C);}\
static  void   P##A##C##_SetCR2(void)         {GPIO##A->CR2 |=  _BV( C);}\
static  void   P##A##C##_ClrCR2(void)         {GPIO##A->CR2 &= ~_BV( C);}\
static  void   P##A##C##_INPUT(void)		  {GPIO_SETMODE_INPUT(A, C);}\
static  void   P##A##C##_INPUT_I(void)        {GPIO_SETMODE_INPUT_I(A, C);}\
static  void   P##A##C##_INPUT_UP(void)       {GPIO_SETMODE_INPUT_UP(A,C);}\
static  void   P##A##C##_INPUT_UPI(void)      {GPIO_SETMODE_INPUT_UPI(A,C);}\
static  void   P##A##C##_OUTPUT(void)         {GPIO_SETMODE_OUTPUT(A,C);}\
static  void   P##A##C##_OUTPUT_OD(void)      {GPIO_SETMODE_OUTPUT_OD(A,C);}\
static  void   P##A##C##_OUTPUT_ODI(void)     {GPIO_SETMODE_OUTPUT_ODI(A,C);}\
static  void   P##A##C##_OUTPUT_PPI(void)     {GPIO_SETMODE_OUTPUT_PPI(A,C);}\
static  uint8_t  P##A##C##_ReadIn(void)       {return ((GPIO##A->IDR & _BV( C)) != 0);}\
static  uint8_t  P##A##C##_Read(void)         {return P##A##C##_ReadIn();}\
static  uint8_t  P##A##C##_ReadOut(void)      {return ((GPIO##A->ODR & _BV( C)) != 0);}\
static  uint8_t  P##A##C##_ReadDir(void)      {return ((GPIO##A->DDR & _BV( C)) != 0);}\
static  void   	 P##A##C##_Out(uint8_t x)     {(x)?(P##A##C##_Set()):(P##A##C##_Clr());}\
static  uint8_t  P##A##C##_IsOutHigh(void)    {return P##A##C##_ReadOut();}\
static  uint8_t  P##A##C##_IsOutLow(void)     {return !P##A##C##_ReadOut();}


#define STM8_GPIO_ASSIGN_POLARITY(A, C, X) \
STM8_GPIO_ASSIGN(A, C)\
static  void     P##A##C##_On(void)           { (X)?(P##A##C##_Set()):(P##A##C##_Clr());}\
static  void     P##A##C##_Off(void)          {(!X)?(P##A##C##_Set()):(P##A##C##_Clr());}\
static  uint8_t  P##A##C##_IsOn(void)         {return  (X)?P##A##C##_IsOutHigh():P##A##C##_IsOutLow();}\
static  uint8_t  P##A##C##_IsOff(void)        {return (!X)?P##A##C##_IsOutHigh():P##A##C##_IsOutLow();}

#define STM8_GNAME_ASSIGN(N, A, C) \
static  void   N##_Set(void)            {GPIO##A->ODR |=  _BV( C);}\
static  void   N##_Clr(void)            {GPIO##A->ODR &= ~_BV( C);}\
static  void   N##_Toggle(void)         {GPIO##A->ODR ^=  _BV( C);}\
static  void   N##_MakeOut(void)        {GPIO##A->DDR |=  _BV( C);}\
static  void   N##_MakeIn(void)         {GPIO##A->DDR &= ~_BV( C);}\
static  void   N##_SetCR1(void)         {GPIO##A->CR1 |=  _BV( C);}\
static  void   N##_ClrCR1(void)         {GPIO##A->CR1 &= ~_BV( C);}\
static  void   N##_SetCR2(void)         {GPIO##A->CR2 |=  _BV( C);}\
static  void   N##_ClrCR2(void)         {GPIO##A->CR2 &= ~_BV( C);}\
static  void   N##_INPUT(void)		    {GPIO_SETMODE_INPUT(A,C);}\
static  void   N##_INPUT_I(void)        {GPIO_SETMODE_INPUT_I(A,C);}\
static  void   N##_INPUT_UP(void)       {GPIO_SETMODE_INPUT_UP(A,C);}\
static  void   N##_INPUT_UPI(void)      {GPIO_SETMODE_INPUT_UPI(A,C);}\
static  void   N##_OUTPUT(void)         {GPIO_SETMODE_OUTPUT(A,C);}\
static  void   N##_OUTPUT_OD(void)      {GPIO_SETMODE_OUTPUT_OD(A,C);}\
static  void   N##_OUTPUT_ODI(void)     {GPIO_SETMODE_OUTPUT_ODI(A,C);}\
static  void   N##_OUTPUT_PPI(void)     {GPIO_SETMODE_OUTPUT_PPI(A,C);}\
static  uint8_t  N##_ReadIn(void)       {return ((GPIO##A->IDR & _BV(C)) != 0);}\
static  uint8_t  N##_Read(void)         {return N##_ReadIn();}\
static  uint8_t  N##_ReadOut(void)      {return ((GPIO##A->ODR & _BV(C)) != 0);}\
static  uint8_t  N##_ReadDir(void)      {return ((GPIO##A->DDR & _BV(C)) != 0);}\
static  void   	 N##_Out(uint8_t x)     {(x)?(N##_Set()):(N##_Clr());}\
static  uint8_t  N##_IsOutHigh(void)    {return N##_ReadOut();}\
static  uint8_t  N##_IsOutLow(void)     {return !N##_ReadOut();}


#define STM8_GNAME_ASSIGN_POLARITY(N, A, C, X) \
STM8_GNAME_ASSIGN(N, A, C) \
static  void     N##_On(void)           { (X)?(N##_Set()):(N##_Clr());}\
static  void     N##_Off(void)          { (X)?(N##_Clr()):(N##_Set());}\
static  uint8_t  N##_IsOn(void)         {return (X)?N##_IsOutHigh():N##_IsOutLow(); }\
static  uint8_t  N##_IsOff(void)        {return (X)?N##_IsOutLow() :N##_IsOutHigh();}


//fast_io macro

#define GPIO_IN(p,n)     ((((GPIO_TypeDef*)GPIO##p##_BaseAddress)->IDR)&(1<<n))
#define GPIO_LOW(p,n)    (((GPIO_TypeDef*)GPIO##p##_BaseAddress)->ODR &=~(1<<n))
#define GPIO_HIGH(p,n)   (((GPIO_TypeDef*)GPIO##p##_BaseAddress)->ODR |=(1<<n))
#define GPIO_TOGGLE(p,n) (((GPIO_TypeDef*)GPIO##p##_BaseAddress)->ODR ^=(1<<n))

//fast_io macro for every pins
#ifdef                PA0
#define       pinMode_PA0_IN()              GPIO_SETMODE_IN(A,0)
#define       pinMode_PA0_INPUT()        GPIO_SETMODE_INPUT(A,0)
#define       pinMode_PA0_OUT()	           GPIO_SETMODE_OUT(A,0)	
#define       pinMode_PA0_OUTPUT()	    GPIO_SETMODE_OUTPUT(A,0)	
#define   digitalRead_PA0()\
           GPIO_IN(A,0)
#define  digitalWrite_PA0(n)\
    ((n)?GPIO_HIGH(A,0):\
          GPIO_LOW(A,0))
#define digitalToggle_PA0()\
       GPIO_TOGGLE(A,0)
#endif

#ifdef 				  PA1
#define       pinMode_PA1_IN()              GPIO_SETMODE_IN(A,1)
#define       pinMode_PA1_INPUT()        GPIO_SETMODE_INPUT(A,1)
#define       pinMode_PA1_OUT()	           GPIO_SETMODE_OUT(A,1)	
#define       pinMode_PA1_OUTPUT()	    GPIO_SETMODE_OUTPUT(A,1)	
#define   digitalRead_PA1()\
           GPIO_IN(A,1)
#define  digitalWrite_PA1(n)\
    ((n)?GPIO_HIGH(A,1):\
          GPIO_LOW(A,1))
#define digitalToggle_PA1()\
       GPIO_TOGGLE(A,1)
#endif

#ifdef				  PA2
#define       pinMode_PA2_IN()              GPIO_SETMODE_IN(A,2)
#define       pinMode_PA2_INPUT()        GPIO_SETMODE_INPUT(A,2)
#define       pinMode_PA2_OUT()	           GPIO_SETMODE_OUT(A,2)	
#define       pinMode_PA2_OUTPUT()	    GPIO_SETMODE_OUTPUT(A,2)	
#define   digitalRead_PA2()\
           GPIO_IN(A,2)
#define  digitalWrite_PA2(n)\
    ((n)?GPIO_HIGH(A,2):\
          GPIO_LOW(A,2))
#define digitalToggle_PA2()\
       GPIO_TOGGLE(A,2)
#endif

#ifdef                PA3
#define       pinMode_PA3_IN()              GPIO_SETMODE_IN(A,3)
#define       pinMode_PA3_INPUT()        GPIO_SETMODE_INPUT(A,3)
#define       pinMode_PA3_OUT()	           GPIO_SETMODE_OUT(A,3)	
#define       pinMode_PA3_OUTPUT()	    GPIO_SETMODE_OUTPUT(A,3)	
#define   digitalRead_PA3()\
           GPIO_IN(A,3)
#define  digitalWrite_PA3(n)\
    ((n)?GPIO_HIGH(A,3):\
          GPIO_LOW(A,3))
#define digitalToggle_PA3()\
       GPIO_TOGGLE(A,3)
#endif

#ifdef                PA4
#define       pinMode_PA4_IN()              GPIO_SETMODE_IN(A,4)
#define       pinMode_PA4_INPUT()        GPIO_SETMODE_INPUT(A,4)
#define       pinMode_PA4_OUT()	           GPIO_SETMODE_OUT(A,4)	
#define       pinMode_PA4_OUTPUT()	    GPIO_SETMODE_OUTPUT(A,4)	
#define   digitalRead_PA4()\
           GPIO_IN(A,4)
#define  digitalWrite_PA4(n)\
    ((n)?GPIO_HIGH(A,4):\
          GPIO_LOW(A,4))
#define digitalToggle_PA4()\
       GPIO_TOGGLE(A,4)
#endif

#ifdef                PA5
#define       pinMode_PA5_IN()              GPIO_SETMODE_IN(A,5)
#define       pinMode_PA5_INPUT()        GPIO_SETMODE_INPUT(A,5)
#define       pinMode_PA5_OUT()	           GPIO_SETMODE_OUT(A,5)	
#define       pinMode_PA5_OUTPUT()	    GPIO_SETMODE_OUTPUT(A,5)	
#define   digitalRead_PA5()\
           GPIO_IN(A,5)
#define  digitalWrite_PA5(n)\
    ((n)?GPIO_HIGH(A,5):\
          GPIO_LOW(A,5))
#define digitalToggle_PA5()\
       GPIO_TOGGLE(A,5)
#endif

#ifdef                PA6
#define       pinMode_PA6_IN()              GPIO_SETMODE_IN(A,6)
#define       pinMode_PA6_INPUT()        GPIO_SETMODE_INPUT(A,6)
#define       pinMode_PA6_OUT()	           GPIO_SETMODE_OUT(A,6)	
#define       pinMode_PA6_OUTPUT()	    GPIO_SETMODE_OUTPUT(A,6)	
#define   digitalRead_PA6()\
           GPIO_IN(A,6)
#define  digitalWrite_PA6(n)\
    ((n)?GPIO_HIGH(A,6):\
          GPIO_LOW(A,6))
#define digitalToggle_PA6()\
       GPIO_TOGGLE(A,6)
#endif

#ifdef                PA7
#define       pinMode_PA7_IN()              GPIO_SETMODE_IN(A,7)
#define       pinMode_PA7_INPUT()        GPIO_SETMODE_INPUT(A,7)
#define       pinMode_PA7_OUT()	           GPIO_SETMODE_OUT(A,7)	
#define       pinMode_PA7_OUTPUT()	    GPIO_SETMODE_OUTPUT(A,7)	
#define   digitalRead_PA7()\
           GPIO_IN(A,7)
#define  digitalWrite_PA7(n)\
    ((n)?GPIO_HIGH(A,7):\
          GPIO_LOW(A,7))
#define digitalToggle_PA7()\
       GPIO_TOGGLE(A,7)
#endif

#ifdef                PB0
#define       pinMode_PB0_IN()              GPIO_SETMODE_IN(B,0)
#define       pinMode_PB0_INPUT()        GPIO_SETMODE_INPUT(B,0)
#define       pinMode_PB0_OUT()	           GPIO_SETMODE_OUT(B,0)	
#define       pinMode_PB0_OUTPUT()	    GPIO_SETMODE_OUTPUT(B,0)	
#define   digitalRead_PB0()\
           GPIO_IN(B,0)
#define  digitalWrite_PB0(n)\
    ((n)?GPIO_HIGH(B,0):\
          GPIO_LOW(B,0))
#define digitalToggle_PB0()\
       GPIO_TOGGLE(B,0)
#endif

#ifdef                PB1
#define       pinMode_PB1_IN()\
      GPIO_SETMODE_IN(B,1)
#define       pinMode_PB1_INPUT()\
   GPIO_SETMODE_INPUT(B,1)
#define       pinMode_PB1_OUT()\
     GPIO_SETMODE_OUT(B,1)	
#define       pinMode_PB1_OUTPUT()\
	GPIO_SETMODE_OUTPUT(B,1)	
#define   digitalRead_PB1()\
           GPIO_IN(B,1)
#define  digitalWrite_PB1(n)\
    ((n)?GPIO_HIGH(B,1):\
                 GPIO_LOW(B,1))
#define digitalToggle_PB1()\
       GPIO_TOGGLE(B,1)
#endif

#ifdef                PB2
#define       pinMode_PB2_IN()\
      GPIO_SETMODE_IN(B,2)
#define       pinMode_PB2_INPUT()\
   GPIO_SETMODE_INPUT(B,2)
#define       pinMode_PB2_OUT()\
     GPIO_SETMODE_OUT(B,2)	
#define       pinMode_PB2_OUTPUT()\
  GPIO_SETMODE_OUTPUT(B,2)	
#define   digitalRead_PB2()\
           GPIO_IN(B,2)
#define  digitalWrite_PB2(n)\
    ((n)?GPIO_HIGH(B,2):\
          GPIO_LOW(B,2))
#define digitalToggle_PB2()\
       GPIO_TOGGLE(B,2)
#endif

#ifdef                PB3
#define       pinMode_PB3_IN()\
      GPIO_SETMODE_IN(B,3)
#define       pinMode_PB3_INPUT()\
   GPIO_SETMODE_INPUT(B,3)
#define       pinMode_PB3_OUT()\
     GPIO_SETMODE_OUT(B,3)	
#define       pinMode_PB3_OUTPUT()\
  GPIO_SETMODE_OUTPUT(B,3)	
#define   digitalRead_PB3()\
           GPIO_IN(B,3)
#define  digitalWrite_PB3(n)\
    ((n)?GPIO_HIGH(B,3):\
          GPIO_LOW(B,3))
#define digitalToggle_PB3()\
       GPIO_TOGGLE(B,3)
#endif

#ifdef                PB4
#define       pinMode_PB4_IN()\
      GPIO_SETMODE_IN(B,4)
#define       pinMode_PB4_INPUT()\
   GPIO_SETMODE_INPUT(B,4)
#define       pinMode_PB4_OUT()\
     GPIO_SETMODE_OUT(B,4)	
#define       pinMode_PB4_OUTPUT()\
  GPIO_SETMODE_OUTPUT(B,4)	
#define   digitalRead_PB4()\
           GPIO_IN(B,4)
#define  digitalWrite_PB4(n)\
    ((n)?GPIO_HIGH(B,4):\
          GPIO_LOW(B,4))
#define digitalToggle_PB4()\
       GPIO_TOGGLE(B,4)
#endif

#ifdef                PB5
#define       pinMode_PB5_IN()\
      GPIO_SETMODE_IN(B,5)
#define       pinMode_PB5_INPUT()\
   GPIO_SETMODE_INPUT(B,5)
#define       pinMode_PB5_OUT()\
     GPIO_SETMODE_OUT(B,5)	
#define       pinMode_PB5_OUTPUT()\
  GPIO_SETMODE_OUTPUT(B,5)	
#define   digitalRead_PB5()\
           GPIO_IN(B,5)
#define  digitalWrite_PB5(n)\
    ((n)?GPIO_HIGH(B,5):\
          GPIO_LOW(B,5))
#define digitalToggle_PB5()\
       GPIO_TOGGLE(B,5)
#endif

#ifdef                PB6
#define       pinMode_PB6_IN()\
      GPIO_SETMODE_IN(B,6)
#define       pinMode_PB6_INPUT()\
   GPIO_SETMODE_INPUT(B,6)
#define       pinMode_PB6_OUT()\
     GPIO_SETMODE_OUT(B,6)	
#define       pinMode_PB6_OUTPUT()\
  GPIO_SETMODE_OUTPUT(B,6)	
#define   digitalRead_PB6()\
           GPIO_IN(B,6)
#define  digitalWrite_PB6(n)\
    ((n)?GPIO_HIGH(B,6):\
          GPIO_LOW(B,6))
#define digitalToggle_PB6()\
       GPIO_TOGGLE(B,6)
#endif

#ifdef                PB7
#define       pinMode_PB7_IN()\
      GPIO_SETMODE_IN(B,7)
#define       pinMode_PB7_INPUT()\
   GPIO_SETMODE_INPUT(B,7)
#define       pinMode_PB7_OUT()\
     GPIO_SETMODE_OUT(B,7)	
#define       pinMode_PB7_OUTPUT()\
  GPIO_SETMODE_OUTPUT(B,7)	
#define   digitalRead_PB7()\
           GPIO_IN(B,7)
#define  digitalWrite_PB7(n)\
    ((n)?GPIO_HIGH(B,7):\
          GPIO_LOW(B,7))
#define digitalToggle_PB7()\
       GPIO_TOGGLE(B,7)
#endif

#ifdef                PC0
#define       pinMode_PC0_IN()\
      GPIO_SETMODE_IN(C,0)
#define       pinMode_PC0_INPUT()\
   GPIO_SETMODE_INPUT(C,0)
#define       pinMode_PC0_OUT()\
     GPIO_SETMODE_OUT(C,0)	
#define       pinMode_PC0_OUTPUT()\
  GPIO_SETMODE_OUTPUT(C,0)	
#define   digitalRead_PC0()\
           GPIO_IN(C,0)
#define  digitalWrite_PC0(n)\
    ((n)?GPIO_HIGH(C,0):\
          GPIO_LOW(C,0))
#define digitalToggle_PC0()\
       GPIO_TOGGLE(C,0)
#endif

#ifdef                PC1
#define       pinMode_PC1_IN()\
      GPIO_SETMODE_IN(C,1)
#define       pinMode_PC1_INPUT()\
   GPIO_SETMODE_INPUT(C,1)
#define       pinMode_PC1_OUT()\
     GPIO_SETMODE_OUT(C,1)	
#define       pinMode_PC1_OUTPUT()\
  GPIO_SETMODE_OUTPUT(C,1)	
#define   digitalRead_PC1()\
           GPIO_IN(C,1)
#define  digitalWrite_PC1(n)\
    ((n)?GPIO_HIGH(C,1):\
          GPIO_LOW(C,1))
#define digitalToggle_PC1()\
       GPIO_TOGGLE(C,1)
#endif

#ifdef                PC2
#define       pinMode_PC2_IN()\
      GPIO_SETMODE_IN(C,2)
#define       pinMode_PC2_INPUT()\
   GPIO_SETMODE_INPUT(C,2)
#define       pinMode_PC2_OUT()\
     GPIO_SETMODE_OUT(C,2)	
#define       pinMode_PC2_OUTPUT()\
  GPIO_SETMODE_OUTPUT(C,2)	
#define   digitalRead_PC2()\
           GPIO_IN(C,2)
#define  digitalWrite_PC2(n)\
    ((n)?GPIO_HIGH(C,2):\
          GPIO_LOW(C,2))
#define digitalToggle_PC2()\
       GPIO_TOGGLE(C,2)
#endif

#ifdef                PC3
#define       pinMode_PC3_IN()\
      GPIO_SETMODE_IN(C,3)
#define       pinMode_PC3_INPUT()\
   GPIO_SETMODE_INPUT(C,3)
#define       pinMode_PC3_OUT()\
     GPIO_SETMODE_OUT(C,3)	
#define       pinMode_PC3_OUTPUT()\
  GPIO_SETMODE_OUTPUT(C,3)	
#define   digitalRead_PC3()\
           GPIO_IN(C,3)
#define  digitalWrite_PC3(n)\
    ((n)?GPIO_HIGH(C,3):\
          GPIO_LOW(C,3))
#define digitalToggle_PC3()\
       GPIO_TOGGLE(C,3)
#endif

#ifdef                PC4
#define       pinMode_PC4_IN()\
      GPIO_SETMODE_IN(C,4)
#define       pinMode_PC4_INPUT()\
   GPIO_SETMODE_INPUT(C,4)
#define       pinMode_PC4_OUT()\
     GPIO_SETMODE_OUT(C,4)	
#define       pinMode_PC4_OUTPUT()\
  GPIO_SETMODE_OUTPUT(C,4)	
#define   digitalRead_PC4()\
           GPIO_IN(C,4)
#define  digitalWrite_PC4(n)\
    ((n)?GPIO_HIGH(C,4):\
          GPIO_LOW(C,4))
#define digitalToggle_PC4()\
       GPIO_TOGGLE(C,4)
#endif

#ifdef                PC5
#define       pinMode_PC5_IN()\
      GPIO_SETMODE_IN(C,5)
#define       pinMode_PC5_INPUT()\
   GPIO_SETMODE_INPUT(C,5)
#define       pinMode_PC5_OUT()\
     GPIO_SETMODE_OUT(C,5)	
#define       pinMode_PC5_OUTPUT()\
  GPIO_SETMODE_OUTPUT(C,5)	
#define   digitalRead_PC5()\
           GPIO_IN(C,5)
#define  digitalWrite_PC5(n)\
    ((n)?GPIO_HIGH(C,5):\
          GPIO_LOW(C,5))
#define digitalToggle_PC5()\
       GPIO_TOGGLE(C,5)
#endif

#ifdef                PC6
#define       pinMode_PC6_IN()\
      GPIO_SETMODE_IN(C,6)
#define       pinMode_PC6_INPUT()\
   GPIO_SETMODE_INPUT(C,6)
#define       pinMode_PC6_OUT()\
     GPIO_SETMODE_OUT(C,6)	
#define       pinMode_PC6_OUTPUT()\
  GPIO_SETMODE_OUTPUT(C,6)	
#define   digitalRead_PC6()\
           GPIO_IN(C,6)
#define  digitalWrite_PC6(n)\
    ((n)?GPIO_HIGH(C,6):\
          GPIO_LOW(C,6))
#define digitalToggle_PC6()\
       GPIO_TOGGLE(C,6)
#endif

#ifdef                PC7
#define       pinMode_PC7_IN()\
      GPIO_SETMODE_IN(C,7)
#define       pinMode_PC7_INPUT()\
   GPIO_SETMODE_INPUT(C,7)
#define       pinMode_PC7_OUT()\
     GPIO_SETMODE_OUT(C,7)	
#define       pinMode_PC7_OUTPUT()\
	GPIO_SETMODE_OUTPUT(C,7)	
#define   digitalRead_PC7()\
           GPIO_IN(C,7)
#define  digitalWrite_PC7(n)\
    ((n)?GPIO_HIGH(C,7):\
          GPIO_LOW(C,7))
#define digitalToggle_PC7()\
       GPIO_TOGGLE(C,7)
#endif

#ifdef                PD0
#define       pinMode_PD0_IN()\
      GPIO_SETMODE_IN(D,0)
#define       pinMode_PD0_INPUT()\
   GPIO_SETMODE_INPUT(D,0)
#define       pinMode_PD0_OUT()\
     GPIO_SETMODE_OUT(D,0)	
#define       pinMode_PD0_OUTPUT()\
	GPIO_SETMODE_OUTPUT(D,0)	
#define   digitalRead_PD0()\
           GPIO_IN(D,0)
#define  digitalWrite_PD0(n)\
    ((n)?GPIO_HIGH(D,0):\
          GPIO_LOW(D,0))
#define digitalToggle_PD0()\
       GPIO_TOGGLE(D,0)
#endif

#ifdef                PD1
#define       pinMode_PD1_IN()\
      GPIO_SETMODE_IN(D,1)
#define       pinMode_PD1_INPUT()\
   GPIO_SETMODE_INPUT(D,1)
#define       pinMode_PD1_OUT()\
     GPIO_SETMODE_OUT(D,1)	
#define       pinMode_PD1_OUTPUT()\
  GPIO_SETMODE_OUTPUT(D,1)	
#define   digitalRead_PD1()\
           GPIO_IN(D,1)
#define  digitalWrite_PD1(n)\
    ((n)?GPIO_HIGH(D,1):\
          GPIO_LOW(D,1))
#define digitalToggle_PD1()\
       GPIO_TOGGLE(D,1)
#endif

#ifdef                PD2
#define       pinMode_PD2_IN()\
      GPIO_SETMODE_IN(D,2)
#define       pinMode_PD2_INPUT()\
   GPIO_SETMODE_INPUT(D,2)
#define       pinMode_PD2_OUT()\
     GPIO_SETMODE_OUT(D,2)	
#define       pinMode_PD2_OUTPUT()\
  GPIO_SETMODE_OUTPUT(D,2)	
#define   digitalRead_PD2()\
           GPIO_IN(D,2)
#define  digitalWrite_PD2(n)\
    ((n)?GPIO_HIGH(D,2):\
          GPIO_LOW(D,2))
#define digitalToggle_PD2()\
       GPIO_TOGGLE(D,2)
#endif

#ifdef                PD3
#define       pinMode_PD3_IN()\
      GPIO_SETMODE_IN(D,3)
#define       pinMode_PD3_INPUT()\
   GPIO_SETMODE_INPUT(D,3)
#define       pinMode_PD3_OUT()\
     GPIO_SETMODE_OUT(D,3)	
#define       pinMode_PD3_OUTPUT()\
  GPIO_SETMODE_OUTPUT(D,3)	
#define   digitalRead_PD3()\
           GPIO_IN(D,3)
#define  digitalWrite_PD3(n)\
    ((n)?GPIO_HIGH(D,3):\
          GPIO_LOW(D,3))
#define digitalToggle_PD3()\
       GPIO_TOGGLE(D,3)
#endif

#ifdef                PD4
#define       pinMode_PD4_IN()\
      GPIO_SETMODE_IN(D,4)
#define       pinMode_PD4_INPUT()\
   GPIO_SETMODE_INPUT(D,4)
#define       pinMode_PD4_OUT()\
     GPIO_SETMODE_OUT(D,4)	
#define       pinMode_PD4_OUTPUT()\
  GPIO_SETMODE_OUTPUT(D,4)	
#define   digitalRead_PD4()\
           GPIO_IN(D,4)
#define  digitalWrite_PD4(n)\
    ((n)?GPIO_HIGH(D,4):\
          GPIO_LOW(D,4))
#define digitalToggle_PD4()\
       GPIO_TOGGLE(D,4)
#endif

#ifdef                PD5
#define       pinMode_PD5_IN()\
      GPIO_SETMODE_IN(D,5)
#define       pinMode_PD5_INPUT()\
   GPIO_SETMODE_INPUT(D,5)
#define       pinMode_PD5_OUT()\
  GPIO_SETMODE_OUT(D,5)	
#define       pinMode_PD5_OUTPUT()\
  GPIO_SETMODE_OUTPUT(D,0)	
#define   digitalRead_PD5()\
           GPIO_IN(D,5)
#define  digitalWrite_PD5(n)\
    ((n)?GPIO_HIGH(D,5):\
          GPIO_LOW(D,5))
#define digitalToggle_PD5()\
       GPIO_TOGGLE(D,5)
#endif

#ifdef                PD6
#define       pinMode_PD6_IN()\
      GPIO_SETMODE_IN(D,6)
#define       pinMode_PD6_INPUT()\
   GPIO_SETMODE_INPUT(D,6)
#define       pinMode_PD6_OUT()\
     GPIO_SETMODE_OUT(D,6)	
#define       pinMode_PD6_OUTPUT()\
  GPIO_SETMODE_OUTPUT(D,6)	
#define   digitalRead_PD6()\
           GPIO_IN(D,6)
#define  digitalWrite_PD6(n)\
    ((n)?(GPIO_HIGH(D,6)):\
          (GPIO_LOW(D,6)))
#define digitalToggle_PD6()\
       GPIO_TOGGLE(D,6)
#endif

#ifdef                PD7
#define       pinMode_PD7_IN()\
      GPIO_SETMODE_IN(D,7)
#define       pinMode_PD7_INPUT()\
   GPIO_SETMODE_INPUT(D,7)
#define       pinMode_PD7_OUT()\
     GPIO_SETMODE_OUT(D,7)	
#define       pinMode_PD7_OUTPUT()\
  GPIO_SETMODE_OUTPUT(D,7)	
#define   digitalRead_PD7()\
           GPIO_IN(D,7)
#define  digitalWrite_PD7(n)\
    ((n)?(GPIO_HIGH(D,7)):\
          (GPIO_LOW(D,7)))
#define digitalToggle_PD7()\
       GPIO_TOGGLE(D,7)
#endif

#ifdef                PE0
#define       pinMode_PE0_IN()\
      GPIO_SETMODE_IN(E,0)
#define       pinMode_PE0_INPUT()\
   GPIO_SETMODE_INPUT(E,0)
#define       pinMode_PE0_OUT()\
     GPIO_SETMODE_OUT(E,0)	
#define       pinMode_PE0_OUTPUT()\
  GPIO_SETMODE_OUTPUT(E,0)	
#define   digitalRead_PE0()\
           GPIO_IN(E,0)
#define  digitalWrite_PE0(n)\
    ((n)?GPIO_HIGH(E,0):\
          GPIO_LOW(E,0))
#define digitalToggle_PE0()\
       GPIO_TOGGLE(E,0)
#endif


#ifdef                PE1
#define       pinMode_PE1_IN()\
      GPIO_SETMODE_IN(E,1)
#define       pinMode_PE1_INPUT()\
   GPIO_SETMODE_INPUT(E,1)
#define       pinMode_PE1_OUT()\
     GPIO_SETMODE_OUT(E,1)	
#define       pinMode_PE1_OUTPUT()\
  GPIO_SETMODE_OUTPUT(E,1)	
#define   digitalRead_PE1()\
           GPIO_IN(E,1)
#define  digitalWrite_PE1(n)\
    ((n)?GPIO_HIGH(E,1):\
          GPIO_LOW(E,1))
#define digitalToggle_PE1()\
       GPIO_TOGGLE(E,1)
#endif


#ifdef                PE2
#define       pinMode_PE2_IN()\
      GPIO_SETMODE_IN(E,2)
#define       pinMode_PE2_INPUT()\
   GPIO_SETMODE_INPUT(E,2)
#define       pinMode_PE2_OUT()\
     GPIO_SETMODE_OUT(E,2)	
#define       pinMode_PE2_OUTPUT()\
	IO_SETMODE_OUTPUT(E,2)	
#define   digitalRead_PE2()\
           GPIO_IN(E,2)
#define  digitalWrite_PE2(n)\
    ((n)?GPIO_HIGH(E,2):\
          GPIO_LOW(E,2))
#define digitalToggle_PE2()\
       GPIO_TOGGLE(E,2)
#endif


#ifdef                PE3
#define       pinMode_PE3_IN()\
      GPIO_SETMODE_IN(E,3)
#define       pinMode_PE3_INPUT()\
   GPIO_SETMODE_INPUT(E,3)
#define       pinMode_PE3_OUT()\
     GPIO_SETMODE_OUT(E,3)	
#define       pinMode_PE3_OUTPUT()\
	GPIO_SETMODE_OUTPUT(E,3)	
#define   digitalRead_PE3()\
           GPIO_IN(E,3)
#define  digitalWrite_PE3(n)\
    ((n)?GPIO_HIGH(E,3):\
          GPIO_LOW(E,3))
#define digitalToggle_PE3()\
       GPIO_TOGGLE(E,3)
#endif


#ifdef                PE4
#define       pinMode_PE4_IN()\
      GPIO_SETMODE_IN(E,4)
#define       pinMode_PE4_INPUT()\
   GPIO_SETMODE_INPUT(E,4)
#define       pinMode_PE4_OUT()\
     GPIO_SETMODE_OUT(E,4)	
#define       pinMode_PE4_OUTPUT()\
	GPIO_SETMODE_OUTPUT(E,4)	
#define   digitalRead_PE4()\
           GPIO_IN(E,4)
#define  digitalWrite_PE4(n)\
    ((n)?GPIO_HIGH(E,4):\
          GPIO_LOW(E,4))
#define digitalToggle_PE4()\
       GPIO_TOGGLE(E,4)
#endif


#ifdef                PE5
#define       pinMode_PE5_IN()\
      GPIO_SETMODE_IN(E,5)
#define       pinMode_PE5_INPUT()\
   GPIO_SETMODE_INPUT(E,5)
#define       pinMode_PE5_OUT()\
     GPIO_SETMODE_OUT(E,5)	
#define       pinMode_PE5_OUTPUT()\
	IO_SETMODE_OUTPUT(E,5)	
#define   digitalRead_PE5()\
           GPIO_IN(E,5)
#define  digitalWrite_PE5(n)\
    ((n)?GPIO_HIGH(E,5):\
          GPIO_LOW(E,5))
#define digitalToggle_PE5()\
       GPIO_TOGGLE(E,5)
#endif


#ifdef                PE6
#define       pinMode_PE6_IN()\
      GPIO_SETMODE_IN(E,6)
#define       pinMode_PE6_INPUT()\
   GPIO_SETMODE_INPUT(E,6)
#define       pinMode_PE6_OUT()\
     GPIO_SETMODE_OUT(E,6)	
#define       pinMode_PE6_OUTPUT()\
	GPIO_SETMODE_OUTPUT(E,6)	
#define   digitalRead_PE6()\
           GPIO_IN(E,6)
#define  digitalWrite_PE6(n)\
    ((n)?GPIO_HIGH(E,6):\
          GPIO_LOW(E,6))
#define digitalToggle_PE6()\
       GPIO_TOGGLE(E,6)
#endif


#ifdef                PE7
#define       pinMode_PE7_IN()\
      GPIO_SETMODE_IN(E,7)
#define       pinMode_PE7_INPUT()\
   GPIO_SETMODE_INPUT(E,7)
#define       pinMode_PE7_OUT()\
     GPIO_SETMODE_OUT(E,7)	
#define       pinMode_PE7_OUTPUT()\
	GPIO_SETMODE_OUTPUT(E,7)	
#define   digitalRead_PE7()\
           GPIO_IN(E,7)
#define  digitalWrite_PE7(n)\
    ((n)?GPIO_HIGH(E,7):\
          GPIO_LOW(E,7))
#define digitalToggle_PE7()\
       GPIO_TOGGLE(E,7)
#endif

#ifdef                PF0
#define       pinMode_PF0_IN()\
      GPIO_SETMODE_IN(F,0)
#define       pinMode_PF0_INPUT()\
   GPIO_SETMODE_INPUT(F,0)
#define       pinMode_PF0_OUT()\
     GPIO_SETMODE_OUT(F,0)	
#define       pinMode_PF0_OUTPUT()\
  GPIO_SETMODE_OUTPUT(F,0)	
#define   digitalRead_PF0()\
           GPIO_IN(F,0)
#define  digitalWrite_PF0(n)\
    ((n)?GPIO_HIGH(F,0):\
          GPIO_LOW(F,0))
#define digitalToggle_PF0()\
       GPIO_TOGGLE(F,0)
#endif

#ifdef                PF1
#define       pinMode_PE1_IN()\
      GPIO_SETMODE_IN(F,1)
#define       pinMode_PF1_INPUT()\
   GPIO_SETMODE_INPUT(F,1)
#define       pinMode_PF1_OUT()\
     GPIO_SETMODE_OUT(F,1)	
#define       pinMode_PF1_OUTPUT()\
	IO_SETMODE_OUTPUT(F,1)	
#define   digitalRead_PF1()\
           GPIO_IN(F,1)
#define  digitalWrite_PF1(n)\
    ((n)?GPIO_HIGH(F,1):\
          GPIO_LOW(F,1))
#define digitalToggle_PF1()\
       GPIO_TOGGLE(F,1)
#endif

#ifdef                PF2
#define       pinMode_PF0_IN()\
      GPIO_SETMODE_IN(F,0)
#define       pinMode_PF0_INPUT()\
   GPIO_SETMODE_INPUT(F,0)
#define       pinMode_PF0_OUT()\
     GPIO_SETMODE_OUT(F,0)	
#define       pinMode_PF0_OUTPUT()\
  GPIO_SETMODE_OUTPUT(F,0)	
#define   digitalRead_PF2()\
           GPIO_IN(F,2)
#define  digitalWrite_PF2(n)\
    ((n)?GPIO_HIGH(F,2):\
                 GPIO_LOW(F,2))
#define digitalToggle_PF2()\
       GPIO_TOGGLE(F,2)
#endif

#ifdef                PF3
#define       pinMode_PF3_IN()\
      GPIO_SETMODE_IN(F,3)
#define       pinMode_PF3_INPUT()\
   GPIO_SETMODE_INPUT(F,3)
#define       pinMode_PF3_OUT()\
     GPIO_SETMODE_OUT(F,3)	
#define       pinMode_PF3_OUTPUT()\
  GPIO_SETMODE_OUTPUT(F,3)	
#define   digitalRead_PF3()\
           GPIO_IN(F,3)
#define  digitalWrite_PF3(n)\
    ((n)?GPIO_HIGH(F,3):\
          GPIO_LOW(F,3))
#define digitalToggle_PF3()\
       GPIO_TOGGLE(F,3)
#endif

#ifdef                PF4
#define       pinMode_PF4_IN()\
      GPIO_SETMODE_IN(F,4)
#define       pinMode_PF4_INPUT()\
   GPIO_SETMODE_INPUT(F,4)
#define       pinMode_PF4_OUT()\
     GPIO_SETMODE_OUT(F,4)	
#define       pinMode_PF4_OUTPUT()\
  GPIO_SETMODE_OUTPUT(F,4)	
#define   digitalRead_PF4()\
           GPIO_IN(F,4)
#define  digitalWrite_PF4(n)\
    ((n)?GPIO_HIGH(F,4):\
          GPIO_LOW(F,4))
#define digitalToggle_PF4()\
       GPIO_TOGGLE(F,4)
#endif

#ifdef                PF5
#define       pinMode_PF5_IN()\
      GPIO_SETMODE_IN(F,5)
#define       pinMode_PF5_INPUT()\
   GPIO_SETMODE_INPUT(F,5)
#define       pinMode_PF5_OUT()\
     GPIO_SETMODE_OUT(F,5)	
#define       pinMode_PF5_OUTPUT()\
  GPIO_SETMODE_OUTPUT(F,5)	
#define   digitalRead_PF5()\
           GPIO_IN(F,5)
#define  digitalWrite_PF5(n)\
    ((n)?GPIO_HIGH(F,5):\
          GPIO_LOW(F,5))
#define digitalToggle_PF5()\
       GPIO_TOGGLE(F,5)
#endif

#ifdef                PF6
#define       pinMode_PF6_IN()\
      GPIO_SETMODE_IN(F,6)
#define       pinMode_PF6_INPUT()\
   GPIO_SETMODE_INPUT(F,6)
#define       pinMode_PF6_OUT()\
     GPIO_SETMODE_OUT(F,6)	
#define       pinMode_PF6_OUTPUT()\
  GPIO_SETMODE_OUTPUT(F,6)	
#define   digitalRead_PF6()\
           GPIO_IN(F,6)
#define  digitalWrite_PF6(n)\
    ((n)?GPIO_HIGH(F,6):\
          GPIO_LOW(F,6))
#define digitalToggle_PF6()\
       GPIO_TOGGLE(F,6)
#endif

#ifdef                PF7
#define       pinMode_PF7_IN()\
      GPIO_SETMODE_IN(F,7)
#define       pinMode_PF7_INPUT()\
   GPIO_SETMODE_INPUT(F,7)
#define       pinMode_PF7_OUT()\
     GPIO_SETMODE_OUT(F,7)	
#define       pinMode_PF7_OUTPUT()\
  GPIO_SETMODE_OUTPUT(F,7)	
#define   digitalRead_PF7()\
           GPIO_IN(F,7)
#define  digitalWrite_PF7(n)\
    ((n)?GPIO_HIGH(F,7):\
          GPIO_LOW(F,7))
#define digitalToggle_PF7()\
       GPIO_TOGGLE(F,7)
#endif

#ifdef                PG0
#define       pinMode_PG0_IN()\
      GPIO_SETMODE_IN(G,0)
#define       pinMode_PG0_INPUT()\
   GPIO_SETMODE_INPUT(G,0)
#define       pinMode_PG0_OUT()\
     GPIO_SETMODE_OUT(G,0)	
#define       pinMode_PG0_OUTPUT()\
  GPIO_SETMODE_OUTPUT(G,0)	
#define   digitalRead_PG0()\
           GPIO_IN(G,0)
#define  digitalWrite_PG0(n)\
    ((n)?GPIO_HIGH(G,0):\
          GPIO_LOW(G,0))
#define digitalToggle_PG0()\
       GPIO_TOGGLE(G,0)
#endif

#ifdef                PG1
#define       pinMode_PG1_IN()\
      GPIO_SETMODE_IN(G,1)
#define       pinMode_PG1_INPUT()\
   GPIO_SETMODE_INPUT(G,1)
#define       pinMode_PG1_OUT()\
     GPIO_SETMODE_OUT(G,1)	
#define       pinMode_PG1_OUTPUT()\
  GPIO_SETMODE_OUTPUT(G,1)	
#define   digitalRead_PG1()\
           GPIO_IN(G,1)
#define  digitalWrite_PG1(n)\
    ((n)?GPIO_HIGH(G,1):\
          GPIO_LOW(G,1))
#define digitalToggle_PG1()\
       GPIO_TOGGLE(G,1)
#endif

#ifdef                PG2
#define       pinMode_PG2_IN()\
      GPIO_SETMODE_IN(G,2)
#define       pinMode_PG2_INPUT()\
   GPIO_SETMODE_INPUT(G,2)
#define       pinMode_PG2_OUT()\
     GPIO_SETMODE_OUT(G,2)	
#define       pinMode_PG2_OUTPUT()\
  GPIO_SETMODE_OUTPUT(G,2)	
#define   digitalRead_PG2()\
           GPIO_IN(G,2)
#define  digitalWrite_PG2(n)\
    ((n)?GPIO_HIGH(G,2):\
          GPIO_LOW(G,2))
#define digitalToggle_PG2()\
       GPIO_TOGGLE(G,2)
#endif

#ifdef                PG3
#define       pinMode_PG3_IN()\
      GPIO_SETMODE_IN(G,3)
#define       pinMode_PG3_INPUT()\
   GPIO_SETMODE_INPUT(G,3)
#define       pinMode_PG3_OUT()\
     GPIO_SETMODE_OUT(G,3)	
#define       pinMode_PG3_OUTPUT()\
  GPIO_SETMODE_OUTPUT(G,3)	
#define   digitalRead_PG3()\
           GPIO_IN(G,3)
#define  digitalWrite_PG3(n)\
    ((n)?GPIO_HIGH(G,3):\
          GPIO_LOW(G,3))
#define digitalToggle_PG3()\
       GPIO_TOGGLE(G,3)
#endif

#ifdef                PG4
#define       pinMode_PG4_IN()\
      GPIO_SETMODE_IN(I,4)
#define       pinMode_PG4_INPUT()\
   GPIO_SETMODE_INPUT(I,4)
#define       pinMode_PG4_OUT()\
     GPIO_SETMODE_OUT(I,4)	
#define       pinMode_PG4_OUTPUT()\
  GPIO_SETMODE_OUTPUT(I,4)	
#define   digitalRead_PG4()\
           GPIO_IN(I,4)
#define  digitalWrite_PG4(n)\
    ((n)?GPIO_HIGH(I,4):\
          GPIO_LOW(I,4))
#define digitalToggle_PG4()\
       GPIO_TOGGLE(I,4)
#endif

#ifdef                PG5
#define       pinMode_PG5_IN()\
      GPIO_SETMODE_IN(G,5)
#define       pinMode_PG5_INPUT()\
   GPIO_SETMODE_INPUT(G,5)
#define       pinMode_PG5_OUT()\
     GPIO_SETMODE_OUT(G,5)	
#define       pinMode_PG5_OUTPUT()\
  GPIO_SETMODE_OUTPUT(G,5)	
#define   digitalRead_PG5()\
           GPIO_IN(G,5)
#define  digitalWrite_PG5(n)\
    ((n)?GPIO_HIGH(G,5):\
          GPIO_LOW(G,5))
#define digitalToggle_PG5()\
       GPIO_TOGGLE(G,5)
#endif

#ifdef                PG6
#define       pinMode_PG6_IN()\
      GPIO_SETMODE_IN(G,6)
#define       pinMode_PG6_INPUT()\
   GPIO_SETMODE_INPUT(G,6)
#define       pinMode_PG6_OUT()\
     GPIO_SETMODE_OUT(G,6)	
#define       pinMode_PG6_OUTPUT()\
  GPIO_SETMODE_OUTPUT(G,6)	
#define   digitalRead_PG6()\
           GPIO_IN(G,6)
#define  digitalWrite_PG6(n)\
    ((n)?GPIO_HIGH(G,6):\
          GPIO_LOW(G,6))
#define digitalToggle_PG6()\
       GPIO_TOGGLE(G,6)
#endif

#ifdef                PG7
#define       pinMode_PG7_IN()\
      GPIO_SETMODE_IN(G,7)
#define       pinMode_PG7_INPUT()\
   GPIO_SETMODE_INPUT(G,7)
#define       pinMode_PG7_OUT()\
     GPIO_SETMODE_OUT(G,7)	
#define       pinMode_PG7_OUTPUT()\
  GPIO_SETMODE_OUTPUT(G,7)	
#define   digitalRead_PG7()\
           GPIO_IN(G,7)
#define  digitalWrite_PG7(n)\
    ((n)?GPIO_HIGH(G,7):\
          GPIO_LOW(G,7))
#define digitalToggle_PG7()\
       GPIO_TOGGLE(G,7)
#endif

#ifdef                PH0
#define       pinMode_PH0_IN()\
      GPIO_SETMODE_IN(H,0)
#define       pinMode_PH0_INPUT()\
   GPIO_SETMODE_INPUT(H,0)
#define       pinMode_PH0_OUT()\
     GPIO_SETMODE_OUT(H,0)	
#define       pinMode_PH0_OUTPUT()\
  GPIO_SETMODE_OUTPUT(H,0)	
#define   digitalRead_PH0()\
           GPIO_IN(H,0)
#define  digitalWrite_PH0(n)\
    ((n)?GPIO_HIGH(H,0):\
          GPIO_LOW(H,0))
#define digitalToggle_PH0()\
       GPIO_TOGGLE(H,0)
#endif

#ifdef                PH1
#define       pinMode_PH1_IN()\
      GPIO_SETMODE_IN(H,1)
#define       pinMode_PH1_INPUT()\
   GPIO_SETMODE_INPUT(H,1)
#define       pinMode_PH1_OUT()\
     GPIO_SETMODE_OUT(H,1)	
#define       pinMode_PH1_OUTPUT()\
  GPIO_SETMODE_OUTPUT(H,1)	
#define   digitalRead_PH1()\
           GPIO_IN(H,1)
#define  digitalWrite_PH1(n)\
    ((n)?GPIO_HIGH(H,1):\
          GPIO_LOW(H,1))
#define digitalToggle_PH1()\
       GPIO_TOGGLE(H,1)
#endif

#ifdef                PH2
#define       pinMode_PH2_IN()\
      GPIO_SETMODE_IN(H,2)
#define       pinMode_PH2_INPUT()\
   GPIO_SETMODE_INPUT(H,2)
#define       pinMode_PH2_OUT()\
     GPIO_SETMODE_OUT(H,2)	
#define       pinMode_PH2_OUTPUT()\
  GPIO_SETMODE_OUTPUT(H,2)	
#define   digitalRead_PH2()\
           GPIO_IN(H,2)
#define  digitalWrite_PH2(n)\
    ((n)?GPIO_HIGH(H,2):\
          GPIO_LOW(H,2))
#define digitalToggle_PH2()\
       GPIO_TOGGLE(H,2)
#endif

#ifdef                PH3
#define       pinMode_PH3_IN()\
      GPIO_SETMODE_IN(H,3)
#define       pinMode_PH3_INPUT()\
   GPIO_SETMODE_INPUT(H,3)
#define       pinMode_PH3_OUT()\
     GPIO_SETMODE_OUT(H,3)	
#define       pinMode_PH3_OUTPUT()\
  GPIO_SETMODE_OUTPUT(H,3)	
#define   digitalRead_PH3()\
           GPIO_IN(H,3)
#define  digitalWrite_PH3(n)\
    ((n)?GPIO_HIGH(H,3):\
          GPIO_LOW(H,3))
#define digitalToggle_PH3()\
       GPIO_TOGGLE(H,3)
#endif

#ifdef                PH4
#define       pinMode_PH4_IN()\
      GPIO_SETMODE_IN(H,4)
#define       pinMode_PH4_INPUT()\
   GPIO_SETMODE_INPUT(H,4)
#define       pinMode_PH4_OUT()\
     GPIO_SETMODE_OUT(H,4)	
#define       pinMode_PH4_OUTPUT()\
  GPIO_SETMODE_OUTPUT(H,4)	
#define   digitalRead_PH4()\
           GPIO_IN(H,4)
#define  digitalWrite_PH4(n)\
    ((n)?GPIO_HIGH(H,4):\
          GPIO_LOW(H,4))
#define digitalToggle_PH4()\
       GPIO_TOGGLE(H,4)
#endif

#ifdef                PH5
#define       pinMode_PH5_IN()\
      GPIO_SETMODE_IN(H,5)
#define       pinMode_PH5_INPUT()\
   GPIO_SETMODE_INPUT(H,5)
#define       pinMode_PH5_OUT()\
     GPIO_SETMODE_OUT(H,5)	
#define       pinMode_PH5_OUTPUT()\
  GPIO_SETMODE_OUTPUT(H,5)	
#define   digitalRead_PH5()\
           GPIO_IN(H,5)
#define  digitalWrite_PH5(n)\
    ((n)?GPIO_HIGH(H,5):\
          GPIO_LOW(H,5))
#define digitalToggle_PH5()\
       GPIO_TOGGLE(H,5)
#endif

#ifdef                PH6
#define       pinMode_PH6_IN()\
      GPIO_SETMODE_IN(H,6)
#define       pinMode_PH6_INPUT()\
   GPIO_SETMODE_INPUT(H,6)
#define       pinMode_PH6_OUT()\
     GPIO_SETMODE_OUT(H,6)	
#define       pinMode_PH6_OUTPUT()\
  GPIO_SETMODE_OUTPUT(H,6)	
#define   digitalRead_PH6()\
           GPIO_IN(H,6)
#define  digitalWrite_PH6(n)\
    ((n)?GPIO_HIGH(H,6):\
          GPIO_LOW(H,6))
#define digitalToggle_PH6()\
       GPIO_TOGGLE(H,6)
#endif

#ifdef                PH7
#define       pinMode_PH7_IN()\
      GPIO_SETMODE_IN(H,7)
#define       pinMode_PH7_INPUT()\
   GPIO_SETMODE_INPUT(H,7)
#define       pinMode_PH7_OUT()\
     GPIO_SETMODE_OUT(H,7)	
#define       pinMode_PH7_OUTPUT()\
  GPIO_SETMODE_OUTPUT(H,7)	
#define   digitalRead_PH7()\
           GPIO_IN(H,7)
#define  digitalWrite_PH7(n)\
    ((n)?GPIO_HIGH(H,7):\
          GPIO_LOW(H,7))
#define digitalToggle_PH7()\
       GPIO_TOGGLE(H,7)
#endif

#ifdef                PI0
#define       pinMode_PI0_IN()\
      GPIO_SETMODE_IN(I,0)
#define       pinMode_PI0_INPUT()\
   GPIO_SETMODE_INPUT(I,0)
#define       pinMode_PI0_OUT()\
     GPIO_SETMODE_OUT(I,0)	
#define       pinMode_PI0_OUTPUT()\
  GPIO_SETMODE_OUTPUT(I,0)	
#define   digitalRead_PI0()\
           GPIO_IN(I,0)
#define  digitalWrite_PI0(n)\
    ((n)?GPIO_HIGH(I,0):\
          GPIO_LOW(I,0))
#define digitalToggle_PI0()\
       GPIO_TOGGLE(I,0)
#endif

#ifdef                PI1
#define       pinMode_PI1_IN()\
      GPIO_SETMODE_IN(I,1)
#define       pinMode_PI1_INPUT()\
   GPIO_SETMODE_INPUT(I,1)
#define       pinMode_PI1_OUT()\
     GPIO_SETMODE_OUT(I,1)	
#define       pinMode_PI1_OUTPUT()\
  GPIO_SETMODE_OUTPUT(I,1)	
#define   digitalRead_PI1()\
           GPIO_IN(I,1)
#define  digitalWrite_PI1(n)\
    ((n)?GPIO_HIGH(I,1):\
          GPIO_LOW(I,1))
#define digitalToggle_PI1()\
       GPIO_TOGGLE(I,1)
#endif

#ifdef                PI2
#define       pinMode_PI2_IN()\
      GPIO_SETMODE_IN(I,2)
#define       pinMode_PI2_INPUT()\
   GPIO_SETMODE_INPUT(I,2)
#define       pinMode_PI2_OUT()\
     GPIO_SETMODE_OUT(I,2)	
#define       pinMode_PI2_OUTPUT()\
  GPIO_SETMODE_OUTPUT(I,2)	
#define   digitalRead_PI2()\
           GPIO_IN(I,2)
#define  digitalWrite_PI2(n)\
    ((n)?GPIO_HIGH(I,2):\
          GPIO_LOW(I,2))
#define digitalToggle_PI2()\
       GPIO_TOGGLE(I,2)
#endif

#ifdef                PI3
#define       pinMode_PI3_IN()\
      GPIO_SETMODE_IN(I,3)
#define       pinMode_PI3_INPUT()\
   GPIO_SETMODE_INPUT(I,3)
#define       pinMode_PI3_OUT()\
     GPIO_SETMODE_OUT(I,3)	
#define       pinMode_PI3_OUTPUT()\
  GPIO_SETMODE_OUTPUT(I,3)	
#define   digitalRead_PI3()\
           GPIO_IN(I,3)
#define  digitalWrite_PI3(n)\
    ((n)?GPIO_HIGH(I,3):\
          GPIO_LOW(I,3))
#define digitalToggle_PI3()\
       GPIO_TOGGLE(I,3)
#endif

#ifdef                PI4
#define       pinMode_PI4_IN()\
      GPIO_SETMODE_IN(I,4)
#define       pinMode_PI4_INPUT()\
   GPIO_SETMODE_INPUT(I,4)
#define       pinMode_PI4_OUT()\
     GPIO_SETMODE_OUT(I,4)	
#define       pinMode_PI4_OUTPUT()\
  GPIO_SETMODE_OUTPUT(I,4)	
#define   digitalRead_PI4()\
           GPIO_IN(I,4)
#define  digitalWrite_PI4(n)\
    ((n)?GPIO_HIGH(I,4):\
          GPIO_LOW(I,4))
#define digitalToggle_PI4()\
       GPIO_TOGGLE(I,4)
#endif

#ifdef                PI5
#define       pinMode_PI5_IN()\
      GPIO_SETMODE_IN(I,5)
#define       pinMode_PI5_INPUT()\
   GPIO_SETMODE_INPUT(I,5)
#define       pinMode_PI5_OUT()\
     GPIO_SETMODE_OUT(I,5)	
#define       pinMode_PI5_OUTPUT()\
  GPIO_SETMODE_OUTPUT(I,5)	
#define   digitalRead_PI5()\
           GPIO_IN(I,5)
#define  digitalWrite_PI5(n)\
    ((n)?GPIO_HIGH(I,5):\
          GPIO_LOW(I,5))
#define digitalToggle_PI5()\
       GPIO_TOGGLE(I,5)
#endif

#ifdef                PI6
#define       pinMode_PI6_IN()\
      GPIO_SETMODE_IN(I,6)
#define       pinMode_PI6_INPUT()\
   GPIO_SETMODE_INPUT(I,6)
#define       pinMode_PI6_OUT()\
     GPIO_SETMODE_OUT(I,6)	
#define       pinMode_PI6_OUTPUT()\
  GPIO_SETMODE_OUTPUT(I,6)	
#define   digitalRead_PI6()\
           GPIO_IN(I,6)
#define  digitalWrite_PI6(n)\
    ((n)?GPIO_HIGH(I,6):\
          GPIO_LOW(I,6))
#define digitalToggle_PI6()\
       GPIO_TOGGLE(I,6)
#endif

#ifdef                PI7
#define       pinMode_PI7_IN()\
      GPIO_SETMODE_IN(I,7)
#define       pinMode_PI7_INPUT()\
   GPIO_SETMODE_INPUT(I,7)
#define       pinMode_PI7_OUT()\
     GPIO_SETMODE_OUT(I,7)	
#define       pinMode_PI7_OUTPUT()\
  GPIO_SETMODE_OUTPUT(I,7)	
#define   digitalRead_PI7()\
           GPIO_IN(I,7)
#define  digitalWrite_PI7(n)\
    ((n)?GPIO_HIGH(I,7):\
          GPIO_LOW(I,7))
#define digitalToggle_PI7()\
       GPIO_TOGGLE(I,7)
#endif

#endif //_STM8_FASTIO_H_
