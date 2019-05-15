# RGB LED strip

The component **RGB LED** has **four** WS2813 RGB LEDs. The LEDs are connected to each other and therefore they could be handled like an LED strip.

!!! example
    An example project for the Arduino IDE is provided in **RGB-LED-HSV.ino** which could be downloaded [here](../../source/esp32/rgb-led-hsv/RGB-LED-HSV.ino)
    
ESP Board | RGB LED
--- | ---
<img src="/images/esp32/block_rgb_led.png"  width="30%"> | SW312,SW313

## USING THE COMPONENT

The four LEDs are labeled on the board. The first LED in the strip is the LED **D300** nearby the switches.

|Label on the board|LED number|
|------------------|:----------:|
|D300|0|
|D301|1|
|D302|2|
|D303|3|

## Hardware activation of the RGB LED strip

!!! Caution
    The LEDs are connected to **two** GPIO-Pins. In order to control the LEDs you have to activate one connection and have to deactivate the other connection. With the switch **SW313** you could active the connection to **IO 33** of the ESP32. With **SW312** you could active the connection to **IO 2** of the ESP32.

Activate the RGB LED on the board with either **SW313** or **SW312**.

## Preparing the IDE for using the LED strip

The LED strip could be programmed by using the [Adafruit Neopixel Library](https://github.com/adafruit/Adafruit_NeoPixel). This libray has to be installed in your Arduino IDE. The following steps are necessary:

1. Download the latest version of the Library from here [https://github.com/adafruit/Adafruit_NeoPixel/archive/master.zip](https://github.com/adafruit/Adafruit_NeoPixel/archive/master.zip)
2. Extract the the downloaded *master.zip* and rename the folder to *Adafruit_Neopixel*
3. Copy the complete folder to the libraries directory of your Arduino IDE.

!!! Info
    The library order is named *libraries* and could be found in Windows under **XXXXX** and in Mac OS X in *Documents/Arduino/libraries* in the user directory.

Now restart your Arduino IDE.
After a successful installation the examples of the library should occur in *File > Examples > Adafruit Neopixel*

ESP Board | RGB LED
--- | ---
<img src="/images/esp32/neopixel_1.png"  width="30%"> | Examples from the Neopixel libray

## Sample project

An example project for the Arduino IDE is provided in **RGB-LED-HSV.ino** which could be downloaded [here](../../source/esp32/rgb-led-hsv/RGB-LED-HSV.ino)
