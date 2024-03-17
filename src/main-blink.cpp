#include <Arduino.h>
#include <InitUtil.h>
#include <BlinkUtil.h>

void setup()
{
    InitUtil::init();
}

void loop()
{
    Serial.println("something you todo");
    BlinkUtil::blink(testLedArray);
    BlinkUtil::blink(boardLed8266Array);

    Serial.println("led blink");
    delay(1000);
}