#include <Arduino.h>
#include <InitUtil.h>
#include <OTAUtil.h>
#include <WifiUtil.h>

void setup()
{
    InitUtil::init();
    WifiUtil::wifiInit();
    OTAUtil::OTAInitLocalNet();
    Serial.println("setup down");
}

void loop()
{
    Serial.println("something you todo1111");
    OTAUtil::OTAHandler();
    delay(10);
}