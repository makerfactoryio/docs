## Overview

The development board supports monochrome OLED displays with the SSD1306 driver. The display is not soldered on the board, but there is a four pin connector of a OLED display. The right image shows the component with connected display.

!!! example
    A sample project for the Arduino IDE is provided in **OLED_1.ino** which could be downloaded [here](../../source/esp32/OLED_1/OLED_1.ino)

<img src="/images/esp32/block_lcd.png"  width="24%"> <img src="/images/esp32/block_lcd_with_oled.png"  width="25%">

## Activating the component

The component has a dip switch *SW309*, which have to be activated in order to uhse the component. The component is connected to the following ports:

Function|SWITCH|IO port|Conflicts with|Remarks|
|------------------|----------|----------|----------|----------|
|SCL|1|4|**Gyro**, SW310-4, SCL/SCLK; **Camera**, SW402-1, RCK/RCKL; **SD Card**, SW200-1, CN212 - PIN 6; **Grove I2C**, SW203-2, I2C - SCL|I2C Pull-up by SW308
|SDA|2|19|**RFID**, SW310-3, MISO; **Gyro**, SW310-3, SDA/SDI; **TFT**, SW314-1, MSIO; **mikroBus**, SW405-2, MISO; **Unit-Bus**, SW200-2, CN212 - PIN 5; **Grove I2C**, SW203-1, I2C- SDA|I2C Pull-up by SW307

## Using the component

!!! Info
    **Required libraries**

    In order to use the component you need two libraries: Adafruit SSD1306 and Adafruit GFX library. The latest version of the Adafruit SSD1306 library could be downloaded from the [GitHub repository](https://github.com/adafruit/Adafruit_SSD1306). Additionally you could [download](../../source/esp32/OLED1/Adafruit_SSD1306-master.zip) a tested version.
    After the download it's necessary to add both libraries to your Arduino IDE. Open *Sketch > Include Library > Add .ZIP Library ...* and select the downloaded archive. Do it for both libraries. After a sucessful installation the menu *Sketch > Include Library* should contain an entry *Adafruit GFX library* and *Adafruit SSD 1306** in the category *Contributed libraries*.

### Import the necessary libraries
```c
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_SSD1306.h"
```

### Setup the display

Initialize with the I2C addr 0x3D (for the 128x64).

```c
void setup()   {
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
}
```

### Draw a Pixel

```c
display.clearDisplay();
display.drawPixel(10, 10, WHITE);
```

### Draw many lines

```c
void testdrawline() {
  for (int16_t i=0; i<display.width(); i+=4) {
    display.drawLine(0, 0, i, display.height()-1, WHITE);
    display.display();
    delay(1);
  }
  for (int16_t i=0; i<display.height(); i+=4) {
    display.drawLine(0, 0, display.width()-1, i, WHITE);
    display.display();
    delay(1);
  }
  delay(250);

  display.clearDisplay();
  for (int16_t i=0; i<display.width(); i+=4) {
    display.drawLine(0, display.height()-1, i, 0, WHITE);
    display.display();
    delay(1);
  }
  for (int16_t i=display.height()-1; i>=0; i-=4) {
    display.drawLine(0, display.height()-1, display.width()-1, i, WHITE);
    display.display();
    delay(1);
  }
  delay(250);

  display.clearDisplay();
  for (int16_t i=display.width()-1; i>=0; i-=4) {
    display.drawLine(display.width()-1, display.height()-1, i, 0, WHITE);
    display.display();
    delay(1);
  }
  for (int16_t i=display.height()-1; i>=0; i-=4) {
    display.drawLine(display.width()-1, display.height()-1, 0, i, WHITE);
    display.display();
    delay(1);
  }
  delay(250);

  display.clearDisplay();
  for (int16_t i=0; i<display.height(); i+=4) {
    display.drawLine(display.width()-1, 0, 0, i, WHITE);
    display.display();
    delay(1);
  }
  for (int16_t i=0; i<display.width(); i+=4) {
    display.drawLine(display.width()-1, 0, i, display.height()-1, WHITE);
    display.display();
    delay(1);
  }
  delay(250);
}
```

### Draw many lines

```c
void testscrolltext(void) {
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(10,0);
  display.clearDisplay();
  display.println("scroll");
  display.display();
  delay(1);

  display.startscrollright(0x00, 0x0F);
  delay(2000);
  display.stopscroll();
  delay(1000);
  display.startscrollleft(0x00, 0x0F);
  delay(2000);
  display.stopscroll();
  delay(1000);
  display.startscrolldiagright(0x00, 0x07);
  delay(2000);
  display.startscrolldiagleft(0x00, 0x07);
  delay(2000);
  display.stopscroll();
}
```
### Text display tests

```c
display.setTextSize(1);
display.setTextColor(WHITE);
display.setCursor(0,0);
display.println("Hello, world!");
display.setTextColor(BLACK, WHITE); // 'inverted' text
display.println(3.141592);
display.setTextSize(2);
display.setTextColor(WHITE);
display.print("0x"); display.println(0xDEADBEEF, HEX);
display.display();
delay(2000);
display.clearDisplay();
```

### Invert the display

```c
display.invertDisplay(true);
delay(1000);
display.invertDisplay(false);
delay(1000);
display.clearDisplay();
```

## Sample project

A sample project for the Arduino IDE is provided in **OLED_1.ino** which could be downloaded [here](../../source/esp32/OLED_1/OLED_1.ino). The following image shows the oled display with results from the sample project:

<img src="/images/esp32/oled_sample.png"  width="25%">
