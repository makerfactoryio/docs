## Overview

The component **TEMPERATURE** has an Dallas DS18B20+ for measuring the temperature

!!! example
    A sample project for the Arduino IDE is provided in **Temperature.ino** which could be downloaded [here](../../source/esp32/Temperature/Temperature.ino). In order to use the sample it's necessary to to install the OneWire library which is described in the section *Using the component*.

<img src="/images/esp32/block_temperature.png"  width="30%">

## Activating the component
The component has a dip switch *SW315* for activating the temperature sensor. Each of the five buttons is connected to one IO port. *Switch 1* is not connected and therefore the state of this switch is not relevant. The buttons are connected to the following ports

|Function|SWITCH|IO port|Conflicts with|Remarks|
|------------------|----------|----------|----------|----------|
|DQ|1|35|**CAMERA**, SW400-2, D6


## Using the component

!!! Info
    **Required libraries**
    In order to use the component you need the OneWire-Library. The latested version could be download from the [GitHub repository](https://github.com/PaulStoffregen/OneWire). If you want to use the version from GitHub download a zip archiv. Addtionally you could [download](../../source/esp32/Temperature/OneWire-master.zip) a tested version. After the download it's necessary to add the library to your Arduino IDE. Open *Sketch > Include Library > Add .ZIP Library ...* and select the downloaded archive. After a sucessful installation the menu *Sketch > Include Library* should contain an entry *OneWire* in the category *Contributed libraries*.



## Sample project

A sample project for the Arduino IDE is provided in **Temperature.ino** which could be downloaded [here](../../source/esp32/Temperature/Temperature.ino). In order to use the sample it's necessary to to install the OneWire library which is described in the section *Using the component*.
