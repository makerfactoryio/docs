/******************************************************************
Created with PROGRAMINO IDE for Arduino
Project     : WS2813 smart RGB LEDs
Board       : MAKERFACTORY EBB ESP32
Version     : 1.0
Date        : 28.12.2018
Author      : MF

Description : WS2813 smart RGB-LEDs, automatic smooth color change

Switches:
RGB LED SW312 ON

******************************************************************/

#include <Adafruit_NeoPixel.h> // https://github.com/adafruit/Adafruit_NeoPixel

// LED data pin
#define PIN            2

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      4

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define delayTime 20
int redVal;
int blueVal;
int greenVal;

void setup()
{
    pixels.begin(); // This initializes the NeoPixel library.
    pixels.show();
}

void loop()
{
    for (int j=0; j<765;j++)
    {
        setLEDs(j);
        delay(20);
    }
}

void setLEDs(int i)
{
    // set start colors (red)
    static int red   = 255;
    static int green = 0;
    static int blue  = 0;
    
    if (i < 255)      // 1: from red to green
    {
        red--;       // red down
        green++;     // green up
        blue = 0;    // blue low
    }
    else if (i < 510) // 2: from green to blue 
    {
        red = 0;     // red low
        green--;     // green down
        blue++;      // blue up
    } 
    else if (i < 766) // 3: from blue to red
    {
        red++;       // red up
        green = 0;   // green low
        blue--;      // blue down
    }
    
    for (int i=0;i<NUMPIXELS;i++)
    {
        pixels.setPixelColor(i, pixels.Color(red, green, blue)); 
        pixels.show();
    }
    
}
