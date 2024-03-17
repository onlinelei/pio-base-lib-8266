//
// Created by Ray on 2023/8/29.
//

#ifndef AUTOOAT8266_BLINKUTIL_H
#define AUTOOAT8266_BLINKUTIL_H


#include <vector>
#include "LED.h"

static std::vector<int> testLedPin = {16, 14, 12, 13, 5, 4, 2};
static std::vector<LED> testLedArray = {LED(16, 1000, 0x0, 0x1), LED(14, 1000, 0x0, 0x1), LED(12, 1000, 0x0, 0x1),
                                        LED(13, 1000, 0x0, 0x1), LED(2, 1000, 0x1, 0x0), LED(5, 1000, 0x0, 0x1),
                                        LED(4, 1000, 0x0, 0x1)};
static std::vector<LED> boardLed8266Array = {LED(12, 1000, 0x0, 0x1)};


class BlinkUtil {
public:
    static void blinkPinInit(const std::vector<int>& arr);

    static void blinkUpPin(const std::vector<int>& arr, long ms);

    static void blinkDownPin(const std::vector<int>& arr, long ms);

    static void blink(std::vector<LED> vector);

    static void init(std::vector<LED> vector);
};

#endif //AUTOOAT8266_BLINKUTIL_H
