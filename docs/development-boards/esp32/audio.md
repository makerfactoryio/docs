## Overview

<img src="/images/esp32/block_audio.png"  width="30%">

## Activating the component
The component has the dip switch *SW306* for activating the component.

|Function|SWITCH|IO port|Conflicts with|Remarks|
|------------------|----------|----------|----------|----------|
|SD_MODE|SW306-1|16|**mikroBus**, SW404-3, RX; **Camera**, SW403-2, WRST; **Unit-Bus**, SW201-1, CN212 - PIN 3; **Grove UART**, SW202-2, UART TX
|BCKL|SW306-2|26|**MENU**, SW401-3, LEFT; **Camera**, SW402-6, D4
|LRCLK|SW306-3|25|**MENU**, SW401-2, DOWN; **Camera**, SW400-1, D5
|DIN|SW306-4|22|**mikroBus**, SW404-5, SCL; **Camera**, SW400-6, SIOC/SCL

## Using the component


## Sample project
