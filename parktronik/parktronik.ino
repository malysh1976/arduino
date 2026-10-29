#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);

const int svetPin = 13;
const int echoPin = 10;
const int trigPin = 9;
const int zoomPin = 8;

void setup() {
  pinMode(svetPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
}

void loop() {
  lcd.clear();
  drawScale(2);
  delay(500);
}

float readDistance() {
  digitalWrite(trigPin, LOW);
  delay(2);
  digitalWrite(trigPin, HIGH);
  delay(20);
  digitalWrite(trigPin, LOW);
  long time = pulseIn(echoPin, HIGH);
  float distance = time * 0.0343 / 2;
  return distance;
}

void updateDisplay(float dist) {
  lcd.print("Dist: ");
  lcd.print(dist);
  lcd.print("cm");
}

void drawScale(int dist) {
  int cells = map(dist, 10, 100, 1, 16);
  lcd.setCursor(0, 1);
  cells = constrain(cells, 0, 16);
  for (int i = 0; i < cells; i++) {
    lcd.print("1");
  }
}
  

