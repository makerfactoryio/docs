# Tools

SensorIO board is equipped with [STM32F413ZH MCU](https://www.st.com/en/microcontrollers/stm32f413zh.html) so it can work with many different RTOSs or even bare metal. This guide (and other examples in this documentation) will concentrate on [Mbed OS](https://www.mbed.com/en/platform/mbed-os/) and command line tooling, which can be easily integrated into any IDE.

## Mbed CLI

### Software requirements

1. Python [2.7.11](https://www.python.org/downloads/release/python-2711/) or [3.6.0](https://www.python.org/downloads/release/python-360/). Other python versions might work, but `mbed-cli` is tested with those two.
2. Compiler: Mbed OS supports several toolchains, both free and paid (ARM Compiler, IAR, GNU Arm, and more), but all examples in this documentation are based and tested with [GNU Arm Embedded Toolchain](#gnu-arm-embedded-toolchain).

### Installation

1. Create a virtualenv for `mbed-cli`:
    - With Python 2.7.11:
    ```bash
    virtualenv -p python2.7 mbed
    ```
    - with Python 3.6.0:
    ```bash
    virtualenv -p python3.6 mbed
    ```

2. Activate virtual environment
    - on macOS/Linux:
    ```bash
    source mbed/bin/activate
    ```
    - on Windows:
    ```cmd
    mbed\Scripts\activate
    ```

3. Install `mbed-cli`:
    ```
    pip install mbed-cli
    ```

`pip` installs a release version of `mbed-cli`, you can choose however to install a development version - instructions are [here](https://github.com/ARMmbed/mbed-cli#installing-mbed-cli).

## GNU Arm Embedded Toolchain

GNU Arm Embedded Toolchain can be downloaded [directly from ARM](https://developer.arm.com/open-source/gnu-toolchain/gnu-rm/downloads). Mbed OS requires `6-2017-q2-update`, however SensorIO firmware is also tested with `7-2018-q2-update` version.

For installation instructions please refer to readme file in compiler package for your operating system.

## OpenOCD

[OpenOCD](http://openocd.org) is an open source debugging tool that supports numerous debugger interfaces and microcontrollers. Base installation instructions are available on [Getting OpenOCD](http://openocd.org/getting-openocd/) web page.

SensorIO comes with an onboard ST-Link V2 debugger, which is working with OpenOCD, however this functionality has to be enabled during OpenOCD build. If a binary provided for you operating system is not able to work with SensorIO, it is possible to compile OpenOCD from source - [here are official instructions](https://repo.or.cz/w/openocd.git).

SensorIO is tested with custom binary built from source and following configuration:
```bash
./configure --enable-ftdi --enable-ti-icdi --enable-stlink --enable-cmsis-dap --enable-jlink --enable-openjtag --disable-verbose-usb-comms --disable-verbose-usb-io
```

## Segger JLink

SensorIO provides a 10 pin JTAG/SWD header that can be used to connect external debuggers. [Segger JLink probes](https://www.segger.com/products/debug-probes/j-link/) work well with SensorIO and Segger software can be downloaded [from their website](https://www.segger.com/downloads/jlink/#J-LinkSoftwareAndDocumentationPack).
