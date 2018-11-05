#pragma once

#include "PwmOut.h"
#include <cmath>

class RGBLed
{

static constexpr float REFRESH_RATE = 0.001; // in seconds

public:
    RGBLed(PinName _r, PinName _g, PinName _b)
        : red(_r),
          green(_g),
          blue(_b)
    {
        red.period(REFRESH_RATE);
        green.period(REFRESH_RATE);
        blue.period(REFRESH_RATE);
    }

    void set(uint8_t r, uint8_t g, uint8_t b)
    {
        // RGB is from 0 to 255, PWM pulsewidth is float 0-1
        constexpr float RGB_2_PERIOD = 0.00392156862745098 * REFRESH_RATE;

        red.pulsewidth(RGB_2_PERIOD * static_cast<float>(r));
        green.pulsewidth(RGB_2_PERIOD * static_cast<float>(g));
        blue.pulsewidth(RGB_2_PERIOD * static_cast<float>(b));
    }

    void set(float h, float s, float v)
    {
        float r, g, b;
        HSVtoRGB(&r, &g, &b, h, s, v);
        set(static_cast<uint8_t>(r * 255),
            static_cast<uint8_t>(g * 255),
            static_cast<uint8_t>(b * 255));
    }

    void HSVtoRGB(float *r, float *g, float *b, float h, float s, float v )
    {
        int i;
        float f, p, q, t;
        if( s == 0 ) {
            // achromatic (grey)
            *r = *g = *b = v;
            return;
        }
        h /= 60;            // sector 0 to 5
        i = std::floor( h );
        f = h - i;          // factorial part of h
        p = v * ( 1 - s );
        q = v * ( 1 - s * f );
        t = v * ( 1 - s * ( 1 - f ) );
        switch( i ) {
            case 0:
                *r = v;
                *g = t;
                *b = p;
                break;
            case 1:
                *r = q;
                *g = v;
                *b = p;
                break;
            case 2:
                *r = p;
                *g = v;
                *b = t;
                break;
            case 3:
                *r = p;
                *g = q;
                *b = v;
                break;
            case 4:
                *r = t;
                *g = p;
                *b = v;
                break;
            default:        // case 5:
                *r = v;
                *g = p;
                *b = q;
                break;
        }
    }

private:
    mbed::PwmOut red;
    mbed::PwmOut green;
    mbed::PwmOut blue;
};
