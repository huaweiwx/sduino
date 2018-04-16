/*
  shownum.ino: SevenSegment show a DEC num demo by huaweiwx@sina.com 2018.3.8
*/

//   VC288  3DigitsVolt  :
//A  PD1  		PC4		
//B  PA3  		PB5		
//C  PC3  		PC7		
//D  PC6  		PD1		
//E  PC7  		PD3		
//F  PC4  		PC3		
//G  PA2  		PB4		
//DP PC5  		PD2		
//D1 PD4  		PC6		
//D2 PD6  		PC5		
//D3 PD5  		PA3		
//D4 PB5    		
//D5 PB4    		
//D6 PA1

#include <SevenSegment.h>
//	SevenSegment (instancename,da,  db,  dc,  dd,  de,  df,  dg,  dp,  d01,  d02, d03, d04, d11, d12, d13, d14); // 2*4 

//	SevenSegment (instancename,da,  db,  dc,  dd,  de,  df,  dg,  dp,  d01,  d02, d03, d11, d12, d13); 		       // 2*3
//    SevenSegment(seg7d3,     PD1, PA3, PC3, PC6, PC7, PC4, PA2, PC5, PD4 , PD6, PD5, PB5, PB4, PA1);   /*VC288 board use 2*3 digits*/

//	SevenSegment (instancename,da,  db,  dc,  dd,  de,  df,  dg,  dp,  d1,   d2,  d3,  d4); 					           // 1*4
//	SevenSegment (instancename,da,  db,  dc,  dd,  de,  df,  dg,  dp,  d1,   d2,  d3); 						               // 1*3
    SevenSegment(seg7d3,     PC4, PB5, PC7, PD1, PD3, PC3, PB4, PD2, PC6 , PC5, PA3);   /*3DigitsVolt board use 1*3 digits*/

void setup() {
  seg7d3_begin(1); //0/1 共阳/阴7段数码管
}

void loop() {
  for (uint8_t i3 = 0; i3 < 10; i3++) {
    for (uint8_t i2 = 0; i2 < 10; i2++) {
      for (uint8_t i1 = 0; i1 < 10; i1++) {
        seg7d3_showDEC(i3 * 100 + i2 * 10 + i1);
        for (uint8_t i = 0; i < 100; i++) seg7d3_display();
      }
    }
  }
}

