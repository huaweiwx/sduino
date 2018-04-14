/*
  testPin.ino 对每个脚翻转电平，通过示波器检测波形，探测引脚
  for stm8s003f/103f 示例针对 stm8s003f/103f
  
  by huaweiwx@sina.com 2018.4.2
 */

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(PA1, OUTPUT); //set all pins as OUTPUT 将所有脚设定为输出
  pinMode(PA2, OUTPUT);
  pinMode(PA3, OUTPUT);
  pinMode(PB4, OUTPUT);
  pinMode(PB5, OUTPUT);
  pinMode(PC3, OUTPUT);
  pinMode(PC4, OUTPUT);
  pinMode(PC5, OUTPUT);
  pinMode(PC6, OUTPUT);
  pinMode(PC7, OUTPUT);
  pinMode(PD1, OUTPUT);
  pinMode(PD2, OUTPUT);
  pinMode(PD3, OUTPUT);
  pinMode(PD4, OUTPUT);
  pinMode(PD5, OUTPUT);
  pinMode(PD6, OUTPUT);
}

void blink(uint8_t pin, uint8_t n) {
  for (uint8_t i = 0; i < n; i++) {
    digitalToggle(pin);
    delay(1);
  }
}
// the loop function runs over and over again forever

void loop() {
  blink(PA1, 2);  //每个脚不同的翻转次数，可通过示波器检测判别
  blink(PA2, 4);
  blink(PA3, 6);
  blink(PB4, 8);
  blink(PB5, 10);
  blink(PC3, 12);
  blink(PC4, 14);
  blink(PC5, 16);
  blink(PC6, 18);
  blink(PC7, 20);
  blink(PD1, 22);
  blink(PD2, 24);
  blink(PD3, 26);
  blink(PD4, 28);
  blink(PD5, 30);
  blink(PD6, 32);
}
