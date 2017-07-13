#include <Stepper.h>

// Rotation angle setting = 2048:(360 degree), 1024:(180 degree)
const int stepsPerRevolution = 2048;

// Pin connected to motor drive IN4, IN2, IN3, IN1
Stepper myStepper(stepsPerRevolution,11,9,10,8);

void setup() {
  myStepper.setSpeed(14);  //Motor speed setting
  Serial.begin(9600);
}
void loop() {
  // One turn counterclockwise
  Serial.println("counterclockwise");
  myStepper.step(stepsPerRevolution);
  delay(1000);

  // Clockwise rotation
  Serial.println("clockwise");
  myStepper.step(-stepsPerRevolution);
  delay(1000);
}
