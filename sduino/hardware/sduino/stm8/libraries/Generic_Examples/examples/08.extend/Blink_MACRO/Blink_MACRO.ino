/*
  Blink use fastIO macro SDUINO_ASSIGN_POLARITY demo 
 
  Macro: SDUINO_ASSIGN_POLARITY(name[s],port[A...I],pin[0..7],polarity[0/1])
  exp: SDUINO_ASSIGN_POLARITY(LED,D,7,0) assign 
*/

#define LED PD7  //LED is PD7

SDUINO_ASSIGN_POLARITY(Led,B,3,0)/*name Led/port GPIOD/pin 7 / & On is Low */

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
   Led_OUTPUT();
  (GPIOA->CR2 &= ~_BV(2); GPIOA->CR1 &= ~_BV(2); GPIOA->DDR &= ~_BV(2));
// pinMode(LED_BUILTIN,OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  Led_On();   // turn the LED on/off
  delay(1000);               // wait for a second
  Led_Off();
  delay(1000);
}


