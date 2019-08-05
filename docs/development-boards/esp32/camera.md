## Overview
The component **camera** allows the connection of a camera chip of type OV7670. 
OV7670 is a camera module with FiFo supporting 640x480 VGA. 
The PIN description is listed at the backside of the board.

!!! example
    There is one example project for the Arduino IDE which can be downloaded: 
    **Camera_Webserver.ino** ([download here](../../source/esp32/Camera/Camera_Webserver.zip))
    
ESP Board | camera connector
--- | ---
<img src="/images/esp32/block_camera.png"  width="15%"> | SW400,SW402,SW403

## Activating the component
The component has three dip switches for controlling the component: *SW400*, *SW402* and *SW403*.

|Function|SWITCH|IO port|Conflicts with|Remarks|
|------------------|----------|----------|----------|----------|
|RRST|SW403-1|17|**Microphone**, SW301-2, SCK; **mikroBus**, SW404-4, TX; **Unit-Bus**, SW201-2, CN212 - PIN 4; **Grove UART**, SW202-1, UART - RX; **Grove Digital4**, SW209-2, IO17
|WRST|SW403-2|16|**Audio**, SW306-1, SD_MODE; **mikroBus**, SW404-3, RX; **Unit-Bus**, SW201-1, CN212 - PIN 3; **Grove UART**, SW202-2, UART - TX
|OE|SW403-3|GND|-|
|WR/WEN|SW403-4|0|-|
|RCK/RCKL|SW402-1|4|**Gyro**, SW310-4, SCL/SCLK; **OLED**, SW309-1, SCL; **SD Card**, SW406-3, DAT1; **Unit-Bus**, SW200-1, CN212 - PIN 6; **Grove I2C**, SW203-2, I2C - SCL
|D0|SW402-2|13|**mikroBus**, SW405-5, RST; **SD Card**, SW406-1, CD/DAT3; **Grove Digital2**, SW207-2, IO13
|D1|SW402-3|12|**RFID**, SW303-2, IRQ; **Gyro**, SW310-2, AD0/SD0; **mirkoBus**, SW404-1, PWM; **SD Card**, SW406-2, DAT2; **Grove Digital1**, SW206-1, IO12
|D2|SW402-3|14|**Gyro**, SW310-1, INT; **mikroBus**, SW404-2, INT; **SD Card**, SW406-5, CLK; **Grove Digital2**, SW207-1, IO14
|D3|SW402-5|27|**Menu**, SW401-4, CENTER; **SD Card**, SW407-2, CDET
|D4|SW402-6|26|**Audio**, SW306-2, BCKL; **Menu**, SW401-3, LEFT
|D5|SW400-1|25|**Audio**, SW306-3, LRCLK; **Menu**, SW401-2, DOWN
|D6|SW400-2|35|**Temperature**, SW315, DQ; **Grove Analog2**, SW205-2, ADC7
|D7|SW400-3|34|**Menu**, SW401-6, UP; **Grove Analog2**, SW205-1, ADC6
|VSYNC|SW400-4|32|**Menu**, SW401-5, RIGHT; **SD Card**, SW407-1, LED
|SIOD/SDA|SW400-5|21|**mikroBus**, SW404-6, SDA; **Grove Digital3**, SW208-1, IO21
|SIOC/SCL|SW400-6|22|**RFID**, SW303-1, RST; **Audio**, SW306-4, IO22; **mikroBus**, SW404-5, SCL

## Using the component


## Sample project
There is one example project for the Arduino IDE which can be downloaded: 
    **Camera_Webserver.ino** ([download here](../../source/esp32/Camera/Camera_Webserver.zip))
