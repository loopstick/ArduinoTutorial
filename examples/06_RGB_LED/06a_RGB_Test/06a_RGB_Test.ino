/* 

 Example code for Arduino Tutorial
  
    RGB LED connected to pins 9, 10, 11

  We still need to use limiting resistors to keep our LEDs safe

  Generally we use a slightly larger resistor (470 ohm) for the RED component 
    and the same slightly smaller resistor values (430 ohm) for the GREEN and BLUE components.

  for our circuit let's use:
  - 470 ohm for RED
    - color bands -> yellow, purple, black, black, brown
  - 430 ohm for GREEN and BLUE
    - color bands -> yellow, orange, black, black, brown
*/

 
// the numbers of the LED pins
const int redLED = 9;  
const int greenLED = 10;  
const int blueLED = 11;  

int delaytime = 500;  // a variable for all delay times
                      // now we can change them all just by changing this one number!
 
void setup(){
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
}

// note: full brightness is REALLY bright, so we often start at 50% and increase from there if necessary 

void loop(){
    analogWrite(redLED, 127);   // turn red on 50%
    delay(delaytime);           // wait
    analogWrite(redLED, 0);     // set red to 0%
    delay(delaytime);           // wait

    analogWrite(greenLED, 127);
    delay(delaytime);
    analogWrite(greenLED, 0);
    delay(delaytime);

    analogWrite(blueLED, 127);
    delay(delaytime);
    analogWrite(blueLED, 0);
    delay(delaytime);
}
