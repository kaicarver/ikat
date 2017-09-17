// Basic yarn-painting machine

// Writes a pattern defined in an array of on/off time codes

// Circuit: Red to Ground, Orange to D2, Yellow to D3

const int maxCmds = 300; // Arduino Nano size limits us to no more than 300 or so long commands, 600 int
unsigned long slitCmds[maxCmds]; // TODO: this size should be checked for

const int interval = 500; // the basic element of time in milliseconds
int count = 0; // this counts the commands
unsigned long curTime = 0; // just used to calculate times for array

// this is just testing code to fill the array with a pattern
// the actual pattern to be painted should be calculated upstream
void setupTimes() {
  Serial.print("basic interval of time in milliseconds: ");
  Serial.println(interval);
  Serial.println("setup array of timed on/off commands...");
  // print SOS twice
  morseSOS();
  morseSOS();
  morseSOS();
  Serial.print("number of commands: ");
  Serial.println(count);
  
  for (int i = 0; i < count; i++) {
    //Serial.println(slitCmds[i]);
  }
}
void dot() {
  paintSymbol(1);
}
void dash() {
  paintSymbol(3);
}
void paintSymbol(int duration) {
  if (count < maxCmds - 2) {
    slitCmds[count] = curTime; count++; 
    curTime += interval * duration;
    slitCmds[count] = curTime; count++; 
    symbolSpace();
  } else {
    Serial.println("ignoring, max number of commands exceeded!");
  }
}
void symbolSpace() {
  curTime += interval * 1;
}
void letterSpace() {
  curTime += interval * 2;
}
void wordSpace() {
  curTime += interval * 4;
}
void morseSOS() {
  // Morse code S O S
  dot(); dot(); dot();    letterSpace(); // S
  dash(); dash(); dash(); letterSpace(); // O
  dot(); dot(); dot();    letterSpace(); // S
  wordSpace();
}

// This is the real painting code:
// paint according to an array of on/off timecodes

int slitCmdIndex = 0;
unsigned long tInitial = millis();
unsigned long curPaintOn = 0;
unsigned long curPaintOff = 0;

void setup() {
  // initialize the serial port:
  Serial.begin(9600);
  setupTimes(); // this is only for testing: the pattern to be painted should be calculated upstream
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  tInitial = millis();
}

void loop() {
  unsigned long t = millis() - tInitial; // relative time
  if (slitCmdIndex < count) {
    if (t >= slitCmds[slitCmdIndex]) {
      if ((slitCmdIndex % 2) == 0) {
        stepOn();  // turn paint on if not already on
        Serial.print("no paint: ");
        Serial.println(t - curPaintOff);
        curPaintOn = t;
      } else {
        stepOff(); // turn off if not already off
        Serial.print("painted ----> : ");
        Serial.println(t - curPaintOn);
        curPaintOff = t;
      }
      slitCmdIndex++;
    }
  } else {
    // we executed all the commands in the array
    Serial.println("done painting!");
    delay(60000);
  }
}

void stepOn() {
  logCount();
  Serial.print("step ON ");
  digitalWrite(2,  LOW);
  digitalWrite(3, HIGH);  
}
void stepOff() {
  logCount();
  Serial.print("step OFF ");
  digitalWrite(2, HIGH);
  digitalWrite(3,  LOW);
}

void logCount() {
  Serial.print(slitCmdIndex+1);
  Serial.print("/");
  Serial.print(count);
  Serial.print(": ");
}

