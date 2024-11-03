# ArduinoTutorial

### Arduino Hands-on Introduction Workshop

This workshop originally created by:
Michael Shiloh and Judy Castro for *Teach Me To Make*

Revised by Sudhu Tewari 2018-24

<!-- ##### Arduino Examples - coming soon! --> 

The workshop will focus on getting you up and running with Arduino quickly, so that you will understand the basic procedures for working with Arduino and can explore further on your own.

We will cover how to install Arduino on your laptop; how to understand, modify, and write Arduino programs; how to connect sensors to Arduino and read them from a program; and how to connect actuators (LEDs, motors, speakers) and control them from a program. Other topics will be covered as interest dictates and time permits.

#### What is Arduino anyway?
Read about Arduino here : https://www.arduino.cc/en/Guide/Introduction
Additionally: Lady Ada's [Learn Arduino](https://learn.adafruit.com/ladyadas-learn-arduino-lesson-number-0?view=all) lessons are great. The [tour](https://learn.adafruit.com/ladyadas-learn-arduino-lesson-number-0?view=all#take-a-tour) of Arduino architecture is particularly useful for understanding Arduino.

#### Before the Workshop - Install Arduino Software
Arduino software (IDE) runs on Windows, Mac OSX, and Linux. Please download and install the (free) Arduino software from http://arduino.cc/en/Main/Software.  <!-- We prefer to use an older version of the Arduino IDE: Version 1.8.19. Feel free to download the newer version as well and run them both for comparison. -->
Please bring your laptop, with the software installed, to the workshop.

Additional instructions at http://arduino.cc/en/Guide/HomePage  
and https://learn.adafruit.com/ladyadas-learn-arduino-lesson-number-0/download-software

An Arduino kit will be provided for use during the workshop or you may bring your own.

If you have questions prior to or after the workshop please contact Sudhu: loopstick@hotmail.com

#### At the Workshop
 - Please interrupt any time with questions.

