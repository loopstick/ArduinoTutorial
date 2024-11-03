
//
// Works better than without smoothing - a little slow to react but more stable
//
// ---------------------------------------------------------------------------
// Example NewPing library sketch that does a ping about 20 times per second.
// ---------------------------------------------------------------------------

#include <NewPing.h>
#define TRIGGER_PIN  11  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     12  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 360 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

//   50cm = 19.865" = approx 2ft
//   61cm = 2ft
//   76cm = 2.5ft
//  150cm = 5ft
//  300cm = 10ft - plenty!! for max
//  400cm = 13ft
//  500cm = 16ft

int hiThresh = 160;
int lowThresh = 60;

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

int ledPinBlue = 11;
int ledPinGreen = 10;
int ledPinRed = 9;

// Smoothing Variables
//  make sure variables do not exceed int8_t or u_int16_t limits
//  int maximum = 32768
// unsigned int maximum = 65,535

int readIndex = 0;              // the index of the current reading
unsigned int total = 0;                  // the running total
const int numReadings = 10;
unsigned int readings[numReadings];
//unsigned int readings[numReadings] = {0,1,2,3,4,5,6,7,8,9};   // array of the readings from the analog input

unsigned int dist = 0;
//unsigned int duration = 0;
unsigned int average = 0;

void setup() {
  //pinMode(trigPinGreen, OUTPUT); // Sets the trigPin as an Output
  //pinMode(echoPinGreen, INPUT); // Sets the echoPin as an Input

  pinMode(ledPinBlue, OUTPUT);
  pinMode(ledPinRed, OUTPUT);
  pinMode(ledPinGreen, OUTPUT);
  
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.

  // Initialize the thisReading array with all zeroes
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
  }
}

void loop() {
// ===================================================================
//   NEW PING  - ultrasonic sensor read
// ===================================================================
  delay(50);                     // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  dist = sonar.ping_cm(); // Send ping, get distance in cm - assign to variable (0 = outside set distance range)
  Serial.print("Ping: ");
  Serial.print(dist);  // print ping result (0 = outside set distance range)
  Serial.print("cm \t");
// ===================================================================

  // subtract current [readIndex] value from total (in preparation for adding in the new value)
  total = total - readings[readIndex];
  
  // read from the sensor:
  readings[readIndex] = dist; 
  // add the new sensor reading to the total:
  
  total = total + readings[readIndex];
  // advance to the next position in the array:
  
  readIndex = readIndex + 1;
  delay(20);

  // if we're at the end of the array...
  if (readIndex >= numReadings) {
    // ...wrap around to the beginning:
    readIndex = 0;
  }

    // debug printouts
    //  Serial.print("\t sensor: ");
    //  Serial.print(dist);
    //  Serial.print("\t readIndex: ");
    //  Serial.print(readIndex);
    //  Serial.print("\t total: ");
    //  Serial.print(total);
    //  Serial.print("\t OLD readings[readIndex]: ");
    //  Serial.print(readings[readIndex]);
    //  Serial.print("\t total-readings[readIndex]: ");
    //  Serial.print(total);
    //  Serial.print("\t NEW readings[readIndex]: ");
    //  Serial.print(readings[readIndex]);
    //  Serial.print("\t  total+readings[readIndex]: ");
    //  Serial.print(total);

  // calculate the average:
  average = total / numReadings;
    Serial.print("\t  Average:  ");
    Serial.print(" ");
    Serial.print(average);

// ===================================================================
// Light LEDs (and do other stuff, like play audio) according to ranges
// ===================================================================
    if (average >= hiThresh) {
    analogWrite(ledPinBlue, 0); //turn on Blue LED
    analogWrite(ledPinRed, 0);
    analogWrite(ledPinGreen, 50);
      // play FAR audio
    Serial.println("\t \t  \t FAR");
  }
  else if (average < hiThresh && average > lowThresh) {
    analogWrite(ledPinBlue, 50); //turn on Blue LED
    analogWrite(ledPinRed, 0);
    analogWrite(ledPinGreen, 0);
      // play MEDIUM audio
    Serial.println("\t \t  MED");
  }
  else if (average <= lowThresh) {
    analogWrite(ledPinBlue, 0); //turn on Blue LED
    analogWrite(ledPinRed, 50);
    analogWrite(ledPinGreen, 0);
      // play CLOSE audio
    Serial.println("\t  CLOSE");
  }
// ===================================================================  

// ===================================================================  
} // END loop ========================================================
// ===================================================================  
