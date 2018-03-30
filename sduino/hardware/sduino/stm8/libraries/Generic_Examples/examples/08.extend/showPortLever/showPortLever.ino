/*
  showPortLever
*/

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 115200 bits per second:
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(PE0, INPUT);
  pinMode(PE1, INPUT);
  pinMode(PE2, INPUT);
  pinMode(PE3, INPUT);
  pinMode(PE4, INPUT);
  pinMode(PE5, INPUT);
  pinMode(PE6, INPUT);
  pinMode(PE7, INPUT);
  for (uint8_t i = 6; i > 0; i--) {
    digitalToggle(LED_BUILTIN);
    delay(200);
  }
  Serial_begin(115200);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  uint8_t porte = GPIOE->IDR;
  digitalToggle(LED_BUILTIN);
  Serial_println_ib(porte, HEX);
  delay(1000);
}

