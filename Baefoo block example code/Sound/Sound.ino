int sensorPin = 0;// Connect the sound sensor to pin analog zero.
int ledPin = 11;// Connect the LED to pin 11.
void setup() {
  pinMode(ledPin,OUTPUT);
  Serial.begin(9600);
}
void loop() {
  int value = analogRead(sensorPin); // Read sensor value from sound sensor.
  int intensity = map(value,20,300,0,255);// Maps the read value to the led brightness value.
  analogWrite(ledPin, intensity);
  delay(10);
  Serial.println(value);
  delay(100);
}
