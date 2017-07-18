/*
A
ena 5
in1 2
in2 4

B
in3 7
in4 8
enb 9
*/
int speed = 100;

void setup() {
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  Serial.begin(9600);
  help();
}

void loop() {
  if (Serial.available()) {
    int cmd = Serial.parseInt();
    switch (cmd) {
      case 1:// Forward
        digitalWrite(2, HIGH);
        digitalWrite(4, LOW);
        analogWrite(5, speed);

        digitalWrite(7, HIGH);
        digitalWrite(8, LOW);
        analogWrite(9, speed);
      break;
      case 2:// Left
        digitalWrite(2, LOW);
        digitalWrite(4, HIGH);
        analogWrite(5, speed);

        digitalWrite(7, HIGH);
        digitalWrite(8, LOW);
        analogWrite(9, speed);
      break;
      case 3:// Right
        digitalWrite(2, HIGH);
        digitalWrite(4, LOW);
        analogWrite(5, speed);

        digitalWrite(7, LOW);
        digitalWrite(8, HIGH);
        analogWrite(9, speed);
      break;
      case 4:// Backward
        digitalWrite(2, LOW);
        digitalWrite(4, HIGH);
        analogWrite(5, speed);

        digitalWrite(7, LOW);
        digitalWrite(8, HIGH);
        analogWrite(9, speed);
      break;
      case 5:
        setSpeed();
      break;
      case 9:// help
        help();
      break;
      case 0:// Stop
        analogWrite(5, 0);
        analogWrite(9, 0);
      break;
    }
  }
}

void help() {
  Serial.println("===================================");
  Serial.println("1: Forward, 2: Left, 3: Right, 4: Backward");
  Serial.println("5: set speed 0~1023 (e.g: 5 200)");
  Serial.println("9: help, 0: stop");
  Serial.println("===================================");
}

void setSpeed() {
  int val = Serial.parseInt();
  if (val >= 0 && val <= 1023)
    speed = map(val, 0, 1023, 0, 255);
  else
    Serial.println("Please check range.");
}
