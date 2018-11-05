SensorIO is extremely flexible and supports majority of Arduino shields and Grove extensions. This is achieved with hardware multiplexers and switches that can be controlled by firmware.

## Multiplexer driver

There are two ways to set multiplexers:

1. By directly controlling appropriate pins (see Pin Definitions sections) with Mbed OS built-in `DigitalOut` class
2. By using a simple wrappers with more verbose, one-line settings from [Github](https://github.com)

## Arduino

Multiplexer for Arduino selects which analog input pin on Arduino port (`A0` to `A5`) is connected to main MCU analog input (`PC_0`/`ARD_ANALOG_IN`).

#### Pin definitions

```c++
    /**** Arduino analog multiplexer ***/
    ARD_MUX_A   = PG_6,
    ARD_MUX_B   = PG_7,
    ARD_MUX_C   = PG_8,

    ARD_ANALOG_IN = PC_0,
```

#### Pin settings

ARD_MUX_A | ARD_MUX_B | ARD_MUX_C | Selection
:-------: |:---------:| :-------: | :-------:
 0 | 0 | 0 | A0
 0 | 0 | 1 | A1
 0 | 1 | 0 | A2
 0 | 1 | 1 | A3
 1 | 0 | 0 | A4
 1 | 0 | 1 | A5
 1 | 1 | 0 | CALIB_HIGH
 1 | 1 | 1 | CALIB_LOW

!!! note "`A4` and `A5`"
    Pins A4 and A5 are internally connected to D14 and D15 in some shields, therefore, remember to configure D14 (PB4) and D15 (PA8) in high impedance mode (set as INPUT) to use these analog inputs.

!!! note "`CALIB_HIGH` and `CALIB_LOW`"
    MUX values 6 and 7 can be used to calibrate the Analog Inputs to the Max and Min values respectively.

#### Example

This snippet shows how to route pin `A3` from Arduino port to MCU analog input (`PC_0`/`ARD_ANALOG_IN`) with `DigitalOut` class:

```c++
{!development-boards/sensorio/assets/ardanalogin.cpp!}
```

This file can be downloaded [here](./assets/ardanalogin.cpp).

This snippet shows the same functionality, but with `ArduinoMultiplexer` wrapper:

```c++
{!development-boards/sensorio/assets/ardmultiplexer.cpp!}
```

This file can be downloaded [here](./assets/ardmultiplexer.cpp).

## Grove

Each Grove connector has a voltage level switch and mode selection multiplexer. Voltage level switch can be used to select between 3.3V and 5V on `Vcc` pin. Mode multiplexer selects function of two signal pins, from PWM, to UART, to I2C to analog input.

#### Pin definitions

1. Grove 1 connector:

    ```c++
        /**** Grove 1 multiplexer pins ****/
        GROVE1_MUX_A    = PD_10,
        GROVE1_MUX_B    = PD_11,

        /**** Grove 1 3V3/5V switch pin ****/
        GROVE1_SW_5V = PG_9,
    ```

2. Grove 2 connector:

    ```c++
        /**** Grove 2 multiplexer pins ****/
        GROVE2_MUX_A    = PG_4,
        GROVE2_MUX_B    = PG_5,

        /**** Grove 2 3V3/5V switch pin ****/
        GROVE2_SW_5V = PG_10,
    ```

#### Pin settings

1. Mode multiplexer:

    GROVEX_MUX_A | GROVEX_MUX_B | Mode
    :-------: |:---------:| :-------:
     0 | 0 | PWM
     0 | 1 | UART
     1 | 0 | I2C
     1 | 1 | ANALOG_IN

2. Voltage switch:

    GROVEX_SW_5V | Vcc [V]
    :-------: |:---------:
    0 | 3.3
    1 | 5

!!! warning "I2C on Grove"
    Driver for I2C on Grove connectors (both connectors share the same I2C bus) is not yet ready.

#### Example

This snippet shows how to configure Grove 1 connector as UART with 3.3V Vcc and Grove 2 connector as analog input with 5V Vcc:

```c++
{!development-boards/sensorio/assets/grovemtx.cpp!}
```

This file can be downloaded [here](./assets/grovemtx.cpp).

Grove multiplexers can also be used with just `DigitalOut` instead of `GroveMultiplexer` class. For this please refer to [Arduino example](#example).
