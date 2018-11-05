#include "mbed_events.h"
#include "InterruptIn.h"
#include "Serial.h"
#include "rgbled.h"
#include "Ticker.h"

mbed::Serial console(SERIAL_TX, SERIAL_RX, 115200);
events::EventQueue scheduler;
mbed::Ticker tickColor;

RGBLed rgb(RGB_RED, RGB_GREEN, RGB_BLUE);
bool ledOn = false;

// Color toggling with HSV palette
float h = 0.0f;
float s = 0.75f;
float v = 0.005f;

void changeColor()
{
    if(ledOn)
    {
        rgb.set(h, s, v);
        h += 0.44f;

        if(h > 360.0f)
        {
            h = 0.0f;
        }
    }
    else
    {
        rgb.set(0.0f, 0.0f, 0.0f);
    }
}

void scheduleColorChange()
{
    scheduler.call(&changeColor);
}

void rgbLedStatus(int status)
{
    console.printf("RGB Led is %s\r\n", (status == 1) ? "ON" : "OFF");
}

void buttonPressed()
{
    // toggle RGB Led state
    ledOn = !ledOn;

    // log RGB Led state via Serial (via EventLoop)
    scheduler.call(&rgbLedStatus, ledOn);
}

int main(int argc, char **argv)
{
    mbed::InterruptIn button(USER_BUTTON);
    // attach function to button press
    button.fall(&buttonPressed);

    tickColor.attach(&scheduleColorChange, 1.0f/60.0f);

    console.printf("This is SensorIO\r\n");
    // running event loop
    scheduler.dispatch_forever();
}
