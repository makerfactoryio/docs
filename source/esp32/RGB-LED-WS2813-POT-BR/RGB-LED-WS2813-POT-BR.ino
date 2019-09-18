/******************************************************************
Created with PROGRAMINO IDE for Arduino
Project     : WS2813 smart RGB LEDs
Board       : MAKERFACTORY EBB ESP32
Version     : 1.0
Date        : 28.12.2018
Author      : MF

Description : WS2813 smart RGB-LEDs, control brightness via poti

Switches:
RGB LED         SW312 ON
POTIENTIOMETER  SW302 ON

GPIO ADC Channel:
GPIO 0 ==> ADC2_CH1
GPIO 2 ==> ADC2_CH2
GPIO 4 ==> ADC2_CH0
GPIO 12 => ADC2_CH5
GPIO 13 => ADC2_CH4
GPIO 14 => ADC2_CH6
GPIO 15 => ADC2_CH3
GPIO 25 => ADC2_CH8
GPIO 26 => ADC2_CH9
GPIO 27 => ADC2_CH7
GPIO 32 => ADC1_CH4
GPIO 33 => ADC1_CH5
GPIO 34 => ADC1_CH6
GPIO 35 => ADC1_CH7
GPIO 36 => ADC1_CH0
GPIO 37 => ADC1_CH1
GPIO 38 => ADC1_CH2
GPIO 39 => ADC1_CH3

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

void setup()
{
    pixels.begin(); // This initializes the NeoPixel library.
    pixels.show();  // Initialize all pixels to 'off'    
}

void loop()
{
    // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.
    int rVar = 0;
    int gVar = 0;
    int bVar = 0;
    
    for (int i=0;i<NUMPIXELS;i++)
    {
        int br = map(analogRead(36),0,4095,0,255);
        
        // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
        pixels.setPixelColor(i, pixels.Color(br,br,br)); // All color components have the same value => the poti is regulating the brightness 
        
        pixels.show(); // This sends the updated pixel color to the hardware.
        
        delay(20); // Delay for a period of time (in milliseconds).  
    }
}
