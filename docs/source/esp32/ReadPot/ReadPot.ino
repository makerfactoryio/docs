/******************************************************************
Created with PROGRAMINO IDE for Arduino
Project     : Maker-Factory ESP32 Board
Libraries   : 
Author      : UlliS

Description : Read POTs and print the value over the Serial

SW302 is ON
SW312 is ON

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
void setup()
{
    
    Serial.begin(115200);
    Serial.println("Maker-Factory ESP32");
    
}

void loop()
{   
    //Reading the left potentiometer (SENSOR_VN)
    int R300 = analogRead(39);
    //Reading the right potentiometer (SENSOR_VP)
    int R302 = analogRead(36);
    
    char s[30];
    sprintf(s,  "R300: %04d  -  R302: %04d", R300, R302);
    Serial.println(s);
    delay(250);   
}
