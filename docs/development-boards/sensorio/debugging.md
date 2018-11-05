Depending on your needs SensorIO offers several ways of monitoring and debugging your firmware.

## With SensorIO only

### RGB Led

On-board RGB LED (`LD1`) can be programmed to show firmware status. Detailed usage is covered on [LED](./rgbled.md) page.

### OLED display

Firmware can also use on-board OLED display to show pictures and/or text messages. Detailed usage is covered on [OLED](./oled.md) page.

## With PC

### Logging

Once SensorIO is connected to PC with USB cable it should be visible both as a removable drive and as a serial port (usually called `COMX` on Windows and `ttyUSBX` on macOS/Linux). Terminal emulators, like [PuTTY](https://putty.org), [CoolTerm](https://freeware.the-meiers.org) or [picocom](https://github.com/npat-efault/picocom) and many others, can connect to SensorIO serial port and display messages sent from firmware. By default SensorIO uses `115200` baudrate.

Mbed OS makes it easy to use serial port in firmware:

1. Include Mbed OS `Serial` header:

    ```c++
    #include "Serial.h"
    ```

2. Create `Serial` object:

    ```c++
    mbed::Serial pc(USBTX, USBRX, 115200);
    ```

3. Use this object to send text to PC:

    ```c++
    pc.printf("This is SensorIO!");
    ```

Full `Serial` documentation is available on [Mbed OS pages](https://os.mbed.com/docs/latest/apis/serial.html).

### GDB

Debugging with GDB is more advanced than previous methods, but offers complete control and insight into firmware execution.

!!! info "Build type"
    For correct operation firmware should be build with debug profile.

In order to start debugging with GDB:

1. Make sure that SensorIO is connected to PC with USB cable.
2. If using external debugger it should also be connected to both PC and SensorIO JTAG/SWD port.
3. Start GDB server (a program that will allow GDB to communicate with debugger) in first console:

    - for OpenOCD and on-board ST-Link V2:

    ```bash
    openocd -f stlink-v2.cfg -f stm32f4x_stlink.cfg
    ```

    - for JLink:

    ```bash
    JLinkGDBServer -if SWD -device STM32F413ZH -speed 8000
    ```

4. Start GDB in another console:

    ```bash
    arm-none-eabi-gdb /path/to/firmware.elf
    ```

    !!! warning "Binary extension"
        Please note that for GDB to know most about firmware under debug it has to use `.elf` binary with debug symbols.

5. Connect from GDB (second console) to GDB server:

    - for OpenOCD and on-board ST-Link V2:

    ```bash
    target extended-remote:3333
    ```

    - for JLink:

    ```bash
    target extended-remote:2331
    ```

    !!! warning "GDB server ports"
        Ports used by GDB servers are configurable. Numbers - `3333` and `2331` - in examples reflect default ports for OpenOCD and JLink respectively.

6. Allow GDB to sync to firmware state by allowing it to run, by executing following command from GDB:

    ```
    continue
    ```

7. Stop firmware execution by pressing `CTRL+C` in GDB.

8. Flash the binary to SensorIO from GDB:

    ```
    load
    ```

    !!! info "Flashing"
        Whenever you change source code and recompiled binary has the same name/path as in step 4, it can be flashed with the same `load` command. As a bonus GDB will automatically pick up and understand all changes - no need to quit GDB!

9. Now firmware is redy for debugging - setting breakpoints, stepping through code execution and watching variables' values. [Here](http://unknownroad.com/rtfm/gdbtut/gdbtoc.html) is a good GDB tutorial to get started.
