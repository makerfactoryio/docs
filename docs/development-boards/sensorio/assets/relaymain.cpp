#include "mbed_events.h"
#include "DigitalOut.h"
#include "InterruptIn.h"
#include "Serial.h"

mbed::Serial console(SERIAL_TX, SERIAL_RX, 115200);
events::EventQueue scheduler;
mbed::DigitalOut relay(RELAY_1);

void relayStatus(int status)
{
    console.printf("Relay is %s\r\n", (status == 1) ? "ON" : "OFF");
}

void buttonPressed()
{
    // toggle relay state
    relay = !relay;

    // log relay state via Serial (via EventLoop)
    scheduler.call(&relayStatus, relay);
}

int main(int argc, char **argv)
{
    mbed::InterruptIn button(USER_BUTTON);
    // attach function to button press
    button.fall(&buttonPressed);

    console.printf("This is SensorIO\r\n");
    // running event loop
    scheduler.dispatch_forever();
}
