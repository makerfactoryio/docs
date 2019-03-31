SensorIO is designed to support a wide range of existing Arduino shields, Grove and mikroBUS extensions. There are however some limitations, like shared buses.

## Buses

Bus   | Ardunio | Grove 1 | Grove 2 | mikroBUS 1 | mikroBUS 2
:---: |:-------:| :-----: | :-----: | :--------: | :--------:
SPI | `SPI2` | - | - | **SPI5** | **SPI5**
I<sup>2</sup>C |  I2C3 | <span style="color:red">**I2C_FMP1**</span> | <span style="color:red">**I2C_FMP1**</span> | <span style="color:blue">**I2C1**</span> | <span style="color:blue">**I2C1**</span>
UART | UART4 | UART8 | UART9 | UART7 | UART5
PWM | TIM2_CH4 | TIM4_CH3 / _CH4 | TIM4_CH1 / _CH2 | TIM12_CH1 | TIM12_CH2


## Limitations

### mikroBUS

1. Shared buses:

    - `SPI5` - only one SPI Click board can be used at a time
    - `I2C1` - all devices attached to mikroBUS ports need unique I<sup>2</sup>C addresses

### Grove

1. Shared buses:

    - `I2C_FMP1` - all devices attached to Grove ports need unique I<sup>2</sup>C addresses

2. Mode:

    - each port can be separately configured into one of the modes:
        - UART
        - PWM
        - I<sup>2</sup>C
        - analog input

    Configuration is done with [Grove multiplexers](./multiplexers.md#pin-settings_1)

### Arduino

1. Analog inputs:
    - only one analog input from `A0` to `A5` pins can be used at a time. Selection is done with [Arduino multiplexer](./multiplexers.md#pin-settings).
