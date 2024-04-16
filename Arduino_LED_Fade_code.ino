/*
By TurboTronics~
Like and subscribe!!
#Beginner_To_Professional series Part 2
Code's Link in Description!

Hey Once again to another beginner friendly project. Using this code, you will be using the PWM Pins Present on Arduino.
Now, What PWM is? PWM = Pulse Width Modulation , That is using digital pins to obtain analog signal output results.
In Arduino Uno R3/R4, There are certain pins marked with '~' sign. These are PWM pins. Turning a digital pin on and off 
very quickly with different ratio between on and off, creates different PWM values, which are used to control the brightness
of a LED bulb.

Requirements: Breadboard, Arduino Uno R3/R4, Jumper wires(male to male), 220 ohm resistor, LED bulb 
*/ 
int led = 9;         // The PWM pin on Arduino to which the LED is attached. It is also important to note that in Arduino UNO R4 WIFI, You can even use the builtin led for this work!
int brightness = 0;  // Creating a variable for setting the brightness of LED. You can change this variable
int fadeAmount = 5;  // How many points to fade the LED by. Try experimenting by changing this value.

void setup() { //Remember about setup() function??
  // declare PWM pin 9 to be an output:
  pinMode(led, OUTPUT);
}

void loop() { //Remember Function loop() ??
  // set the brightness of pin 9, This brightness is the variable which is created above, its value is currently 0, that is, the led is off! 
  analogWrite(led, brightness); //analogWrite() is a function used to utilize the PWM function of ~ marked pins. Values are between 0 to 255

  // change the brightness for next time through the loop:
  //As the loop continues, we will add a certain amount each time to brightness to slowly increase the brightness of led
  brightness = brightness + fadeAmount;

  /*Now comes a tricky part. We also want to dim the brightness of LED only when the brightness of led becomes full.
  When brightness becomes full, or brightness = 255, we will negative the value of fadeAmount variable. So, the brightness will gradually
  decrease. Now, when brightness = 0, we again want that the value of fadeAmount becomes positive, so,
  fadeAmount = -(-fadeAmount) = +fadeAmount. (integer rule)
  This is how we achieve continuous fading effect..
  If any doubts, ask in comments..
  */
  if (brightness <= 0 || brightness >= 255) {  // here, that || means 'or', <= means 'less than or equal to', >= means'greater than or equal to'
    fadeAmount = -fadeAmount;
  }
  // wait for 30 milliseconds to see the dimming effect. Try changing this value also and notice the change in led fade.
  delay(30);
}

/*Please support me just by Subscribing and watching my videos till last, so I will also bring unboxing 
videos on my channel. I will do all my efforts to turn all you beginners into professionals!! There's 
not only Arduino in electronics, there's a whole sea beyond! Stay Tuned with me and explore more!
Happy Coding!
 */

