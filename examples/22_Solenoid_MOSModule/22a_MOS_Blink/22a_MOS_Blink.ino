/*
  MOS module example code

  Dr Sudhu 3/5/24
*/

const int mos = 9;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize the  signal pin as an output.
  pinMode(mos, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(mos, HIGH);   // turn the module on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(mos, LOW);    // turn the module off by making the voltage LOW
  delay(1000);                       // wait for a second
}
