//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h>                            // I2C control library
#include <LiquidCrystal_I2C.h>          // LCD library
LiquidCrystal_I2C lcd(0x3F,16,2);  // set the LCD address to 0x20 for a 16 chars and 2 line display
void setup()
{
  lcd.init();                      // initialize the lcd
  // Print a message to the LCD.
  lcd.backlight();  // turn on backlight
  Serial.begin(9600);
  printCommand();
}
void loop()
{
  if (Serial.available()) {
    int cmd = Serial.parseInt();
    String str ="";
    switch (cmd) {
      case 1:
        lcd.init();
        str = Serial.readString();
        Serial.println(str);
        lcdModule_printString(str);
      break;
      case 2:
      case 3:
        if (cmd % 2 == 0)
          lcd.backlight();
        else
          lcd.noBacklight();
      break;
      case 4:
        help();
      break;
      case 9:
        printCommand();
      break;
    }
  }
}

void printCommand() {
  Serial.println("===========================");
  Serial.println("1: text input\n2: backlight on\n3: backlight off\n4: help\n9:command list print");
  Serial.println("===========================");
}

void lcdModule_printString(String str) {
  String str1, str2;
  if (str.length() > 16) {
    str1 = str.substring(0, 16);
    str2 = str.substring(16,32);
    lcd.home();
    lcd.print(str1);
    lcd.setCursor(0,1);
    lcd.print(str2);
  } else {
    lcd.home();
    lcd.print(str);
  }
}

void help() {
  Serial.println("===========================");
  Serial.println("Type 1 at the beginning of the string.");
  Serial.println("Text input example: 1hello world");
  Serial.println("===========================");
}

