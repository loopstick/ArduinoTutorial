/*
  Blink x2

  Turns TWO LEDs on and off!

  This example code is modified from: http://www.arduino.cc/en/Tutorial/Blink
*/

// define variables to hold the led pin numbers
  int led1Pin = 13;
  int led2Pin = 12;
// make sure to that the wires are is connected to the correct pins!!

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(led1Pin, OUTPUT); // set the pin to be an output
  pinMode(led2Pin, OUTPUT); 
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(led1Pin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for a second
  digitalWrite(led1Pin, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second

  digitalWrite(led2Pin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(led2Pin, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}
