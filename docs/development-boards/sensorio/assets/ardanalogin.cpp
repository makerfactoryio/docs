#include "DigitalOut.h"
#include "AnalogIn.h"
#include "Serial.h"

mbed::Serial console(SERIAL_TX, SERIAL_RX, 115200);

int main(int argc, char **argv)
{
    console.printf("This is SensorIO\r\n");

    mbed::DigitalOut ardMuxA(ARD_MUX_A);
    mbed::DigitalOut ardMuxB(ARD_MUX_B);
    mbed::DigitalOut ardMuxC(ARD_MUX_C);

    mbed::AnalogIn ardAnalogIn(ARD_ANALOG_IN);

    // select pin A3 with multiplexer
    ardMuxA = 0;
    ardMuxB = 1;
    ardMuxC = 1;

    // read value
    float analogValue = ardAnalogIn.read();

    console.printf("analogValue is %f\r\n", analogValue);
}
