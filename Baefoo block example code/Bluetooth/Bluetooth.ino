#include <SoftwareSerial.h>
int tx = 2;
int rx = 3;
SoftwareSerial btSerial(tx,rx);
String serialString;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Hello Monitor!!");
  btSerial.begin(9600);
  btSerial.println("Hello HC-06");
}

void loop() {
  if(btSerial.available()){
    Serial.write(btSerial.read());
  }
  if(Serial.available()){
    //char ch =(char)Serial.read();
    btSerial.write(Serial.read());
    //Serial.write(ch);
  }
}
