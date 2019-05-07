# Programming the ESP32

After a successful [installation](../install) of the Arduino IDE it's necessary to install the ESP32 as development board inside the Arduino IDE. For this you have to do the following two steps:

1. Register a new board manager
2. Install the extension for ESP32

!!! note
    The communication between the host computer and the development board is done by USB. The used USB chipset is a *Silicon Labs CP210x*. It should be automatically recognized by the operation system. If there is no automatic recognition install the driver manually. The link to the driver page is https://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers

## Register a new board manager

Start the Arduino IDE, open the Preferences window with *File > Preferences* in the menu bar.

| IDE | preferences |
| --- | --- | 
| ![Open Preferences windows](../../images/esp32/arduino_ide/open_preferences.png) | select *preferences* |

The Preferences window has to tabs:

+ *Settings*
+ *Network*

| IDE | Settings |
| --- | --- | 
| ![Preferences window](../../images/esp32/arduino_ide/preferences_window.jpg) | select *Additional Boards Manager URLs* |

It's not necessary to change setting inside the *Network* tab. But a change in the *Settings* tab is necessary. Add an entry to the *Additional Boards Manager URLs*:

![board_manager_urls](../../images/esp32/arduino_ide/board_manager_urls.jpg)

You could directly paste the following url into the input field or open the seperate window:

```
https://dl.espressif.com/dl/package_esp32_index.json
```

| IDE | insert url |
| --- | --- | 
| ![board_manager_urls](../../images/esp32/arduino_ide/url_dialog.png) | insert url |

## Install the extension for ESP32

Now you could install the development extension for the ESP32 into the Arduino IDE. Go to *Tools > Board > Boards Manager...*

| IDE | Boards Manager |
| --- | --- | 
| ![menu_boards_manager](../../images/esp32/arduino_ide/menu_boards_manager.jpg) | select *Boards Manager* |

Use the search input file. Search for *esp32* and select *Install*.

| IDE | Boards |
| --- | --- | 
| ![](../../images/esp32/arduino_ide/board_manager_01.png) | select *install* |

After the install a section *ESP 32* in the menu *Tools > Board* should occur.

| IDE | Boards |
| --- | --- | 
| ![esp32_menu_entry](../../images/esp32/arduino_ide/esp32_menu_entry.jpg) | select *Boards* |

Now select the ESP32 Dev Module in *Tools -> Board*.

| IDE | ESP32 Dev Module |
| --- | --- | 
| ![select_board](../../images/esp32/arduino_ide/select_board.jpg) | select *ESP32 Dev Module* | 
