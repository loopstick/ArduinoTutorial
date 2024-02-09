/*
  ReadAnalogVoltage  
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  This example code modified from: http://www.arduino.cc/en/Tutorial/ReadAnalogVoltage

  Reads an analog input on pin 0
  maps analog input range (0-1024) to output range (0-255)
  outputs mapped value to LED (brightness)
  
*/

  // int led = 13;  // <- if using the on-board LED
  int led = 9;  // <- using pin 9 for PWM -> analogWrite()
  int sensorValue = 0;
  int brightness = 0;
  
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  sensorValue = analogRead(A0);
  
  // print out the value you read:
  Serial.println(sensorValue);

  // map(value, fromLow, fromHigh, toLow, toHigh)
  brightness = map(sensorValue, 140, 750, 200, 100);

  // write brightness value to LED
  analogWrite(led, brightness);

  // write inverse brightness value to LED
  //analogWrite(led, 255-brightness);

}
