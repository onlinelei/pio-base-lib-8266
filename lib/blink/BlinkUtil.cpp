//
// Created by Ray on 2023/8/29.
//

#include "BlinkUtil.h"
#include <Arduino.h>



void BlinkUtil::blinkPinInit(const std::vector<int> &arr) {
    if (arr.empty()) {
        return;
    }

    for (int i = 0; i < arr.size(); ++i) {
        pinMode(arr[i], OUTPUT);
        digitalWrite(arr[i], LOW);
        Serial.print(arr[i]);
        Serial.println("init finish");
    }
}

void BlinkUtil::blinkUpPin(const std::vector<int> &arr, long ms) {
    if (arr.empty() || ms == 0) {
        return;
    }

    for (int i = 0; i < arr.size(); i++) {
        digitalWrite(arr[i], HIGH);
        delay(ms);
        digitalWrite(arr[i], LOW);
        Serial.print(arr[i]);
        Serial.println("led blink");
    }
}

void BlinkUtil::blinkDownPin(const std::vector<int> &arr, long ms) {
    if (arr.empty() || ms == 0) {
        return;
    }

    for (int i = 0; i < arr.size(); i++) {
        digitalWrite(arr[i], LOW);
        delay(ms);
        digitalWrite(arr[i], HIGH);
    }

}

void BlinkUtil::blink(std::vector<LED> vector) {
    if (vector.empty() ) {
        return;
    }

    for (int i = 0; i < vector.size(); i++) {
        digitalWrite(vector[i].getPin(), vector[i].getOnStatus());
        delay(vector[i].getMs());
        digitalWrite(vector[i].getPin(), vector[i].getOffStatus());
        Serial.print(vector[i].getPin());
        Serial.println("led blink");
    }

}

void BlinkUtil::init(std::vector<LED> vector) {
    if (vector.empty() ) {
        return;
    }

    for (int i = 0; i < vector.size(); i++) {
        pinMode(vector[i].getPin(), OUTPUT);
        digitalWrite(vector[i].getPin(), vector[i].getOffStatus());
        Serial.print(vector[i].getPin());
        Serial.println("init finish");
    }

}



