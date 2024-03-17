#include <Arduino.h>
#include <BlinkUtil.h>
#include <InitUtil.h>
#include <WifiUtil.h>
#include <OTAUtil.h>
#include <MyTFTUtils.h>

void setup() {
    // InitUtil::init();
    // WifiUtil::wifiInit();
    // OTAUtil::OTAInitLocalNet();
    // BlinkUtil::init(testLedArray);
//    MyTFTUtils::tftInit();
}

void loop() {
   Serial.println("something you todo");

    // OTAUtil::OTAHandler();
    // BlinkUtil::blink(testLedArray);
//    MyTFTUtils::tftTest();
//    MyTFTUtils::testFont();
Serial.println("led blink");
    delay(1000);
}