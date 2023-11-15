#include <bluefruit.h>

#define UNIQUE_BURNER_ID 1

//https://github.com/ndsh/neopixel-without-delay/blob/master/strandtest_nodelay/strandtest_nodelay.ino

int sleepTimeS = 3;

void setup() {
  Serial.begin(115200);
  //delay(3000);
  Serial.println();

  initLEDs();

  setupBLE();

  
  //pixels.clear(); // Set all pixel colors to 'off'

 // fadeOnOff();
}

void loop() {

  //fadeLEDon(1, 0xff0000);

  //scanBLE();

  //fadeOnOff();


  rainbowEffect();



    // Serial.print("Sleepig now for "); Serial.print(sleepTimeS);  Serial.println("seconds");
    // delay(1000);

    // Serial.flush();
    // Serial.end();

    //  stopBLE();

    //  esp_sleep_enable_timer_wakeup(sleepTimeS * 1000000);
    //  esp_deep_sleep_start();

      //Serial.begin(115200);
  //while ( !Serial ) delay(10);   // for nrf52840 with native usb

 
}

int numFindersFound = 0;

