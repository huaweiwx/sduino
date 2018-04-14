/*
  Vmeter.ino SevenSegment lib demo by huaweiwx@sina.com 2018.3.8
*/

//3digits:

//A  PC4
//B  PB5
//C  PC7
//D  PD1
//E  PD3
//F  PC3
//G  PB4
//DP PD2
//D1 PC6
//D2 PC5
//D3 PA3

#include <SevenSegment.h>
//SevenSegment (instance,  A,   B,   C,   D,   E,   F,   G,   P,  D1,   D2,   D3,   D4 );//for 4 digits (max 4digts)
//SevenSegment (instance,  A,   B,   C,   D,   E,   F,   G,   P,  D1,   D2,   D3);       //for 3 digits
 SevenSegment(seg7d3,   PC4, PB5, PC7, PD1, PD3, PC3, PB4, PD2, PC6 , PC5, PA3);    /*use 3 digits*/

#define VPIN PD6  //电压检测输入脚 PD2/3/5/6 之一

void setup() {
  seg7d3_begin(1);  //0/1 共阳/阴7段数码管初始化
  pinMode(VPIN, INPUT);
}


#define V30K 930
#define V50K 155

static uint32_t vin;
void loop() {
  vin = 0;
  for (uint8_t i = 0; i < 32; i++) {
    vin += analogRead(VPIN);
    for (uint8_t j = 0; j < 5; j++) seg7d3_display(); //刷新 5 次
  }
  
#if 0  // 显示 校准值1/ 电压0 
  seg7d3_showDEC(vin); //30V 5V 两点校准值V30K V05K显示
#else  
  vin *=100;

  //可用seg7d3_showFloat 直接显示浮点数，但计算慢，占内存
  //用整数显示，快速资源占用少
  seg7d3_showDEC(vin /32/307); //显示整数,会清小数点显示,需重设
 
  seg7d3_setpoint(1);          // 重设显示小数点
#endif
}

