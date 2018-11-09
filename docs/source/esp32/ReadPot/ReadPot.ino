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