### First steps: Verifying correct installation
All of this is in the Arduino Getting Started guide for your operating system. [https://www.arduino.cc/en/Guide/HomePage](https://www.arduino.cc/en/Guide/HomePage).

1. Connect Arduino via USB cable
   - Windows? Might see “New Hardware Discovered” and later might see “New Hardware Ready for Use”.
   - Mac OS X? Might see “New Network Interface Found”. Click “Network Preferences…”,  click “Apply”, and when it finishes, click “Close”. It doesn’t matter if the configuration fails.
   - Linux? Nothing to do here

2. Open Arduino software (IDE)

3. Select _Tools -> Board_
   - You have an Uno.

4. Select _Tools -> Port_
   - Windows? Chose the largest COM number
     - No COMs? Raise your hand for help or visit [troubleshooting](http://arduino.cc/en/Guide/Troubleshooting)
   - Mac OS X? Chose either usbmodem - you should also see _(Arduino Uno)_
     - No usbmodem? Raise your hand for help or visit [troubleshooting](http://arduino.cc/en/Guide/Troubleshooting)
   - Linux? There is only one choice

5. Open _File->Examples->Basics->Blink_
   - Click “Upload”
   - Look for errors in the bottom window of the program
     - Errors? Raise your hand for help or visit [troubleshooting](http://arduino.cc/en/Guide/Troubleshooting)
   - Look for the amber LED on your Arduino to be blinking
     - No blinking? Raise your hand for help or visit [troubleshooting](http://arduino.cc/en/Guide/Troubleshooting)

*******************************************************************************
### Is this thing on?
Copy the code below and paste it into a new Arduino sketch _OR_ download and open this example sketch: [HelloWorld.ino](/examples/HelloWorld/HelloWorld.ino)

```cpp
/*
  Hello World
  A "Hello, World!" program generally is a computer program that
	outputs or displays the message "Hello, World!".
	Such a program is very simple in most programming languages,
	and is often used to illustrate the basic syntax of a programming language.
	It is often the first program written by people learning to code
*/

void setup() {
//initialize serial communications at 9600 baud rate
Serial.begin(9600);
}

void loop(){
//send 'Hello, world!' over the serial port
Serial.println("Hello, world!");
//wait 100 milliseconds so we don't drive ourselves crazy
delay(1000);
}
```
The _Serial_ commands allow Arduino to send a message to your laptop. In order to see this message you need to open the _Serial Monitor_ by clicking on the magnifying glass near the top right corner.
- If you are using Arduino IDE 1.8._ the serial monitor will open in another window.
- If you are using Arduino IDE 2._._ the serial monitor will display at the bottom of the IDE window.

a little code anatomy:
- The [setup()](https://www.arduino.cc/reference/en/language/structure/sketch/setup/) function is called when a sketch starts.
  - Use it to initialize variables, pin modes, start using libraries, etc.
  - The setup() function will only run once, after each power-up or reset of the Arduino board.
- The [loop()](https://www.arduino.cc/reference/en/language/structure/sketch/loop/) the loop() function does precisely what its name suggests, and _loops_ consecutively through your list of instructions to control the Arduino.
  - The loop() functions runs continuously as long as the Arduino is powered on.
  - Each instruction is executed in order from top to bottom.
  - Arduino only executes one instruction at a time.

More on the specific functions and variables soon! Let's make something happen in the real world first.

*******************************************************************************
### How to use Arduino to turn something ON and OFF

Copy or download the code below rather than the Arduino tutorial code included in File > Examples. 
(The new version of Blink uses a helpful pointer to BUILTIN_LED, which makes part of the following explanation more difficult)
Most microcontrollers have an on-board LED which you can use for a real-world feedback. 
- On the Arduino Uno the built-in LED is connected to pin 13.
- We can send a signal to pin 13 to turn the LED on and off.
How does the program (sketch) do this? 
- it's all in the example below
  
Copy the code below and paste it into a new Arduino sketch _OR_ download and open this example sketch: Blink example sketch: [01a_Blink_st.ino](examples/01_Blink/01a_Blink_st/01a_Blink_st.ino)

```cpp
/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. 
  On the UNO it is attached to digital pin 13

  This example code is modified from.
  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
*/

int led = 13;  // define a variable to hold the pin number of the internal LED

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(led, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}
```
upload this code to your Arduino!

What happens?

You should see a little LED on the Arduino begin to blink on and off, about once per second.

Can you identify the code that makes this happen?

everything is explained in the [Blink](http://arduino.cc/en/Tutorial/Blink) tutorial
- some more code anatomy - more info about an Arduino [sketches](https://docs.arduino.cc/learn/programming/sketches/)

#### Exercise:
combine HelloWorld and Blink to make a program that shows it's working with physical (LED) and digital (serial) output.
- _Hint/Cheat:_ [02a_HelloWorld_blink.ino](examples/02_HelloWorld_blink/02a_HelloWorld_blink/02a_HelloWorld_blink.ino)


*******************************************************************************
### Let's add an LED of our own
- Add an external LED (as opposed to the internal LED we just lit up)

  ![LED_red](/images/LED_red_sm.jpg)

  Where (and how) do we connect the LED?

 <!-- ![ArduinoUno_Pinout_all](/images/ArduinoUno_Pinout_all.avif) -->

 <!-- ![ArduinoUno_Pinout](/images/ArduinoUno_Pinout.jpg) -->
  
  <!--![ArduinoUno_Pinout_simple](/images/ArduinoUno_Pinout_simple.png) -->

  ![ArduinoUno_board_top](/images/ArduinoUno_board_top.jpg)
  

### Using a solderless Breadboard to connect Arduino to other things (LEDs, motors, speakers, sensors, etc.)

The Solderless Breadboard (SparkFun [tutorial:](https://learn.sparkfun.com/tutorials/how-to-use-a-breadboard))

![Breadboard](/images/Breadboard_st.jpg)

![Breadboard underside](/images/BreadboardUnderside_st.jpg)

[Breadboard connections](http://wiring.org.co/learning/tutorials/breadboard/)


Use the breadboard to add an external LED (and a resistor).

  ![LED](/images/led.jpg)
  
  ![Resistor](/images/resistor_sm.jpg)
 
- LEDs must always be used with resistors so they don’t burn out.
  - The resistor value can be anywhere from 100 ohm to 1k ohm.
    - The lower the resistance, the brighter the light.
    - Evil Mad Scientist explains it well [here](https://www.evilmadscientist.com/2012/resistors-for-leds/)
  - Resistor Color Code!
    - [Learn the Resistor Color Code in in 5 minutes](http://www.resistorguide.com/resistor-color-code/)

    ![ResistorColorCode](/images/ResistorColorCode.png)

- LEDs are polarized
  - video: [identifying LED polarity](https://www.youtube.com/watch?v=SRDgNR_yCms)

  ![led_example](/images/LED_example.png)  ![LED_red](/images/LED_red_md.jpg)

Here’s a picture showing how to connect the LED and resistor on the breadboard:

 <!-- ![LED_Resistor Pic](/images/LED_Breadboard1_rev.jpg) -->
![LED_Resistor Pic](/images/LED_Breadboard2.jpg)

Here is another view of this circuit:

<!-- ![Fritzing: LED resistor pic](/images/2-Blink-an-LED_SMALL.jpg) -->
![Fritzing: Arduino_1LED_d13_bb](/images/Arduino_1LED_d13_bb.png)

And here is a schematic of this circuit:

<!-- ![Fritzing: LED resistor schematic](/images/Arduino_LED_Resistor_schem.jpg) -->
![Fritzing: LED resistor schematic](/images/Arduino_1LED_d13_schem.png)

Use the Blink sketch we used earlier: [01a_Blink_st.ino](examples/01_Blink_st/01a_Blink_st/01a_Blink_st.ino)
- (you can also use the IDE example, but it has some "hepful" shortcuts that make what we'll do next more complicated: _File -> Examples -> Basics -> Blink_)
	
 - Does your LED blink?
		(think about why)

#### Exercise 1:
Move LED to a different pin (e.g. pin 8).
	See if you can figure out how to do this on your own

_Hint:_ the LED won’t blink until you change the program, since the program is only turning pin 13 on and off. Change the program to control pin 8.

#### Exercise 2:
If you changed the program to control only pin 8, then the built-in LED on pin 13 is no longer blinking. Can you change the program to make them both blink?

Are we limited to LEDs? No; we could replace the LED (and its resistor) with any other suitable device, with some considerations. We’ll learn more about this later.

*******************************************************************************
### How to use a sensor: analogRead()
So far we’ve only used Arduino as an output device, to control something in the physical world (the LED). The other way of interfacing to the physical world is as an input device, using a sensor to get information about the physical world. We’ll start with a photoresistor, also called a light dependent resistor or LDR. It’s a resistor whose resistance depends on the light: the more light, the lower the resistance. (The resistor we used above with the LED is a fixed resistor.)

![LDR.png](/images/LDR.png)
<!-- ![LDR_withSchem.png](/images/LDR_withSchem.png) -->

The LDR responds to the amount of light by changing its resistance. Arduino cannot measure resistance directly, but can measure voltage (electrical potential).  Fortunately, we can easily convert a varying resistance to a varying voltage using a fixed resistor to create a [voltage divider](https://learn.sparkfun.com/tutorials/voltage-dividers/all). This time the fixed resistor needs a larger resistance, so select a 10k ohm resistor and build the circuit below. You don’t need to remove the LED circuit as there should be room on your breadboard for both, and we’ll use the LED again later.

<!-- ![CircuitExample](/images/Arduino_LDR_VoltageDiv.jpg) -->
![Fritzing: LDR_bb.png](/examples/03_LDR_LightSensor/LDR_bb.png)

Open and upload this sketch:
[03a_LDR_LightSensor.ino](/examples/03_LDR_LightSensor/03a_LDR_LightSensor/03a_LDR_LightSensor.ino)
- you can also use the Arduino IDE example ->_File->Examples->Basics->AnalogReadSerial_

How do you know if anything is working? Arduino might be reading the sensor, but is it telling you anything? 

Arduino is connected to your computer, so they can communicate - just like we did earlier with Hello World, but now your Ardunio is sending sensor DATA!
 - this line: ```Serial.println(sensorValue);``` allows Arduino to send a message to your laptop. 
- In order to see this message you need to open the _Serial Monitor_ by clicking on the magnifying glass near the top right corner.
- you can also see a graph of the real time data with the Serial Plotter (_Tools > Serial Plotter_)
- Read the Arduino [AnalogReadSerial tutorial](http://arduino.cc/en/Tutorial/AnalogReadSerial) to find out more.
- Also see _File->Examples->Communication_ for more examples of other types of Serial communication).

Now that we've got sensor data coming in (as a range of values) what can we do with the data?

We could do some math to calculate the voltage we're measuring:
 -> _File->Examples->Basics->AnalogReadVoltage_
 - this will show us the voltage that the Arduino analog pin is measuring

What other kinds of sensors are there?
- [Sensor workshop at ITP](https://itp.nyu.edu/physcomp/lessons/sensors-the-basics/)
- [Adafruit Sensors](https://www.adafruit.com/category/35)
- lots of different sensors means we can sense lots of different things!

That's nice, but what if we want to use the sensor data to control some kind of physical reaction (light, heat, motion) to the data?

Let's shift our focus, for a moment, to outputting a range of voltages. Then we'll put the input and output together to get real world input to control real world output. 

*******************************************************************************
### analogWrite(): Controlling speed or brightness
If digitalWrite() can turn an LED on and off, and analogRead() can read a range of values, what would you guess analogWrite() might do?
- If digitalWrite() can turn an LED on and off, and analogRead() can read a range of values, what would you guess _analogWrite()_ might do?
  - You guessed it!
- analogWrite() outputs a range of values, using [PWM](https://www.arduino.cc/en/tutorial/PWM)
  - PWM = pulse width modulation
  - this allows us, effectively, to output any voltage between minimum and maximun
    - minimum = 0 volts = 0 in code
    - maximum = 5 volts = 255 (@8bit resolution)

Move the LED to pin 9:
![Fritzing: LED_pin9_bb.png](/examples/04_LED_Fade/LED_pin9_bb.png)

Now upload this sketch:
[04a_LED_Fade.ino](/examples/04_LED_Fade/04a_LED_Fade/04a_LED_Fade.ino) 
 - you can also use the Arduino IDE _Fade_ example:_File -> Examples -> Basics -> Fade_


What’s the LED doing? Can you figure out how the sketch is doing this?
```cpp
analogWrite(led, brightness);
// and then
brightness = brightness + fadeAmount;
// How does it know to start fading down when it reaches the maximum value?
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ;
  }
```

Why did I ask you to move the LED to pin 9?
	It turns out analogWrite() only works on certain pins which are capable of [PWM](https://www.arduino.cc/en/tutorial/PWM) output: 3, 5, 6, 9, 10, and 11.
	see the [Arduino Uno Board Pins reference](https://www.arduino.cc/en/Reference/Board) for more info

for extra fun, check out _File -> Examples -> Analog -> Fading_ <- this implements a For loop to do the fading!

*******************************************************************************
### Interfacing input & output -> sensor data controls LED state
Now that we've worked with _analogRead()_ to read a range of voltage coming from our LDR.
AND
we've used _analogWrite()_ to fade our LED using a range of voltage

-> can we use the LDR data to control the LED brightness?
-> Yes, we can!!

![LDR_LED_bb.png](examples/05_LDR_LED/LDR_LED_bb.png)

#### Exercise: 
- use the LDR data to control the LED brightness!
- _Hint/Cheats:_
  - [05a_LDR_LED_ifConditional.ino](examples/05_LDR_LED/05a_LDR_LED_ifConditional/05a_LDR_LED_ifConditional.ino)
  - [05b_LDR_LED_MapFade.ino](examples/05_LDR_LED/05b_LDR_LED_MapFade/05b_LDR_LED_MapFade.ino)


*******************************************************************************
### RGB LED - 3 in 1 gets us (almost) all the colors we can imagine!
- RGB LEDs have 3 LEDs in one physical package
- RGB LEDs are really handy for non-text, non-serial debug and they make really pretty colors!
- We can use analogWrite() to define the intensity of each color with a value between 0 and 255. 
  - That means there are 256 x 256 x 256 = 16777216 possible colors!
 
<!-- ![RGB_LED.jpg](/images/RGB_LED.jpg) -->
<img src="/images/RGB_LED.jpg" width="700">
<!-- <img src="/images/RGB_LED.jpg" width="150" height="280"> --> 

- we still need to use a limiting resistor to keep our LEDs safe
- Generally we use a slightly larger resistor (470 ohm) for the RED component and the same slightly smaller resistor values (430 ohm) for the GREEN and BLUE components.
  - for our circuit let's use:
    - 470 ohm for RED
      - color bands-> yellow, purple, black, black, brown
    - 430 ohm for GREEN and BLUE
      - color bands-> yellow, orange, black, black, brown
- We're using common _CATHODE_ RGB LEDs
  - the negative leg (the cathode) is shared by (is common to) all 3 LEDs

RGB LED wiring diagram 
![RGB_LED_bb.png](/examples/06_RGB_LED/RGB_LED_bb.png)

RGB LED test code
- [06a_RGB_Test.ino](/examples/06_RGB_LED/06a_RGB_Test/06a_RGB_Test.ino)
- [06b_RGB_SimpleFade.ino](/examples/06_RGB_LED/06b_RGB_SimpleFade/06b_RGB_SimpleFade.ino)


Some other online information about RGB LEDs
 - [Random Nerd Tutorials: How Do RGB LEDs Work](https://randomnerdtutorials.com/electronics-basics-how-do-rgb-leds-work/)
 - [Adafruit Arduino Lesson 3: RGB LEDs](https://learn.adafruit.com/adafruit-arduino-lesson-3-rgb-leds/breadboard-layout)
 - [How to Mechatronics: How To Use a RGB LED with Arduino](https://howtomechatronics.com/tutorials/arduino/how-to-use-a-rgb-led-with-arduino/)


*******************************************************************************
### Button - Let's add some tactile input!!

A button (switch) is a mechanical device that makes or breaks an electrical connection, usually by moving small metal componenets so they touch or don't touch, thus allowing or preventing the flow of electrons through the conductors.

![SwitchCircuit.png](/images/SwitchCircuit.png)

<!-- ![SwitchButton_actual.jpg](/images/SwitchButton_actual.jpg) -->
<img src="/images/SwitchButton_actual.jpg" width="300">

![SwitchButton.png](/images/SwitchButton.png)

start by wiring a button like this:
![Button_bb.png](/examples/07_Button/Button_bb.png)

if you don't still have an LED hooked up, add one on pin 13, like this:
![Button_LED_bb.png](/examples/07_Button/Button_LED_bb.png)

Button example code:
- [07a_Button.ino](/examples/07_Button/07a_Button/07a_Button.ino) - same as _Examples -> Digital -> Button_
- [07b_Button_StateChangeDetection.ino](/examples/07_Button/07b_Button_StateChangeDetection/07b_Button_StateChangeDetection.ino) - same as _Examples -> Digital -> StateChangeDetection_



Some other online information about buttons (aka pushbuttons aka tactile swiches)
- [Tactile switches](https://www.youtube.com/watch?v=tYemeoqxpNk)
- [Understanding Pushbuttons and Pull Up and Pull Down Resistors](https://www.youtube.com/watch?v=AgQW81zzR18)
- [Using a Pushbutton as a Toggle Switch](https://www.youtube.com/watch?v=aMato4olzi8&ab_channel=PaulMcWhorter)


*******************************************************************************
### Potentiometer
A poteniometer is a like a button in that it allows for tactile control of electron flow, but it allows from analog control rather than just the digitial on/off. With a potentiometer we can adust to any value between minimum and maximum voltage.

![Potentiometers_all.png](/images/Potentiometers_all.png)

Our potentiometers look like this: 

<img src="/images/Potentiometer_actual.jpg" width="200">

start by wiring the potentiometer circuit like this:
![Potentiometer_bb.png](/examples/08_Potentiometer/Potentiometer_bb.png)

Potentiometer example code:
- [08a_Pot_ReadAnalogVoltage.ino](/examples/08_Potentiometer/08a_Pot_ReadAnalogVoltage/08a_Pot_ReadAnalogVoltage.ino) - same as _Examples -> Basics -> ReadAnalogVoltage

Now, add an LED like this:
![Potentiometer_LED_bb.png](/examples/08_Potentiometer/Potentiometer_LED_bb.png)

- [08b_Pot_AnalogInput.ino](/examples/08_Potentiometer/08b_Pot_AnalogInput/08b_Pot_AnalogInput.ino) - same as _Examples -> Analog -> AnalogInput_
- [08c_Pot_AnalogInOutSerial.ino](/examples/08_Potentiometer/08c_Pot_AnalogInOutSerial/08c_Pot_AnalogInOutSerial.ino) - same as _Examples -> Analog -> AnalogInOutSerial_ <-remember to move the LED to pin 9 -> because analogWrite() uses ~PWM

Code challenges:
- potentiometer controls RGB LED color: 1 knob to control them all (the colors)

*******************************************************************************
### Servo motors
Servo motors are a simple and easy way to add motion to your Arduino project.
- They 'know' their own position which makes them easy to control
- they are not _that_ powerful (although larger, more power servos _do_ exist)

<img src="/images/Servo.jpg" width="425"> <img src="/images/Servo_diagram.jpg" width="550">

leave the potentiometer from the previous example connected and add the servo on pin 9. 

![Servo_Potentiometer_v2_bb.png](/examples/09_Servo/Servo_Potentiometer_v2_bb.png)


The servo needs 3 connections:
- positive voltage (power) - in this case: 5v
- ground (GND: 0v)
- signal (the PWM signal from your microcontroller that tells the servo where to go)

Servo example code:
- [09a_Servo_Knob.ino](/examples/09_Servo/09a_Servo_Knob/09a_Servo_Knob.ino) - same as _Examples -> Servo -> Knob_
- [09b_Servo_Sweep.ino](/examples/09_Servo/09b_Servo_Sweep/09b_Servo_Sweep.ino) - same as _Examples -> Servo -> Sweep_

Code challenges:
- potentiometer controls sweep speed
- potentiometer controls sweep range


More comprehensive information about servos:
- [How To Mechatronics: How to Control Servo Motors with Arduino](https://howtomechatronics.com/how-it-works/how-servo-motors-work-how-to-control-servos-using-arduino/)
- [Hobby Servo Tutorial: Sparkfun](https://learn.sparkfun.com/tutorials/hobby-servo-tutorial/all)



*******************************************************************************
### Ultrasonic Distance Sensor - HC-SR04
The HC-SR04 ultrasonic sensor uses sonar to determine distance to an object like bats or dolphins do. They offer excellent non-contact range detection in an easy-to-use package. According to the manufacturer specifications the detection range is 2-400cm or 1-157" (13 feet). 

<img src="/examples/10_Ultrasonic/HCSR04_Ultrasonic_Distance_Sensor.jpg/" width="425"> 

- notes:
  - ultrasonic rangefinders work best when used with a code library (like [NewPing](https://docs.arduino.cc/libraries/newping/))
  - ultrasonic rangefinders are susceptible to false triggers when subjected to loud sounds.
  - ultrasonic rangefinders are not affected by sunlight or black material like Sharp IR rangefinders are (although acoustically soft materials like cloth can be difficult to detect). 

start by wiring the ultrasonic sensor like this:

<img src="/examples/10_Ultrasonic/Ultrasonic_noBB_bb.png" width="800"> 

 hint: you can use Male-Female jumpers to connect directly from the ultrasonic sensor to your Arduino
 <img src="/images/jumper_MtoF.jpg" width="200"> 



- Simple Ultrasonic example code using 
  - FIRST -> install [Erick Simoe's Ultrasonic](https://github.com/ErickSimoes/Ultrasonic) library
  - [10a_UltrasonicSimple_werk.ino](/examples/10_Ultrasonic/10a_UltrasonicSimple_werk/10a_UltrasonicSimple_werk.ino) 
  - [10b_UltrasonicSimple_InCm.ino](/examples/10_Ultrasonic/10b_UltrasonicSimple_InCm/) 

- NewPing example code:
  - FIRST -> install [Tim Eckel's NewPing](https://bitbucket.org/teckel12/arduino-new-ping/wiki/Home) library 
  - [10c_NewPing_v1_simple.ino](/examples/10_Ultrasonic/10c_NewPing_v1_simple/10c_NewPing_v1_simple.ino)
  - [10d_NewPing_v2_ranges.ino](/examples/10_Ultrasonic/10d_NewPing_v2_ranges/10d_NewPing_v2_ranges.ino)   
  - [10e_NewPing_v4_Smoothing_RGB.ino](/examples/10_Ultrasonic/10e_NewPing_Smoothing_v4_RGB/10e_NewPing_Smoothing_v4_RGB.ino) 

More comprehensive information about ultrasonic sensors:
  - [How To Mechatronics: Ultrasonic Sensor HC-SR04 and Arduino](https://howtomechatronics.com/tutorials/arduino/ultrasonic-sensor-hc-sr04/) 
  - [Lady Ada: Ultrasonic Sonar Distance Sensors Overview](https://learn.adafruit.com/ultrasonic-sonar-distance-sensors/overview)  
  - [Last Minute Engineers: How HC-SR04 Ultrasonic Sensor Works](https://lastminuteengineers.com/arduino-sr04-ultrasonic-sensor-tutorial/) 


*******************************************************************************
### Sensor ranges, calibration, and mapping
  - coming soon


*******************************************************************************
### Passive Infrared Sensor - PIR

<img src="/examples/11_PIR/HC-505-Mini-PIR-Motion-Sensor-Module.jpg" width="425"> 

 Here are a few tutorials on PIR sensors:

- [How to Mechatronics: How PIR Sensor Works and How To Use It with Arduino](https://howtomechatronics.com/tutorials/arduino/how-pir-sensor-works-and-how-to-use-it-with-arduino/)
- [Lady Ada: PIR Motion Sensor](https://learn.adafruit.com/pir-passive-infrared-proximity-motion-sensor/overview)
- [Arduino with PIR Sensor](https://randomnerdtutorials.com/arduino-with-pir-motion-sensor/)


*******************************************************************************
### NeoPixels (low-current) 

NeoPixels are individually addressable (WS2812B) RGB LEDs that can be chained together to create a string of lights. They are very bright and can be used to create a wide range of colors. They are available in a variety of form factors, including strips, rings, and matrices. They are typically controlled by a single data line and can be powered by 5V. That said, our Arduino can only supply a limited amount of current, so we need to be careful when powering neoPixels.  

If you want to understand addressable LEDs (aka neoPixels), read this guide!! 
- [Adafruit NeoPixel Uberguide](https://learn.adafruit.com/adafruit-neopixel-uberguide)

<img src="/images/neopixel_Stick_cropped.jpg" width="650"> 

We can start with a simple test to get familiar with the NeoPixel library. When we're ready to control larger numbers of NeoPixels, we'll need to consider power requirements and how to power them safely.

<img src="/examples/12_NeoPixel/NeoPixel_stick_bb.png" width="850"> 

- neoPixel example code:
  - FIRST -> install the Adafruit [NeoPixel](https://github.com/adafruit/Adafruit_NeoPixel) library
  - [12a_NeoPixel_simpleTest.ino](/examples/12_NeoPixel/12a_NeoPixel_simpleTest/12a_NeoPixel_simpleTest.ino)
    - [12b_NeoPixel_strandtest.ino](/examples/12_NeoPixel/12b_NeoPixel_strandtest/12b_NeoPixel_strandtest.ino)


<!-- *******************************************************************************
Earlier, we lit up an LED using _analogWrite()_ based on sensor data _analogRead()_!

What else can _analogWrite()_ do?
	_analogWrite()_ also works well to control the speed of a motor. However now we need to consider whether our motor is compatible with Arduino’s outputs.
  -->

*******************************************************************************
### Arduino outputs: Voltage and current
- When used as outputs, two things must be considered: the voltage and the current. Our Arduino can deliver 5 v, and at most 40 mA.
- The voltage is determined by Arduino, but the current is determined by whatever we’re trying to control. In the case of the LEDs, they only need 20 mA or less. The motor we have might take more than 40 mA. In the worst case, when it’s stalled, it might want a 200 mA.
- The important thing to realize is that Arduino does not have the ability to limit this current. It will try to deliver whatever is asked of it, even if it overheats and damages itself.
- If we want to control a device that might take more than 40 mA, we have to use an intermediary.
- the most common device for controlling large current loads with a microcontroller is a transistor (we could also use a relay or a switch)

### Controlling large loads with a transistor
The transistor is like a bicycle gear: you control it with a small amount of current, and it in turn can control a lot more current. The transistor also allows us to use a higher voltage than the 5V Arduino can deliver.

Use a transistor to control a higher current for a motor.
 - There are hundreds of transisors that will work for this application. 
   - here are a few that I commonly use:
	- [TIP120](https://cdn-shop.adafruit.com/datasheets/TIP120.pdf) - Darlington sold by Adafruit
	- [IRF520](https://www.vishay.com/docs/91017/91017.pdf)
	- [IRF8721](https://cdn-shop.adafruit.com/datasheets/irlb8721pbf.pdf) - MOSFET sold by Adafruit
  - never assume the pinout of a transistor or IC.
    - ALWAYS look up the pinout before applying power.
      - or else 爆炸
      
Transistor Motor Control with 2x AA Batteries = 3V:
![CircuitExample](/images/Motor_Transistor_AA.jpg)


You can test this with either
	_File -> Examples -> Basics -> Blink_	
or
	_File -> Examples -> Basics -> Fade_

It's important to note that we are now using a separate power source for the motor. There are good reasons for doing so...

<!-- Transistor Motor Control with a 9v Battery: ![CircuitExample](/images/Transistor_Motor.jpg) --> 
	
##### References:
- [Arduino Docs: Transistor Motor Control](https://docs.arduino.cc/learn/electronics/transistor-motor-control/)
- [ITP NYU: Using a Transistor to Control High Current Loads](http://itp.nyu.edu/physcomp/labs/motors-and-transistors/using-a-transistor-to-control-high-current-loads-with-an-arduino/)


*******************************************************************************

### H-Bridge Motor Driver
- The H-Bridge is a circuit that allows us to control the direction of a motor as well as its speed.

![Hbridge GIF](/images/Hbridge/Hbridge.gif) 

### L298N H-Bridge Motor Driver
- The L298N is a popular H-Bridge motor driver that can be used with the Arduino.
- The L298N has 2 H-Bridges, which means it can control 2 motors.
- The L298N can handle up to 2A per channel, and up to 35V.
<!-- - The L298N has a built-in 5V regulator, so it can be used to power the Arduino.
- The L298N has a built-in diode to protect against voltage spikes from the motor.
- The L298N has a built-in heat sink, so it can handle a lot of power without overheating.
- The L298N has a built-in current sense resistor, so it can detect when the motor is stalled. -->

  <img src="/images/Hbridge/dual-h-bridge-motor-driver-l298n-44325-750x750.jpg" width="450">

notes:
- on many L298N modules, the power input is labeled 12v
  - but it can handle up to 35v
  - and it can run as low as 4.5v

- since motors take a significant amount of current, we'll use a separate power source for the motor(s)
  - this external source can be a power supply or a battery pack


### External Power Supply - L298N H-Bridge Motor Driver 

  <img src="/images/powerSupply.jpg" width="350">

- We can power the motor(s) with an external power supply      
  - match the power supply voltage to the motor voltage 
    - you'll also need to consider the motor's current draw
    - the manufacturer's specification should provide this information

- the L298N can get the 5v it needs to operate from an onboard voltage regulator 
    - most voltage regulators need about 2v more than their output voltage so the minimum voltage is 7v
- we can also use the L298's onboard voltage regulator to provide 5V for our Arduino

<img src="/images/Hbridge/l298n_1Motor_powerSupply.png" width="950">


### 6v Battery Pack - L298N H-Bridge Motor Driver

- We can power the motor(s) with 6v (4x 1.5v AA batteries) 
  - this is the maximum for [TT motors](https://www.adafruit.com/product/3777)

- the L298N can get the 5v it needs to operate from an onboard voltage regulator OR from an external 5v source
  - since we're only giving it 6v for the motor(s), we'll need to power it with the Arduino's 5v
    - most voltage regulators need about 2v more than their output voltage
- because we're bypassing the onboard voltage regulator we'll need to remove the shorting block near the 5v screw terminal

<img src="/images/Hbridge/L298n_1Motor_6vAA_notes.png" width="950">


### L298N H-Bridge Motor Driver - Operation

- _IN1 & IN2_ control the direction of the motor rotation of motor 1

- _ENA_ "enables" motor 1. 
  - with the shorting block in place, the motor is always on
  - if you connect _ENA_ to a digital pin, you can control the motor On/Off with a digitalWrite() 
  - if you connect _ENA_ to an analog pin, you can use analogWrite() to control the speed of the motor

- _IN3 & IN4_ control the direction of the motor rotation of motor 2
- _ENB_ "enables" motor 2. 

<img src="/images/Hbridge/llustration-of-L298N-Dual-H-Bridge-Motor-Driver.ppm" width="750">

### L298N H-Bridge Motor Driver - Code

L298N example code:

- We _could_ write our own code to control ENA, IN1, and IN2 pins, but there are quite a few H-bridge libraries available for Arduino that make it easier to control the L298N. 
  - We'll use the Arduino [L298N library](https://www.arduino.cc/reference/en/libraries/l298n/)
  - You'll probably need to install the library before you can use it.
    - _Tools -> Manage Libraries_ and search for L298N
    - select the one by Andrea Lombardo and click install
  - _File -> Examples -> L298N -> L298N-Simple_ to control 1 motor
  - _File -> Examples -> L298N -> L298N-Fade_ to control 1 motor, 'fading' the speed up and down


### L298N H-Bridge Motor Driver - References:
- [How To Mechatronics: L298 Motor Driver](https://howtomechatronics.com/tutorials/arduino/arduino-dc-motor-control-tutorial-l298n-pwm-h-bridge/)
- [Arduino: L298N library](https://www.arduino.cc/reference/en/libraries/l298n/)



++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

## More to explore
- Joining inputs and outputs: switch controls speed, switch choses between two brightness levels, thermistor or other sensor changes behavior, etc
- INPUT_PULLUP
- Interrupts
- Boolean logic, tests, and conditionals
- Making sounds: [Melody](https://itp.nyu.edu/physcomp/labs/labs-arduino-digital-and-analog/tone-output-using-an-arduino/) tutorial
- Multiple output devices: play melody while controlling motor speed, etc.

- The problem with, and a solution to, delay(): 
  - [BlinkWithoutDelay](http://arduino.cc/en/Tutorial/BlinkWithoutDelay) tutorial

*******************************************************************************

## Resources!!!
- [Dr Sudhu's resources page](https://github.com/loopstick/ResourcesForClasses)






