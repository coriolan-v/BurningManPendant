#include <Adafruit_NeoPixel.h>

#define PIN_NEOPIXEL 10

#define NUM_PIXELS 12

//#if defined(PIN_NEOPIXEL)
Adafruit_NeoPixel pixel(NUM_PIXELS, PIN_NEOPIXEL, NEO_GRB + NEO_KHZ800);

void initLEDs() {
  pixel.begin();  // INITIALIZE NeoPixel
  pixel.setBrightness(20);
}

void turnLEDon(int pixelID, uint32_t color) {
  //pixel.setPixelColor(pixel, color);
  pixel.setPixelColor(pixelID, color);
  pixel.show();
}

unsigned long prevMill, currentMill;
int fadingInterval = 25;
int fadeValue = 0;
int fadeValueIncrement = 1;
int maxFadeValue = 50;
bool fadeDirection = 0;

int pixelID = 0;
void fadeLEDon(int _pixelID, uint32_t color) {

  pixel.setPixelColor(pixelID, color);
  pixel.show();

  if (millis() - prevMill > fadingInterval) {
    prevMill = millis();

    if (fadeDirection == 0) {
      fadeValue = fadeValue + fadeValueIncrement;
    } else {
      fadeValue = fadeValue - fadeValueIncrement;
    }

    pixel.setBrightness(fadeValue);
    Serial.print("pixelID: ");
    Serial.print(pixelID);
    Serial.print(", fadevalue: ");
    Serial.println(fadeValue);  // Serial.print(", color: "); Serial.println(color * fadeValue, HEX);
    //pixel.setPixelColor(pixelID, color * fadeValue);
    pixel.show();

    if (fadeValue >= maxFadeValue && fadeDirection == 0) {
      fadeDirection = 1;
    } else {
      if (fadeValue <= 0) {
        fadeDirection = 0;
        pixelID++;
      }
    }
  }
}

void fadeOnOff() {

  if (numFindersFound > 0) {
    for (int p = 0; p < numFindersFound; p++) {
      pixel.setPixelColor(p, 0x00FF00);
    }
  } else {
    pixel.setPixelColor(0, 0x0000FF);
  }

  pixel.show();


  fadeValue = 0;
  for (int i = 0; i < maxFadeValue; i++) {

    pixel.setBrightness(i);
    //Serial.print("pixelID: "); Serial.print(pixelID);
    //Serial.print("fadevalue: ");
    //Serial.println(i);  // Serial.print(", color: "); Serial.println(color * fadeValue, HEX);
    //pixel.setPixelColor(pixelID, color * fadeValue);

    pixel.show();
    delay(25);
  }

  for (int i = maxFadeValue; i > 0; i--) {

    pixel.setBrightness(i);
    //Serial.print("pixelID: "); Serial.print(pixelID);
    //Serial.print("fadevalue: ");
    //Serial.println(i);  // Serial.print(", color: "); Serial.println(color * fadeValue, HEX);
    //pixel.setPixelColor(pixelID, color * fadeValue);

    pixel.show();
    delay(25);
  }

  Serial.println("fading done");
}