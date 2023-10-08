#include <Adafruit_NeoPixel.h>
//#include <FastLED.h>

#define PIN_NEOPIXEL 10

#define NUM_PIXELS 12

//CRGB leds[NUM_PIXELS];

//#if defined(PIN_NEOPIXEL)
Adafruit_NeoPixel pixel(NUM_PIXELS, PIN_NEOPIXEL, NEO_GRB);

void initLEDs() {
  //FastLED.addLeds<WS2811, PIN_NEOPIXEL, RGB>(leds, NUM_PIXELS);
  pixel.begin();  // INITIALIZE NeoPixel
  pixel.setBrightness(100);
  //FastLED.setBrightness(100);
}

// void turnLEDon(int pixelID, uint32_t color) {
//   //pixel.setPixelColor(pixel, color);
//   pixel.setPixelColor(pixelID, color);
//   pixel.show();
// }

unsigned long prevMill, currentMill;
int fadingInterval = 25;
int fadeValue = 0;
int fadeValueIncrement = 1;
int maxFadeValue = 75;
bool fadeDirection = 0;

int pixelID = 0;
// void fadeLEDon(int _pixelID, uint32_t color) {


//   pixel.setPixelColor(pixelID, color);
//   pixel.show();

//   if (millis() - prevMill > fadingInterval) {
//     prevMill = millis();

//     if (fadeDirection == 0) {
//       fadeValue = fadeValue + fadeValueIncrement;
//     } else {
//       fadeValue = fadeValue - fadeValueIncrement;
//     }

//     pixel.setBrightness(fadeValue);
//     Serial.print("pixelID: ");
//     Serial.print(pixelID);
//     Serial.print(", fadevalue: ");
//     Serial.println(fadeValue);  // Serial.print(", color: "); Serial.println(color * fadeValue, HEX);
//     //pixel.setPixelColor(pixelID, color * fadeValue);
//     pixel.show();

//     if (fadeValue >= maxFadeValue && fadeDirection == 0) {
//       fadeDirection = 1;
//     } else {
//       if (fadeValue <= 0) {
//         fadeDirection = 0;
//         pixelID++;
//       }
//     }
//   }
// }

//int numFindersFound = 0;
void fadeOnOff() {

  // if (numFindersFound > 0) {
  //   for (int p = 0; p < numFindersFound; p++) {
  //     pixel.setPixelColor(p, pixel.Color(0, 255, 0));
  //     //leds[p].setRGB(0,255,0);
  //   }
  // } else {
  //   pixel.setPixelColor(0, pixel.Color(0, 0, 255));
  //   // pixel.setPixelColor(0, 0,255,0);
  //   //leds[0].setRGB(0,0,255);
  // }

  //FastLED.show();
  // pixel.show();


  fadeValue = 0;
  for (int i = 0; i < maxFadeValue; i++) {

    //pixel.setBrightness(i);
    //FastLED.setBrightness(i);
    Serial.print("i: ");
    Serial.println(i);
    if (numFindersFound > 0) {
      for (int p = 0; p < numFindersFound; p++) {
        pixel.setPixelColor(p, pixel.Color(0, i, 0));
      }
    } else {
      pixel.setPixelColor(0, pixel.Color(0, 0, i));
    }
    //Serial.print("fadevalue: ");
    //Serial.println(i);  // Serial.print(", color: "); Serial.println(color * fadeValue, HEX);
    //pixel.setPixelColor(pixelID, color * fadeValue);

    //FastLED.show();
    pixel.show();
    delay(25);
  }

  for (int i = maxFadeValue; i > 0; i--) {


    //FastLED.setBrightness(i);
    Serial.print("i: ");
    Serial.println(i);
    if (numFindersFound > 0) {
      for (int p = 0; p < numFindersFound; p++) {
        pixel.setPixelColor(p, pixel.Color(0, i, 0));
      }
    } else {
      pixel.setPixelColor(0, pixel.Color(0, 0, i));
    }
    //Serial.print("fadevalue: ");
    //Serial.println(i);  // Serial.print(", color: "); Serial.println(color * fadeValue, HEX);
    //pixel.setPixelColor(pixelID, color * fadeValue);

    //FastLED.show();
    pixel.show();
    delay(25);
  }

  Serial.println("fading done");
}