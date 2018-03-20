/*
  Copyright (c) 2018 HuaWei  huaweiwx@sina.com

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.
*/

//Tx  LQFP32/44/48/64/80
//BX  SDIP32
//Mx  SO8/20
//Px  TSSOP20
//Ux  UFQFPN20/28/32/48  VFQFPN32
//Yx  WLCSP28/32/48

#ifndef STM8_BUILD_DEFINES_H
#define STM8_BUILD_DEFINES_H

/*------------------------------ 20 pins F serials----------------------------*/
//STM8S003F3Px/Ux
//STM8S103F2Px/STM8S103F2Mx/STM8S103F2Ux
//STM8S103F3Px/Mx/Ux 20pins
#if defined(STM8S003F3)||defined(STM8S103F2)||defined(STM8S103F3)
#include "stm8_GpioVariant_20_1.h"
#include "stm8_Tim_20_1.h"
//STM8S903F3M/P/Ux 20PINS
#elif defined(STM8S903F)
#include "stm8_GpioVariant_20_1.h"
#include "stm8_Tim_20_2.h"

/*------------------------------ 32 pins K serials----------------------------*/
//STM8S003K3 Tx  32 pins
//STM8S103K3 Bx/Tx/Ux  32pins
#elif defined(STM8S003K3)||defined(STM8S103K3)
#include "stm8_GpioVariant_32_1.h"
#include "stm8_Tim_32_1.h"

//STM8S005K6   Tx
//STM8S105K6   Bx/Tx/Ux 32pins
//STM8S105K4   Bx/Tx/Ux 32pins
//STM8S207K6/8 Tx 32pins
#elif defined(STM8S005K6)|| defined(STM8S105K6)||defined(STM8S105K4)||defined(STM8S207K)//32 pins
#include "stm8_GpioVariant_32_2.h"
#include "stm8_Tim_32_2.h"

//STM8S903K3(B/T/Ux) 32PINS OK
#elif defined(STM8S903K)
#include "stm8_GpioVariant_32_3.h"
#include "stm8_Tim_32_3.h"

/*---------------------------- 44 pins 207S/208S serials ----------------------------*/
//STM8S207S6/8/BTx 44pins
//STM8S208S6/8/BTx 44pins
#elif defined(STM8S207S)||defined(STM8S208S)
#include "stm8_GpioVariant_44_1.h"
#include "stm8_Tim_44_1.h"

/*---------------------------- 48 pins C/S serials----------------------------*/
//STM8S005C6 48pins
//STM8S007C8 48pins
//STM8S105C6 48pins
//STM8S105C4 48pins

//STM8S207C6/8/BTx 48pins
//STM8S208C6/8/BTx 48pins
#elif defined(STM8S005C6)||defined(STM8S007C8)||defined(STM8S105C6)||defined(STM8S105C4)\
     ||defined(STM8S207C)||defined(STM8S208C)
#include "stm8_GpioVariant_48_1.h"
#include "stm8_Tim_48_1.h"

//STM8S105S4Tx 48pins
//STM8S105S6Tx 48pins
#elif defined(STM8S105S4)||defined(STM8S105S6)
#include "stm8_GpioVariant_48_1.h"
#include         "stm8_Tim_48_1.h"

/*------------------------------ 64 pins R serials----------------------------*/
//STM8S207R6/8/BTx 64pins
#elif defined(STM8S207R)
#include "stm8_GpioVariant_64_1.h"
#include         "stm8_Tim_64_1.h"

//STM8S208R6/8/BTx 64pins
#elif defined(STM8S207R)
#include "stm8_GpioVariant_64_1.h"
#include         "stm8_Tim_64_1.h"

/*------------------------------ 80 pins M serials ----------------------------*/
//STM8S207M8/BTx 80pins
//STM8S208MBTx 80pins
#elif defined(STM8S207M)||defined(STM8S208M)
#include "stm8_GpioVariant_80_1.h"
#include         "stm8_Tim_80_1.h"




//STM8AF52
//STM8AF62
//STM8L31
//STM8L3L
//STM8L001
//STM8L050
//STM8L051
//STM8L052
//STM8L101


//STM8L151F 20pins
#elif defined(STM8L151F)
#include "stm8_GpioVariant_20_1.h"
#include "stm8_Tim_20_1.h"

//STM8L151G 28pins
#elif defined(STM8L151G)
#include "stm8_GpioVariant_28_1.h"
#include "stm8_Tim_28_1.h"

//STM8L151K 32pins
//STM8L152K 32pins
#elif defined(STM8L151K)||defined(STM8L152K)
#include "stm8_GpioVariant_32_1.h"
#include "stm8_Tim_32_1.h"

//STM8L151C 48pins
//STM8L152C 48pins
#elif defined(STM8L151C)||defined(STM8L152C)
#include "stm8_GpioVariant_48_2.h"
#include "stm8_Tim_48_2.h"

//STM8L151R 64pins
//STM8L152R 64pins
#elif defined(STM8L151R)||defined(STM8L152R)
#include "stm8_GpioVariant_64_2.h"
#include "stm8_Tim_64_2.h"

//STM8L151M 80pins
//STM8L152M 80pins
#elif defined(STM8L151M)||defined(STM8L152M)
#include "stm8_GpioVariant_80_2.h"
#include "stm8_Tim_80_2.h"

//STM8L162
#else 
  #error !UNKNOWN CHIP!  Add ME
#endif

#endif