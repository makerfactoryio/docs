## Overview

The component **TEMPERATURE** has an Dallas DS18B20+ for measuring the temperature

!!! example
    An example project for the Arduino IDE is provided in **Temperature.ino** ([download here](../../source/esp32/Temperature/Temperature.ino)). In order to use the sample it is necessary to install the OneWire library which is described in the section [*Using the component*](../../#using-the-component)

ESP Board | temperature
--- | ---
<img src="/images/esp32/block_temperature.png"  width="30%"> | SW315

## Activating the component
The component has a dip switch *SW315* for activating the temperature sensor. The switch is connected to the following io ports:

|Function|SWITCH|IO port|Conflicts with|Remarks|
|------------------|----------|----------|----------|----------|
|DQ|1|16|**Audio**, SW306-1, SD_MODE; **mirkoBus**, SW404-3, RX; **Camera**, SW403-2, WRST; **Unit-Bus**, WS201-1, CN212 - PIN 3; **Grove UART**, SW202-2, UART TX


## Using the component

!!! Info
    **Required libraries**

    In order to use the component you need the OneWire-Library. The latest version could be download from the [GitHub repository](https://github.com/PaulStoffregen/OneWire). If you want to use the version from GitHub download a zip archiv. Addtionally you could [download](../../source/esp32/Temperature/OneWire-master.zip) a tested version. After the download it's necessary to add the library to your Arduino IDE. Open *Sketch > Include Library > Add .ZIP Library ...* and select the downloaded archive. After a successful installation the menu *Sketch > Include Library* should contain an entry *OneWire* in the category *Contributed libraries*.

### Import the necessary libraries

```c
#include <OneWire.h>
```

### Setup the component

For using the temperature sensor the library from Dallas is used. This library controls the sensor and will be configured on the io port 16:

```c
OneWire  ds(16);
```

!!! note
    In serveral examples in the Internet it's mentioned that a pull-up resistor for SDA is necessary. This resistor is already on the board. Therefore you need no additional pull-up resistor in order to use this component.
    <img src="/images/esp32/temperature_pull_up.jpg"  width="50%">

Beside the initialisation of the dallas library there is no special code in the *setup* method necessary:

```c
void setup(void) {
    Serial.begin(115200);
}
```
### Searching for the address on the bus

```c
byte i;
byte present = 0;
byte data[12];
byte addr[8];
float celsius, fahrenheit;

if ( !ds.search(addr)) {
    Serial.println("No more addresses");
    ds.reset_search();
    delay(250);
    return;
}

Serial.print("ROM =");
for( i = 0; i < 8; i++) {
    Serial.write(' ');
    Serial.print(addr[i], HEX);
}

if (OneWire::crc8(addr, 7) != addr[7]) {
    Serial.println("CRC is not valid!");
    return;
}
```

### Select the chip and read the data

```c
ds.reset();
ds.select(addr);
ds.write(0x44, 1);        // start conversion, with parasite power on at the end

delay(1000);     // maybe 750ms is enough, maybe not
// we might do a ds.depower() here, but the reset will take care of it.

present = ds.reset();
ds.select(addr);
ds.write(0xBE);         // Read Scratchpad

Serial.print("    Data = ");
Serial.print(present, HEX);
Serial.print(" ");
for ( i = 0; i < 9; i++) {           // we need 9 bytes
    data[i] = ds.read();
    Serial.print(data[i], HEX);
    Serial.print(" ");
}
Serial.print(" CRC=");
Serial.print(OneWire::crc8(data, 8), HEX);
Serial.println();
```

### Convert the data

```c
// Convert the data to actual temperature
// because the result is a 16 bit signed integer, it should
// be stored to an "int16_t" type, which is always 16 bits
// even when compiled on a 32 bit processor.
int16_t raw = (data[1] << 8) | data[0];
byte cfg = (data[4] & 0x60);
// at lower res, the low bits are undefined, so let's zero them
if (cfg == 0x00) raw = raw & ~7;  // 9 bit resolution, 93.75 ms
else if (cfg == 0x20) raw = raw & ~3; // 10 bit res, 187.5 ms
else if (cfg == 0x40) raw = raw & ~1; // 11 bit res, 375 ms
//// default is 12 bit resolution, 750 ms conversion time

celsius    = (float)raw / 16.0;
fahrenheit = celsius * 1.8 + 32.0;
```

## Sample project

A sample project for the Arduino IDE is provided in **Temperature.ino** [download here](../../source/esp32/Temperature/Temperature.ino). In order to use the sample it is necessary to install the OneWire library which is described in the section *Using the component*.
