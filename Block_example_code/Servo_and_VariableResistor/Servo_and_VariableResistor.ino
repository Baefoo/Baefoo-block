#include <Servo.h>
Servo myservo;
void setup()
{
	myservo.attach(2);
}
void loop()
{
	int val = analogRead(A0);
	int rad = map(val, 0, 1023, 0, 120);
	myservo.write(rad);
	delay(15);
}
