#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET     -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Kalp 1 – normal
const unsigned char kalp1 [] PROGMEM = {
  0b00000000,
  0b01100110,
  0b11111111,
  0b11111111,
  0b11111111,
  0b01111110,
  0b00111100,
  0b00011000
};

// Kalp 2 – büyümüş (atıyor gibi)
const unsigned char kalp2 [] PROGMEM = {
  0b01100110,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
  0b01111110,
  0b00111100,
  0b00011000
};

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
}

void loop() {
  // Kalp 1
  display.clearDisplay();
  display.drawBitmap(60, 28, kalp1, 8, 8, SSD1306_WHITE);
  display.display();
  delay(300);

  // Kalp 2
  display.clearDisplay();
  display.drawBitmap(60, 28, kalp2, 8, 8, SSD1306_WHITE);
  display.display();
  delay(300);
}