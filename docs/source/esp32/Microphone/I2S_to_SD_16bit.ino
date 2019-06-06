/******************************************************************
Project     : I2S_to_SD_16bit
Board       : MAKERFACTORY EBB ESP32
Version     : 1.0
Date        : 21.03.2019
Author      : MHS

Description : This example shows how data are read from an I2S microphone and stored on a microSD card as .wav file.

Connect the following pins (with Female to Female connectors or Jumpers)

MICROPHONE  J305
MICROPHONE  J306
MICROPHONE  J306
MICROPHONE  J307

C:J307  ->  J308
- Pin1  ->  Pin1
- Pin2  ->  Pin2
- Pin3  ->  Pin3

C:J305  ->  J306
- Pin1  ->  Pin1
- Pin2  ->  Pin2
- Pin3  ->  Pin3

C...Connector
1...topmost
3...bottommost

MICROPHONE  SW301 all   ON  

SD CARD     SW406 all   ON
                
MENU        SW401 Pin2  ON
                  Pin3  ON

This example is adapted from:
- Darren Yates - 11 April 2014
    - Project #18 - Digital Audio Recorder v2.0
    - APC magazine - Arduino Masterclass
******************************************************************/

#include "i2s.h"  //  https://github.com/espressif/esp-idf/blob/master/components/driver/include/driver/i2s.h
#include <mySD.h> //  https://github.com/nhatuan84/esp32-micro-sdcard
#include <SPI.h>


#define SAMPLE_RATE 16000 //higher frequencies causes problems that have not been solved yet
#define SAMPLE_SIZE I2S_BITS_PER_SAMPLE_32BIT  //24 bit 2'complement packet into a 32 bit frame

#define CS 13
#define CLK 14
#define MISO 34
#define MOSI 15

static const i2s_port_t i2s_num = I2S_NUM_0; // i2s port number

//Configure struct for the input via I2S
static const i2s_config_t i2s_config = {
  .mode = static_cast<i2s_mode_t>(I2S_MODE_MASTER | I2S_MODE_RX),
  .sample_rate = SAMPLE_RATE,
  .bits_per_sample = SAMPLE_SIZE,
  .channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT,
  .communication_format = static_cast<i2s_comm_format_t>(I2S_COMM_FORMAT_I2S | I2S_COMM_FORMAT_I2S_MSB),
  .intr_alloc_flags = ESP_INTR_FLAG_LEVEL1, // default interrupt priority
  .dma_buf_count = 8,
  .dma_buf_len = 64,
  .use_apll = true,
};

//Pins used for the input of the I2S signal
static const i2s_pin_config_t pin_config = {
  .bck_io_num = 17,
  .ws_io_num = 18,
  .data_out_num = -1, //Configuration of the current pin will not be changed
  .data_in_num = 5
};

File file;

unsigned long fileSize = 0L;
unsigned long waveChunk = 16L;
unsigned int waveType = 1;
unsigned int numChannels = 2;   //confirmed
unsigned int bitsPerSample = 16;   //confirmed
unsigned long sample_rate = SAMPLE_RATE;
unsigned long bytesPerSec = sample_rate * numChannels * bitsPerSample / 8;   //confirmed
unsigned int blockAlign = numChannels * bitsPerSample / 8;    //confirmed
unsigned long dataSize = 0L;
unsigned long recSamples = 0L;
unsigned long recBytes = 0L;
byte byte1, byte2, byte3, byte4;
const int ledStart = 32;  //GPIO pin for the LED next to the SD card slot
int recPressed = 0;
const int btnStart = 25;  //GPIO pin for the "Start recording" button
const int btnStop = 26;  //GPIO pin for the "Stop recording" button
int dloop = 0;  //consecutive number for multiple recordings after each other

