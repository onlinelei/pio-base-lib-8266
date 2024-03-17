//
// Created by Ray on 2023/8/30.
//

#include "WifiUtil.h"
#include <ESP8266WiFi.h>

//const char *ssid = "Redmi_016C";
//const char *password = "87654321";
const char *ssid = "Mi";
const char *password = "12345678";

void WifiUtil::wifiInit() {
    WiFi.mode(WIFI_STA);
    //开始连接wifi
    WiFi.begin(ssid, password);

    //等待WiFi连接,连接成功打印IP
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
    }
    Serial.println("");
    Serial.println("WiFi Connected!");
    Serial.print("IP address:\t");
    Serial.println(WiFi.localIP());
}

void WifiUtil::wifiInitWithReboot() {
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    while (WiFi.waitForConnectResult() != WL_CONNECTED) {
        Serial.println("Connection Failed! Rebooting...");
        delay(5000);
        // 重启 ESP8266 模块
        EspClass::restart();
    }
    Serial.println("");
    Serial.println("WiFi Connected!");
    Serial.print("IP address:\t");
    Serial.println(WiFi.localIP());
}