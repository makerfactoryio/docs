/******************************************************************
Created with PROGRAMINO IDE for Arduino
Project     : MPU9250 IMU and RGB LEDs
Board       : MAKERFACTORY EBB ESP32
Version     : 1.0
Date        : 28.12.2018
Author      : MF

Description : Read the I2C MPU9250 IMU and change the WS2813 RGB colors

Switches:
I2C PULL-UP                 SW307 ON
I2C PULL-UP                 SW308 ON
GYRO+ACCELEROMETER+COMPASS  SW310 3,4 ON
RGB LED                     SW312 ON

Original IMU code from:
https://bitbucket.org/cinqlair/
******************************************************************/

#include <Wire.h>

#include <Adafruit_NeoPixel.h> // https://github.com/adafruit/Adafruit_NeoPixel

// LED data pin
#define PIN            2

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      4

#define SDA 19
#define SCL 4

#define    MPU9250_ADDRESS            0x68
#define    MAG_ADDRESS                0x0C

#define    GYRO_FULL_SCALE_250_DPS    0x00  
#define    GYRO_FULL_SCALE_500_DPS    0x08
#define    GYRO_FULL_SCALE_1000_DPS   0x10
#define    GYRO_FULL_SCALE_2000_DPS   0x18

#define    ACC_FULL_SCALE_2_G         0x00  
#define    ACC_FULL_SCALE_4_G         0x08
#define    ACC_FULL_SCALE_8_G         0x10
#define    ACC_FULL_SCALE_16_G        0x18

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.
int rVar = 0;
int gVar = 0;
int bVar = 0;

// Initial time
long int ti;
volatile bool intFlag=false;

// This function read Nbytes bytes from I2C device at address Address. 
// Put read bytes starting at register Register in the Data array. 
void I2Cread(uint8_t Address, uint8_t Register, uint8_t Nbytes, uint8_t* Data)
{
    // Set register address
    Wire.beginTransmission(Address);
    Wire.write(Register);
    Wire.endTransmission();
    
    // Read Nbytes
    Wire.requestFrom(Address, Nbytes); 
    uint8_t index = 0;
    while (Wire.available())
        Data[index++]=Wire.read();
}


// Write a byte (Data) in device (Address) at register (Register)
void I2CwriteByte(uint8_t Address, uint8_t Register, uint8_t Data)
{
    // Set register address
    Wire.beginTransmission(Address);
    Wire.write(Register);
    Wire.write(Data);
    Wire.endTransmission();
}


// Initializations
void setup()
{
    // Arduino initializations
    Wire.begin(SDA,SCL);
    Serial.begin(115200);
    
    // Set accelerometers low pass filter at 5Hz
    I2CwriteByte(MPU9250_ADDRESS,29,0x06);
    // Set gyroscope low pass filter at 5Hz
    I2CwriteByte(MPU9250_ADDRESS,26,0x06);
    
    
    // Configure gyroscope range
    I2CwriteByte(MPU9250_ADDRESS,27,GYRO_FULL_SCALE_1000_DPS);
    // Configure accelerometers range
    I2CwriteByte(MPU9250_ADDRESS,28,ACC_FULL_SCALE_4_G);
    // Set by pass mode for the magnetometers
    I2CwriteByte(MPU9250_ADDRESS,0x37,0x02);
    
    // Request continuous magnetometer measurements in 16 bits
    I2CwriteByte(MAG_ADDRESS,0x0A,0x16);
    
    // Store initial time
    ti = millis();
    
    Serial.println("MPU9250");
    
    pixels.begin(); // This initializes the NeoPixel library
    pixels.show();  // Initialize all pixels to 'off' 
    
}

// Main loop, read and display data
void loop()
{
    
    // ____________________________________
    // :::  accelerometer and gyroscope ::: 
    
    // Read accelerometer and gyroscope
    uint8_t Buf[14];
    I2Cread(MPU9250_ADDRESS,0x3B,14,Buf);
    
    // Create 16 bits values from 8 bits data
    
    // Accelerometer
    int16_t ax = -(Buf[0]<<8 | Buf[1]);
    int16_t ay = -(Buf[2]<<8 | Buf[3]);
    int16_t az = Buf[4]<<8 | Buf[5];
    
    // Gyroscope
    int16_t gx = -(Buf[8]<<8 | Buf[9]);
    int16_t gy = -(Buf[10]<<8 | Buf[11]);
    int16_t gz = Buf[12]<<8 | Buf[13];
    
    // Accelerometer
    Serial.println ("aX: ");
    Serial.println (ax,DEC); 
    Serial.println ("\t");
    Serial.println ("aY: ");
    Serial.println (ay,DEC);
    Serial.println ("\t");
    Serial.println ("aZ: ");
    Serial.println (az,DEC);  
    Serial.println ("\t");
    
    for (int i=0;i<NUMPIXELS;i++)
    {
        
        int color  = map(ay,-8500,8500,0,1023);    // color
        int bright = map(ax,-8500,8500,15,100);     // brightness
        
        if (color < 10)
        {                  
            rVar = 255;
            gVar = 255;
            bVar = 255;
        }
        else if (color >= 20 && color < 341)
        {
            color = (color * 3 / 4);     
            
            rVar = 255 - color;         
            gVar = color;           
            bVar = 0;               
        }
        else if (color >= 341 && color < 682)    
        {
            color = ((color-341) * 3 / 4);
            
            rVar = 0;               
            gVar = 255 - color;      
            bVar = color;           
        }
        else                        
        {
            color = ((color-683) * 3 / 4); 
            
            rVar = color;               
            gVar = 0;                   
            bVar = 255 - color;     
        }
        
        rVar = rVar * bright / 100; 
        gVar = gVar * bright / 100;
        bVar = bVar * bright / 100;
        
        // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
        pixels.setPixelColor(i, pixels.Color(rVar,gVar,bVar)); 
        pixels.show(); // This sends the updated pixel color to the hardware.
        delay(20);
    }
 
    delay(50);     
}
