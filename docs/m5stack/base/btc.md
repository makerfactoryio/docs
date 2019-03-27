# Loading Base

<div markdown="span" class="float-container text-center">
  <div markdown="span" class="pull-left" style="width: 50%">
<img src="/images/m5stack/product_pics/module/module_btc_01.jpg">
  </div>
  <div markdown="span" class="pull-left" style="width: 50%">
<img src="/images/m5stack/product_pics/module/module_btc_02.jpg">
  </div>
</div>

##  Description

**BTC** is a base including DHT12 module which can detect
temperature and humidity.

Your M5Stack Core board can stay as a small displayer(like a small TV or a small IOT central contronller) after adding this BTC Module.

**Note:**

* Although M5Core [BASIC](../../core/black) or [GRAY](../../core/gray) can be attached to this base, but BTC can not charge them. Actually, our Cores, as we know, are built in chargin chip (IP5306). After plugged a USB cable in, the Core was charging without any charger.

* Once M5Core has been attached to BTC, it can not controll ENV Unit at this time. Because BTC has been built in DHT12 sensor which will cause IIC address conflit.

## Feature

-  DHT12 inside

## Include

-  Type-C USB Cable
-  M3 x 16
-  Tools

<img src="/images/m5stack/product_pics/module/module_btc_04.jpg"><img src="/images/m5stack/product_pics/module/module_btc_03.jpg">

## PinMap

**DHT12**

<table>
 <tr><td>ESP32 Chip</td><td>GPIO22</td><td>GND</td><td>GPIO21</td><td>3V3</td></tr>
 <tr><td>DHT12</td><td>SCL</td><td>GND</td><td>SDA</td><td>3V3</td></tr>
</table>

<img src="/images/m5stack/product_pics/module/module_btc_dht12_pinmap.jpg">


## Related Link

- **[Offical Video](https://www.youtube.com/channel/UCozgFVglWYQXbvTmGyS739w)**

- **[Forum](http://forum.m5stack.com/)**

## Example

### Arduino IDE

*If you want the code `BTC.ino`, please click [here](https://github.com/m5stack/M5-ProductExampleCodes/tree/master/Base/BTC/Arduino).*

```arduino
#include <M5Stack.h>
#include "DHT12.h"
#include <Wire.h> //The DHT12 uses I2C comunication.

void setup() {
    M5.begin();
    Wire.begin();
    M5.Lcd.setBrightness(10);
    Serial.println(F("ENV Unit(DHT12 and BMP280) test..."));
}

void loop() {
    float tmp = dht12.readTemperature();
    float hum = dht12.readHumidity();
    Serial.printf("Temperatura: %2.2f*C  Humedad: %0.2f%%\r\n", tmp, hum);

    M5.Lcd.setCursor(0, 0);
    M5.Lcd.setTextColor(WHITE, BLACK);
    M5.Lcd.setTextSize(3);
    M5.Lcd.printf("Temp: %2.1f  \r\nHumi: %2.0f%%  \r\n", tmp, hum);

    delay(100);
}
```
