/******************************************************************
Created with PROGRAMINO IDE for Arduino
Project     : MPU9250 IMU
Board       : MAKERFACTORY EBB ESP32
Version     : 1.0
Date        : 28.12.2018
Author      : MF

Description : Read the I2C MPU9250 IMU

Switches:
I2C PULL-UP                SW307 ON
I2C PULL-UP                SW308 ON
GYRO+ACCELEROMETER+COMPASS SW310 3,4 ON

Original from:
https://bitbucket.org/cinqlair/
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

#define    ACC_FULL_SCALE_2_G         0x00  
#define    ACC_FULL_SCALE_4_G         0x08
#define    ACC_FULL_SCALE_8_G         0x10
#define    ACC_FULL_SCALE_16_G        0x18

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
}

// Main loop, read and display data
void loop()
{
    
    // Display time
    Serial.println (millis()-ti,DEC);

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
    Serial.printf ("aX:%04d\n", ax);
    //Serial.print (ax,DEC); 
    //Serial.print ("\t");
    Serial.printf ("aY:%04d\n", ay);
    //Serial.print (ay,DEC);
    //Serial.print ("\t");
    Serial.printf ("aZ:%04d\n", az);
    //Serial.print (az,DEC);  
    //Serial.print ("\t");
    
    // Gyroscope
    Serial.printf ("gX:%04d\n", gx);
    //Serial.print (gx,DEC); 
    //Serial.print ("\t");
    Serial.printf ("gY:%04d\n", gy);
    //Serial.print (gy,DEC);
    //Serial.print ("\t");
    Serial.printf ("gZ:%04d\n", gz);
    //Serial.print (gz,DEC);  
    //Serial.print ("\t");
    
    
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
    Serial.printf("mX:%04d\n", mx+200);
    //Serial.print(mx+200,DEC); 
    //Serial.print("\t");
    Serial.printf("mY:%04d\n", my-70);
    //Serial.print(my-70,DEC);
    //Serial.print("\t");
    Serial.printf("mZ:%04d\n", mz-700);
    //Serial.print(mz-700,DEC);  
    //Serial.print("\t");
    
    // End of line
    Serial.println("");
    delay(100);    
}
