//
// Created by Ray on 2023/8/30.
//

#include "OTAUtil.h"
#include <ArduinoOTA.h>

#define CodeVersion "CodeVersion V1.0"

void OTAUtil::OTAInitLocalNet() {
    Serial.println(CodeVersion);
    // Port defaults to 8266
    ArduinoOTA.setPort(8267);
    // Hostname defaults to esp8266-[ChipID]
    ArduinoOTA.setHostname("esp8266-1");
    // No authentication by default
//    ArduinoOTA.setPassword("admin");
    // Password can be set with it's md5 value as well
//    MD5(admin) = 21232f297a57a5a743894a0e4a801fc3
    ArduinoOTA.setPasswordHash("21232f297a57a5a743894a0e4a801fc3");
    ArduinoOTA.onStart([]() {
        String type;
        // 判断一下 OTA 内容
        if (ArduinoOTA.getCommand() == U_FLASH) {
            type = "sketch";
        } else { // U_SPIFFS
            type = "filesystem";
        }
        // NOTE: if updating SPIFFS this would be the place to unmount SPIFFS using SPIFFS.end()
        Serial.println("Start updating" + type);
    });
    ArduinoOTA.onEnd([]() {
        Serial.println("\nEnd");
    });
    ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {

        // 计算进度百分比
        int percent = (progress / (total / 100));

        // 设置进度条的长度
        unsigned int progressBarWidth = 50;  // 这个值可以根据你自己的需要进行修改

        // 根据百分比计算"="的数量
        unsigned int equalSigns = (progressBarWidth * percent) / 100;

        // 创建进度条字符串
        String progressBar;

        // 添加"="到进度条字符串
        for (unsigned int i = 0; i < equalSigns; i++)
            progressBar += "=";

        // 添加空格到进度条字符串直到它达到固定长度
        for (unsigned int i = progressBar.length(); i < progressBarWidth; i++)
            progressBar += " ";

        // 打印进度条到串行
        Serial.print("Uploading: ");
        Serial.print("[");
        Serial.print(progressBar);
        Serial.print("] ");
        Serial.print(percent);
        Serial.println("%");
    });
    ArduinoOTA.onError([](ota_error_t error) {
        Serial.printf("Error[%u]:", error);
        if (error == OTA_AUTH_ERROR) {
            Serial.println("Auth Failed");
        } else if (error == OTA_BEGIN_ERROR) {
            Serial.println("Begin Failed");
        } else if (error == OTA_CONNECT_ERROR) {
            Serial.println("Connect Failed");
        } else if (error == OTA_RECEIVE_ERROR) {
            Serial.println("Receive Failed");
        } else if (error == OTA_END_ERROR) {
            Serial.println("End Failed");
        }
    });
    ArduinoOTA.begin();
}

void OTAUtil::OTAHandler() {
    ArduinoOTA.handle();
}
