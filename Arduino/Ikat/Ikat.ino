/*
  Ikat

  Dyes a piece of yarn for ikat weaving.

  Just sends a series of on/off commands to one (or more) painting devices.

  Not dissimilar to the basic Blink example program, just the timing of the blinks 
  is determined by an array of on and off time offsets.

  http://www.arduino.cc/en/Tutorial/Blink

  Painting devices:
  The initial system has a single color painting device.
  Each additional color would be an additional painting device.
  Additionally, one color of paint can be controlled 
  by two separate, successive devices:
  1) an airbrush button, which when pressed releases a continuous spray of paint.
     turning the spray on and off is relatively slow.
  2) a stepper-operated slit wheel, which blocks or lets pass through
     the continuous spray of paint from the airbrush.
     The slit-based on or off operation is relatively fast.
  The initial version of the program features a single slit-based on/off control.
  The paint spray is turned on or off manually. This will waste more paint than
  the two-device painting solution.
*/

// the setup function runs once when you press reset or power the board
void setup() {
  slitPaintInit();
}

// the loop function runs over and over again forever
void loop() {
  // Initial pattern is a simple striped pattern
  slitPaintOn();
  delay(500); // wait for a second
  slitPaintOff();
  delay(500); // wait for a second
}

// Paint operations are currently simulated with an LED
void slitPaintInit() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}
void slitPaintOn() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
}
void slitPaintOff() {
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
}

