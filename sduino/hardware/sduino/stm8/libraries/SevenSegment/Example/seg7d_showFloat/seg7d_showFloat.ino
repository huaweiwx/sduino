/*
  SevenSegment show Float demo by huaweiwx@sina.com 2018.3.8
*/

//3digits:

//A PC4
//B PB5
//C PC7
//D PD1
//E PD3
//F PC3
//G PB4
//DP PD2
//D1 PC6
//D2 PC5
//D3 PA3

#include <SevenSegment.h>
//SevenSegment (instance,  A,   B,   C,   D,   E,   F,   G,   P,   D1,   D2,   D3,   D4 );//for 4 digits (max 4digts)
//SevenSegment (instance,  A,   B,   C,   D,   E,   F,   G,   P,   D1,   D2,   D3);       //for 3 digits
//SevenSegment (instance,  A,   B,   C,   D,   E,   F,   G,   P,   D1,   D2);             //for 2 digits
//SevenSegment (instance,  A,   B,   C,   D,   E,   F,   G,   P,   D1);                   //for 1 digits
SevenSegment (seg7d3,    PC4,  PB5, PC7, PD1, PD3 , PC3, PB4, PD2,  PC6 , PC5,  PA3 );    /*use 3 digits*/

void setup() {
  seg7d3_begin(1); //0/1 共阳/阴7段数码管
}

void loop() {
  for (uint16_t j = 0; j < 1000; j++) {
    seg7d3_showFloat(j/100.0);
    for (uint8_t i = 0; i < 100; i++) seg7d3_display();
  }
}

