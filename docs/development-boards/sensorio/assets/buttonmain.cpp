#include "mbed_events.h"
#include "DigitalOut.h"
#include "InterruptIn.h"
#include "Serial.h"

mbed::Serial console(SERIAL_TX, SERIAL_RX, 115200);
events::EventQueue scheduler;
mbed::DigitalOut green(RGB_GREEN);

void ledStatus(int status)
{
    console.printf("Green Led is %s\r\n", (status == 1) ? "ON" : "OFF");
}

void buttonPressed()
{
    // toggle led state
    green = !green;

    // log led state via Serial (via EventLoop)
    scheduler.call(&ledStatus, green);
}

int main(int argc, char **argv)
{
    console.printf("This is SensorIO\r\n");

    mbed::InterruptIn button(USER_BUTTON);
    // attach function to button press
    button.fall(&buttonPressed);

    // running event loop
    scheduler.dispatch_forever();
}
