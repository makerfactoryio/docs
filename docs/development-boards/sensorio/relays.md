# Relays

## Description

SensorIO has 2 on-board, normally opened (1-Form-A) photorelays that can be used as programmable switches for devices with power supply up to 26Vdc or 18Vac and up to 2A.

### Part details

Manufacturer:
Toschiba Corporation

Part number:
TLP241A

Datasheet: [link](https://toshiba.semicon-storage.com/info/docget.jsp?did=14237&prodName=TLP241A)

## Code example

!!! info "Compiling example"
    This example is based on Mbed OS and requires a simple setup. For full description check [Code Setup](./code-setup.md) page.

### Relay driver

Relays do not need external driver - only Mbed OS built-in `DigitalOut` class is required.

### Code

#### Pin definitions

```c++
    /**** Relay pins ****/
    RELAY_1 = PG_2,
    RELAY_2 = PG_3,
```

#### Example
In this example user button is used to toggle state of `RELAY_1`.

```c++
{!development-boards/sensorio/assets/relaymain.cpp!}
```

Example `main.cpp` file can be downloaded from [here](./assets/relaymain.cpp).
