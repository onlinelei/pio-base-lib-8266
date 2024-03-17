//
// Created by Ray on 2023/9/3.
//

#include "MyTFTUtils.h"
#include <Arduino.h>

// 初始化静态成员变量
TFT_eSPI MyTFTUtils::tft;
TFT_eSprite MyTFTUtils::spr(&tft);

void MyTFTUtils::tftInit() {
    // 初始化显示屏
    tft.init();
    tft.setRotation(0); // 设置显示屏旋转角度

    // 清空显示屏
    tft.fillScreen(TFT_BLACK);

    // 设置文本颜色和字体大小
    tft.setTextColor(TFT_WHITE);
    tft.setTextSize(1);
}

void MyTFTUtils::tftTest() {
//        std::vector<GFXfont> fontArr = {LOAD_GLCD,LOAD_FONT2,LOAD_FONT4,LOAD_FONT6,LOAD_FONT7, LOAD_FONT8,LOAD_GFXFF, SMOOTH_FONT};

    tft.setFreeFont(LOAD_GLCD);
    tft.setCursor(0, 0);
    tft.println("hello world");
    tft.setFreeFont(LOAD_FONT2);
    tft.setCursor(0, 10);
    tft.println("hello world");
    tft.setFreeFont(LOAD_FONT4);
    tft.setCursor(0, 20);
    tft.println("hello world");
    tft.setFreeFont(LOAD_FONT6);
    tft.setCursor(0, 30);
    tft.println("hello world");
    tft.setFreeFont(LOAD_FONT7);
    tft.setCursor(0, 40);
    tft.println("hello world");
    tft.setFreeFont(LOAD_FONT8);
    tft.setCursor(0, 50);
    tft.println("hello world");
    tft.setFreeFont(LOAD_GFXFF);
    tft.setCursor(0, 60);
    tft.println("hello world");
    tft.setFreeFont(SMOOTH_FONT);
    tft.setCursor(0, 70);
    tft.println("hello world");

    delay(5000);
    tft.fillScreen(TFT_BLACK);
    for (int i = 0; i < 100; ++i) {
        tft.fillScreen((uint16_t) random(0xFFFF));
        delay(200);
    }
    tft.fillScreen(TFT_BLACK);
}

void MyTFTUtils::testFont() {
    rainbow_fill(); // Fill the screen with rainbow colours

    // Select a font size commensurate with screen size
    if (tft.width() >= 320)
        tft.loadFont(AA_FONT_LARGE);
    else
        tft.loadFont(AA_FONT_SMALL);

    tft.setTextColor(TFT_BLACK, TFT_WHITE); // Background color is ignored if callback is set
    tft.setCursor(0, 10); // Set cursor at top left of screen

    uint32_t t = millis();
    tft.println(" Ode to a small\n lump of green\n putty I found\n in my armpit\n one midsummer\n morning ");
    Serial.println(t = millis() - t);

    tft.unloadFont(); // Remove the font to recover memory used

    tft.resetViewport();
    delay(2000);
}

void MyTFTUtils::rainbow_fill() {
    byte red = 31;
    byte green = 0;
    byte blue = 0;
    byte state = 0;
    unsigned int colour = red << 11; // Colour order is RGB 5+6+5 bits each


    // The colours and state are not initialised so the start colour changes each time the funtion is called

    for (int i = 319; i >= 0; i--) {
        // Draw a vertical line 1 pixel wide in the selected colour
        tft.drawFastHLine(0, i, tft.width(),
                          colour); // in this example tft.width() returns the pixel width of the display
        // This is a "state machine" that ramps up/down the colour brightnesses in sequence
        switch (state) {
            case 0:
                green++;
                if (green == 64) {
                    green = 63;
                    state = 1;
                }
                break;
            case 1:
                red--;
                if (red == 255) {
                    red = 0;
                    state = 2;
                }
                break;
            case 2:
                blue++;
                if (blue == 32) {
                    blue = 31;
                    state = 3;
                }
                break;
            case 3:
                green--;
                if (green == 255) {
                    green = 0;
                    state = 4;
                }
                break;
            case 4:
                red++;
                if (red == 32) {
                    red = 31;
                    state = 5;
                }
                break;
            case 5:
                blue--;
                if (blue == 255) {
                    blue = 0;
                    state = 0;
                }
                break;
        }
        colour = red << 11 | green << 5 | blue;
    }
}