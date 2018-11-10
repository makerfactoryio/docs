## Overview

The component **POTENTIOMETER** has two potentiomenters which could be used independently.

!!! example
    A sample project for the Arduino IDE is provided in **ReadPot.ino** which could be downloaded [here](../../source/esp32/ReadPot/ReadPot.ino)

<img src="/images/esp32/block_potentiometer.png"  width="30%">

## Activating the component
The component has two dip switchs *SW300* and *SW302* for activating the buttons. SW300 is for the left potentiometer and SW301 for the right potentiometer. The left potentiometer is to PIN 4 of the ESP32 module which is the **SENSOR_VP**. The right potentiometer is connected to PIN 5 of the ESP32 module which is **SENSOR_VN**. In order to use the potentiometers it's necessary to switch on the appropriate switch.

Function|SWITCH|IO port|Conflicts with|Remarks|
|------------------|----------|----------|----------|----------|
|SENSOR_VN|SW302|SENSOR_VN|**Grove ANALOG1**, SW204-1, VN
|SENSOR_VPN|SW300|SENSOR_VP|**Grove ANALOG1**, SW204-2, VP

## Using the component

It's very important to switch on the right switches on *SW300* and *SW302*. The left potentiometer could be read on io port **39** and the right potentiometer on port **36**.

```c
int R300 = analogRead(39);
int R302 = analogRead(36);
```

## Sample project

A sample project for the Arduino IDE is provided in **ReadPot.ino** which could be downloaded [here](../../source/esp32/ReadPot/ReadPot.ino)

