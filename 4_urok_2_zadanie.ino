#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

const int shinaPin = 2;
const int displayPin1 = A4;
const int displayPin2 = A5;
OneWire oneWire(shinaPin);
DallasTemperature sensors(&oneWire);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  sensors.begin();
}

void loop() {
  sensors.requestTemperatures();
  float temp = sensors.getTempCByIndex(0);
  lcd.clear();
  lcd.setCursor(0, 0);
  Serial.print(temp, 1);
  lcd.print(temp, 1);
  delay(1000);
}
