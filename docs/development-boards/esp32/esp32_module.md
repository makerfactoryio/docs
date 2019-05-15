## Overview

The component **ESP32 MODULE** contains the ESP32 microchip which will be programmed. The component has two placeholders that are used for the **ESP32-WROOM-32** or **ESP32-WROVER**.

!!! Caution
    You could only use one ESP32 module at one time. It's not possible to place both modules on the same time on the EBB board.

!!! example
    You find examples for each component in the component pages.

ESP Board | ESP-WROOM-32
--- | ---
<img src="/images/esp32/block_esp32_module.png"  width="30%"> | SW210

## Activating the component
Active all four switches of *SW210*.

## Using the component

It's necessary that all switches of *SW210* are on and the switch at component *POWER SUPPLY* is on. This is necessary in order to establish the communication between the onboard USB programmer (component *USB PROGRAMMING*) and the esp32 module.

## Sample project

Examples of each component can be found on the component pages.

## Datasheet

|Module|Datasheet from Expressif Systems|
|------|-----------------|
|ESP32-WROOM-32|[esp32-wroom-32_datasheet_en.pdf](https://www.espressif.com/sites/default/files/documentation/esp32-wroom-32_datasheet_en.pdf)
|ESP32-WROVER|[esp32-wrover_datasheet_en.pdf](https://www.espressif.com/sites/default/files/documentation/esp32-wrover_datasheet_en.pdf)


