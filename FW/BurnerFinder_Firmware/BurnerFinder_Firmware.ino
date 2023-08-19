#define UNIQUE_BURNER_ID 1

int sleepTimeS = 3;

void setup() {
  Serial.begin(115200);
  delay(3000);
  Serial.println();

  initBLE();

  initLEDs();
  //pixels.clear(); // Set all pixel colors to 'off'

  fadeOnOff();
}

void loop() {

  //fadeLEDon(1, 0xff0000);

  scanBLE();

  fadeOnOff();



    Serial.print("Sleepig now for "); Serial.print(sleepTimeS);  Serial.println("seconds");
    delay(1000);

    Serial.flush();
    Serial.end();

     stopBLE();

     esp_sleep_enable_timer_wakeup(sleepTimeS * 1000000);
     esp_deep_sleep_start();
}

int numFindersFound = 0;

