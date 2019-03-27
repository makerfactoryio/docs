# Burn A NES Game

*This document will help you for burning a gameboy game(NES file) so that you can play a game with GameBoy Keyboard.*

## Download firmware

Download the gameboy simulator firmware named `firmware.zip` from [Github](https://github.com/m5stack/M5Stack-nesemu). And unzip `firmware.zip`.

<img src="/images/m5stack/getting_started_pics/faces/faces_quick_start_05.png">

### Windows OS

<img src="/images/m5stack/getting_started_pics/faces/unpack_firmware.png">

### Mac OS

<img src="/images/m5stack/getting_started_pics/faces/faces_quick_start_06.jpg">

## Burn Game file

### Windows OS

Open Flash Download Tools[点击下载](https://www.espressif.com/sites/default/files/tools/flash_download_tools_v3.6.4.rar) apply by Espressif, choose `ESP32 DownloadTool` option, choose 4 files, and execute those operations as the following pictures shown. ( *choose firmware file, your serial port, erase and program flash* )

<img src="/images/m5stack/getting_started_pics/faces/chose_files.png">

<img src="/images/m5stack/getting_started_pics/faces/download_it.jpg">

### Mac OS

#### (1) install esptool

Open `terminal`, execute this command `pip install esptool`

<img src="/images/m5stack/getting_started_pics/faces/faces_quick_start_08.png">

#### (2) burn the game firmware

Open `terminal`, go to the path where `firmware.zip` is located

Execute the following commands in the `terminal`

```sh
unzip firmware.zip
cd firmware
esptool.py erase_flash
sh flash.sh
```

<img src="/images/m5stack/getting_started_pics/faces/faces_quick_start_07.jpg">

## Reset you device

After reset FACES, enjoy your game now.

<img src="/images/m5stack/product_pics/core/faces_kit/gameboy_01.jpg">


!!! info
    **If you want another game, please change the `Game file`(.nes)**
