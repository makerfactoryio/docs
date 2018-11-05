# Relays

## Description

SensorIO has one high brightness, user programmable RGB Led (`LD2`). Each color can be switched separately via toggling a pin or via PWM.

## Code example

!!! info "Compiling example"
    This example is based on Mbed OS and requires a simple setup. For full description check [Code Setup](./code-setup.md) page.

### RGB Led driver

RGB Led driver via PWM can be downloaded here (header only library): [link](./assets/rgbled.h). Led control via pin toggling can be done with Mbed OS built-in `DigitalOut` class.

### Code

#### Pin definitions

```c++
    RGB_RED     = PF_3,      // TIM5_CH1
    RGB_GREEN   = PF_4,      // TIM5_CH2
    RGB_BLUE    = PF_5,      // TIM5_CH3
    LED1        = RGB_GREEN, // Green
    LED2        = RGB_BLUE,  // Blue
    LED3        = RGB_RED,   // Red
    LED4        = LED1,
    LED_RED     = LED3,
```

#### Example
In this example user button is used to turn on and off RGB Led which toggles colors in HSV palette.

```c++
{!development-boards/sensorio/assets/rgbledmain.cpp!}
```

Example `main.cpp` file can be downloaded from [here](./assets/rgbledmain.cpp).
