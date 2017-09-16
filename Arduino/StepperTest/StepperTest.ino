// Basic Stepper test

// writes Morse code "S O S" forever

// circuit: Red to Ground, Orange to D2, Yellow to D3

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
}

void loop() {
  // Morse code S O S
  // S
  digitalWrite(2,  LOW);
  digitalWrite(3, HIGH);
  delay(300);
  digitalWrite(2, HIGH);
  digitalWrite(3,  LOW);
  delay(300);
  
  digitalWrite(2,  LOW);
  digitalWrite(3, HIGH);
  delay(300);
  digitalWrite(2, HIGH);
  digitalWrite(3,  LOW);
  delay(300);
  
  digitalWrite(2,  LOW);
  digitalWrite(3, HIGH);
  delay(300);
  digitalWrite(2, HIGH);
  digitalWrite(3,  LOW);
  delay(300);

  // space between letters
  delay(600);

  // O
  digitalWrite(2,  LOW);
  digitalWrite(3, HIGH);
  delay(900);
  digitalWrite(2, HIGH);
  digitalWrite(3,  LOW);
  delay(300);
  
  digitalWrite(2,  LOW);
  digitalWrite(3, HIGH);
  delay(900);
  digitalWrite(2, HIGH);
  digitalWrite(3,  LOW);
  delay(300);
  
  digitalWrite(2,  LOW);
  digitalWrite(3, HIGH);
  delay(900);
  digitalWrite(2, HIGH);
  digitalWrite(3,  LOW);
  delay(300);

  // space between letters
  delay(600);

  // S
  digitalWrite(2,  LOW);
  digitalWrite(3, HIGH);
  delay(300);
  digitalWrite(2, HIGH);
  digitalWrite(3,  LOW);
  delay(300);
  
  digitalWrite(2,  LOW);
  digitalWrite(3, HIGH);
  delay(300);
  digitalWrite(2, HIGH);
  digitalWrite(3,  LOW);
  delay(300);
  
  digitalWrite(2,  LOW);
  digitalWrite(3, HIGH);
  delay(300);
  digitalWrite(2, HIGH);
  digitalWrite(3,  LOW);
  delay(300);

  // space between letters
  delay(600);
  
  // space between words
  delay(1200);
}
