## Overview

The component **POTENTIOMETER** has two potentiomenters which could be used independently.

!!! example
    An example project for the Arduino IDE is provided in **ReadPot.ino** ([download here](../../source/esp32/ReadPot/ReadPot.ino))

ESP Board | potentiometer
--- | ---
<img src="/images/esp32/block_potentiometer.png"  width="30%"> | SW300,SW302

## Activating the component
The component has two dip switchs *SW300* and *SW302* for activating the buttons. SW300 is for the left potentiometer and SW301 for the right potentiometer. In order to use the potentiometers it's necessary to switch on the appropriate switch.

|Function|SWITCH|IO port|Conflicts with|Remarks|
|-----|-----|-----|-----|-----|
|SENSOR_VN|SW302|39|**Grove ANALOG1**, SW204-1, VN| |
|SENSOR_VP|SW300|36|**Grove ANALOG1**, SW204-2, VP| |

## Using the component

It's very important to switch on the right switches on *SW300* and/or *SW302*. The left potentiometer could be read on io port **39** and the right potentiometer on port **36**. The potentiometers are independent of each other. If you solely want to use one of the potentiometer, it's sufficient to switch on the appropriate switch.

There is so special setup code necessary for using the potentiometers.

### Reading the left potentiometer

```c
int R300 = analogRead(39);
```

### Reading the right potentiometer

```c
int R302 = analogRead(36);
```

## Sample project

An example project for the Arduino IDE is provided in **ReadPot.ino** ([download here](../../source/esp32/ReadPot/ReadPot.ino)).

