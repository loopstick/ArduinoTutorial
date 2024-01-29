/*
  a lovely combination of HelloWorld and Blink!
*/

int led = 13;

void setup() {
//initialize serial communications at a 9600 baud rate
Serial.begin(9600);
pinMode(led, OUTPUT);
}

void loop(){
Serial.println("Hello, world!"); //send 'Hello, world!' over the serial port
digitalWrite(led, HIGH);        // turn the LED on (HIGH is the voltage level)
delay(1000);                    // wait for a little while - do nothing else
digitalWrite(led, LOW);         // turn the LED off by making the voltage LOW
delay(1000);                     // wait for a little while - do nothing else
}
