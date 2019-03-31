# MicroSD Card

## Description

SensorIO has a MicroSD card port, connected over `SDIO` interface to MCU. Together with Mbed OS file system utilities it can be used to read from, write to and reformat MicroSD cards.

## Code example

!!! info "Compiling example"
    This example is based on Mbed OS and requires a simple setup. For full description check [Code Setup](./code-setup.md) page.

### MicroSD Card driver

Mbed OS driver for SDIO can be found here: [SDIO on Github](https://github.com).

### Code

#### Pin definitions

```c++
    /**** SDIO pins for uSD card ****/
    uSD_CMD = PD_2,
    uSD_CLK = PC_12,
    uSD_D0  = PC_8,
    uSD_D1  = PC_9,
    uSD_D2  = PC_10,
    uSD_D3  = PC_11,
    uSD_CD  = uSD_D3,
```

#### Example

This example requires that a `FAT32` formatted SD card is inserted to SD card slot. Firmware creates a SDIO BlockDevice, mounts it as `FAT32` file system and creates/appends a text file.

```c++
{!development-boards/sensorio/assets/sdiomain.cpp!}
```

Example `main.cpp` file can be downloaded from [here](./assets/sdiomain.cpp).
