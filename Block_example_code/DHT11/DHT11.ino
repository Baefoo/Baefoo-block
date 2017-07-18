#include <DHT11.h>    //Load Library
int pin=2;                      //pin number
DHT11 dht11(pin);
void setup(){
   Serial.begin(9600);    //Communication speed setting
}
void loop(){
  int err;
  float temp, humi;
  if((err=dht11.read(humi, temp))==0) //Read Temperature, Humidity
  {
    Serial.print("temperature:");
    Serial.print(temp);
    Serial.print(" humidity:");
    Serial.print(humi);
    Serial.println();
  } else                                //In case of error
  {
    Serial.println();
    Serial.print("Error No :");
    Serial.print(err);
    Serial.println();
  }
  delay(1000);                        //Measure every second
}