void writeWavHeader(char* filename) // write out original WAV header to file
{ 
  file = SD.open(filename, FILE_WRITE);
  file.write("RIFF");                                                               //"RIFF" chunck descriptor
  byte1 = fileSize & 0xff;                                                          //ChunckSize byte 1                   (little endian)
  byte2 = (fileSize >> 8) & 0xff;                                                   //ChucnkSize byte 2                   (little endian)
  byte3 = (fileSize >> 16) & 0xff;                                                  //ChucnkSize byte 3                   (little endian)
  byte4 = (fileSize >> 24) & 0xff;                                                  //ChucnkSize byte 4                   (little endian)
  file.write(byte1);  file.write(byte2);  file.write(byte3);  file.write(byte4);    //Write ChunkSize
  file.write("WAVE");                                                               //Format (4 bytes)                    (big endian)
  file.write("fmt ");                                                               //Subchunck1 ID                       (big endian)
  byte1 = waveChunk & 0xff;                                                         //Subchunk1 Size byte 1               (little endian)
  byte2 = (waveChunk >> 8) & 0xff;                                                  //Subchunk1 Size byte 2               (little endian)
  byte3 = (waveChunk >> 16) & 0xff;                                                 //Subchunk1 Size byte 3               (little endian)
  byte4 = (waveChunk >> 24) & 0xff;                                                 //Subchunk1 Size byte 4               (little endian)
  file.write(byte1); file.write(byte2);  file.write(byte3);  file.write(byte4);     //Write Subchunk1 Size (4 bytes)  
  byte1 = waveType & 0xff;                                                          //AudioFormat byte 1                  (little endian)
  byte2 = (waveType >> 8) & 0xff;                                                   //AudioFormat byte 2                  (little endian)
  file.write(byte1);  file.write(byte2);                                            //Write AudioFormat (2 bytes)
  byte1 = numChannels & 0xff;                                                       //Number of Channels byte 1           (little endian)
  byte2 = (numChannels >> 8) & 0xff;                                                //Number of Channels byte 2           (little endian)
  file.write(byte1); file.write(byte2);                                             //Write Number of Channels (2 bytes)
  byte1 = sample_rate & 0xff;                                                        //SampleRate byte 1                   (little endian)
  byte2 = (sample_rate >> 8) & 0xff;                                                 //SampleRate byte 2                   (little endian)
  byte3 = (sample_rate >> 16) & 0xff;                                                //SampleRate byte 3                   (little endian)
  byte4 = (sample_rate >> 24) & 0xff;                                                //SampleRate byte 4                   (little endian)
  file.write(byte1); file.write(byte2);  file.write(byte3); file.write(byte4);      //Write SampleRate (4 bytes)
  byte1 = bytesPerSec & 0xff;                                                       //ByteRate byte 1                     (little endian) 
  byte2 = (bytesPerSec >> 8) & 0xff;                                                //ByteRate byte 2                     (little endian)
  byte3 = (bytesPerSec >> 16) & 0xff;                                               //ByteRate byte 3                     (little endian)
  byte4 = (bytesPerSec >> 24) & 0xff;                                               //ByteRate byte 4                     (little endian)
  file.write(byte1);  file.write(byte2); file.write(byte3);  file.write(byte4);     //Write ByteRate (4 bytes)
  byte1 = blockAlign & 0xff;                                                        //BlockAllign byte 1                  (little endian)
  byte2 = (blockAlign >> 8) & 0xff;                                                 //BlockAllign byte 2                  (little endian)
  file.write(byte1); file.write(byte2);                                             //Write BlockAllign (2 bytes)
  byte1 = bitsPerSample & 0xff;                                                     //BitsPerSample byte 1                (little endian)
  byte2 = (bitsPerSample >> 8) & 0xff;                                              //BitsPerSample byte 2                (little endian)
  file.write(byte1);  file.write(byte2);                                            //Write BitsPerSample (2 bytes)
  file.write("data");                                                               //Subchunck2 ID                       (big endian)
  byte1 = dataSize & 0xff;                                                          //Subchunck2 Size byte 1              (little endian)
  byte2 = (dataSize >> 8) & 0xff;                                                   //Subchunck2 Size byte 2              (little endian)
  byte3 = (dataSize >> 16) & 0xff;                                                  //Subchunck2 Size byte 3              (little endian)
  byte4 = (dataSize >> 24) & 0xff;                                                  //Subchunck2 Size byte 4              (little endian)
  file.write(byte1); file.write(byte2);  file.write(byte3);  file.write(byte4);     //Write Subchunck2 Size (4 bytes)
  //Serial.println("Header written.");
}

