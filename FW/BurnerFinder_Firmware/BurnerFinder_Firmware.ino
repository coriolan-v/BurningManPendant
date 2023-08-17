#define UNIQUE_BURNER_ID 1

#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEScan.h>
#include <BLEAdvertisedDevice.h>

#include <Preferences.h>
Preferences preferences;
unsigned int counter;

int scanTime = 5; //In seconds
BLEScan* pBLEScan;

class MyAdvertisedDeviceCallbacks: public BLEAdvertisedDeviceCallbacks {
    void onResult(BLEAdvertisedDevice advertisedDevice) {
      Serial.printf("Advertised Device: %s \n", advertisedDevice.toString().c_str());
    }
};

//RTC_DATA_ATTR int ledID = 0;

void setup() {
  Serial.begin(115200);
 delay(3000);
  Serial.println();

  preferences.begin("my-app", false);
  counter = preferences.getUInt("counter", 0);
  Serial.printf("Current counter value: %u\n", counter);
  // Store the counter to the Preferences
 

  initBLE();

  initLEDs();
}

void loop() {
  scanBLE();

 counter++;
   preferences.putUInt("counter", counter);
  // Close the Preferences
  preferences.end();

 

  //Serial.println("ledID number: " + String(ledID));

  esp_sleep_enable_timer_wakeup(3000000); // 1 sec
  esp_deep_sleep_start(); 
}