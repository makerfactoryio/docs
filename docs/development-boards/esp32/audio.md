## Overview
The audio amplifier of the ESP board includes the MAX98357A, a digital 3W Class D Audio Amplifier. 
This amplifier provides an digital pulse-code modulation (PCM) input supporting I2S data and delivers a 3.2W output power into 4Ω (4 Ohms) at 5V. 
It accepts specified sample rates between 8kHz and 96kHz for all supported data formats. 
Connect your 4Ω speaker at connector J300 at P and N.

ESP Board | Audio Amplifier
--- | ---
<img src="/images/esp32/block_audio.png"  width="15%"> | SW306

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
An example project for the Arduino IDE can be found in the chapter for the microphone.
