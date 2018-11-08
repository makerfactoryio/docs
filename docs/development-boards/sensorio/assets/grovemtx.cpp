#include "grovemultiplexer.h"
#include "grovetwomultiplexer.h"
#include "AnalogIn.h"
#include "Serial.h"

mbed::Serial console(SERIAL_TX, SERIAL_RX, 115200);

int main(int argc, char **argv)
{
    console.printf("This is SensorIO\r\n");

    // using generic Grove multiplexer class
    GroveMultiplexer grove1Multiplexer(GROVE1_MUX_A, GROVE1_MUX_B, GROVE1_SW_5V);
    // using SensorIO Grove 2 multiplexer class
    GroveTwoMultiplexer grove2Multiplexer;

    // select voltage (3.3V is default, so no need to change Grove 1)
    grove2Multiplexer.select(GroveMultiplexer::Voltage::VCC_5V);

    grove1Multiplexer.select(GroveMultiplexer::Mode::UART);
    grove2Multiplexer.select(GroveMultiplexer::Mode::ANALOG_IN);


    mbed::AnalogIn grove2AnalogIn(GROVE2_AI2);
    mbed::Serial grove1Uart(GROVE1_TX, GROVE1_RX, 9600);

    // read value
    float analogValue = grove2AnalogIn.read();
    console.printf("analogValue is %f\r\n", analogValue);

    // send data over Grove 1 UART
    grove1Uart.puts("From SensorIO to Grove");
}
