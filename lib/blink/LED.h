//
// Created by Ray on 2023/8/31.
//

#ifndef AUTOOAT8266_LED_H
#define AUTOOAT8266_LED_H


#include <cstdint>

class LED {

private:
    int pin;
    long ms;
    uint8_t offStatus;
    uint8_t onStatus;

public:
    // 默认构造函数
    LED() {
        // gpio
        pin = 0;
        // 毫秒数
        ms = 0;
        // 关灯引脚状态
        offStatus = 0;
        // 亮灯引脚状态
        onStatus = 1;
    }

    // 带参构造函数
    LED(int p, long m, int off, int on) {
        pin = p;
        ms = m;
        offStatus = off;
        onStatus = on;
    }

    // 获取pin属性值
    int getPin() const {
        return pin;
    }

    // 获取ms属性值
    long getMs() const {
        return ms;
    }

    // 设置pin属性值
    void setPin(int p) {
        pin = p;
    }

    // 设置ms属性值
    void setMs(long m) {
        ms = m;
    }

    int getOffStatus() const {
        return offStatus;
    }

    void setOffStatus(int offStatus) {
        offStatus = offStatus;
    }

    int getOnStatus() const {
        return onStatus;
    }

    void setOnStatus(int onStatus) {
        onStatus = onStatus;
    }
};


#endif //AUTOOAT8266_LED_H
