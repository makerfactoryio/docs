/******************************************************************
Created with PROGRAMINO IDE for Arduino
Project     : DS18B20 and OLED temperature display
Board       : MAKERFACTORY EBB ESP32
Version     : 1.0
Date        : 28.12.2018
Author      : MF

Description : show temperature of DS18B20 at OLED.

Switches:
I2C PULL-UP  SW307 ON
I2C PULL-UP  SW308 ON
LCD          SW309 all ON
TEMP         SW315 ON

******************************************************************/
#include <OneWire.h> // http://www.pjrc.com/teensy/td_libs_OneWire.html
#include "SSD1306Wire.h" // https://github.com/ThingPulse/esp8266-oled-ssd1306
#include "images.h"

// OLED
SSD1306Wire  display(0x3c, 19, 4);

// DS18B20+
OneWire  ds(16);

void setup()
{
    // OLED
    display.init();
    display.flipScreenVertically();
    display.setFont(ArialMT_Plain_24);
    display.drawXbm(34, 14, WiFi_Logo_width, WiFi_Logo_height, WiFi_Logo_bits);
    
    display.setTextAlignment(TEXT_ALIGN_CENTER);
    display.setFont(ArialMT_Plain_10);
    display.drawString(64, 1, "MAKERFACTORY");
    
    display.setFont(ArialMT_Plain_10);
    display.drawString(64, 52, "EBB ESP32");
    
    // write the buffer to the display
    display.display();
    delay(1500);
}

void loop()
{
    byte i;
    byte present = 0;
    byte type_s;
    byte data[12];
    byte addr[8];
    float celsius, fahrenheit;
    
    if (!ds.search(addr))
    {
        ds.reset_search();
        delay(250);
        return;
    }
    
    ds.reset();
    ds.select(addr);
    ds.write(0x44, 1); // start conversion, with parasite power on at the end
    
    delay(1000); // maybe 750ms is enough, maybe not
    // we might do a ds.depower() here, but the reset will take care of it.
    
    present = ds.reset();
    ds.select(addr);    
    ds.write(0xBE); // Read Scratchpad
    
    // we need 9 bytes
    for (i = 0; i < 9; i++) 
    {  
        data[i] = ds.read();
    }
    
    // Convert the data to actual temperature
    // because the result is a 16 bit signed integer, it should
    // be stored to an "int16_t" type, which is always 16 bits
    // even when compiled on a 32 bit processor.
    int16_t raw = (data[1] << 8) | data[0];
    
    if (type_s) 
    {
        raw = raw << 3; // 9 bit resolution default
        if (data[7] == 0x10) 
        {
            // "count remain" gives full 12 bit resolution
            raw = (raw & 0xFFF0) + 12 - data[6];
        }
    } 
    else 
    {
        byte cfg = (data[4] & 0x60);
        // at lower res, the low bits are undefined, so let's zero them
        if (cfg == 0x00) raw = raw & ~7;  // 9 bit resolution, 93.75 ms
        else if (cfg == 0x20) raw = raw & ~3; // 10 bit res, 187.5 ms
        else if (cfg == 0x40) raw = raw & ~1; // 11 bit res, 375 ms
        // default is 12 bit resolution, 750 ms conversion time
    }
    
    celsius    = (float)raw / 16.0;
    fahrenheit = celsius * 1.8 + 32.0;
    
    // celsius
    display.clear();
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.setFont(ArialMT_Plain_16);
    display.drawString(0, 5, "Temperature");
    display.setFont(ArialMT_Plain_24);
    display.drawString(0, 30, String(celsius));
    display.drawString(65, 30, "°C");
    
    // write the buffer to the display
    display.display();
    delay(2000);
    
    // fahrenheit
    display.clear();
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.setFont(ArialMT_Plain_16);
    display.drawString(0, 5, "Temperature");
    display.setFont(ArialMT_Plain_24);
    display.drawString(0, 30, String(fahrenheit));
    display.drawString(65, 30, "°F");
    
    // write the buffer to the display
    display.display();
    delay(2000);
    
}
