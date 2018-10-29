# Flashing SensorIO

SensorIO offers several methods of flashing. Example commands assume that binary is built with Mbed OS, however most of these methods work with any binary built for SensorIO MCU.
For all methods SensorIO has to be connected to computer with a USB cable.

## Drag & Drop

An easy way to flash new firmware to SensorIO is to drag the binary from build folder (for Mbed OS it is usually located in `./BUILD/SENSORIO/GCC_ARM-DEBUG/` directory) and drop it to `SENSORIO` removable drive.

Once the copy is complete removable drive will disappear and `LD1` LED will blink red and green. After a few seconds removable drive should reappear again and SensorIO will start executing new firmware.

## Copy from terminal

Of course, [Drag & drop](#drag-drop) can be executed directly from terminal:

```bash
cp /path/to/firmware.bin /path/to/SENSORIO
```

After this command SensorIO should behave the same way as in [Drag & drop](#drag-drop). On some operating systems syncing (via `sync`) and/or explicit `SENSORIO` removal might be required.

## OpenOCD

With a [correctly installed OpenOCD](./tools.md#openocd) binary can be flash from command line:

```bash
openocd -f stlink-v2.cfg -f stm32f4x_stlink.cfg -c "program ./path/to/firmware.elf verify reset exit"
```

This command assumes that SensorIO is connected only via USB cable and flashing is done with on-board ST-Link V2 debugger. For other debuggers (like Segger JLink) configuration files have to be adjusted

## Segger JLink

SensorIO has a separate 10-pin JTAG/SWD header that allows connecting external debuggers to the board. Once Segger JLink debugger is connected to this header and [Segger tools](./tools.md#segger-jlink) are installed, binary can be quickly flashed from terminal:

1. Create a `sensorio.jlink` command file with following contents (needed only once):

    ```
    si 1
    speed 1000
    device STM32F413ZH
    halt
    loadfile path/to/firmware.hex
    r
    g
    q
    ```

2. Flash new binary with JLink application:

    ```bash
    JLinkExe -commanderscript sensorio.jlink
    ```

## GDB

Binaries can also be flash from GDB prompt. Instructions are on [Debugging with GDB](./debugging.md#gdb) page.

## Mbed CLI

!!! warning "Mbed CLI"
    This method will work only for binaries built with Mbed OS and will be available once SensorIO Mbed Enabled certification is complete.

To compile and flash new Mbed OS based firmware to SensorIO execute this command (after proper [Code setup](./code-setup.md)):

```bash
mbed compile --flash --profile debug.json
```
