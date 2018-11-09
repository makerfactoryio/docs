/***************************************************************************************
Created with PROGRAMINO IDE for Arduino
Project     : Maker-Factory ESP32 Board
Libraries   :
Author      : UlliS
Description : Read the buttons


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
***************************************************************************************/

#define BTN_UP      34
#define BTN_DOWN    25
#define BTN_LEFT    26
#define BTN_RIGHT   32
#define BTN_CENTER  27


void setup()
{
    
    pinMode(BTN_UP,INPUT);
    pinMode(BTN_DOWN,INPUT);
    pinMode(BTN_LEFT,INPUT);
    pinMode(BTN_RIGHT,INPUT);
    pinMode(BTN_CENTER,INPUT);
    
    Serial.begin(115200);
    
}

void loop()
{
    
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
