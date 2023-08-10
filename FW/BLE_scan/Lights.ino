#include <Adafruit_NeoPixel.h>

 #define PIN_NEOPIXEL 10
 
 #define NUM_PIXELS 12

//#if defined(PIN_NEOPIXEL)
  Adafruit_NeoPixel pixel(NUM_PIXELS, PIN_NEOPIXEL, NEO_GRB + NEO_KHZ800);

void initLEDs()
{
  pixel.begin(); // INITIALIZE NeoPixel
  pixel.setBrightness(20);
}

void turnLEDon(int pixelID, uint32_t color)
{
    //pixel.setPixelColor(pixel, color);
    pixel.setPixelColor(pixelID, color);
    pixel.show();
}