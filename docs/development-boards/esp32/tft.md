## Overview
The development board supports a 2.8 inch TFT display with a resolution of 240*320 pixels.The display is not soldered on the board, but there is a 14 pin connector for a TFT display. The ILI9341 has been tested.

!!! example
    There are four sample projects for the Arduino IDE which could be downloaded: **TFT-Box3D** ([download here](../../source/esp32/TFT-Box3D/TFT-Box3D.ino)), **TFT-Graphic-Test** ([download here](../../source/esp32/TFT-Graphic-Test/TFT-Graphic-Test.ino)), **TFT-HelloWorld** ([download here](../../source/esp32/TFT-HelloWorld/TFT-HelloWorld.ino)) and **TFT-HowToUseFonts** ([download here](../../source/esp32/TFT-HowToUseFonts/TFT-HowToUseFonts.ino)).  
And there are two examples for the Arduino IDE for using the touch functionality which could be downloaded: **TFT-TouchBtn** ([download here](../../source/esp32/TFT-TouchBtn/TFT-TouchBtn.ino)) and **TFT-TouchDraw** ([download here](../../source/esp32/TFT-TouchDraw/TFT-TouchDraw.ino)). 

ESP Board | TFT
--- | ---
<img src="/images/esp32/block_tft.png"  width="30%"> | SW311,SW314

## Activating the component
There are two dip switches for the component: *SW311* and *SW314*. If you want to use the TFT display all switches on *SW311* have to be on on. If you additonally want to use the touchpad of the display all switch of *SW314* have to be on. The following two tables shows the functions and the potential conflicts with other components

### SW311

All switches of *SW311* have to be activated in order to use the display.

Function|SWITCH|IO port|Conflicts with|Remarks|
|------------------|----------|----------|----------|----------|
|CS|1|2|**RGB LED**, SW312, DIN; **SD Card**, SW406-4, DAT0
|RESET|2|5|**Micropohne**, SW301-1, SD; **RFID**, SW303-6, SDA; **Grove Digital1**, SW206-2, IO5
|D/C|3|15|**SD Card**, SW406-6, CMD; **Grove Digital3**, SW208-2, IO15
|MOSI|4|23|**RFID**, SW303-4, MOSI; **Motor Driver**, SW304-2, STEP; **TFT**, SW314-4, T_DIN; **mikroBus**, SW405-1, MOSI
|SCK|5|18|**TFT**, SW314-2, T_CLK; **mikroBus**, SW405-3, SCK; **Grove Digital4**, IO18, IO18
|LED|6|**VCC**|-


### SW314

All switches of *SW311* and *SW314* have to be activated in order to use the display with the **touchpad**.

Function|SWITCH|IO port|Conflicts with|Remarks|
|------------------|----------|----------|----------|----------|
|MISO|1|19|**RFID**, SW303-3, MISO; **Gyro**, SW310-3, SDA/SDI; **OLED**, SW309-2, SDA; **mikroBus**, SW405-2, MISO; **Unit-Bus**, SW200-2, CN212 - PIN 5; **Grove I2C**, SW203-1, S2C - SDA
|T_CLK|2|18|**TFT**, SW311-5, SCK; **mikroBus**, SW405-3, SCK; **Grove Digital4**, IO18, IO18
|T_CS|3|GND|-
|T_DIN|4|23|**RFID**, SW303-4, MOSI; **Motor Driver**, SW304-2, STEP; **TFT**, SW311-4, MOSI; **mikroBus**, SW405-1, MOSI
|T_DO|5|33|**Motor Driver**, SW304-1, DIR; **RGB**, SW313, DIN; **mikroBus**, SW405-6, AN
|T_IRQ|6|not connected (NC)|-

## Using the component

!!! Info
    **Required libraries**

    In order to use the component you need the Ucglib in Version 1.5.2. This version could be downloaded from [GitHub](). Additionally you could [download](../../source/esp32/TFT-HelloWorld/Ucglib_Arduino-1.5.2) from this site..
    After the download it's necessary to add both libraries to your Arduino IDE. Open *Sketch > Include Library > Add .ZIP Library ...* and select the downloaded archive. Do it for both libraries.

    After a sucessful installation the menu *Sketch > Include Library* should contain an entry *Ucglib* in the category *Contributed libraries*.

### Including necessary libaries

```c
  #include <Ucglib.h>
```

### Definition the appropriate constructor

```c
  Ucglib_ILI9341_18x240x320_HWSPI ucg(/*cd=*/5, /*cs=*/33, /*reset=*/17);
```

### Configuration

```c
void setup(void)
{
  delay(1000);
  ucg.begin(UCG_FONT_MODE_TRANSPARENT);
  ucg.clearScreen();
}
```

### Writing on the display

```c
void loop(void)
{
  ucg.setFont(ucg_font_ncenR12_tr);
  ucg.setColor(255, 255, 255);
  ucg.setColor(1, 255, 0,0);

  ucg.setPrintPos(0,25);
  ucg.print("Hello World!");


  delay(500);
}
```


## Sample project
There are four sample projects for the Arduino IDE which could be downloaded: **TFT-Box3D** ([download here](../../source/esp32/TFT-Box3D/TFT-Box3D.ino)), **TFT-Graphic-Test** ([download here](../../source/esp32/TFT-Graphic-Test/TFT-Graphic-Test.ino)), **TFT-HelloWorld** ([download here](../../source/esp32/TFT-HelloWorld/TFT-HelloWorld.ino)) and **TFT-HowToUseFonts** ([download here](../../source/esp32/TFT-HowToUseFonts/TFT-HowToUseFonts.ino)).  
And there are two examples for the Arduino IDE for using the touch functionality which could be downloaded: **TFT-TouchBtn** ([download here](../../source/esp32/TFT-TouchBtn/TFT-TouchBtn.ino)) and **TFT-TouchDraw** ([download here](../../source/esp32/TFT-TouchDraw/TFT-TouchDraw.ino)). 
