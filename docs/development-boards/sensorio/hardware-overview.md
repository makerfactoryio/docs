##Hardware description

*SensorIO* is a powerful and versatile *ARM Cortex&reg;-M4*, [*mbed&trade;*](https://www.mbed.com)-enabled Internet-of-Things hardware development kit.

Its broad set of features makes it a versatile prototyping and development board for *Wi-Fi&reg;* connected products:

In order to maximize the flexibility of use for different applications, all the expansion interfaces have software-configurable support for 3.3V and 5V boards, bringing compatibility for more than 500+ different expansion boards available in the market from different manufacturers.

The core of the SensorIO board is the [*STM32F413ZH*](https://www.st.com/en/microcontrollers/stm32f413zh.html), a powerful *ARM Cortex&reg;-M4* MCU with a very rich set of peripherals presented into a 144-balls 10x10mm BGA chip.

![Features Front](../../images/sensorio/SensorIO-features-front.png)
![Features back](../../images/sensorio/SensorIO-features-back.png)

##Features 

This is an overview of the main components and features:

* **STM32F413ZH** MCU, *ARM Cortex&trade;-M4*, 1.5 Mbytes of Flash memory, 320 Kbytes of RAM, FPU unit w/ DSP instructions, 125 DMIPS @ 100 MHz.
* On-board WiFi: **CC3120R** *SimpleLink®*  Wi-Fi 802.11b/g/n 
* 128x32 0.91’’ OLED display 
* *LiteOn LTR303-ALS* ambient light sensor
* *Bosch Sensortec BMA253* 3-axis accelerometer with motion triggered interrups
* *Bosch Sensortec BME680* Environmental sensor (temperature, humidity, barometric pressure, VOC air quality) 
* 2x opto-relays output (*Toshiba TLP241A*, 2A/24Vac)
* 2x *MikroBUS&trade;* expansion sockets
* *Arduino&trade; R3* socket with 3.3V & 5V support on I/Os and Analog Inputs
* 2x *Grove&trade;* connectors 
	- Software programable individual 3.3V / 5V switches
	- Each connector provides software configurable UART, I2C, PWM, GPIO and Analog interfacing
* Onboard **ST-Link&trade;-V2.1** debugger
* Micro SD/MMC flash memory socket (for datalogging, storing credentials, etc.)
* User & reset buttons, RGB color LED
* USB functions:
	- Power input
	- Debugging port
	- Virtual Serial COMM
	- Mass storage programming (simply drag & drop to flash)


!!! todo
	Add total interfaces counts

##Block Diagram

![Block Diagram](../../images/sensorio/SensorIO-block-diagrBETA.png)


The board can be powered through the on-board USB Micro B connector or directly by the +5V pins of the MikroBUS connectors. Please check the [*Technical specifications*](../datasheet) and the [*circuit Schematics*](../schematics) for more details.

The target MCU can be programmed in 3 different ways:

* Using the flashing and debugging functionalities of the ST-Link interface (check the [Getting Started](../getting-started) and [Tools](../tools) for more information)
* Using the Cortex-M&trade; 10-pin connector present in the front (SWD). Debug probes like Segger's [J-Link&reg;](https://www.segger.com/products/debug-probes/j-link/) can be attached to this connector if preferred
* Just *drag and drop* the compiled binary file into the Mass Storage Device created in the host PC when the board is plugged into the USB

The ST-Link interface also provides a virtual serial port in addition to the SWD debugging interface, which can be used to print debug and logging information during the application development.

*SensorIO* integrates the Industrial-grade *CC3120R* SoC from *Texas Instruments*, a *Wi-Fi&reg;* Network Processor designed for Internet of Things applications. This subsystem includes an 802.11b/g/n radio, baseband, and MAC with a powerful crypto engine for fast, secure Internet connections with 256-bit encryption. The device also supports WPA2 personal and enterprise security. The external SPI flash attached to it is used to store the *Wi-Fi&reg;* and security stacks.

The board takes advantage of the main MCU's 20+ communication interfaces available through its 114 I/O ports to provide an unmached set of options to extend its functionalities through the [expansion interfaces](../interfaces) (Grove, MikroBUS and ArduinoR3 sockets).

## On-board interaction

In order to help the users to quickly evaluate the board and prototype a series of use-cases, the board provides a set of [sensors](../sensors),


##Limitations

!!! info "foo"
	bar




