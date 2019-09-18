#include "mbed_events.h"
#include "Serial.h"
#include "ltr303.h"

mbed::Serial console(USBTX, USBRX, 115200);
mbed::I2C iic(SENSORS_SDA, SENSORS_SCL);
mbed::InterruptIn irq(LTR303_INT, PinMode::PullUp);
events::EventQueue scheduler;

Ltr303 sensor(iic, irq);

void measDone(float);

// callback from driver in separate execution context
void dataCallback(float result)
{
    scheduler.call_in(500, measDone, result);
}

// executor in this context
void measDone(float result)
{
    console.printf("Light sensor output: %5.3f lux.\n", result);
    // request next measurement
    sensor.get(dataCallback);
}

int main(int argc, char **argv)
{
    console.printf("This is SensorIO\r\n");

    // schedule first measurement, it will chain next in callback
    sensor.get(dataCallback);

    // running event loop
    scheduler.dispatch_forever();
}
