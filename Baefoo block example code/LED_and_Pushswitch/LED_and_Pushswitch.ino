int buttonpin = 2;
int LED = 11;
void setup()
{
 pinMode(buttonpin, INPUT);
 pinMode(LED, OUTPUT);
}
void loop()
{
 int buttoninput = digitalRead(buttonpin);
 if (buttoninput == HIGH)
 {
   digitalWrite(LED, HIGH);
 }
 else
 {
   digitalWrite(LED, LOW);
 }
}
