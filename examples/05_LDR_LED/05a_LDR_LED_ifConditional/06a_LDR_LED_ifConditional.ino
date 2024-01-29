/*
  AnalogReadSerial

  Reads an analog input on pin 0, lights LED if input exceeds threshold

    5v - LDR - 10kΩ - GND             pin 13 - LED - 330Ω - GND
           |
           A0  

  This example code is modified from:
  https://www.arduino.cc/en/Tutorial/BuiltInExamples/AnalogReadSerial
*/

//int led = 13;  // <- using the internal LED
int led = 9;  // <- using pin 9 for PWM -> analogWrite()
int sensorValue = 0;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(led, OUTPUT);  
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0: range 0-1024
  sensorValue = analogRead(A0);
  // print out the value you read:
  Serial.println(sensorValue);

  if(sensorValue > 512){
    digitalWrite(led, HIGH);  
  }else{
    digitalWrite(led, LOW);  
  }

  delay(1);        // delay in between reads for stability
}
