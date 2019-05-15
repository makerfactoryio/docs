/******************************************************************
Created with PROGRAMINO IDE for Arduino
Project     : ON/OFF touch button
Board       : MAKERFACTORY EBB ESP32
Version     : 1.0
Date        : 28.12.2018
Author      : MF

Description : This example implements a simple sliding On/Off button. The example
              demonstrates drawing and touch operations and switch on/off the
              neopixel LEDs.

Switches:
RGB LED SW312 ON
TFT     SW311 all ON
TFT     SW314 all ON

License:
This file may be redistributed under the terms of the MIT license.
A copy of this license has been included with this distribution in the file LICENSE.
******************************************************************/

#include <SPI.h>
#include <Adafruit_GFX.h>           // https://github.com/adafruit/Adafruit-GFX-Library
#include <Adafruit_ILI9341.h>       // https://github.com/adafruit/Adafruit_ILI9341/tree/espressif-master
#include <XPT2046_Touchscreen.h>    // https://github.com/PaulStoffregen/XPT2046_Touchscreen
#include <Adafruit_NeoPixel.h>      // https://github.com/adafruit/Adafruit_NeoPixel

#define TFT_DC             5
#define TFT_CS             33
#define TFT_RST            17
#define TOUCH_CS_PIN       16

#define TFT_NORMAL          1
#define TFT_UPSIDEDOWN      3

// This is calibration data for the raw touch data to the screen coordinates
#define TS_MINX 150
#define TS_MINY 130
#define TS_MAXX 3800
#define TS_MAXY 4000

const uint8_t TFT_ORIENTATION = TFT_NORMAL;
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);

XPT2046_Touchscreen touch(TOUCH_CS_PIN);
TS_Point rawLocation;

boolean ButtonFlag = false;

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            2

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      4

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ400);

#define FRAME_X 85
#define FRAME_Y 80
#define FRAME_W 150
#define FRAME_H 80

#define REDBUTTON_X FRAME_X
#define REDBUTTON_Y FRAME_Y
#define REDBUTTON_W (FRAME_W/2)
#define REDBUTTON_H FRAME_H

#define GREENBUTTON_X (REDBUTTON_X + REDBUTTON_W)
#define GREENBUTTON_Y FRAME_Y
#define GREENBUTTON_W (FRAME_W/2)
#define GREENBUTTON_H FRAME_H

void drawFrame()
{
    tft.drawRect(FRAME_X, FRAME_Y, FRAME_W, FRAME_H, ILI9341_BLACK);
}

void LED_ON()
{
    for(int i=0;i<NUMPIXELS;i++)
    {
        // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
        strip.setPixelColor(i, strip.Color(0,0,50)); // dark blue color.
        strip.show(); // This sends the updated pixel color to the hardware.
    }
}

void LED_OFF()
{
    for(int i=0;i<NUMPIXELS;i++)
    {
        // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
        strip.setPixelColor(i, strip.Color(0,0,0)); // Turn off the LEDs
        strip.show(); // This sends the updated pixel color to the hardware.
    }
}

void redBtn()
{
    tft.fillRect(REDBUTTON_X, REDBUTTON_Y, REDBUTTON_W, REDBUTTON_H, ILI9341_RED);
    tft.fillRect(GREENBUTTON_X, GREENBUTTON_Y, GREENBUTTON_W, GREENBUTTON_H, ILI9341_BLUE);
    drawFrame();
    tft.setCursor(GREENBUTTON_X + 6 , GREENBUTTON_Y + (GREENBUTTON_H/2));
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(2);
    tft.println("ON");
    LED_OFF();
    ButtonFlag = false;
}

void greenBtn()
{
    tft.fillRect(GREENBUTTON_X, GREENBUTTON_Y, GREENBUTTON_W, GREENBUTTON_H, ILI9341_GREEN);
    tft.fillRect(REDBUTTON_X, REDBUTTON_Y, REDBUTTON_W, REDBUTTON_H, ILI9341_BLUE);
    drawFrame();
    tft.setCursor(REDBUTTON_X + 6 , REDBUTTON_Y + (REDBUTTON_H/2));
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(2);
    tft.println("OFF");
    LED_ON();
    ButtonFlag = true;
}

void setup(void)
{
    Serial.begin(115200);
    tft.begin();
    if (!touch.begin())
    {
        Serial.println("Unable to start touchscreen.");
    }
    else
    {
        Serial.println("Touchscreen started.");
    }
    
    strip.begin(); // This initializes the NeoPixel library.
    
    for(uint16_t i=0; i<strip.numPixels(); i++)
    {
        strip.setPixelColor(i, 0,0,0);
        strip.show();
    }
    
    tft.fillScreen(ILI9341_BLUE);
    tft.setRotation(TFT_ORIENTATION);
    redBtn();
}


void loop()
{
    // See if there's any  touch data for us
    if (!touch.bufferEmpty())
    {
        // Retrieve a point
        TS_Point p = touch.getPoint();
        
        // Scale using the calibration #'s
        // and rotate coordinate system
        p.x   = mapFloat(p.x, TS_MINX, TS_MAXX, 0, tft.width());
        p.y   = mapFloat(p.y, TS_MINY, TS_MAXY, 0, tft.height());
        int y = p.y;
        int x = p.x;
        
        if (ButtonFlag)
        {
            if((x > REDBUTTON_X) && (x < (REDBUTTON_X + REDBUTTON_W)))
            {
                if ((y > REDBUTTON_Y) && (y <= (REDBUTTON_Y + REDBUTTON_H)))
                {
                    Serial.println("Red btn hit");
                    redBtn();
                    while(p.z>500)
                    {
                        delay(50);
                        p = touch.getPoint();
                    }
                }
            }
        }
        else //ButtonFlag is off (ButtonFlag == false)
        {
            if((x > GREENBUTTON_X) && (x < (GREENBUTTON_X + GREENBUTTON_W)))
            {
                if ((y > GREENBUTTON_Y) && (y <= (GREENBUTTON_Y + GREENBUTTON_H)))
                {
                    Serial.println("Green btn hit");
                    greenBtn();
                    while(p.z>500)
                    {
                        delay(50);
                        p = touch.getPoint();
                    }
                }
            }
        }
        
        Serial.println(ButtonFlag);
    }
}

// Map float variables
static inline __attribute__((always_inline)) float mapFloat(float x, const float in_min, const float in_max, const float out_min, const float out_max)
{
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
