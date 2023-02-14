// Complete project details at https://RandomNerdTutorials.com/esp8266-load-cell-hx711/
// Library HX711 by Bogdan Necula: https://github.com/bogde/HX711
// Library: pushbutton by polulu: https://github.com/pololu/pushbutton-arduino

#include <Arduino.h>
#include "HX711.h"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Pushbutton.h>

// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = D6;
const int LOADCELL_SCK_PIN = D7;

HX711 scale;
int reading;
int lastReading;
//REPLACE WITH YOUR CALIBRATION FACTOR
#define CALIBRATION_FACTOR 1565.7894

//OLED Display
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

//Button
#define BUTTON_PIN D5
Pushbutton button(BUTTON_PIN);

void displayWeight(int weight){
  display.clearDisplay();
  
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("PUSH: -> 0 <- ");
  display.display();

  display.setCursor(0, 17);
  display.setTextSize(4);
  display.print(weight);
  display.print(" ");
  display.display();
  
  display.setCursor(104, 27);
  display.setTextSize(2);
  display.println("g");
  display.display();  
  
}

void setup() {
  Serial.begin(115200);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);
  display.clearDisplay();
  display.setTextColor(WHITE);
  
  Serial.println("Initializing the scale");
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);

  display.clearDisplay();
  
  display.setTextSize(1.2);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("Initializing the scale");
  display.display();

  scale.set_scale(CALIBRATION_FACTOR);   // this value is obtained by calibrating the scale with known weights
  
  display.clearDisplay();
  
  display.setTextSize(1.2);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("CALIBRATION...");
  display.display();
  
  scale.tare();               // reset the scale to 0
  
  display.clearDisplay();
  
  display.setTextSize(1.2);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("reset the scale to 0");
  display.display();
  
}

void loop() {
  
  if (button.getSingleDebouncedPress()){
    Serial.print("tare...");

    display.clearDisplay();
  
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.println("tare...");
    display.display();
  
    scale.tare();

    display.clearDisplay();
  
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.println("ZEROING >>> 0");
    display.display();
    
  }
  
  if (scale.wait_ready_timeout(200)) {
    reading = round(scale.get_units());
    Serial.print("Weight: ");
    Serial.println(reading);

    
    display.setCursor(0, 17);
    display.setTextSize(4);
    display.print(reading);
    display.print(" ");
    //display.print("g");
    display.display();
    
    display.setCursor(104, 27);
    display.setTextSize(2);
    display.println("g");
    display.display(); 

    
    if (reading != lastReading){
      displayWeight(reading); 
    }
    lastReading = reading;
  }
  else {
    Serial.println("HX711 not found.");
  }
}
