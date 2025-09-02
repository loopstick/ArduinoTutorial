/*
  MOS module example code

  Dr Sudhu 3/5/24
*/

const int mos = 9;
int note = 500;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize the  signal pin as an output.
  pinMode(mos, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(mos, HIGH);    // turn the module on (HIGH is the voltage level)
  delay(random(1,5)*100);     // wait for a random amount of time
  digitalWrite(mos, LOW);     // turn the module off by making the voltage LOW
  delay(random(1,5)*100);     // wait for a random amount of time
}
