// Basic yarn-painting machine

// Writes a pattern defined in an array of on/off time codes

// Circuit: Red to Ground, Orange to D2, Yellow to D3

const int maxCmds = 300; // Arduino Nano size limits us to no more than 300 or so long commands, 600 int
// the following pattern was generated from: https://rawgit.com/kaicarver/ikat/master/index.html
unsigned long slitCmds[] = {
17000, // ON 
21500, // OFF 
27500, // ON 
28000, // OFF 
36000, // ON 
36500, // OFF 
38000, // ON 
38500, // OFF 
39000, // ON 
39500, // OFF 
46500, // ON 
47000, // OFF 
47500, // ON 
48500, // OFF 
49000, // ON 
50000, // OFF 
55500, // ON 
57000, // OFF 
58000, // ON 
58500, // OFF 
65500, // ON 
66000, // OFF 
67500, // ON 
68000, // OFF 
75000, // ON 
75500, // OFF 
77000, // ON 
77500, // OFF 
84500, // ON 
85000, // OFF 
86500, // ON 
87000, // OFF 
94000, // ON 
94500, // OFF 
96000, // ON 
96500 // OFF 
}; // TODO: this size should be checked for

int count = 35; // this should match the number of commands

// This is the real painting code:
// paint according to an array of on/off timecodes

int slitCmdIndex = 0;
unsigned long tInitial = millis();
unsigned long curPaintOn = 0;
unsigned long curPaintOff = 0;

void setup() {
  // initialize the serial port:
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  tInitial = millis();
  Serial.println("start painting...");
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

