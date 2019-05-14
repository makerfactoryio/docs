## Overview

At component SD card you can read and write data to the card.

!!! example
    A sample project for the Arduino IDE is provided in **SD_Dir.ino** which could be downloaded [here](../../source/esp32/SD_Dir/SD_Dir.ino)

ESP Board | sd card
--- | ---
<img src="/images/esp32/block_sd_card.png"  width="30%"> | SW406,SW407

## Activating the component

Function|SWITCH|IO port|Conflicts with|Remarks|
|------------------|----------|----------|----------|----------|
|CD/DAT3|IO13|SW406-1|
|DAT2|IO12|SW406-2|
|DAT1|IO4|SW406-3|
|DAT0|IO2|SW406-4|
|CLK|IO14|SW406-5|
|CMD|IO15|SW406-6|
| | | |
|LED|IO32|SW407-1|
|CDET|IO27|SW407-2|

## Using the component
### Setup

```c
#include <SPI.h>
#include <mySD.h>

#define CS 13
#define CLK 14
#define MISO 2
#define MOSI 15

File root;

void setup()
{

    delay(3000); // delay for SD-Card issue -> upload switches OFF, aber booting switch to ON. Litle bit tricky :-)

    // Open serial communications and wait for port to open:
    Serial.begin(115200);
    while (!Serial) {
        ; // wait for serial port to connect. Needed for Leonardo only
    }


    Serial.print("Initializing SD card...");


    if (!SD.begin(CS, MOSI, MISO, CLK)) {
        Serial.println("initialization failed!");
        return;
    }
    Serial.println("initialization done.");

    root = SD.open("/");

    printDirectory(root, 0);

    Serial.println("done!");
}

```

### Print directory
```c
void printDirectory(File dir, int numTabs) {
    // Begin at the start of the directory
    dir.rewindDirectory();

    while(true) {
        File entry = dir.openNextFile();
        if (! entry) {
            // no more files
            //Serial.println("**nomorefiles**");
            break;
        }
        for (uint8_t i=0; i<numTabs; i++) {
            Serial.print('\t');   // we'll have a nice indentation
        }
        // Print the 8.3 name
        Serial.print(entry.name());
        // Recurse for directories, otherwise print the file size
        if (entry.isDirectory()) {
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
```

## Sample project
A sample project for the Arduino IDE is provided in **SD_Dir.ino** which could be downloaded [here](../../source/esp32/SD_Dir/SD_Dir.ino)