void StopRec()  // stop recording process, update WAV header, close file
{ 
  writeOutHeader();
  digitalWrite(ledStart,LOW); // turn off recording LED
  recPressed = 0;
}

void writeOutHeader() // update WAV header with final filesize/datasize
{
  recBytes = numChannels*recSamples*bitsPerSample/8;
  if (recSamples % 2)
  {
    //If the chunk size is an odd number of bytes, a pad byte with value is written at the end of file.
    byte1 = 0;
    file.write(byte1);
    recBytes++;
  }

  dataSize = 36 + recBytes;
  file.seek(4);
  byte1 = dataSize & 0xff;
  byte2 = (dataSize >> 8) & 0xff;
  byte3 = (dataSize >> 16) & 0xff;
  byte4 = (dataSize >> 24) & 0xff;
  file.write(byte1);  file.write(byte2);  file.write(byte3);  file.write(byte4);
  byte1 = recBytes & 0xff;
  byte2 = (recBytes >> 8) & 0xff;
  byte3 = (recBytes >> 16) & 0xff;
  byte4 = (recBytes >> 24) & 0xff;
  file.seek(40);
  file.write(byte1);  file.write(byte2);  file.write(byte3);  file.write(byte4);
  file.close();
  //Serial.println("Header updated");
}

void getNewFile()  //create a new file and check if the name already exists
{
  char filename[15] = {'\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0'};
  for (int dloop = 0; dloop < 10000; dloop++) 
  {
    sprintf(filename, "rec%d.wav\0", dloop);
    if (!SD.exists(filename)) 
    {
      writeWavHeader(filename);
      break;
    }
  }
}

void StartRec() // begin recording process
{ 
  digitalWrite(ledStart,HIGH);
  recSamples = 0;
  dataSize = 0;  
  recPressed = 1; // recording button has been pressed
  getNewFile();
}

void setup() 
{
  //Serial.begin(9600);
  delay(5000);

  if (!SD.begin(CS, MOSI, MISO, CLK)) 
  {
    return;
  }

  pinMode(ledStart, OUTPUT);
  pinMode(btnStart, INPUT_PULLUP);
  pinMode(btnStop, INPUT_PULLUP);
  
  i2s_driver_install(i2s_num, &i2s_config, 0, NULL);   //install and start i2s driver for input
  
  //Configure the pins for I2S
  i2s_set_pin(i2s_num, &pin_config);  
  
  //Set the sample rate of the audio signal
  i2s_set_sample_rates(i2s_num, SAMPLE_RATE); //set sample rates

}

void loop() 
{
  // put your main code here, to run repeatedly:
  size_t read_lenght = 0;
  size_t size_ = 4;   //data is always packed into a 32 bit frame; additional bits are force to 0 by hardware
  int32_t data_sample;
  byte byte_array[512];
    
  if (digitalRead(btnStart) == LOW && recPressed == 0) 
  {
    StartRec(); //Start recording audio
    delay(10);
    i2s_zero_dma_buffer(i2s_num);
   
    while(1)
    {
      for (int i = 0; i < 512; i+=2)
      {
        read_lenght = 0;
        i2s_read(i2s_num, &data_sample, size_, &read_lenght, portMAX_DELAY);  //read the input of the microphone
        byte_array[i] = ((data_sample & 0x00ff0000) >> 16) & 0xff;
        byte_array[i+1] = ((data_sample & 0xff000000) >> 24) & 0xff; 
        recSamples++;
      }

      file.write(byte_array, 512);
      
      //Stop recording audio
      if (digitalRead(btnStop) == LOW && recPressed == 1)
      {
        StopRec(); // launch StopRec method
        break;
      }
    }
  }

}
