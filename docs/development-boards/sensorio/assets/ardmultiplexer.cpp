#include "arduinomultiplexer.h"
#include "AnalogIn.h"
#include "Serial.h"

mbed::Serial console(SERIAL_TX, SERIAL_RX, 115200);

int main(int argc, char **argv)
{
    console.printf("This is SensorIO\r\n");

    ArduinoMultiplexer multiplexer;
    mbed::AnalogIn ardAnalogIn(ARD_ANALOG_IN);

    // select pin A3 with multiplexer
    multiplexer.select(ArduinoMultiplexer::Input::SELECT_A3);

    // read value
    float analogValue = ardAnalogIn.read();

    console.printf("analogValue is %f\r\n", analogValue);
}
