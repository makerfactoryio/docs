## Overview

The component **I2C Pull-up** provides two 1k resistors for the usage as pull-up for the I2C bus. The resistors are independent.

<img src="/images/esp32/block_i2c_pull_up.png" width="100">

## Activating the component
The left resistor could be controlled with *SW307* and the right resistor with *SW308*. The resistor on *SW307* is connected to io port **19** and the resistor on *SW308* is connected to port **4**

## Using the component

There is no special source code needed for this component. If you need an pull-up in you project you have to activate the appropriate pull-up.

## Sample project

There is no specific source code necessary.
