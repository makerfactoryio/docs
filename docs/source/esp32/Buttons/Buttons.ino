/******************************************************************
Created with PROGRAMINO IDE for Arduino
Project     : Read menu buttons
Board       : MAKERFACTORY EBB ESP32
Version     : 1.0
Date        : 28.12.2018
Author      : MF

Description : output the button status via the terminal

Switches:
MENU SW401 all ON

License:
This file may be redistributed under the terms of the MIT license.
A copy of this license has been included with this distribution 
in the file LICENSE.
******************************************************************/

// pin defines for the menu buttons
#define BTN_UP      34
#define BTN_DOWN    25
#define BTN_LEFT    26
#define BTN_RIGHT   32
#define BTN_CENTER  27

void setup()
{
    // initialize the button pins as input without internal pullup resistor
    pinMode(BTN_UP,INPUT);
    pinMode(BTN_DOWN,INPUT);
    pinMode(BTN_LEFT,INPUT);
    pinMode(BTN_RIGHT,INPUT);
    pinMode(BTN_CENTER,INPUT);
    
    // initialize the serial port
    Serial.begin(115200);
}

void loop()
{
    // endless loop
    // output the button status via the terminal
    Serial.print("UP: ");
    Serial.print(digitalRead(BTN_UP));
    Serial.print(" | ");
    
    Serial.print("DOWN: ");
    Serial.print(digitalRead(BTN_DOWN));
    Serial.print(" | ");
    
    Serial.print("LEFT: ");
    Serial.print(digitalRead(BTN_LEFT));
    Serial.print(" | ");
    
    Serial.print("RIGHT: ");
    Serial.print(digitalRead(BTN_RIGHT));
    Serial.print(" | ");
    
    Serial.print("CENTER: ");
    Serial.println(digitalRead(BTN_CENTER));
    
    delay(250);   
}
