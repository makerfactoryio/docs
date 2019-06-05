/******************************************************************
Created with PROGRAMINO IDE for Arduino
Project     : DS18B20 and TFT temperature display
Board       : MAKERFACTORY EBB ESP32
Version     : 1.0
Date        : 28.12.2018
Author      : MF

Description : show temperature of DS18B20 at TFT.

Switches:
TFT   SW311 all ON

******************************************************************/
#include <OneWire.h>
#include "images.h"
#include <SPI.h>
#include <Ucglib.h> // https://github.com/olikraus/Ucglib_Arduino

// TFT
// https://github.com/olikraus/ucglib/wiki/reference#font-mode-ucg_font_mode_solid
Ucglib_ILI9341_18x240x320_HWSPI ucg(5, 33, 17);

// DS18B20+
OneWire  ds(16);  // on pin 10 (a 4.7K resistor is necessary)

void setup()
{
    // TFT
    ucg.begin(UCG_FONT_MODE_TRANSPARENT);
    ucg.setFont(ucg_font_ncenR14_hr);
    ucg.setRotate90();
    ucg.clearScreen();
    
    ucg.setColor(0, 255, 255, 255);
    ucg.setPrintDir(0);
    ucg.setPrintPos(64,40);
    
    ucg.print("MAKERFACTORY");    
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
    ds.write(0x44, 1);          // start conversion, with parasite power on at the end
    
    delay(1000);                // maybe 750ms is enough, maybe not
    // we might do a ds.depower() here, but the reset will take care of it.
    
    present = ds.reset();
    ds.select(addr);    
    ds.write(0xBE);             // Read Scratchpad
    
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
        //// default is 12 bit resolution, 750 ms conversion time
    }
    
    celsius    = (float)raw / 16.0;
    fahrenheit = celsius * 1.8 + 32.0;
    
    ucg.clearScreen();
    ucg.setColor(0, 255, 255, 255);
    ucg.setPrintDir(0);
    ucg.setPrintPos(64,90);
    
    ucg.print("Temperature"); 
    
    ucg.setPrintPos(64,120);
    ucg.print(String(celsius));
    
    ucg.setPrintPos(140,120);
    ucg.print("°C");
    
}
