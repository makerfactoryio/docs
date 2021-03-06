/******************************************************************
Created with PROGRAMINO IDE for Arduino
Project     : Maker-Factory ESP32 Board
Libraries   : 
Author      : UlliS

Description : Read the MPU9250

Copyright (c) 2018 Conrad Electronic SE.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.


******************************************************************/

#include <Wire.h>

#define SDA 19
#define SCL 4

#define    MPU9250_ADDRESS            0x68
#define    MAG_ADDRESS                0x0C

#define    GYRO_FULL_SCALE_250_DPS    0x00  
#define    GYRO_FULL_SCALE_500_DPS    0x08
#define    GYRO_FULL_SCALE_1000_DPS   0x10
#define    GYRO_FULL_SCALE_2000_DPS   0x18

#define    ACC_FULL_SCALE_2_G        0x00  
#define    ACC_FULL_SCALE_4_G        0x08
#define    ACC_FULL_SCALE_8_G        0x10
#define    ACC_FULL_SCALE_16_G       0x18



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



// Initial time
long int ti;
volatile bool intFlag=false;

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
}

// Main loop, read and display data
void loop()
{
    
    // Display time
    Serial.print (millis()-ti,DEC);
    Serial.print ("\t");

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
    
    // Display values
    
    // Accelerometer
    Serial.print ("aX: ");
    Serial.print (ax,DEC); 
    Serial.print ("\t");
    Serial.print ("aY: ");
    Serial.print (ay,DEC);
    Serial.print ("\t");
    Serial.print ("aZ: ");
    Serial.print (az,DEC);  
    Serial.print ("\t");
    
    // Gyroscope
    Serial.print ("gX: ");
    Serial.print (gx,DEC); 
    Serial.print ("\t");
    Serial.print ("gY: ");
    Serial.print (gy,DEC);
    Serial.print ("\t");
    Serial.print ("gZ: ");
    Serial.print (gz,DEC);  
    Serial.print ("\t");
    
    
    // _____________________
    // :::  Magnetometer ::: 
    
    
    // Read register Status 1 and wait for the DRDY: Data Ready
    
    uint8_t ST1;
    do
    {
        I2Cread(MAG_ADDRESS,0x02,1,&ST1);
    }
    while (!(ST1&0x01));
    
    // Read magnetometer data  
    uint8_t Mag[7];  
    I2Cread(MAG_ADDRESS,0x03,7,Mag);
    
    
    // Create 16 bits values from 8 bits data
    
    // Magnetometer
    int16_t mx = -(Mag[3]<<8 | Mag[2]);
    int16_t my = -(Mag[1]<<8 | Mag[0]);
    int16_t mz = -(Mag[5]<<8 | Mag[4]);
    
    
    // Magnetometer
    Serial.print("mX: ");
    Serial.print(mx+200,DEC); 
    Serial.print("\t");
    Serial.print("mY: ");
    Serial.print(my-70,DEC);
    Serial.print("\t");
    Serial.print("mZ: ");
    Serial.print(mz-700,DEC);  
    Serial.print("\t");
    
    // End of line
    Serial.println("");
    delay(100);    
}









