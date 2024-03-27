#include <LiquidCrystal.h>

#define TRIG_PIN 2
#define ECHO_PIN 3
#define GREEN_LED 4
#define RED_LED 5
#define RS_PIN 8
#define E_PIN 9
#define D4_PIN 10
#define D5_PIN 11
#define D6_PIN 12
#define D7_PIN 13

LiquidCrystal lcd(RS_PIN, E_PIN, D4_PIN, D5_PIN, D6_PIN, D7_PIN);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);  // Initialize the LCD
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
}

void loop() {
  long duration, distance;

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  distance = (duration / 2) / 29.1; // Calculate distance in cm

  if (distance < 10) {
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, HIGH);
    lcd.clear();
    lcd.print("Parking: Occupied");
    Serial.println("Parking space occupied");
  } else {
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
    lcd.clear();
    lcd.print("Parking: Available");
    Serial.println("Parking space available");
  }

  delay(1000);
}
