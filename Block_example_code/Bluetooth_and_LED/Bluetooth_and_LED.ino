#include <SoftwareSerial.h>
int tx=2;
int rx=3;
int LED=13;
SoftwareSerial bluetoothSerial(tx,rx);
void setup() {
  bluetoothSerial.begin(9600);
  pinMode(LED, OUTPUT);
}
void loop() {
  if (bluetoothSerial.available()) {
    if (bluetoothSerial.read() == '1')
      digitalWrite(LED, HIGH);
    else
      digitalWrite(LED, LOW);
  }
}

