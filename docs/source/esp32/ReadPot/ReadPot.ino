/******************************************************************
Created with PROGRAMINO IDE for Arduino
Project     : Maker-Factory ESP32 Board
Libraries   : 
Author      : UlliS

Description : Read POTs and print the value over the Serial

SW302 is ON
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

Copyright (c) 2018 Conrad Electronic SE.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

******************************************************************/
#include <stdio.h>

void setup()
{
    
    Serial.begin(115200);
    Serial.println("Maker-Factory ESP32");
    
}

void loop()
{
    
    int R300 = analogRead(39);
    int R302 = analogRead(36);
    
    char s[30];
    sprintf(s,  "R300: %04d  -  R302: %04d", R300, R302);
    Serial.println(s);
    delay(250);
    
}
