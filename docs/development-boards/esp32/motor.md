## Overview

<img src="/images/esp32/block_motor.png"  width="30%">

## Activating the component
The component has two dip switches *SW304* and *SW305* for activating the component.

|Function|SWITCH|IO port|Conflicts with|Remarks|
|------------------|----------|----------|----------|
|DIR|SW304-1|33|**RGB LED**, SW313, DIN; **TFT**, SW314, T_DO; **mikroBus**, SW405-6, AN
|STEP|SW304-2|23|**RFID**, SW303-4, MOSI; **TFT**, SW311-4, MOSI; **TFT**, SW314-4, T_DIN; **mikroBus**, SW405-1, MOSI

The four switch of *SW305* are connected to GND. The functions are as follows:

|Function|SWITCH|
|------------------|----------|
|EN|SW305-1|
|CFG1|SW305-2|
|CFG2|SW305-3|
|CFG3|SW305-4|

## Using the component


## Sample project
