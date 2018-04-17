/*
	SevenSegment.c - sduino 7 Segment Led Display Library 
	Copyright (c) 2018  huaweiwx@sina.com
	
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
#include "Arduino.h"
#include "SevenSegment.h"

#define  digitalWrite_INV(p,v,b)  digitalWrite((p),((b)?(!(v)):v))

//                                   A                   
//                                  ---  
//                                F| G | B
//                                  ---
//                                E|   | C
//                                  --- .DP
//                                   D

//         DIGIT              A  B  C  D  E  F  G
#define  ZERO    B1111110  /* 1, 1, 1, 1, 1, 1, 0   0 */
#define  ONE 	 B0110000  /* 0, 1, 1, 0, 0, 0, 0   1 */
#define  TWO     B1101101  /* 1, 1, 0, 1, 1, 0, 1   2 */
#define  THREE   B1111001  /* 1, 1, 1, 1, 0, 0, 1   3 */
#define  FOUR	 B0110011  /* 0, 1, 1, 0, 0, 1, 1   4 */
#define  FIVE	 B1011011  /* 1, 0, 1, 1, 0, 1, 1   5 */
#define  SIX	 B1011111  /* 1, 0, 1, 1, 1, 1, 1   6 */
#define  SEVEN   B1110000  /* 1, 1, 1, 0, 0, 0, 0   7 */
#define  EIGHT   B1111111  /* 1, 1, 1, 1, 1, 1, 1   8 */
#define  NINE	 B1111011  /* 1, 1, 1, 1, 0, 1, 1   9 */
#define  HEX_A   B1110111  /* 1, 1, 1, 0, 1, 1, 1   A */
#define  HEX_B   B0011111  /* 0, 0, 1, 1, 1, 1, 1   b */
#define  HEX_C   B1001110  /* 1, 0, 0, 1, 1, 1, 0   C */
#define  HEX_D   B0111101  /* 0, 1, 1, 1, 1, 0, 1   d */
#define  HEX_E   B1001111  /* 1, 0, 0, 1, 1, 1, 1   e */
#define  HEX_F   B1000111  /* 1, 0, 0, 0, 1, 1, 1   F */
#define  DASH	 B0000001  /* 0, 0, 0, 0, 0, 0, 1   - */
#define  SPACE	 B0000000  /* 0, 0, 0, 0, 0, 0, 0     */
#define  CHARH	 B1100111  /* 0, 1, 1, 0, 1, 1, 1   H */
#define  CHARL	 B0001110  /* 0, 0, 0, 1, 1, 1, 0   L */
#define  CHARU	 B0111110  /* 0, 1, 1, 1, 1, 1, 0   U */
#define  CHARr	 B0111110  /* 0, 0, 0, 0, 1, 0, 1   U */

static const uint8_t data7segs[] ={
ZERO,    /*0*/
ONE,	 /*1*/ 
TWO,     /*2*/
THREE,   /*3*/
FOUR,    /*4*/
FIVE,    /*5*/
SIX,	 /*6*/ 
SEVEN,   /*7*/
EIGHT,   /*8*/
NINE,    /*9*/
HEX_A,   /*A*/
HEX_B,   /*B*/
HEX_C,   /*C*/
HEX_D,   /*D*/
HEX_E,   /*E*/
HEX_F,   /*F*/
DASH,    /*-*/
SPACE,	 /*0x11  */ 	
CHARH,	 /*0x12 H*/
CHARL,	 /*0x13 L*/
CHARU,	 /*0x14 U*/
CHARr,	 /*0x15 r*/
};

static uint8_t pins[16];    //全部驱动脚号 da/db/dc/dd/de/df/dg/dp/d1/d2/d3/d4/d5/d6/d7/d8, 255 空
static uint8_t digits;      //驱动位数 1/2/3/4
static uint8_t lines;       //0/1 7段1/2行
static uint8_t invet;       //0/1 共阳B/共阴A位  on电平; 

static uint8_t showBuf[8];  //2*4位显示缓冲区
static uint8_t pos[2];      //当前显示位置
static uint8_t line;        //0/1 当前显示行
static uint8_t point[2];    //小数点显示位置 0/1/2/3，其他不显示
void SevenSegment_init(uint8_t da,uint8_t db,uint8_t dc,uint8_t dd,uint8_t de,uint8_t df, 
					   uint8_t dg,uint8_t dp,uint8_t d1,uint8_t d2,uint8_t d3,uint8_t d4,
											 uint8_t d5,uint8_t d6,uint8_t d7,uint8_t d8)
{
	pins[0] = da;
	pins[1] = db;
	pins[2] = dc;
	pins[3] = dd;
	pins[4] = de;
	pins[5] = df;
	pins[6] = dg;
	pins[7] = dp;

    pins[8]   = d1;
    pins[9]   = d2;
    pins[10]  = d3;
	pins[11]  = d4;
    pins[12]  = d5;
    pins[13]  = d6;
    pins[14]  = d7;
	pins[15]  = d8;

	digits = 0;
	for (uint8_t pin = 8;pin < 12; pin++){
		if(pins[pin]<255) digits++;
	}
	
    if(digits >4){
	   digits /= 2;
       lines=1;	   
	}else{
       lines=0;	   
	}

	pos[0]=0;
	pos[1]=0;

	line = 0;
}

