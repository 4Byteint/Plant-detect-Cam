/**************************************************************************
  Arduino Nano RP2040 Connect display on
  1.14" 240x135 ST7789 SPI IPS Display using hardware SPI
  : Color Test

  Connection:
  GND GND
  VCC 3V3
  SCL D13
  SDA D11
  RES D10
  DC  D9
  CS  D8
  BLK 3V3
 **************************************************************************/

#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include <SPI.h>

#define TFT_CS        8
#define TFT_RST       10
#define TFT_DC        9

// For ST7789:
Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

void setup(void) {
  delay(500);
  Serial.begin(9600);
  delay(500);
  Serial.print(F("135x240 (RGB) IPS ST778V SPI"));

  // using a 1.14" 240x135 TFT:
  tft.init(135, 240);           // Init ST7789 240x135
  tft.setRotation(3);
  tft.fillScreen(ST77XX_BLACK);
  
  Serial.println(F("Initialized"));
  Serial.println(tft.width());
  Serial.println(tft.height());

  delay(1000);
}

void loop() {
  tft.fillScreen(ST77XX_BLACK);
  tft.setTextSize(3);
  drawtext("BLACK", ST77XX_WHITE, 10, 10);
  tft.drawRect(0, 0, tft.width(), tft.height(), ST77XX_WHITE);
  delay(3000);

  tft.fillScreen(ST77XX_WHITE);
  tft.setTextSize(3);
  drawtext("WHITE", ST77XX_BLACK, 10, 10);
  tft.drawRect(1, 1, tft.width()-2, tft.height()-2, ST77XX_BLACK);
  delay(3000);

  tft.fillScreen(ST77XX_RED);
  tft.setTextSize(3);
  drawtext("RED", ST77XX_WHITE, 10, 10);
  delay(3000);

  tft.fillScreen(ST77XX_GREEN);
  tft.setTextSize(3);
  drawtext("GREEN", ST77XX_WHITE, 10, 10);
  delay(3000);

  tft.fillScreen(ST77XX_BLUE);
  tft.setTextSize(3);
  drawtext("BLUE", ST77XX_WHITE, 10, 10);
  delay(3000);
}

void drawtext(char *text, uint16_t color, int16_t x, int16_t y) {
  tft.setCursor(x, y);
  tft.setTextColor(color);
  tft.setTextWrap(true);
  tft.print(text);
}
