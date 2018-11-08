## Overview

The component **MENU** has five switches which could be used for control tasks.

<img src="/images/esp32/block_menu.png"  width="30%">

## Activating the component
The component has a dip switch *SW401* for activating the buttons. Each of the five buttons is connected to one IO port. *Switch 1* is not connected and therefore the state of this switch is not relevant. The buttons are connected to the following ports

|Button|SWITCH|IO port|Conflicts with|
|------------------|----------|----------|----------|
|UP|6|34|**CAMERA**, SW400-3, D7; **GROVE, UART**, SW205-1, ADC6
|LEFT|3|26|**CAMERA**, SW402-6, D4; **Audio**, SW306-2, BCKL
|CENTER|4|27|**CAMERA**, SW402-5, D3; **SD CARD**, SW407-2, CDET
|RIGHT|5|32|**CAMERA**, SW400-4, VSYNC; **SD CARD**, SW407-1, LED
|DOWN|2|25|**CAMERA**, SW400-1, D5; **Audio**, SW306-3, LRCLK

