#include "mbed_bme680.h"
#include "I2C.h"
#include "Serial.h"
#include "mbed_events.h"

const uint8_t BME680_I2C_ADDR = 0x76 << 1;

mbed::Serial console(SERIAL_TX, SERIAL_RX, 115200);
events::EventQueue scheduler;

void getMeasurements(BME680* sensor)
{
    if(sensor->performReading())
    {
        console.printf("Temp: %3.2f %cC Humidity: %2.2f %%, Pressure: %4.2f hPA, VOC resistance: %4.4f kOhm\r\n",
                       sensor->getTemperature(), 161,
                       sensor->getHumidity(),
                       sensor->getPressure()/100.0f,
                       sensor->getGasResistance()/1000.0f);
    }
    else
    {
        console.printf("Reading FAILED!\r\n");
    }
}

int main(int argc, char **argv)
{
    console.printf("This is SensorIO\r\n");

    mbed::I2C i2c(SENSORS_SDA, SENSORS_SCL);
    BME680 sensor(i2c, BME680_I2C_ADDR);

    sensor.begin();

    scheduler.call_every(1000, getMeasurements, &sensor);
    // running event loop
    scheduler.dispatch_forever();
}
