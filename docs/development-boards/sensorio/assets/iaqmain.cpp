#include "mbed_bme680.h"
#include "I2C.h"
#include "Serial.h"
#include "Timer.h"
#include "airqualityestimator.h"
#include "mbed_wait_api.h"

const uint8_t BME680_I2C_ADDR = 0x76 << 1;

mbed::Serial console(SERIAL_TX, SERIAL_RX, 115200);

const char* QUALITY_TEXT[] =
{
    "GOOD ",
    "AVG  ",
    "LOW  ",
    "POOR ",
    "BAD  ",
    "V.BAD",
    "N/A  "
};

const char* airQualityToText(float iaq)
{
    // all categories from BME680 datasheet
    // good
    if(iaq >= 0.0f && iaq < 50.0f)
    {
        return QUALITY_TEXT[0];
    }
    // average
    else if(iaq >= 50.0f && iaq < 100.0f)
    {
        return QUALITY_TEXT[1];
    }
    // little bad
    else if(iaq >= 100.0f && iaq < 150.0f)
    {
        return QUALITY_TEXT[2];
    }
    // bad
    else if(iaq >= 150.0f && iaq < 200.0f)
    {
        return QUALITY_TEXT[3];
    }
    // worse
    else if(iaq >= 200.0f && iaq < 300.0f)
    {
        return QUALITY_TEXT[4];
    }
    // very bad
    else if(iaq >= 300.0f && iaq < 501.0f)
    {
        return QUALITY_TEXT[5];
    }
    else
    {
        return QUALITY_TEXT[6];
    }
}

const char* ACCURACY_TEXT[] =
{
    "UNKNOWN         ",
    "UNRELIABLE      ",
    "LOW_ACCURACY    ",
    "MEDIUM_ACCURACY ",
    "HIGH_ACCURACY   "
};

const char* airQualityAccuracyToText(uint8_t accuracy)
{
    const char* text = ACCURACY_TEXT[0];
    switch(accuracy)
    {
        case 0:
            text = ACCURACY_TEXT[1];
            break;
        case 1:
            text = ACCURACY_TEXT[2];
            break;
        case 2:
            text = ACCURACY_TEXT[3];
            break;
        case 3:
            text = ACCURACY_TEXT[4];
            break;
        default:
            break;
    }

    return text;
}

int main(int argc, char **argv)
{
    console.printf("This is SensorIO\r\n");

    mbed::I2C i2c(SENSORS_SDA, SENSORS_SCL);
    BME680 sensor(i2c, BME680_I2C_ADDR);

    sensor.begin();

    AirQualityEstimator airQuality(sensor);
    AirQualityEstimator::Results results;

    // start time reference
    mbed::Timer tickSource;
    tickSource.start();

    while(1)
    {
        const volatile us_timestamp_t timeStamp = tickSource.read_high_resolution_us();
        const volatile int64_t nextStepAt = airQuality.get(results, timeStamp);

        // \u00B0 is Unicode Character 'DEGREE SIGN'
        console.printf("IAQ: %3.0f - %s / %s Temp: %3.2f \u00B0C Humidity: %2.2f %%, Pressure: %4.2f hPA, VOC resistance: %4.4f kOhm\r\n",
                       results.airQuality,
                       airQualityToText(results.airQuality),
                       airQualityAccuracyToText(results.airQualityAccuracy),
                       results.temp,
                       results.humidity,
                       results.rawPressure/100.0f,
                       results.rawGas/1000.0f);

        volatile us_timestamp_t currTim = tickSource.read_high_resolution_us();
        us_timestamp_t timeDiff = (nextStepAt - (currTim * 1000))/1000;

        wait_ms(timeDiff/1000);
    }
}
