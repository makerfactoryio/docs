## Overview

<img src="/images/esp32/block_microphone.png"  width="30%">

!!! example
    A sample project is in process.


## Activating the component

The component has a dip switch *SW301*, which have to be activated in order to uhse the component. The component is connected to the following ports:

Function|SWITCH|IO port|Conflicts with|Remarks|
|------------------|----------|----------|----------|----------|
|SD|1|5|**RFID**, SW303-6, SDA; **TFT**, SW311-2, RESET; **Grove Digital1**, SW206-2, IO5
|SCK|2|17|**Microphone**, SW301-2, SCK; **mikroBus**, SW404-4, TX; **Camera**, SW403-1, RRST; **Unit-Bus**, SW201-2, CN212 - PIN 4; **Grove UART**, SW202-1, UART-RX; **Grove Digital4**, SW209-2, IO17
|SWS|3|18|**RFID**, SW303-5, SCL; **TFT**, SW311-5, SCK; **TFT**, SW314-2, T_CLK; **mikroBus**, SW405-3, SCK; **Grove Digital4**, SW209-1, IO18|

Switch 4 (LR) of SW301 is connected to GND.

## Using the component

## Sample project
A sample project is in process.

