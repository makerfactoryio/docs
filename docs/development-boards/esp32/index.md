# Documentation for the Embedded Board Builder for ESP32

This documentation describes the **ESP32 Evalulation board** as part of the Embedded Board Builder (EBB) familiy from Makerfactory. This board is an an devleopment board for the ESP32 module from [Expressif Systems](https://www.espressif.com/). With this development board you could develop projects for the **ESP32-WROOM-32** (for more information check the [datasheet on the page of Expressif Systems](https://www.espressif.com/sites/default/files/documentation/esp32-wroom-32_datasheet_en.pdf)) or **ESP32-WROVER** (for more information check the [datasheet on the page of Expressif Systems](https://www.espressif.com/sites/default/files/documentation/esp32-wrover_datasheet_en.pdf)).

!!! info
    The screenshots are created with the english version of Windows 10. If screenshots completly differs from the Mac OS version it's mentioned in the text.

## Board

The following picture shows the ESP32 Evaluation Board in Version V1.3.

![Board](../../images/esp32/board_ebb-esp32.jpg)

## Peripheral components

The EBB for ESP32 comes with a bunch of peripheral components which could be used for own projects. The usage of these component is described in this document. The follwing table lists the components:

!!! hint
    The ESP32 module has a **limited** number of usable IO ports. It's **not possible** to use all components on the board to the same time. Therefore you have to decide which component on the evaluation board you want to use in your project. In order to use a component you have you switch the appropriate dip switches to on. Additionally you have to switch conflicting components to off. The components which are using the same IO are described in the component pages.

- [Audio Amplifier](./audio.md)
- [Camera](./camera.md)
- [GPIO](./gpio.md)
- [Grove](./grove.md)
- [Gyro](./gyro.md)
- [I2C Pull-up](./i2c_pull_up.md)
- [Menu](./menu.md)
- [Microphone](./microphone.md)
- [mirkoBUS](./mikro_bus.md)
- [Motor](./motor.md)
- [OLED-LCD](./lcd.md)
- [Potentiometer](./potentiometer.md)
- [RFID](./rfid.md)
- [RGB LED](./rgb-led.md)
- [SD CARD](./sd_card.md)
- [Temperature](./temperature.md)
- [TFT](./tft.md)
- [Unit-Bus](./unit-bus.md)


## Schematics of the evaluation board

Download the schematics of the evaluation board if you need deep information about the structure of the board. The schematics could be found [here](../../assets/pdf/ESP32_Eval_V13_CS.PDF).

## License for the source code

The provided source code has the following license:

*Copyright (c) 2018 Conrad Electronic SE.*

*Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions: The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software. THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.*
