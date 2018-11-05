# User button

## Description

SensorIO has one button that can be used by firmware.

## Code example

!!! info "Compiling example"
    This example is based on Mbed OS and requires a simple setup. For full description check [Code Setup](./code-setup.md) page.

### Button driver

Button does not need external driver - only Mbed OS built-in `InterruptIn` class is required.

### Code

#### Pin definitions

```c++
    USER_BUTTON = PC_13,
    BUTTON1     = USER_BUTTON,
```

#### Example
In this example user button is used to turn `LD2` on and off.

```c++
{!development-boards/sensorio/assets/buttonmain.cpp!}
```

Example `main.cpp` file can be downloaded from [here](./assets/buttonmain.cpp).
