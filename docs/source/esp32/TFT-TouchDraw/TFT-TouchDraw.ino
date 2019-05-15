/******************************************************************
Created with PROGRAMINO IDE for Arduino
Project     : TFT-TouchDraw demo
Board       : MAKERFACTORY EBB ESP32
Version     : 1.0
Date        : 28.12.2018
Author      : MF

Description : How to use fonts with Ucglib.

Switches:
TFT   SW311 all ON
TFT   SW314 all ON

License:
This file may be redistributed under the terms of the MIT license.
A copy of this license has been included with this distribution in the file LICENSE.

******************************************************************/

#include <SPI.h>
#include <Adafruit_GFX.h> // https://github.com/adafruit/Adafruit-GFX-Library
#include <Adafruit_ILI9341.h> // https://github.com/adafruit/Adafruit_ILI9341
#include <XPT2046_Touchscreen.h> // https://github.com/PaulStoffregen/XPT2046_Touchscreen

#define TFT_DC             5
#define TFT_CS             33
#define TFT_RST            17

#define TOUCH_CS_PIN       16 

#define TFT_NORMAL          1
#define TFT_UPSIDEDOWN      3

const uint8_t TFT_ORIENTATION = TFT_NORMAL;
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);
XPT2046_Touchscreen touch(TOUCH_CS_PIN);
TS_Point rawLocation;

void setup() 
{
    Serial.begin(115200);
    
    tft.begin();
    tft.setRotation(TFT_NORMAL);
    tft.fillScreen(ILI9341_BLACK );
    tft.setTextColor(ILI9341_GREEN, ILI9341_BLACK);
    
    touch.begin();
    Serial.println("Touch screen ready.");
}

static uint16_t prev_x = 0xffff, prev_y = 0xffff;
void loop() 
{
    if (touch.touched())
    {
        rawLocation = touch.getPoint();
        
        tft.setCursor(1, 20);
        tft.print("X = ");
        tft.print(rawLocation.x);
        tft.setCursor(1, 40);
        tft.print("Y = ");
        tft.print(rawLocation.y);
        Serial.print("x = ");
        Serial.print(rawLocation.x);
        Serial.print(", y = ");
        Serial.print(rawLocation.y);
        Serial.print(", z = ");
        Serial.println(rawLocation.z);
        
        if (TFT_ORIENTATION == TFT_UPSIDEDOWN)
        {
            if (prev_x == 0xffff) {
                tft.drawPixel(mapFloat(rawLocation.x, 340, 3900, 320, 0),
                mapFloat(rawLocation.y, 200, 3850, 240, 0),ILI9341_GREEN);
            } else {
                tft.drawLine(prev_x, prev_y, mapFloat(rawLocation.x, 340, 3900, 320, 0),
                mapFloat(rawLocation.y, 200, 3850, 240, 0),ILI9341_GREEN);
            }   
            prev_x = mapFloat(rawLocation.x, 340, 3900, 320, 0);
            prev_y = mapFloat(rawLocation.y, 200, 3850, 240, 0);
        }
        else if (TFT_ORIENTATION == TFT_NORMAL)
        {
            if (prev_x == 0xffff) {
                tft.drawPixel(mapFloat(rawLocation.x, 340, 3900, 0, 320),
                mapFloat(rawLocation.y, 200, 3850, 0, 240),ILI9341_GREEN);
            } else {
                tft.drawLine(prev_x, prev_y, mapFloat(rawLocation.x, 340, 3900, 0, 320),
                mapFloat(rawLocation.y, 200, 3850, 0, 240),ILI9341_GREEN);
            }
            prev_x = mapFloat(rawLocation.x, 340, 3900, 0, 320);
            prev_y = mapFloat(rawLocation.y, 200, 3850, 0, 240);
        }
        
    } 
    else 
        prev_x = prev_y = 0xffff;
    
    delay(20);
    
}

static inline __attribute__((always_inline)) float mapFloat(float x, const float in_min, const float in_max, const float out_min, const float out_max)
{
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
