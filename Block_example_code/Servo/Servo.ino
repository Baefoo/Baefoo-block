#include <Servo.h>
Servo myservo;
void setup()
{
	myservo.attach(2);
}
void loop()
{
	for (int i = 0; i < 120; ++i)
	{
		myservo.write(i);
		delay(15);
	}
	myservo.write(0);
	delay(100);
}
