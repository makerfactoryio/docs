Following pages contain detailed description and example usage of all SensorIO on-board peripherals and sensors from firmware perspective. All examples are based on Mbed OS and [SensorIO template project](./code-setup.md#using-template-repository).

## Peripherals

- [OLED display - SSD1306 128x32 pixels](./oled.md)
- [Relays - TLP241A](./relays.md)
- [RGB Led](./rgbled.md)
- [User button](./button.md)
- [Multiplexers for Grove and Arduino connectors](./multiplexers.md)
- [MicroSD Card](./sdcard.md)
- [WiFi - CC3120](./wifi.md)
- [Extension ports](./extension-ports.md)

## Sensors

!!! info "I2C"
    All on-board sensors are attached to the same I2C bus - `I2C2`. Pin names are defined as `SENSORS_SDA` and `SENSORS_SCL` (`PF_0` and `PF_1` accordingly).

- [Luminosity - LTR303-ALS](./ltr303.md)
- [Acceleration - BMA253](./bma253.md)
- [Environmental sensor - BME680](./bme680.md)

