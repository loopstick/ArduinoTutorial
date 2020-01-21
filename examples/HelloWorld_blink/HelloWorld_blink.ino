/*
  a lovely combination of HelloWorld and Blink!
*/

int ledPin = 13;

void setup() {
//initialize serial communications at a 9600 baud rate
Serial.begin(9600);
pinMode(ledPin, OUTPUT);
}

void loop(){
//send 'Hello, world!' over the serial port
Serial.println("Hello, world!");
//wait a little so we don't see an continuous stream of messages that we can't read
delay(500);
digitalWrite(ledPin, HIGH);   // turn the LED on (HIGH is the voltage level)
delay(1000);                       // wait for a little while - do nothing else
digitalWrite(ledPin, LOW);    // turn the LED off by making the voltage LOW
delay(500);                       // wait for a little while - do nothing else
}
