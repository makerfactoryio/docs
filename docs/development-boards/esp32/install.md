# Installation of the IDE

Your EBB evaluation board has an ESP32 from [Espressif](https://www.espressif.com/). There are various toolchains for programming an ESP32.

!!! note
    We recommend the [Arduino IDE](https://www.arduino.cc/en/Main/Software). The source code in this documentation is tested for the Arduino IDE.

Download the latest version of Arduino IDE from the [download section](https://www.arduino.cc/en/Main/Software) of the Arduino webpage. If you already have installed a version of the Arduino IDE, it should be at least the version 1.8. We recommend to use a stable version and **not** the *HOURLY BUILDS* or *BETA BUILDS*. After a successful download, execute the downloaded installer and start the Arduino IDE. It will present an pre-generated sketch:

Arduino IDE | start of IDE
--- | ---
<img src="/images/esp32/arduino_ide/arduino_ide_01.png"  width="30%"> | sketch shown after installation

In order to program the ESP32 it's necessary to install the appropriate addon. This is described in chapter [Programming the board](../program)
