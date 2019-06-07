/******************************************************************
Created with PROGRAMINO IDE for Arduino
Project     : WS2813 smart RGB LEDs
Board       : MAKERFACTORY EBB ESP32
Version     : 1.0
Date        : 28.12.2018
Author      : MF

Description : WS2813 smart RGB-LEDs, control color and brightness via poti

Switches:
RGB LED       SW312 ON
POTENTOIMETER SW300 ON
POTENTOIMETER SW302 ON

Source:
https://we-mod-it.com/board258-diy-do-it-yourself/board263-diy-how-to/board231-raspberry-arduino/3076-arduino-tutorial-2-3-farbmischer-per-drehpoti/
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

// For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.
int rVar = 0;
int gVar = 0;
int bVar = 0;

void setup()
{
    pixels.begin(); // This initializes the NeoPixel library
    pixels.show();  // Initialize all pixels to 'off' 
}

void loop()
{
    for (int i=0;i<NUMPIXELS;i++)
    {
        
        int color  = map(analogRead(39),0,4095,0,1023);    // color
        int bright = map(analogRead(36),0,4095,15,90);     // brightness
        
        if (color < 10)
        {                  
            rVar = 255;
            gVar = 255;
            bVar = 255;
        }
        else if (color >= 10 && color < 341)
        {
            color = (color * 3 / 4);     
            
            rVar = 255 - color;         
            gVar = color;           
            bVar = 0;               
        }
        else if (color < 682)    
        {
            color = ((color-341) * 3 / 4);
            
            rVar = 0;               
            gVar = 255 - color;      
            bVar = color;           
        }
        else                        
        {
            color = ((color-683) * 3 / 4); 
            
            rVar = color;               
            gVar = 0;                   
            bVar = 255 - color;     
        }
        
        rVar = rVar * bright / 100; 
        gVar = gVar * bright / 100;
        bVar = bVar * bright / 100;
        
        // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
        pixels.setPixelColor(i, pixels.Color(rVar,gVar,bVar)); // Moderately bright green color.
        pixels.show(); // This sends the updated pixel color to the hardware.
        delay(20); // Delay for a period of time (in milliseconds).
    }
}
