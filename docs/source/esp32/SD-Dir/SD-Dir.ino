/******************************************************************
Created with PROGRAMINO IDE for Arduino
Project     : µSD
Board       : MAKERFACTORY EBB ESP32
Author      : MF

Description : Read the µSD card FAT32 directory

Switches:
SD CARD  SW406 Pin 1 ON
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

#define CS 13
#define CLK 14
#define MISO 34   //Pin 2 on older version of the board
#define MOSI 15

File root;

void setup()
{
    delay(100); // delay for SD-Card issue -> upload switches OFF, aber booting switch to ON. Litle bit tricky :-)
    
    // Open serial communications and wait for port to open:
    Serial.begin(115200);
    while (!Serial) 
    {
        ; // wait for serial port to connect. Needed for Leonardo only
    }
    
    Serial.print("Initializing SD card...");
    
    if (!SD.begin(CS, MOSI, MISO, CLK)) 
    {
        Serial.println("initialization failed!");
        return;
    }
    Serial.println("initialization done.");
    
    root = SD.open("/");
    printDirectory(root, 0);
    Serial.println("done!");
}

void loop()
{
    // nothing happens after setup finishes.
}

void printDirectory(File dir, int numTabs) 
{
    // Begin at the start of the directory
    dir.rewindDirectory();
    
    while(true) 
    {
        File entry = dir.openNextFile();
        if (! entry) 
        {
            // no more files
            //Serial.println("**nomorefiles**");
            break;
        }
        
        for (uint8_t i=0; i<numTabs; i++) 
        {
            Serial.print('\t');   // we'll have a nice indentation
        }
        
        // Print the 8.3 name
        Serial.print(entry.name());
        
        // Recurse for directories, otherwise print the file size
        if (entry.isDirectory()) 
        {
            Serial.println("/");
            printDirectory(entry, numTabs+1);
        } else {
            // files have sizes, directories do not
            Serial.print("\t\t");
            Serial.println(entry.size(), DEC);
        }
        entry.close();
    }
}
