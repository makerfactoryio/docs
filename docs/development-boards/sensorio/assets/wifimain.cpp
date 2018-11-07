#include "simplelinkinterface.h"
#include "Serial.h"
#include "SPI.h"
#include "UDPSocket.h"
#include "istdinout.h"
#include "mbed_wait_api.h"
#include "Thread.h"

mbed::Serial console(SERIAL_TX, SERIAL_RX, 115200);

uint8_t TASK_STACK[7168];
rtos::Thread wifiTask(osPriorityNormal, sizeof(TASK_STACK), TASK_STACK, "UdpSender");

const char WIFI_SSID[] = "";
const char WIFI_PASSWD[] = "";

const char SERVER[] = "";
const size_t PORT = 6789;

const uint8_t WIFI_CHANNEL_AUTO_SELECTION = 0;


void udpSender()
{
    mbed::SPI wifiSpi(CC_SPI_MOSI, CC_SPI_MISO, CC_SPI_CLK, CC_SPI_CS);
    IStdInOut devnull;
    SimpleLinkInterface wifi(wifiSpi, CC_NRESET, CC_SPI_CS, CC_IRQ, devnull);

    console.printf("WiFi interface up.\r\n");

    console.printf("Connecting to %s\r\n", WIFI_SSID);
    int connected = wifi.connect(WIFI_SSID, WIFI_PASSWD, NSAPI_SECURITY_WPA2, WIFI_CHANNEL_AUTO_SELECTION);
    console.printf("Connection %s\r\n", (connected == 0) ? "OK" : "FAILED");
    if(0 == connected)
    {
        UDPSocket socket(&wifi);

        SocketAddress address;
        nsapi_size_or_error_t error = wifi.gethostbyname(SERVER, &address);

        if(error)
        {
            console.printf("Socket connect fail - DNS failure\r\n");
            socket.close();
            return;
        }

        address.set_port(PORT);

        error = socket.connect(address);
        if(error)
        {
            console.printf("Socket connect fail - %d\r\n", error);
            socket.close();
            return;
        }

        console.printf("UDPSocket connected to %s:%d\r\n", SERVER, PORT);
        size_t packetNumber = 0;
        char data[255];

        while(1)
        {
            int length = std::snprintf(data, sizeof(data), "This is packet number %d\r\n", ++packetNumber);
            size_t sent = socket.sendto(address, data, length);
            console.printf("Sent %d bytes: %s\r\n", sent, data);
            wait(1.0f);
        }
    }
}

int main(int argc, char **argv)
{
    console.printf("This is SensorIO\r\n");

    wifiTask.start(&udpSender);
    wifiTask.join();
}
