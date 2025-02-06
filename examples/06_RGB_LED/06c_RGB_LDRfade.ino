/*
Example Code - ST 2/5/2025

single RGB LED - common anode (negative)
using pins 9, 10, 11

CITRUS test:
use LDR to control brightness of 
RED LED(directly proportional) 
& GREEN LED (inversely proportional) 

*/
int sensorValue = 0;
int sensorPin = A0;

int brightness = 0;    // how bright the LED is
int redBrightness = 0;
int greenBrightness = 0;
int blueBrightness = 0;

//int fadeAmount = 5;    // how many points to fade the LED by
int redFadeAmount = 5;    
int greenFadeAmount = 5;    
int blueFadeAmount = 5;    

const int redLEDPin = 9;     // LED connected to pin 9
const int greenLEDPin = 10;  // LED connected to pin 10
const int blueLEDPin = 11;    // LED connected to pin 11

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600); 
  pinMode(sensorPin, INPUT);

  // set the digital pins as outputs
  pinMode(greenLEDPin,OUTPUT);
  pinMode(redLEDPin,OUTPUT);
  pinMode(blueLEDPin,OUTPUT);

  TestEm();
}

void loop() {
// read the input on analog pin 0:
  sensorValue = analogRead(sensorPin);
  // print out the value you read:
  Serial.print("Analog IN value = ");
  Serial.print(sensorValue);
  delay(50);        // delay in between reads for stability

// actual observed values
// lowest value in the HL = 327
// highest value = 822
brightness = map(sensorValue, 300, 850, 0, 255);
  Serial.print("\t brightness = ");
  Serial.println(brightness);

  analogWrite(redLEDPin, brightness); 
  analogWrite(greenLEDPin, 255-brightness); 

// NOT USED ANYMORE
// // RED ==========================================
// // set the brightness of RED - pin 9:
//   analogWrite(redLEDPin, redBrightness);  
  
//   // change the brightness for next time through the loop:
//   redBrightness = redBrightness + redFadeAmount;

//   // reverse the direction of the fading at the ends of the fade: 
//   // range scaled just because: 0-255 changed to 0-100
//   if (redBrightness == 0 || redBrightness == 200) {
//     redFadeAmount = -redFadeAmount ; 
//   }     
//   // wait for 30 milliseconds to see the dimming effect    
// //
// //==========================================
 
//  // GREEN ==========================================
//  // set the brightness of Green - pin 10:
//   analogWrite(greenLEDPin, greenBrightness);  
  
//   // change the brightness for next time through the loop:
//   greenBrightness = greenBrightness + greenFadeAmount;

//   // reverse the direction of the fading at the ends of the fade: 
//   if (greenBrightness == 0 || greenBrightness == 120) {
//     greenFadeAmount = -greenFadeAmount ; 
//   }     
//   // wait for 30 milliseconds to see the dimming effect    
//   //delay(10);   

// // BLUE ==========================================
//   // set the brightness of BLUE - pin 11:
//   analogWrite(blueLEDPin, blueBrightness);  
  
//   // change the brightness for next time through the loop:
//   blueBrightness = blueBrightness + blueFadeAmount;

//   // reverse the direction of the fading at the ends of the fade: 
//   if (blueBrightness == 0 || blueBrightness == 255) {
//     blueFadeAmount = -blueFadeAmount ; 
//   }     
//   // wait for 30 milliseconds to see the dimming effect    
//   delay(30); 
// //==========================================

// // Fade;
}

// ---------------------------------
void AllOff (){
  analogWrite(redLEDPin, 0);
  analogWrite(greenLEDPin, 0);
  analogWrite(blueLEDPin, 0);
}
// ---------------------------------

// ---------------------------------
void TestEm() {
  //Test the LED.
  analogWrite(redLEDPin, 100);
  delay(300);
  analogWrite(redLEDPin, 0);
  delay(300);
  analogWrite(greenLEDPin, 100);
  delay(300);
  analogWrite(greenLEDPin, 0);
  delay(300);
  analogWrite(blueLEDPin, 100);
  delay(300);
  analogWrite(blueLEDPin, 0);
  delay(300);
}
// ---------------------------------
