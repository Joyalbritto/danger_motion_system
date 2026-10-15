#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int pirPin = 2;   // PIR sensor OUT connected to digital pin 2
const int ledPin1 = 8;  // First red LED connected to digital pin 8
const int ledPin2 = 9;  // Second red LED connected to digital pin 9

void setup() {
  Serial.begin(9600);
  
  pinMode(pirPin, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);

  // Initialize SSD1306 display at address 0x3C
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(10, 28);
  display.println(F("System Armed..."));
  display.display();
  delay(2000);
}

void loop() {
  int motionState = digitalRead(pirPin);

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);

  if (motionState == HIGH) {
    // Motion detected
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    
    display.setCursor(15, 24);
    display.println(F("DANGER"));
    display.setCursor(15, 44);
    display.println(F("DETECTED"));
    display.display();
    
    delay(250); // Blink effect / debounce delay
    
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    delay(250);
  } else {
    // No motion
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    
    display.setTextSize(1);
    display.setCursor(25, 28);
    display.println(F("Status: Secure"));
    display.display();
  }
}