/*
  Blink use fastIO macro SDUINO_ASSIGN_POLARITY demo
  Macro: SDUINO_ASSIGN_POLARITY(name[s],port[A...I],pin[0..7],polarity[0/1])
  exp: SDUINO_ASSIGN_POLARITY(LED,D,7,0) assign
*/

#ifdef PD7
FASTIO_POLARITY(Led,D, 7, 0) /*name Led/port GPIOD/pin 7 / & On is Low */
#else
#error #!his board hav'nt PG2 pin!
#endif

void setup() {
   Led_OUTPUT();
}

// the loop function runs over and over again forever
void loop() {
    Led_Toggle();   // turn the LED on/off
    delay(1000);
}

