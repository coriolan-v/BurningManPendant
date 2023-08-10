#define UNIQUE_BURNER_ID 1

#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEScan.h>
#include <BLEAdvertisedDevice.h>

int scanTime = 5; //In seconds
BLEScan* pBLEScan;

class MyAdvertisedDeviceCallbacks: public BLEAdvertisedDeviceCallbacks {
    void onResult(BLEAdvertisedDevice advertisedDevice) {
      Serial.printf("Advertised Device: %s \n", advertisedDevice.toString().c_str());
    }
};

RTC_DATA_ATTR int ledID = 0;

void setup() {
  Serial.begin(115200);

 // setupSleep();

  initBLE();

  initLEDs();
}

void loop() {
  scanBLE();

  ++ledID;
  Serial.println("ledID number: " + String(ledID));

  esp_sleep_enable_timer_wakeup(3000000); // 1 sec
  esp_deep_sleep_start(); 
}