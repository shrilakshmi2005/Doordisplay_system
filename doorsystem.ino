#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int trigPin = 8;
int echoPin = 9;
int irPin = 7;
int ledPin = 13;

long duration;
float distance;

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(irPin, INPUT);
  pinMode(ledPin, OUTPUT);

  lcd.begin(16, 2);
}

void loop()
{
  // Ultrasonic Sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  int irState = digitalRead(irPin);

  if (irState == LOW || distance < 20)
  {
    digitalWrite(ledPin, HIGH);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("WELCOME");
  }
  else
  {
    digitalWrite(ledPin, LOW);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("HAVE A GOOD");
    lcd.setCursor(0, 1);
    lcd.print("DAY");
  }

  delay(500);
}


  