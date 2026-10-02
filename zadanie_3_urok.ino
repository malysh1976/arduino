const int greenPin = 7;
const int yellowPin = 8;
const int redPin = 10;
const int button1 = 4;
const int button2 = 5;
const int button3 = 6;
const int zoomPin = 2;
const int cbutton1 = 262;
const int cbutton2 = 330;
const int cbutton3 = 392;
 
void setup() {
  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(zoomPin, OUTPUT);
  Serial.begin(9600);
}


void loop() {
  if (digitalRead(button1) == LOW) {
    delay(50);
    if (digitalRead(button1) == LOW) 
    {
      digitalWrite(greenPin, HIGH);
      tone(zoomPin, cbutton1);
      Serial.println("До");
    }
    else {
      digitalWrite(greenPin, LOW);
      noTone(zoomPin);
    }
   }
  if (digitalRead(button2) == LOW) {
    delay(50);
    if (digitalRead(button2) == LOW) {
      digitalWrite(yellowPin, HIGH);
      Serial.println("Ми");
      tone(zoomPin, cbutton2);
      }
    else {
      digitalWrite(yellowPin, LOW);
      noTone(zoomPin);
    }
    }
  if (digitalRead(button3) == LOW) {
    delay(50);
    if (digitalRead(button3) == LOW) {
      digitalWrite(redPin, HIGH);
      Serial.println("Соль");
      tone(zoomPin, cbutton3);
      }
    else {
      digitalWrite(redPin, LOW);
      noTone(zoomPin);
    }
    }
}
