#Onboard Sensors

SensorIO integrates 3 sensor modules which can be used to measure 6 physical variables.

## Bosch Sensortec BME680

The [BME680](https://ae-bst.resource.bosch.com/media/_tech/media/datasheets/BST-BME680-DS001-00.pdf) is a low power gas, pressure, temperature & humidity sensor.
This sensor module is a digital 4-in-1 sensor with gas, humidity, pressure and temperature measurement based on proven sensing principles. It's is housed in an extremely compact metal-lid LGA package with a footprint of 3.0 × 3.0 mm2 with a maximum height of 1.00 mm. 

<img src="/images/sensorio/BME680-render.png" class="img-center" width="30%">

The gas sensor within the BME680 can detect a broad range of gases to measure indoor air quality for personal well being. Gases that can be detected by the BME680 include: Volatile Organic Compounds (VOC) from paints (such as formaldehyde), lacquers, paint strippers, cleaning supplies, furnishings, office equipment, glues, adhesives and alcohol.

<img src="/images/sensorio/BME680.png" class="img-center" width="80%">

The module can be interfaced by SPI or I2C buses. In this case, the module is configured to use the I2C bus with the slave address **0x76**

!!! info "Temperature readings"
	Please note that, while the temperature sensor integrated on the BME680 has been optimized for very low noise and high resolution, it's primarily used for temperature compensation of the gas. Therefore, the measured temperature reflects the internal module temperature, which is higher than the ambient temperature since the module uses a very small heater for the gas measurement operation. Ambient temperature can be estimated with certain accuracy with the proper compensation and calibration.

## Bosch Sensortec BMA253

The [BMA253](https://ae-bst.resource.bosch.com/media/_tech/media/datasheets/BST-BMA253-DS000-01.pdf) is a triaxial, low-g acceleration sensor with digital output for consumer applications. It allows measurements of acceleration in three perpendicular axes. An evaluation circuitry (ASIC) converts the output of a micromechanical acceleration-sensing structure (MEMS) that works according to the differential capacitance principle.

<img src="/images/sensorio/BMA253.png" class="img-center" width="75%">

The sensor is interfaced via the I2C bus, and the slave address is **0x18**. The two interrupt lines (ACCEL_INT1 and ACCEL_INT2) can be configured independently for various motion triggers and asynchronous data readout.

## LiteOn LTR-303ALS

The [LTR-303ALS](https://www.mouser.com/ds/2/239/Lite-On_LTR-303ALS-01_DS_ver%201.1-1175269.pdf) is a light sensor with a spectral response close to the human eye, which it makes it useful for indoor luminosity control application. This sensor converts light intensity to a digital output signal and it provides a linear response over a wide dynamic range from 0.01 lux to 64k lux and is well suited to applications under high ambient brightness. To increase the usable dynamic range, is has six configurable gain settings (1X, 2X, 4X, 8X, 48X and 96X).


<img src="/images/sensorio/LTR303.png" class="img-center" width="65%">

The sensor is also interfaced through the I2C bus and the slave address is **0x29**. 

The sensor integrates two photodiodes (CH0 and CH1) which responses are combined to calculate the final luminosity value. This process is performed by the driver on the MCU.

The plot below shows the normalized response of both channels:
<img src="/images/sensorio/LTR303-spectralResponse.png" class="img-center" width="65%">

!!! tip "IRQ"
	The sensor supports an interrupt feature that removes the need to poll the sensor for a reading which improves system efficiency. 
	