# Expansion interfaces

This section describes the Grove, MikroBUS and Arduino R3 expansion interfaces. 

## MikroBUS sockets

<img src="/images/sensorio/MBus-logo.png" class="img-left" width="20%" > 

The [mikroBUS™ socket](https://download.mikroe.com/documents/standards/mikrobus/mikrobus-standard-specification-v200.pdf) comprises a pair of 1×8 female headers with a proprietary pin configuration and silkscreen markings. The pinout consists of three groups of communications pins (SPI, UART and I2C), six additional pins (PWM, Interrupt, Analog input, Reset and Chip select), and two power groups (+3.3V and 5V). 

The company [Mikroelectronica](https://www.mikroe.com) produces over [500 expansion boards](https://www.mikroe.com/click) called "Click modules", available through various distributors. These modules are often useful for rapid prototyping and evaluation of a broad variety of sensors, interfaces and actuators.

The figure below shows the MikroBUS#1 schematic, the second interface is identical. 

<img src="/images/sensorio/MikroBUS_1.png" class="img-center" width="80%" > 

The pin-mapping to the MCU of the pins are listed on the [pinout section](../pinouts#mikrobus). The pinout lists also the alternative functions when available (as a CAN Bus or I2S for audio for instance).

!!! info "Pin sharing limitation"
	Please note that, although the STM32F413 MCU provides a rich set and number of peripherals, in some cases the buses are shared between the expansion interfaces. 

	For example, the MikroBUS sockets share one SPI bus, which doesn't present a problem if this interface is used as a bus, since each interface has it's own Chip Select lines exposed (MBx_CS), but if these pins are intended to be used as independent GPIOs, only one interface can be used at a time. Please refer to the [*Pinouts section*](../pinouts#expansion-interfaces) for more details.

The capture below shows the I2C pull-up resistors. Please note the I2C lines are shared between the MikroBUS 1 and 2 interfaces.

<img src="/images/sensorio/MBus-I2C.png" class="img-center" width="50%" > 

!!! tip "mickroBUS orientation"
	Please note the correct orientation mark in the image below. An incorrect installation could damage the modules or the SensorIO board.

<img src="/images/sensorio/MB-orientation.jpg" class="img-center" width="80%" > 

## Grove connectors

## Arduino R3 socket	


