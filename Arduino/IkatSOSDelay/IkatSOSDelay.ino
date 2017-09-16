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

// TODO: switch to BlinkWithoutDelay method using millis() and array of  instead of delay();

const int ledPin =  LED_BUILTIN; // the number of the LED pin

int ledState = LOW;              // ledState used to set the LED

// sequence of on/off time commands
// commands at even offsets are times to turn paint ON
// commands at odd offsets are times to turn paint OFF 
unsigned long slitCmds[] = {
1000,1200,
1400,1600,
1800,2000,
2200,2600,
2800,3200,
3400,3800,
4000,4200,
4400,4600,
4800,5000
};

int slitCmdIndex = 0;
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

// Stepper configuration
#include <Stepper.h>

// change this to fit the number of steps per revolution for your motor
const int stepsPerRevolution = 200;

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);
boolean useStepper = false;

// Painting is controlled by stepper motor rotating a wheel with n slits
// Paint operations are also simulated with an LED for testing
boolean slitPaintIsOn = false;
void slitPaintInit() {
  slitPaintIsOn = false; // start out not painting
  if (useStepper) {
    // set the speed at 60 rpm:
    myStepper.setSpeed(60);
  }
  // initialize the serial port:
  Serial.begin(9600);

  // initialize digital pin LED_BUILTIN as an output.
  pinMode(ledPin, OUTPUT);
  Serial.print("initialized digital pin LED_BUILTIN=");
  Serial.println(ledPin);
}
void slitPaintOn() {
  if (!slitPaintIsOn) {
    if (useStepper) {
      // step one revolution in one direction:
      Serial.println("stepper on");
      myStepper.step(stepsPerRevolution);
    }
    Serial.println("LED on");
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    slitPaintIsOn = true;
  }
}
void slitPaintOff() {
  if (slitPaintIsOn) {
    if (useStepper) { 
      // step one revolution in one direction:
      //Serial.println("stepper off");
      myStepper.step(stepsPerRevolution);
    }
    Serial.println("LED off");
    digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
    slitPaintIsOn = false;
  }
}

