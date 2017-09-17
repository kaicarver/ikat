// Basic Stepper test

// writes Morse code "S O S" forever

// circuit: Red to Ground, Orange to D2, Yellow to D3

unsigned long slitCmds[20];
const int interval = 300;
int count = 0;
unsigned long curTime = 0;

void setupTimes() {
  // Morse code S O S
  dot(); dot(); dot();    letterSpace(); // S
  dash(); dash(); dash(); letterSpace(); // O
  dot(); dot(); dot();    letterSpace(); // S
  wordSpace();
  Serial.print("number of offsets: ");
  Serial.println(count);
  for (int i = 0; i < count; i++) {
    Serial.println(slitCmds[i]);
  }
  curTime = 0; // reset timer to use when printing
}

void dot() {
  paintSymbol(1);
}
void dash() {
  paintSymbol(3);
}
void paintSymbol(int duration) {
  slitCmds[count] = curTime; count++; 
  curTime += interval * duration;
  slitCmds[count] = curTime; count++; 
  symbolSpace();
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

void setup() {
  // initialize the serial port:
  Serial.begin(9600);
  setupTimes();
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
}

void stepOn() {
  digitalWrite(2,  LOW);
  digitalWrite(3, HIGH);  
}
void stepOff() {
  digitalWrite(2, HIGH);
  digitalWrite(3,  LOW);
}

void loop() {
  unsigned long currentMillis = millis();
  // Morse code S O S
  // S
  stepOn();
  delay(300);
  stepOff();
  delay(300);
  
  stepOn();
  delay(300);
  stepOff();
  delay(300);
  
  stepOn();
  delay(300);
  stepOff();
  delay(300);

  // space between letters
  delay(600);

  // O
  stepOn();
  delay(900);
  stepOff();
  delay(300);
  
  stepOn();
  delay(900);
  stepOff();
  delay(300);
  
  stepOn();
  delay(900);
  stepOff();
  delay(300);

  // space between letters
  delay(600);

  // S
  stepOn();
  delay(300);
  stepOff();
  delay(300);
  
  stepOn();
  delay(300);
  stepOff();
  delay(300);
  
  stepOn();
  delay(300);
  stepOff();
  delay(300);

  // space between letters
  delay(600);
  
  // space between words
  delay(1200);
}
