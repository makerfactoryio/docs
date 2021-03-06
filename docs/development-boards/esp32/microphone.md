## Overview
The component **microphone** includes the ICS-43432 chip, a digital I2S output microphone. 
It consists of a MEMS sensor, signal conditioning, an analog-to-digital converter, decimation and anti-aliasing filters, power management, and an industry standard 24-bit I²S interface. 
The ICS-43432 has a high SNR of 65 dBA and a wideband frequency response.

!!! example
    There are three example projects for the Arduino IDE which can be downloaded:
    **I2S_Microphone_Speaker.ino** ([download here](../../source/esp32/Microphone/I2S_Microphone_Speaker.ino)), 
    **I2S_to_SD_16bit.ino** ([download here](../../source/esp32/Microphone/I2S_to_SD_16bit.ino)) and
    **I2S_to_SD_24bit.ino** ([download here](../../source/esp32/Microphone/I2S_to_SD_24bit.ino))


ESP Board | microphone
--- | ---
<img src="/images/esp32/block_microphone.png"  width="30%"> | SW301

## Activating the component

The component has a dip switch *SW301*, which has to be activated in order to use the component. The component is connected to the following ports:

Function|SWITCH|IO port|Conflicts with|Remarks|
|------------------|----------|----------|----------|----------|
|SD|1|5|**RFID**, SW303-6, SDA; **TFT**, SW311-2, RESET; **Grove Digital1**, SW206-2, IO5
|SCK|2|17|**Microphone**, SW301-2, SCK; **mikroBus**, SW404-4, TX; **Camera**, SW403-1, RRST; **Unit-Bus**, SW201-2, CN212 - PIN 4; **Grove UART**, SW202-1, UART-RX; **Grove Digital4**, SW209-2, IO17
|SWS|3|18|**RFID**, SW303-5, SCL; **TFT**, SW311-5, SCK; **TFT**, SW314-2, T_CLK; **mikroBus**, SW405-3, SCK; **Grove Digital4**, SW209-1, IO18|

Switch 4 (LR) of SW301 is connected to GND.

## Using the component

You need 6 jumpers to use the microphone connected to the board. 
The microphone can also be broken out of the board and can then be connected to the board by 6 cables.

!!! Info
    **Required libraries**

    In order to use the component you need the library "i2s.h". The latest version can be downloaded from the GitHub repository ([download here](https://github.com/espressif/esp-idf/blob/master/components/driver/include/driver/i2s.h)).
    
## Sample project

There are three example projects for the Arduino IDE which can be downloaded: **I2S_Microphone_Speaker.ino** ([download here](../../source/esp32/Microphone/I2S_Microphone_Speaker.ino)), **I2S_to_SD_16bit.ino** ([download here](../../source/esp32/Microphone/I2S_to_SD_16bit.ino)) and **I2S_to_SD_24bit.ino** ([download here](../../source/esp32/Microphone/I2S_to_SD_24bit.ino))
