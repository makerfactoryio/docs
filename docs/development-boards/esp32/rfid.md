## Overview

Read data from RFID RC522

ESP Board | rfid
--- | ---
<img src="/images/esp32/block_rfid.png"  width="30%"> | SW303

!!! example
    A sample project for the Arduino IDE is provided in **RFID.ino** which could be downloaded [here](../../source/esp32/RFID/RFID.ino)

## Activating the component
The component has a dip switch *SW303* for activating the temperature sensor. The switch connected to the following io ports:

Function|SWITCH|IO port|Conflicts with|Remarks|
|------------------|----------|----------|----------|----------|
|RST|1|22|**Audio**, SW306-4, DIN; **mikroBus**, SW404-5, SCL; **Camera**, SW400-6, SIOC/SCL
|IRQ|2|12|**Gyro**, SW310-2, AD0/SD0; **mikroBus**, SW404-1, PWM; **Camera**, SW402-3, D1; **SD Card**, SW406-2, DAT; **Grove Digital1**, SW206-1, IIO12
|MISO|3|19|**Gyro**, SW310-3, SDA/SDI; **OLED**, SW309-4, SDA; **TFT**, SW314-1, MISO; **mikroBus**, SW405-2, MISO; **Unit-Bus**, SW200-2, CN212 - PIN 2; **Grove I2C**, SW203-1, I2C - SDA
|MOSI|4|23|**Motor**, SW304-2, STEP; **TFT**, SW311-4, MOSI; **TFT**, SW314-4, T_DIN; **mikroBus**, SW405-1, MOSI
|SCL|5|18|**Microphone**, SW301-3, WS; **RFID**, SW303-5, SCL; **TFT**, SW311-5, SCK; **TFT**, SW314-2, T_CLK; **mikroBus**, SW405-3, SCK; **Grove Digital4**, SW209-1, IO18
|SDA|6|5|**Microphone**, SW301-1; **TFT**, SW311-2, RESET; **Grove Digital1**, SW206-2, IO5

## Using the component

!!! Info
    **Required libraries**

    In order to use the component you need the MFRC522-Library. The latested version could be download from the [GitHub repository](https://github.com/miguelbalboa/rfid). If you want to use the version from GitHub download a zip archiv. Addtionally you could [download](../../source/esp32/RFID/rfid-master.zip) a tested version. After the download it's necessary to add the library to your Arduino IDE. Open *Sketch > Include Library > Add .ZIP Library ...* and select the downloaded archive. After a sucessful installation the menu *Sketch > Include Library* should contain an entry *MFRC522* in the category *Contributed libraries*.


### Setup the component
```c
void setup() {
  Serial.begin(115200);       // Initialize serial communications with the PC
  while (!Serial);        // Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
  SPI.begin();            // Init SPI bus
  mfrc522.PCD_Init();     // Init MFRC522
  mfrc522.PCD_DumpVersionToSerial();  // Show details of PCD - MFRC522 Card Reader details
  Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));
}
```

### Check for new cards

```c
if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return;
}
```

### Select one of the cards

```c
if ( ! mfrc522.PICC_ReadCardSerial()) {
    return;
}
```

### Dump debug info about the card

```c
mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
```


## Sample project

A sample project for the Arduino IDE is provided in **RFID.ino** which could be downloaded [here](../../source/esp32/RFID/RFID.ino)
