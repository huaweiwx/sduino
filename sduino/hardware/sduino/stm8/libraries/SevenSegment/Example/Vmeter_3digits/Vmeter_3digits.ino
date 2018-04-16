/*
  Vmeter_3digits.ino: SevenSegment lib demo by huaweiwx@sina.com 2018.3.8
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

#define VPIN PD6  //3DigitsVolt PD6(电压检测输入脚 PD2/3/5/6 之一)
//#define VPIN PD3  //VC288     PD3
//#define IPIN PD2  //VC288     PD2

void setup() {
  seg7d3_begin(1);  //0/1 共阳/阴7段数码管初始化
  pinMode(VPIN, INPUT);
}


#define Vk (32*307) // 校准系数 32* 307/10v

static uint32_t vin;
void loop() {
  vin = 0;
  for (uint8_t i = 0; i < 32; i++) {
    vin += analogRead(VPIN);
    for (uint8_t j = 0; j < 5; j++) seg7d3_display(); //刷新 5 次
  }
  
#if 0                       // 首次设置为1:显示校准值,并修改Vk　/　然后再改为0: 正常工作状态, 显示 电压
  seg7d3_showDEC(vin/32);  // 校准值Vk/10V(30V 档）
#else  
  vin *=100;

  //可用seg7d3_showFloat 直接显示浮点数，但计算慢，占内存
  //用整数显示，快速资源占用少
  seg7d3_showDEC(vin / Vk); //显示整数,会清小数点显示,需重设
 
  seg7d3_setpoint(1);          // 重设显示小数点
#endif
}

