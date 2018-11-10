## Overview

The component **GROVE** provides eight connectors for the **Grove System** from Seeed Studio. These connectors are four digital connectors (named from *DIGITAL1* to *DIGITAL4*), two analog connectors (named from *ANALOG1* to *ANALOG2*), I2C and UART.

<img src="/images/esp32/block_grove.png"  width="30%">

## Activating the component

Each of the eight connectors has a own switch which have to be activated in order to use the component.

### ANALOG1

The switch for *Analog1* is *SW204*.

Function|SWITCH|IO port|Conflicts with|Remarks|
|------------------|----------|----------|----------|----------|
|VN|1|SENSOR_VN|**Potentiometer**, SW302, VN
|VP|2|SENSOR_VP|**Potentiometer**, SW300, VP

### ANALOG2

The switch for *Analog2* is *SW205*.

Function|SWITCH|IO port|Conflicts with|Remarks|
|------------------|----------|----------|----------|----------|
|ADC6|1|34|**MENU**, SW401-6, UP; **Camera**, SW400-3, D7
|ADC7|2|35|**Temperature**, SW315, DQ; **Camera**, SW400-2, D6

### DIGITAL1

The switch for *Digital1* is *SW206*.

Function|SWITCH|IO port|Conflicts with|Remarks|
|------------------|----------|----------|----------|----------|
|IO12|1|12|**RFID**, SW303-2, IRQ; **Gyro**, SW310-2, AD0/SD0; **mikroBus**, SW404-1, PWM; **Camera**, SW402-3, D1; **SD Card**, SW406-2, DAT2
|IO5|2|5|**Microphone**, SW301-1, SD; **RFID**, SW303-6, SDA; **TFT**, SW311-2, RESET

### DIGITAL2

The switch for *Digital2* is *SW207*.

Function|SWITCH|IO port|Conflicts with|Remarks|
|------------------|----------|----------|----------|----------|
|IO14|1|14|**Gyro**, SW310-1, INT; **mikroBus**, SW404-2, INT; **Camera**, SW402-4, D2; **SD Card**, SW406-5, CLK
|IO13|2|13|**mikroBus**, SW405-5, RST; **Camera**, SW402-2, D0; **SD Card**, SW406-1, CD/DAT3

### DIGITAL3

The switch for *Digital3* is *SW208*.

Function|SWITCH|IO port|Conflicts with|Remarks|
|------------------|----------|----------|----------|----------|
|IO21|1|21|**Menu**, SW404-6, SDA; **Camera**, SW400-5, SIOD /SCL
|IO15|2|15|**TFT**, SW311-3, D/C; **SD Card**, SW406-6, CMD


### DIGITAL4

The switch for *Digital4* is *SW209*.

Function|SWITCH|IO port|Conflicts with|Remarks|
|------------------|----------|----------|----------|----------|
|IO18|1|18|**Microphone**, SW301-3, WS; **RFID**, SW303-5, SCL; **TFT**, SW311-5, SCK; **TFT**, SW314-2, T_CLK; **mikroBus**, SW405-3, SCK
|IO17|2|17|**Microphone**, SW301-2, SCK; **mikroBus**, SW404-4, TX; **Camera**, SW403-1, RRST; **Unit-Bus**, SW202-1, CN212 - PIN 4; **Grove UART**, SW202-1, UART - RX

### I2C

The switch for *I2C* is *SW203*.

Function|SWITCH|IO port|Conflicts with|Remarks|
|------------------|----------|----------|----------|----------|
|I2C - SDA|1|19|
|I2C - SCL|2|4|

### UART

The switch for *UART* is *SW202*.

Function|SWITCH|IO port|Conflicts with|Remarks|
|------------------|----------|----------|----------|----------|
|UART - RX|1|17|**Microphone**, SW301-2, SCK; **mikroBus**, SW404-4, TX; **Camera**, SW403-1, RRST; **Unit-Bus**, SW202-1, CN212 - PIN 4; **Grove DIGITAL2**, SW209-2, IO17
|UART - TX|2|16|


## Using the component


## Sample project


