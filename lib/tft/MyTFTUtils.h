//
// Created by Ray on 2023/9/3.
//

#ifndef AUTOOAT8266_MYTFTUTILS_H
#define AUTOOAT8266_MYTFTUTILS_H


#include <TFT_eSPI.h>
#include "NotoSansBold15.h"
#include "NotoSansBold36.h"

// Do not include "" around the array name!
#define AA_FONT_SMALL NotoSansBold15
#define AA_FONT_LARGE NotoSansBold36


class MyTFTUtils {
private:
    static TFT_eSPI tft;
    static TFT_eSprite spr; // Sprite class needs to be invoked

public:
    static void tftInit();

    static void tftTest();

    static void testFont();

    static void rainbow_fill();
};


#endif //AUTOOAT8266_MYTFTUTILS_H
