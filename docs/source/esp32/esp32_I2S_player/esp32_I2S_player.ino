/******************************************************************
Created with PROGRAMINO IDE for Arduino
Project     : Maker-Factory ESP32 Board
Libraries   : https://github.com/nhatuan84/esp32-micro-sdcard
Author      : UlliS

Description : Stream a WAV file to the I2S PA

I2S not working... example in progress
******************************************************************/

#include "I2S.h"
#include <mySD.h>
#include "sampleaac.h"

#define CS 13
#define CLK 14
#define MISO 2
#define MOSI 15

const int offset = 0x2C;
char data[800];

File myFile;

void setup() {
    
    delay(3000);  // delay for SD-Card issue -> upload switches OFF, aber booting switch to ON. Litle bit tricky :-)
    
    Serial.begin(115200);
    Serial.print("Initializing SD card...");
    if (!SD.begin(CS, MOSI, MISO, CLK)) {
            Serial.println("initialization failed!");
            return;
    }
    
    Serial.println("initialization done.");
    Serial.println("File Open...");
    myFile = SD.open("/T.wav");  // 44100Hz, 16bit, stereo, linear PCM
    Serial.println("Seek...");
    myFile.seek(offset);
    Serial.println("I2S Init...");
    I2S_Init();
    Serial.println("Read...");
    while (myFile.readBytes(data, sizeof(data))) {
            I2S_Write(data, sizeof(data));
            //Serial.println(data);
    }
    myFile.close();
    Serial.println("Done.");
    
    I2S_Init();
    
    
    
    
    
}

void loop() {
    
    
}
