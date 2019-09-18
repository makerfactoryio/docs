/******************************************************************
Created with PROGRAMINO IDE for Arduino
Project     : WS2913 HSV Demo
Board       : MAKERFACTORY EBB ESP32
Version     : 1.0
Date        : 14.03.2019
Author      : MF

Description : Conversion of HSV (hue, value, saturation) to RGB (red, green, blue)

Switches:
RGB LED SW312 ON

Original Code: https://www.ulrichradig.de/home/index.php/projekte/hsv-to-rgb-led

******************************************************************/
#include <Adafruit_NeoPixel.h> // https://github.com/adafruit/Adafruit_NeoPixel

#define PIN                  2
#define MAX_WS2811_LEDS      4

Adafruit_NeoPixel strip = Adafruit_NeoPixel(MAX_WS2811_LEDS, PIN, NEO_GRB + NEO_KHZ800);

struct CRGB { uint8_t g; uint8_t r; uint8_t b; };
struct CRGB led[MAX_WS2811_LEDS];
struct CRGB led_tabelle[MAX_WS2811_LEDS];

const uint8_t PROGMEM LEDTABLE[] =
{
    0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,1, 2,2,2,2,2,2,2,2, 2,2,2,2,2,2,2,2, 2,2,2,2,2,2,2,2, 3,3,3,3,3,3,3,3, 3,3,3,3,3,3,3,3, 4,4,4,4,4,4,4,4, 5,5,5,5,5,5,5,5, 6,6,6,6,6,6,6,6, 7,7,7,7,7,7,7,7, 8,8,8,8,8,8,8,8, 10,10,10,10,10,10,10,10, 11,11,11,11,11,11,11,11,  13,13,13,13,13,13,13,13, 16,16,16,16,16,16,16,16, 19,19,19,19,19,19,19,19, 23,23,23,23,23,23,23,23,
    
    27,27,27,27,27,27,27,27,  32,32,32,32,32,32,32,32, 38,38,38,38,38,38,38,38, 45,45,45,45,45,45,45,45, 54,54,54,54,54,54,54,54,  64,64,64,64,64,64,64,64, 76,76,76,76,76,76,76,76, 91,91,91,91,91,91,91,91, 108,108,108,108,108,108,108,108, 128,128,128,128,128,128,128,128, 152,152,152,152,152,152,152,152, 181,181,181,181,181,181,181,181, 215,215,215,215,215,215,215,215, 255,255,255,255,255,255,255,255
};

void init_WS2813()
{    
    // This initializes the NeoPixel library.
    strip.begin();
    
    // LEDs off
    for(uint16_t i=0; i<strip.numPixels(); i++) {
        strip.setPixelColor(i, 0,0,0);
        strip.show();
    }
}

// HSV to RGB 8Bit
// Color Wheel h = 0 bis 360 (chromaticity)
//             s = 0 bis 100 (darkness)
//             v = 0 bis 100 (saturation)
// Return value r, g, b as pointer
void hsv_to_rgb (unsigned int h,unsigned char s,unsigned char v, unsigned char* r, unsigned char* g, unsigned char* b)
{       
    unsigned char diff;
    
    // Angle in color wheel 0 - 360 in 1 degree increments
    // h = hue
    // 1 degree increment, 4.25 pitch per step at 60 degrees
    if(h<61){
        *r = 255;
        *b = 0;
        *g = (425 * h) / 100;
    }else if(h < 121){
        *g = 255;
        *b = 0;
        *r = 255 - ((425 * (h-60))/100);
    }else if(h < 181){
        *r = 0;
        *g = 255;
        *b = (425 * (h-120))/100;
    }else if(h < 241){
        *r = 0;
        *b = 255;
        *g = 255 - ((425 * (h-180))/100);
    }else if(h < 301){
        *g = 0;
        *b = 255;
        *r = (425 * (h-240))/100;
    }else if(h< 360){
        *r = 255;
        *g = 0;
        *b = 255 - ((425 * (h-300))/100);
    }   
    
    // Calculation of color saturation
    // s = saturation
    s    = 100 - s;
    diff = ((255 - *r) * s)/100;
    *r = *r + diff;
    diff = ((255 - *g) * s)/100;
    *g = *g + diff;
    diff = ((255 - *b) * s)/100;
    *b = *b + diff;
    
    // Calculation of the dark level
    // v = dark Level Simple Theorem 0..100%
    *r = (*r * v)/100;
    *g = (*g * v)/100;
    *b = (*b * v)/100;
}

void setup()
{
    init_WS2813();
    
}

void loop()
{
    
    unsigned char r, g, b,tmp;
    unsigned int winkel;
    
    while(1)
    {   
        for(tmp = 0;tmp < MAX_WS2811_LEDS;tmp ++)
        {
            for(unsigned x = 0;x<100;x++)
            {
                for (unsigned a = 0;a<MAX_WS2811_LEDS;a++)
                {
                    // Calculation of the angle for the number of LEDs
                    winkel = (359/MAX_WS2811_LEDS)*a;
                    winkel += ((359/(MAX_WS2811_LEDS)*x)/100);
                    if(winkel>359) winkel-=359;
                    
                    // HSV to RGB
                    hsv_to_rgb(winkel,100,25,&r,&g,&b);
                    led_tabelle[a].r= r;
                    led_tabelle[a].g= g;
                    led_tabelle[a].b= b;
                }
                
                for (unsigned a = 0;a<MAX_WS2811_LEDS;a++)
                {
                    led[a].r= led_tabelle[tmp].r;
                    led[a].g= led_tabelle[tmp].g;
                    led[a].b= led_tabelle[tmp].b;   
                    tmp ++;
                    if(tmp == MAX_WS2811_LEDS)
                    {
                        tmp = 0;
                    }
                }    
                
                for (unsigned i = 0; i < MAX_WS2811_LEDS; i++)
                {
                    strip.setPixelColor(i, strip.Color(led[i].r,led[i].g,led[i].b));
                    strip.show();
                }
                
                delay(10);
                
            }               
        }       
    }   
}
