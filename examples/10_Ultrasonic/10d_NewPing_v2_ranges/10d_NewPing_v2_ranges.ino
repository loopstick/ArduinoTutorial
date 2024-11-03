
//
// ranges for different actions
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

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

int hiThresh = 120;
int lowThresh = 60;
unsigned int dist = 0;

void setup() {
  //pinMode(trigPinGreen, OUTPUT); // Sets the trigPin as an Output
  //pinMode(echoPinGreen, INPUT); // Sets the echoPin as an Input

  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
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

// ===================================================================
// Light LEDs (or do other stuff, like play audio) according to ranges
// ===================================================================
   if (dist >= hiThresh) {
    // do "Far away" stuff here
    Serial.println("\t \t  \t FAR");
  }
  else if (dist < hiThresh && dist > lowThresh) {
    // do "medium distance" stuff here
    Serial.println("\t \t  MED");
  }
  else if (dist <= lowThresh) {
    // do "CLOSE" stuff here
    Serial.println("\t  CLOSE");
  }
// ===================================================================  

// ===================================================================  
} // END loop ========================================================
// ===================================================================  
