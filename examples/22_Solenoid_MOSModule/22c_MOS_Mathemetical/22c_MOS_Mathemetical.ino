/*
  MOS module example code

  Dr Sudhu 3/5/24
*/

const int mos = 9;
int quarter = 500;
int half = quarter*2;
int whole = quarter*4; 
int eighth = quarter/2;
int sixteenth = quarter/4;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize the  signal pin as an output.
  pinMode(mos, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(mos, HIGH);   // turn the module on (HIGH is the voltage level)
  delay(quarter);                       // wait for a quarter note
  digitalWrite(mos, LOW);    // turn the module off by making the voltage LOW
  delay(quarter);                       // wait for a quarter note

  digitalWrite(mos, HIGH);   
  delay(eighth);                       // wait for an eighth note 
  digitalWrite(mos, LOW);   
  delay(eighth);                       // wait for an eighth note  

//  digitalWrite(mos, HIGH);   
//  delay(sixteenth);                    // wait for a sixteenth note 
//  digitalWrite(mos, LOW);   
//  delay(sixteenth);                    // wait for a sixteenth note  
//
//  digitalWrite(mos, HIGH);   
//  delay(sixteenth);                    // wait for a sixteenth note 
//  digitalWrite(mos, LOW);   
//  delay(sixteenth);                    // wait for a sixteenth note 

  digitalWrite(mos, HIGH);   
  delay(eighth);                       // wait for an eighth note 
  digitalWrite(mos, LOW);   
  delay(eighth);                       // wait for an eighth note  

  digitalWrite(mos, HIGH);   
  delay(eighth);                       // wait for an eighth note 
  digitalWrite(mos, LOW);   
  delay(eighth);                       // wait for an eighth note  
}
