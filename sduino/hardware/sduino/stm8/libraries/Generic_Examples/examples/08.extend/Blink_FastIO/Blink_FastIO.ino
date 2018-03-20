/*
  Blink use fastIO macro PorPin demo

  fastIO macro list:(Pxx  as  PA2/PB/2/PC3//PD4/PE5/PF2..)
     pinMode_Pxx(mode)
     digitalRead_Pxx()
     digitalWrite_Pxx(n)
     digitalToggle_Pxx()
*/

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode_PD7(OUTPUT);
}

//LED_BUILTIN is PD7
// the loop function runs over and over again forever
void loop() {
  digitalToggle_PD7();   // turn the LED on/off
  delay(1000);               // wait for a second
}

