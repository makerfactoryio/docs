/******************************************************************
Created with PROGRAMINO IDE for Arduino
Project     : Maker-Factory ESP32 Board
Libraries   : https://github.com/adafruit/Adafruit_NeoPixel
Author      : UlliS
Description : WS2812 RGB-LEDs
Color via Pot

SW312 is ON

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

// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
    #include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            2

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      4

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


void setup()
{
    
    // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
    #if defined (__AVR_ATtiny85__)
        if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
    #endif
    // End of trinket special code
    
    pixels.begin(); // This initializes the NeoPixel library.
    
}

void loop()
{
    
    // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.
    int rVar = 0;
    int gVar = 0;
    int bVar = 0;

    
    for(int i=0;i<NUMPIXELS;i++){

        int color = map(analogRead(39),0,4095,0,1023);    // Poti Farbe
        int bright = map(analogRead(36),0,4095,10,90);    // Poti Helligkeit

        if(color < 10)
        {                  
            rVar = 255;
            gVar = 255;
            bVar = 255;
        }
        else if(color >= 10 && color < 341)
        {
            color = (color * 3 / 4);        // Den Wert auf 0-255 umrechnen
            
            rVar = 255 - color;             // Rot von an nach aus
            gVar = color;                   // Grün von aus nach an
            bVar = 0;                       // Blau aus
        }
        else if(color < 682)                // Mittleres Drittel des Potenziometerbereichs (341-681)
        {
            color = ((color-341) * 3 / 4);  // Den Wert auf 0-255 umrechnen
            
            rVar = 0;                       // Rot aus
            gVar = 255 - color;             // Grün von an nach aus
            bVar = color;                   // Blau von aus nach an
        }
        else                                // Oberes Drittel des Potenziometerbereichs (682-1023)
        {
            color = ((color-683) * 3 / 4);  // Den Wert auf 0-255 umrechnen
            
            rVar = color;                   // Rot von aus nach an
            gVar = 0;                       // Grün aus
            bVar = 255 - color;             // Blau von an nach aus
        }
        

        rVar = rVar * bright / 100;         // Faktor Helligkeit
        gVar = gVar * bright / 100;
        bVar = bVar * bright / 100;
      

        // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
        pixels.setPixelColor(i, pixels.Color(rVar,gVar,bVar)); // Moderately bright green color.
        pixels.show(); // This sends the updated pixel color to the hardware.
        delay(20); // Delay for a period of time (in milliseconds).
        
    }

}
