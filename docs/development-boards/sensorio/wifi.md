SensorIO features a Texas Instruments WiFi CC3120 SimpleLink Wi-Fi® Network Processor. Communication with WiFi coprocessor is carried over SPI (`SPI1`) interface.

### Part details

Manufacturer:
Texas Instruments Inc.

Part number:
CC3120

Datasheet: [link](http://www.ti.com/lit/ds/symlink/cc3120.pdf)

## Code example

!!! info "Compiling example"
    This example is based on Mbed OS and requires a simple setup. For full description check [Code Setup](./code-setup.md) page.

### CC3120 WiFi driver

Mbed OS driver for CC3120 can be found here: [CC3120 on Github](https://github.com).

### Code

#### Pin definitions

```c++
    /**** WiFi pins (SPI1) ****/
    CC_SPI_CS   = PA_4,
    CC_SPI_CLK  = PA_5,
    CC_SPI_MISO = PA_6,
    CC_SPI_MOSI = PA_7,
    CC_NRESET   = PE_8,
    CC_IRQ      = PE_9,
    CC_RESTORE  = PE_10,
```

#### Example

This example shows how to connect to a WPA2 secured WiFi network and send data over UDP port to a server.

Preparation:

- open UDP socket on PC. On macOS/Linux this can be done with `netcat`:
    ```bash
    nc -l -u  IP_ADDRESS PORT_NUMBER
    ```
- specify WiFi credentials in `WIFI_SSID` and `WIFI_PASSWD`
- specify PC address with open UDP socket in `SERVER` (this is `IP_ADDRESS` from `netcat` command) and `PORT` (this is `PORT_NUMBER` from `netcat` command)

```c++
{!development-boards/sensorio/assets/wifimain.cpp!}
```

Example `main.cpp` file can be downloaded from [here](./assets/wifimain.cpp).
