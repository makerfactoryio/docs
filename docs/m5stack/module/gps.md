# GPS

<div markdown="span" class="float-container text-center">
  <div markdown="span" class="pull-left" style="width: 50%">
<img src="/images/m5stack/product_pics/module/module_gps_01.jpg">
  </div>
  <div markdown="span" class="pull-left" style="width: 50%">
<img src="/images/m5stack/product_pics/module/module_gps_02.jpg">
  </div>
</div>

## Description

GPS is a module built in small GPS module. The small GPS
module named UBLOX NEO-M8N. You can program it through Blockly, Arduino
or MicroPython after connected to any series of M5Stack Core.

GPS module is built on the high performing u-blox M8 GNSS engine and
exhibit high performance and high sensitivity.And it can supply your
global positioning information even you in the wild and get lost.

> **The M5Stack Fire** uses GPIO16 / 17 to connect to PSRAM by default, it overlaps with TXD / RXD (GPIO16, GPIO17) of GPS module. Therefore, when using the GPS module from the M5Stack Fire, it is necessary to cut the TXD and RXD default patterns on the GPS module with a cutter and connect them to another port using solder or 0Ω resistance.

## Feature

-  GPS NEO-M8N Module
-  high-performance
-  high-sensitivity
-  Concurrent reception of up to 3 GNSS
-  Industry leading –167 dBm navigation sensitivity

## Include

-  1x M5Stack GPS Module
-  1x M5Stack Antenna

## Application

-  Child positioning bracelet
-  Logistics Tracking Management based on GPS

## Related Link

- **[Offical Video](https://www.youtube.com/channel/UCozgFVglWYQXbvTmGyS739w)**

- **[Forum](http://forum.m5stack.com/)**

-  **[GPS Info](https://www.u-blox.com/zh/product/neo-m8-series)** (GPS)

- **[TinyGPS++ library](http://arduiniana.org/libraries/tinygpsplus/)**

## Example

### Arduino IDE

*If you want the complete code `GPSRaw.ino`, please click [here](https://github.com/m5stack/M5-ProductExampleCodes/tree/master/Module/GPS/Arduino).*

```arduino
#include <M5Stack.h>

/* By default, GPS is connected with M5Core through UART2 */
HardwareSerial GPSRaw(2);

void setup() {
  M5.begin();
  GPSRaw.begin(9600);// GPS init
  Serial.println("hello");
  termInit();
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()) {
    int ch = Serial.read();
    GPSRaw.write(ch);
  }
  if(GPSRaw.available()) {
    int ch = GPSRaw.read();// read GPS information
    Serial.write(ch);
    termPutchar(ch);
  }
}
```

After burnt the example code `GPSRaw.ino`, m5core and PC serial terminal will display following information

```
$GPGSA,A,1,,,,,,,,,,,,,25.5,25.5,25.5*02
$BDGSA,A,1,,,,,,,,,,,,,25.5,25.5,25.5*13
$GPGSV,1,1,00*79
$BDGSV,1,1,00*68
$GNRMC,,V,,,,,,,,,,M*4E
$GNVTG,,,,,,,,,M*2D
$GNZDA,,,,,,*56
$GPTXT,01,01,01,ANTENNA OPEN*25
```

## Schematic

<img src="/images/m5stack/product_pics/module/gps_sch.png">
