/**
  ******************************************************************************
  * @file    stm8s_legacy.h
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
#if defined(STM8S)
#ifndef __STM8S_LEGACY
#define __STM8S_LEGACY
/*------------------------------------------ stm8l15x.h ------------------------------------------------*/
#define IS_FUNCTIONAL_STATE IS_FUNCTIONALSTATE_OK

//SPI_TypeDef
#define ICR  				CR3

//GPIO         L            S
#define GPIOA_BASE GPIOA_BaseAddress
#define GPIOB_BASE GPIOB_BaseAddress
#define GPIOC_BASE GPIOC_BaseAddress
#define GPIOD_BASE GPIOD_BaseAddress
#define GPIOE_BASE GPIOE_BaseAddress
#define GPIOF_BASE GPIOF_BaseAddress
#define GPIOG_BASE GPIOG_BaseAddress
#define GPIOH_BASE GPIOH_BaseAddress
#define GPIOI_BASE GPIOI_BaseAddress




/*------------------------------------------ stm8l15x_gpio.h ------------------------------------------------*/
//GPIO_Mode_TypeDef 
//          L                               S 
#define GPIO_Mode_In_FL_No_IT      GPIO_MODE_IN_FL_NO_IT     
#define GPIO_Mode_In_PU_No_IT      GPIO_MODE_IN_PU_NO_IT     
#define GPIO_Mode_In_FL_IT         GPIO_MODE_IN_FL_IT        
#define GPIO_Mode_In_PU_IT         GPIO_MODE_IN_PU_IT        
#define GPIO_Mode_Out_OD_Low_Fast  GPIO_MODE_OUT_OD_LOW_FAST 
#define GPIO_Mode_Out_PP_Low_Fast  GPIO_MODE_OUT_PP_LOW_FAST 
#define GPIO_Mode_Out_OD_Low_Slow  GPIO_MODE_OUT_OD_LOW_SLOW 
#define GPIO_Mode_Out_PP_Low_Slow  GPIO_MODE_OUT_PP_LOW_SLOW 
#define GPIO_Mode_Out_OD_HiZ_Fast  GPIO_MODE_OUT_OD_HIZ_FAST 
#define GPIO_Mode_Out_PP_High_Fast GPIO_MODE_OUT_PP_HIGH_FAST
#define GPIO_Mode_Out_OD_HiZ_Slow  GPIO_MODE_OUT_OD_HIZ_SLOW 
#define GPIO_Mode_Out_PP_High_Slow GPIO_MODE_OUT_PP_HIGH_SLOW


//GPIO_Pin_TypeDef
//          L            S 
#define GPIO_Pin_0    GPIO_PIN_0   
#define GPIO_Pin_1    GPIO_PIN_1   
#define GPIO_Pin_2    GPIO_PIN_2   
#define GPIO_Pin_3    GPIO_PIN_3   
#define GPIO_Pin_4    GPIO_PIN_4   
#define GPIO_Pin_5    GPIO_PIN_5   
#define GPIO_Pin_6    GPIO_PIN_6   
#define GPIO_Pin_7    GPIO_PIN_7   
#define GPIO_Pin_LNib GPIO_PIN_LNIB
#define GPIO_Pin_HNib GPIO_PIN_HNIB
#define GPIO_Pin_All  GPIO_PIN_ALL 

//Macro
//          L            S 
#define IS_GPIO_MODE  IS_GPIO_MODE_OK
#define IS_GPIO_PIN   IS_GPIO_PIN_OK


//GPIO_Exported_Functions
//          L            S 
#define GPIO_WriteHigh    GPIO_SetBits
#define GPIO_WriteLow     GPIO_ResetBits
#define GPIO_WriteReverse GPIO_ToggleBits

#endif /* __STM8S_LEGACY */
#endif //STM8S

/****************** END OF FILE ***************/

