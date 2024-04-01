// //#include <BLEDevice.h>
// //#include <BLEUtils.h>
// #include <BLEScan.h>
// #include <BLEAdvertisedDevice.h>

// int scanTime = 5; //In seconds
// BLEScan* pBLEScan;

// class MyAdvertisedDeviceCallbacks: public BLEAdvertisedDeviceCallbacks {
//     void onResult(BLEAdvertisedDevice advertisedDevice) {
//       //Serial.printf("Advertised Device: %s \n", advertisedDevice.toString().c_str());
//     }
// };

// void initBLE(){
//   Serial.print("Init BLE... ");
//   BLEDevice::init("");
//   pBLEScan = BLEDevice::getScan(); //create new scan
//   pBLEScan->setAdvertisedDeviceCallbacks(new MyAdvertisedDeviceCallbacks());
//   pBLEScan->setActiveScan(true); //active scan uses more power, but get results faster
//   pBLEScan->setInterval(100);
//   pBLEScan->setWindow(99);  // less or equal setInterval value
//   Serial.println("Done Init BLE");
// }

// void stopBLE()
// {
//    BLEDevice::deinit(true);
// }


// void scanBLE()
// {
//   numFindersFound= 0;
  
//   Serial.print("Scanning...");
//     // put your main code here, to run repeatedly:
//   BLEScanResults foundDevices = pBLEScan->start(scanTime, false);
//   //
//   //Serial.println(foundDevices.getCount());
//   Serial.println("Scan done!");

//   int count = foundDevices.getCount();
//   for (int i = 0; i < count; i++) {
//     BLEAdvertisedDevice bleSensor = foundDevices.getDevice(i);
//     String sensorName = bleSensor.getName().c_str();
//     String address = bleSensor.getAddress().toString().c_str();

//     if(sensorName == "BURNER_TESTER"){
//       Serial.println("Found Burner Tester device");
//       numFindersFound++;
//     }
//     if(sensorName == "BURNER_FINDER_1"){
//       Serial.print("Found "); Serial.println(sensorName);
//       numFindersFound++;
//     }
//     if(sensorName == "BURNER_FINDER_2"){
//       Serial.print("Found "); Serial.println(sensorName);
//       numFindersFound++;
//     }
//     if(sensorName == "BURNER_FINDER_3"){
//       Serial.print("Found "); Serial.println(sensorName);
//       numFindersFound++;
//     }
//     if(sensorName == "BURNER_FINDER_4"){
//       Serial.print("Found "); Serial.println(sensorName);
//       numFindersFound++;
//     }
//     if(sensorName == "BURNER_FINDER_5"){
//       Serial.print("Found "); Serial.println(sensorName);
//       numFindersFound++;
//     }
//     if(sensorName == "BURNER_FINDER_6"){
//       Serial.print("Found "); Serial.println(sensorName);
//       numFindersFound++;
//     }
//     if(sensorName == "BURNER_FINDER_7"){
//       Serial.print("Found "); Serial.println(sensorName);
//       numFindersFound++;
//     }
//     if(sensorName == "BURNER_FINDER_8"){
//       Serial.print("Found "); Serial.println(sensorName);
//       numFindersFound++;
//     }
//     if(sensorName == "BURNER_FINDER_9"){
//       Serial.print("Found "); Serial.println(sensorName);
//       numFindersFound++;
//     }
//     if(sensorName == "BURNER_FINDER_10"){
//       Serial.print("Found "); Serial.println(sensorName);
//       numFindersFound++;
//     }
//     if(sensorName == "BURNER_FINDER_11"){
//       Serial.print("Found "); Serial.println(sensorName);
//       numFindersFound++;
//     }
    
   
//     //Serial.println("Find" + address + " " + sensorName);

//   }

//    Serial.print("Total finders found: "); Serial.println(numFindersFound);

  
  

//   pBLEScan->clearResults();   // delete results fromBLEScan buffer to release memory
//   //delay(2000);

//   //turnLEDon(counter, 0xFF0000);
// }