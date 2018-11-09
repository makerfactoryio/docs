/******************************************************************
Created with PROGRAMINO IDE for Arduino
Project     : Maker-Factory ESP32 Board
Libraries   : mySD.h
Author      : UlliS

Description : SD-Card Init

******************************************************************/

/*
SD card test 

This example shows how use the utility libraries on which the'
SD library is based in order to get info about your SD card.
Very useful for testing a card when you're not sure whether its working or not.

The circuit:
* SD card attached to SPI bus as follows:
** UNO:  MOSI - pin 11, MISO - pin 12, CLK - pin 13, CS - pin 4 (CS pin can be changed)
and pin #10 (SS) must be an output
** Mega:  MOSI - pin 51, MISO - pin 50, CLK - pin 52, CS - pin 4 (CS pin can be changed)
and pin #52 (SS) must be an output
** Leonardo: Connect to hardware SPI via the ICSP header
Pin 4 used here for consistency with other Arduino examples


created  28 Mar 2011  by Limor Fried 
modified 9 Apr 2012   by Tom Igoe
*/
// include the SD library:
#include <mySD.h>
#include "driver/i2s.h"
#include "freertos/queue.h"

#define CS 13
#define CLK 14
#define MISO 2
#define MOSI 15

void setup()
{
    
    delay(3000); // delay for SD-Card issue -> upload switches OFF, aber booting switch to ON. Litle bit tricky :-)
	
    Serial.begin(115200);
    Serial.print("Initializing SD card...");
    if (!SD.begin(CS, MOSI, MISO, CLK)) {
        Serial.println("initialization failed!");
        return;
    }
    
    Serial.println("initialization done.");
    
    
}


void loop(void) {
    
}