void SevenSegment_begin(uint8_t inv){
	invet = inv;
	for (uint8_t pin = 0; pin < 16; pin++)
	{
		if(pins[pin]<255) pinMode(pins[pin], OUTPUT);
	}
} 

void SevenSegment_showChar(uint8_t c,uint8_t i){
	showBuf[i+line*4] = c;
}

void SevenSegment_showErr(void)
{
  if (digits > 2){
    if (digits > 3)	showBuf[3] = 0x11; //SPACE    
    showBuf[2+line*4] = 0x0E;   //E  
    showBuf[1+line*4] = 0x15;   //r	  
    showBuf[0+line*4] = 0x15;   //r
  }
}

void SevenSegment_setLine(uint8_t l){
  if(lines){
    if(l) line = 1;
	else line = 0;
  }
}

void SevenSegment_setPoint(uint8_t p){
	point[line]=p;
}

void SevenSegment_setPos(uint8_t i){
	pos[line]=i;
}

void SevenSegment_showDEC(int16_t num)
{
  uint16_t n;
  uint8_t  i = line*4;
  
  n = (num<0)? -1*num:num;
  
  switch(digits)
  {
    case 4:
      if((num>9999)||(num < -999)){ // 4digits show -999~9999
    	SevenSegment_showErr(); 
      }else{
    	if (num <0) showBuf[3+i] = 0x10;        //16 DASH, 最高位显 "-"
    	else        showBuf[3+i] = n/1000;       //di4
    	showBuf[2+i] = (n/100)%10;   //di3 
    	showBuf[1+i] = (n/10)%10;    //di2
    	showBuf[0+i] = n %10;	 	 //di1
      }
      break;
    case 3:
      if((num>999)||(num < -99)){  // 3digits show -99~999
    	SevenSegment_showErr(); 
      }else{
    	if (num <0) showBuf[2+i] = 0x10;   //16 DASH, 最高位显 "-"
    	else	showBuf[2] = n/100;   //di3 
    	showBuf[1+i] = (n/10)%10;     //di2
    	showBuf[0+i] = n %10;	 	  //di1
      }
      break;
    default:
      if((num>99)||(num<-9)) {  // 2digits show -9~99             
    	showBuf[1+i] = 0x0E;   //E  
        showBuf[0+i] = 0x15;   //r
      }else{
    	if (num <0) showBuf[1+i] = 0x10;
    	else showBuf[1+i] = n/10;    //di2
    	showBuf[0+i] = n %10;						 //di1
      }
      break;
  }
  point[line]=255;
}

 /*3digits 0.01~999.0 or 4digits 0.001~9999*/
void SevenSegment_showFloat(float num)
{
  point[line]=0;	
  switch(digits)
  {
    case 4:
	  if(num >1000.0)SevenSegment_showDEC((int16_t)(num+0.5)); //1000~9999 -999~-100
      else if (num >100.0){
		 SevenSegment_showDEC((int16_t)(num*10.0+0.5));         //100.0~999.9
         point[line]=1;
	  }	  
      else if (num >10.0){
		 SevenSegment_showDEC((int16_t)(num*100.0+0.5));        //10.00~99.99
         point[line]=2;
	  }
      else {
		 SevenSegment_showDEC((int16_t)(num*1000.0+0.5));       //0.000~9.999
         point[line]=3;
	  }
      break;
   case 3:
	  if (num >100.0) SevenSegment_showDEC((int16_t)(num+0.5));
      else if (num >10.0){
		 SevenSegment_showDEC((int16_t)(num*10.0+0.5));
         point[line]=1;
	  }
      else {
		 SevenSegment_showDEC((int16_t)(num*100.0+0.5));
         point[line]=2;
	  }
      break;
  }	  
}

void SevenSegment_showHEX(uint32_t num)
{
    uint8_t  i = line*4;
	if (digits > 3) showBuf[3+i] = num >> 24;		    //di4
	if (digits > 2) showBuf[2+i] = (num >> 16)&0xff;    //di3
	if (digits > 1) showBuf[1+i] = (num >> 8)&0xff;     //di2
	showBuf[0+i] = num &0xff;                           //di1
}

void SevenSegment_display(void)
{
    uint8_t c;
    for(uint8_t num = 0; num < digits;num++){
       for(uint8_t i=0; i<=lines;i++){ //lines = 0~1
          c = showBuf[num+i*4];
   	      for (uint8_t segment = 0; segment < 7; segment++){
   		    digitalWrite_INV(pins[segment], bitRead(data7segs[c], segment),invet);
   	      }
		  
//show point
	      if (point[i] == num) digitalWrite_INV(pins[7], 1 ,invet); //show dp
	      else digitalWrite_INV(pins[7], 0 ,invet);
		  
//show num
          digitalWrite_INV(pins[8 + i*digits + num],LOW,invet);  /*开2 ms*/
   	      delay(2);
          digitalWrite_INV(pins[8 + i*digits + num],HIGH,invet); /*关闭该段*/
       }
    }
}

size_t SevenSegment_write(uint8_t num){
	
	SevenSegment_showChar(num,--pos[line]);
	if(pos[line]==0) pos[line] = digits;
	return 1;
}
