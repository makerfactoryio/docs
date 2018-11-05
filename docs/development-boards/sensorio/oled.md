# OLED display

## Description

SensorIO's display is a monochrome (white) OLED screen with 128x32 pixels and based on SSD1306 controller. Communication is carried over SPI interface (`SPI4`).

### Part details

Manufacturer:
Univision Technology Inc.

Part number:
UG-2832HSSWEG04

Datasheet: [link](https://cdn-shop.adafruit.com/datasheets/UG-2832HSWEG04.pdf)

## Code example

!!! info "Compiling example"
    This example is based on Mbed OS and requires a simple setup. For full description check [Code Setup](./code-setup.md) page.

### SSD1306 driver

Mbed OS driver for SensorIO can be found here: [SSD1306 on Github](https://github.com).

### Code

#### Pin definitions

```c++
    /**** OLED pins (SPI4) ****/
    OLED_CLK   = PE_2,
    OLED_RESET = PE_3,
    OLED_CS    = PE_4,
    OLED_DC    = PE_5,
    OLED_MOSI  = PE_6,
```

#### Example
This example shows basic usage of text display and image acceleration (scrolling and inverting).

```c++
{!development-boards/sensorio/assets/ssd1306main.cpp!}
```

Example `main.cpp` file can be downloaded from [here](./assets/ssd1306main.cpp).
