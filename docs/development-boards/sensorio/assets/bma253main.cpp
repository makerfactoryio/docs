#include "I2C.h"
#include "Serial.h"
#include "InterruptIn.h"
#include "DigitalOut.h"
#include "bma253.h"
#include "mbed_wait_api.h"

mbed::Serial log(USBTX, USBRX, 115200);
events::EventQueue scheduler;

constexpr uint8_t BMA253_I2C_ADDRESS = 0b0011000 << 1;

mbed::InterruptIn bma253Irq1(ACCEL_INT1);
mbed::InterruptIn bma253Irq2(ACCEL_INT2);
mbed::I2C iic(SENSORS_SDA, SENSORS_SCL);

Bma253 sensor(iic,
              BMA253_I2C_ADDRESS,
              {&bma253Irq1, &bma253Irq2});

void measDone(Bma253::Output& data);

// callback from driver in separate execution context
void dataCallback(Bma253::Output data)
{
    // not necessary if moving to main execution context is not needed
    scheduler.call(measDone, data);
}

// executor in this context
void measDone(Bma253::Output& data)
{
    log.printf("Accelerometer output:\r\n"
               "x = %f mg [new: %d]\r\n"
               "y = %f mg [new: %d]\r\n"
               "z = %f mg [new: %d]\r\n"
               "temp = %f C\r\n",
               data.x,
               data.newData[0],
               data.y,
               data.newData[1],
               data.z,
               data.newData[2],
               data.temp);
}

int main(int argc, char **argv)
{
    log.printf("Start\n");

    // enable sensor and configure interrupt to trigger on a new data available
    Bma253::Config accConfig;
    accConfig.attachCallback(Bma253::IrqLine::LINE_1, &dataCallback)
             .enableEvent(Bma253::IrqLine::LINE_1, Bma253::Event::NEW_DATA);

    const bool configOk = sensor.setConfig(accConfig);

    if(configOk)
    {
        log.printf("Sensor configured correctly\n");
        sensor.enable();
    }
    else
    {
        log.printf("Sensor configuration failed\n");
    }

    // running event loop
    scheduler.dispatch_forever();
}
