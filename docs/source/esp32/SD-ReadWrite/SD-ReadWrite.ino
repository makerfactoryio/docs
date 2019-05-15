/******************************************************************
Created with PROGRAMINO IDE for Arduino
Project     : µSD
Board       : MAKERFACTORY EBB ESP32
Author      : MF

Description : Read and Write the µSD card

Switches:
SDCARD  SW406 Pin 1 ON
              Pin 2 OFF
              Pin 3 ON
              Pin 4 OFF
              Pin 5 ON
              Pin 6 ON

Programming -> SW406 IO34 must be OFF!


SD card basic file example
This example shows how to create and destroy an SD card file   
The circuit:
* SD card attached to SPI bus as follows:
** UNO:  MOSI - pin 11, MISO - pin 12, CLK - pin 13, CS - pin 4 (CS pin can be changed)
and pin #10 (SS) must be an output
** Mega:  MOSI - pin 51, MISO - pin 50, CLK - pin 52, CS - pin 4 (CS pin can be changed)
and pin #52 (SS) must be an output
** Leonardo: Connect to hardware SPI via the ICSP header

created   Nov 2010 by David A. Mellis
modified 9 Apr 2012 by Tom Igoe
modified 13 June 2012 by Limor Fried

This example code is in the public domain.

******************************************************************/

#include <SPI.h>
#include <mySD.h> // https://github.com/nhatuan84/esp32-micro-sdcard

File myFile;

#define CS 13
#define CLK 14
#define MISO 34 //Pin 2 on older versions of the board
#define MOSI 15


void setup()
{
    // Open serial communications and wait for port to open:
    Serial.begin(115200);
    while (!Serial) {
        ; // wait for serial port to connect. Needed for Leonardo only
    }
    
    Serial.print("Initializing SD card...");
    if (!SD.begin(CS, MOSI, MISO, CLK)) 
    {
        Serial.println("initialization failed!");
        return;
    }
    Serial.println("initialization done.");
    
    // open the file. note that only one file can be open at a time,
    // so you have to close this one before opening another.
    myFile = SD.open("test.txt", FILE_WRITE);
    
    // if the file opened okay, write to it:
    if (myFile) {
        Serial.print("Writing to test.txt...");
        myFile.println("testing 1, 2, 3.");
        // close the file:
        myFile.close();
        Serial.println("done.");
    } else {
        // if the file didn't open, print an error:
        Serial.println("error opening test.txt");
    }
    
    // re-open the file for reading:
    myFile = SD.open("test.txt");
    if (myFile) {
        Serial.println("test.txt:");
        
        // read from the file until there's nothing else in it:
        while (myFile.available()) {
            Serial.write(myFile.read());
        }
        // close the file:
        myFile.close();
    } else {
        // if the file didn't open, print an error:
        Serial.println("error opening test.txt");
    }
}

void loop()
{
    // nothing happens after setup
}
