## Overview

The component **I2C Pull-up** provides two 1k resistors for the usage as pull-up for the I2C bus. The resistors are independent.

ESP Board | I2C pull-up
--- | ---
<img src="/images/esp32/block_i2c_pull_up.png"  width="30%"> | SW307 and SW308

## Activating the component
The left resistor can be connected to SDA with *SW307* and the right resistor to SCL with *SW308*. The resistor on *SW307* is connected to io port **19** and the resistor on *SW308* is connected to io port **4**

SDA | SCL
--- | ---
SW307 | SW308
IO19 | IO4

## Using the component
There is no special source code needed for this component. If you need an pull-up in your project you have to activate the appropriate pull-up.

## Sample project
There is no specific source code necessary.
