/*
  Button control RGB LED - ST 2025

  Turns on and off a light emitting diode(LED) connected to pin 9 (RGB - red),
  when pressing a pushbutton attached to pin 2.

  The circuit:
  - RGB LED RED attached to pin 9 through 470 ohm resistor
  - RGB LED GREEN attached to pin 10 through 430 ohm resistor
  - RGB common connected to GND
  - pushbutton attached to pin 2 from +5V
  - 10K resistor attached to pin 2 from GND

  modified from
  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Button
*/

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin
const int redLEDPin = 9;     // LED connected to pin 9 (RGB red)
const int greenLEDPin = 10;  // LED connected to pin 10 (RGB green)

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  Serial.begin(9600);
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  pinMode(greenLEDPin,OUTPUT);
  pinMode(redLEDPin,OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  Serial.println(buttonState);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(redLEDPin, HIGH);
    digitalWrite(greenLEDPin, LOW);
  } else {
    // turn LED off:
    digitalWrite(redLEDPin, LOW);
    digitalWrite(greenLEDPin, HIGH);
  }
}
