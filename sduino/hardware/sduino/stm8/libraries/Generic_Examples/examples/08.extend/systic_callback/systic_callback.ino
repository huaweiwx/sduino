/*
 * systic_callback.ino:  TIM4(timebase) interrupt callback demo;
 * 2018.3.22  huaweiwx@sina.com 
*/

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 115200 bits per second:
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
}


/*TIM4 1ms interrupt callback func: void systic_callback() */
uint16_t count = 0;
void systic_callback(void)
{
  if (count >= 1000) {
    digitalToggle(LED_BUILTIN);
    count = 0;
  } else {
    count++;
  }
}


