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
  // Pattern is repeated Morse code "SOS"
  // S----   O----------   S----       
  // =.=.=...===.===.===...=.=.=.......
  dot(); dot(); dot();    // S
  letterSpace();
  dash(); dash(); dash(); // 0
  letterSpace();
  dot(); dot(); dot();    // S
  letterSpace();
  wordSpace();
}

// Morse functions just for testing
int s = 200; // Morse code speed, the length of a dot or of the space between symbols
void dot() {
  slitPaintOn();
  delay(1*s); // paint for 1 unit
  slitPaintOff();
  delay(1*s); // no paint for 1 unit
}
void dash() {
  slitPaintOn();
  delay(3*s); // paint for 3 units
  slitPaintOff();
  delay(1*s); // no paint for 1 unit
}
void letterSpace() {
  slitPaintOff();
  delay(2*s); // no paint for 2 units
}
void wordSpace() {
  slitPaintOff();
  delay(4*s); // no paint for 4 units
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

