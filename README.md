# UltraSonicUno
Arduino Parking Spot Availability Using Ultra Sonic Sensors, Leds, And LCD

Components:

<p>2 leds(Green and Red)</p>
<P>1 LCD I2C 1200x2</P>
<p>Arduino Bord uno</p>
<p>Jumpers cable</p>
<p>2 Resistors 220ohm </p>
<p>Ultra Sonic Censor</p> 

<p>Setup :

Ultrasonic Sensor:
 VCC --> 5V
 Trig --> Digital Pin 2
 Echo --> Digital Pin 3
 GND --> GND
<p/>

<p>
 LEDs:
 Green LED:
  Anode (long leg) --> Digital Pin 4
  Cathode (short leg) --> Resistor --> GND

 Red LED:
  Anode (long leg) --> Digital Pin 5
  Cathode (short leg) --> Resistor --> GND
LCD Display:
 GND --> GND
 VCC --> 5V
 SDA --> A4 (analog pin 4)
 SCL --> A5 (analog pin 5)

 I2C Adapter:
 GND --> GND
 VCC --> 5V
 SDA --> A4 (analog pin 4)
 SCL --> A5 (analog pin 5)

</p>

<p>
 Codes:
 #include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define TRIG_PIN 2
#define ECHO_PIN 3
#define GREEN_LED 4
#define RED_LED 5
#define LCD_COLS 12
#define LCD_ROWS 2

LiquidCrystal_I2C lcd(0x27, LCD_COLS, LCD_ROWS);  // Set the LCD address to 0x27 for a 12x2 display

void setup() {
  Serial.begin(9600);
  lcd.init();  // Initialize the LCD
  lcd.backlight();  // Turn on the backlight
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
    lcd.setCursor(0, 0);
    lcd.print("Parking: Occupied");
    Serial.println("Parking space occupied");
  } else {
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Parking: Available");
    Serial.println("Parking space available");
  }

  delay(1000);
}

</p>
