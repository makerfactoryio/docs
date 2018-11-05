#include "SPI.h"
#include "ssd1306.h"
#include "ssd1306spibus.h"
#include "mbed_wait_api.h"

using mbed::SPI;

constexpr size_t OLED_WIDTH = 128;
constexpr size_t OLED_HEIGHT = 32;

int main(int argc, char **argv)
{
    SPI spi(OLED_MOSI, OLED_DC, OLED_CLK);
    Ssd1306SPIBus spiBus(spi, OLED_RESET, OLED_CS, OLED_DC);
    Ssd1306 oled(spiBus, OLED_WIDTH, OLED_HEIGHT);

    while(1)
    {
        oled.clear();
        oled.printf(FontSize::BIG,
                    0, // X offset in pixels
                    0, // Y offset in pixels
                    "SensorIO");
        wait(2);
        oled.scrollUp();
        wait(2);
        oled.stopScroll();
        oled.invert();
        wait(2);
        oled.clear();
        wait(2);
    }
}
