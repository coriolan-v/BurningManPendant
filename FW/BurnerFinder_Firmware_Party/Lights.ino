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
  pixel.setBrightness(30);
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

unsigned long pixelPrevious = 0;        // Previous Pixel Millis
unsigned long patternPrevious = 0;      // Previous Pattern Millis
int           patternCurrent = 0;       // Current Pattern Number
int           patternInterval = 5000;   // Pattern Interval (ms)
int           pixelInterval = 50;       // Pixel Interval (ms)
int           pixelQueue = 0;           // Pattern Pixel Queue
int           pixelCycle = 0;           // Pattern Pixel Cycle
uint16_t      pixelCurrent = 0;         // Pattern Current Pixel Number
uint16_t      pixelNumber = NUM_PIXELS;  // Total Number of Pixels

unsigned long pixelsInterval=50;  // the time we need to wait
unsigned long colorWipePreviousMillis=0;
unsigned long theaterChasePreviousMillis=0;
unsigned long theaterChaseRainbowPreviousMillis=0;
unsigned long rainbowPreviousMillis=0;
unsigned long rainbowCyclesPreviousMillis=0;

int theaterChaseQ = 0;
int theaterChaseRainbowQ = 0;
int theaterChaseRainbowCycles = 0;
int rainbowCycles = 0;
int rainbowCycleCycles = 0;

void rainbowEffect()
{
  if ((unsigned long)(millis() - rainbowCyclesPreviousMillis) >= pixelsInterval) {
            rainbowCyclesPreviousMillis = millis();
            rainbowCycle();
        }  
}

void rainbow() {
  for(uint16_t i=0; i<pixel.numPixels(); i++) {
    pixel.setPixelColor(i, Wheel((i+rainbowCycles) & 255));
  }
  pixel.show();
  rainbowCycles++;
  if(rainbowCycles >= 256) rainbowCycles = 0;
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle() {
  uint16_t i;

  //for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< pixel.numPixels(); i++) {
      pixel.setPixelColor(i, Wheel(((i * 256 / pixel.numPixels()) + rainbowCycleCycles) & 255));
    }
    pixel.show();

  rainbowCycleCycles++;
  if(rainbowCycleCycles >= 256*5) rainbowCycleCycles = 0;
}

// void rainbow(uint8_t wait) {



//   if(pixelInterval != wait)
//     pixelInterval = wait;          
//     for(int j=0; j<256*5; j++) { // 5 cycles of all colors on wheel         
//   for(uint16_t i=0; i < pixelNumber; i++) {
//     //pixel.setPixelColor(i, Wheel((i + pixelCycle) & 255)); //  Update delay time  
//     pixel.setPixelColor(i, Wheel(((i * 256 / pixel.numPixels()) + j) & 255));
//   }
//     }
//   pixel.show();                             //  Update strip to match
//   pixelCycle++;                             //  Advance current cycle
//   if(pixelCycle >= 256)
//     pixelCycle = 0;                         //  Loop the cycle back to the begining
// }

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return pixel.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return pixel.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return pixel.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}