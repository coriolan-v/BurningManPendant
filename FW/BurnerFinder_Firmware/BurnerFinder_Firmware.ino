#define UNIQUE_BURNER_ID 1

#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEScan.h>
#include <BLEAdvertisedDevice.h>

#include <Preferences.h>
Preferences preferences;
unsigned int counter;

int sleepTimeuS = 3000000;


//RTC_DATA_ATTR int ledID = 0;

void setup() {
  Serial.begin(115200);
  delay(3000);
  Serial.println();

  initBLE();

  initLEDs();
}

void loop() {

  //fadeLEDon(1, 0xff0000);

   scanBLE();

   fadeOnOff();

//  counter++;
//    preferences.putUInt("counter", counter);
//   // Close the Preferences
//   preferences.end();

 

//   //Serial.println("ledID number: " + String(ledID));

  Serial.print("Sleepig now for "); Serial.println(sleepTimeuS / 1000000);  Serial.println("s");

   esp_sleep_enable_timer_wakeup(sleepTimeuS); // 1 sec
   esp_deep_sleep_start(); 
}