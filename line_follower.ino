// Line Follower Robot
// Arduino Uno + 5 IR Sensors + L298N Motor Driver

// IR sensor pins
const int S1 = A4;   // Far Right
const int S2 = A3;   // Right
const int S3 = A2;   // Center
const int S4 = A1;   // Left
const int S5 = A0;   // Far Left

// L298N motor driver pins
const int ENA = 5;
const int ENB = 6;

const int IN1 = 8;
const int IN2 = 9;
const int IN3 = 10;
const int IN4 = 11;

int baseSpeed = 150;
int turnSpeed = 180;

void setup() {
  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(S3, INPUT);
  pinMode(S4, INPUT);
  pinMode(S5, INPUT);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  Serial.begin(9600);

  stopMotors();
}

void loop() {

  int s1 = digitalRead(S1);
  int s2 = digitalRead(S2);
  int s3 = digitalRead(S3);
  int s4 = digitalRead(S4);
  int s5 = digitalRead(S5);

  // LOW = black line
  // HIGH = white surface

  // Center of the line
  if (s3 == LOW && s2 == HIGH && s4 == HIGH) {
    forward();
  }

  // Slightly right
  else if (s2 == LOW) {
    turnRight();
  }

  // Hard right
  else if (s1 == LOW) {
    hardRight();
  }

  // Slightly left
  else if (s4 == LOW) {
    turnLeft();
  }

  // Hard left
  else if (s5 == LOW) {
    hardLeft();
  }

  // If multiple sensors detect the line
  else if (s2 == LOW && s3 == LOW) {
    turnRight();
  }

  else if (s3 == LOW && s4 == LOW) {
    turnLeft();
  }

  // All sensors on white surface
  else if (s1 == HIGH &&
           s2 == HIGH &&
           s3 == HIGH &&
           s4 == HIGH &&
           s5 == HIGH) {
    stopMotors();
  }

  delay(10);
}

// ---------------- MOTOR FUNCTIONS ----------------

void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, baseSpeed);
  analogWrite(ENB, baseSpeed);
}

void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, turnSpeed);
  analogWrite(ENB, turnSpeed);
}

void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  analogWrite(ENA, turnSpeed);
  analogWrite(ENB, turnSpeed);
}

void hardLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, 200);
  analogWrite(ENB, 200);
}

void hardRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  analogWrite(ENA, 200);
  analogWrite(ENB, 200);
}

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}
