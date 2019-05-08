/******************************************************************
Project     : I2S_to_SD_16bit
Board       : MAKERFACTORY EBB ESP32
Version     : 1.0
Date        : 21.03.2019
Author      : MHS

Description : This example shows how data are read from an I2S microphone and is played back via the on board audio amplifier.

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

Requirements:
  - Connect a speaker to the connector J300.

Switches:
AUDIO AMPLIFIER SW306 all   ON 
MICROPHONE      SW301 all   ON

******************************************************************/

#include "i2s.h"  //  https://github.com/espressif/esp-idf/blob/master/components/driver/include/driver/i2s.h

#define SAMPLE_RATE 16000
#define SAMPLE_SIZE I2S_BITS_PER_SAMPLE_32BIT

static const i2s_port_t i2s_num_in = I2S_NUM_0; // i2s port number
static const i2s_port_t i2s_num_out = I2S_NUM_1; // i2s port number

//Configure struct for the input via I2S
static const i2s_config_t i2s_config_in = {
  .mode = static_cast<i2s_mode_t>(I2S_MODE_MASTER | I2S_MODE_RX),
  .sample_rate = SAMPLE_RATE,
  .bits_per_sample = SAMPLE_SIZE,
  .channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT,
  .communication_format = static_cast<i2s_comm_format_t>(I2S_COMM_FORMAT_I2S | I2S_COMM_FORMAT_I2S_MSB),
  .intr_alloc_flags = ESP_INTR_FLAG_LEVEL1, // default interrupt priority
  .dma_buf_count = 8,
  .dma_buf_len = 64,
  .use_apll = false,
};

//Configure struct for the output via I2S
static const i2s_config_t i2s_config_out = {
  .mode = static_cast<i2s_mode_t>(I2S_MODE_MASTER | I2S_MODE_TX),
  .sample_rate = SAMPLE_RATE,
  .bits_per_sample = SAMPLE_SIZE,
  .channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT,
  .communication_format = static_cast<i2s_comm_format_t>(I2S_COMM_FORMAT_I2S | I2S_COMM_FORMAT_I2S_MSB),
  .intr_alloc_flags = ESP_INTR_FLAG_LEVEL1, // default interrupt priority
  .dma_buf_count = 8,
  .dma_buf_len = 64,
  .use_apll = false,
};

//Pins used for the input of the I2S signal
static const i2s_pin_config_t pin_config_in = {
  .bck_io_num = 17,
  .ws_io_num = 18,
  .data_out_num = -1, //Configuration of the current pin will not be changed
  .data_in_num = 5
};

//Pins used for the output of the I2S signal
static const i2s_pin_config_t pin_config_out = {
  .bck_io_num = 26,
  .ws_io_num = 25,
  .data_out_num = 22,
  .data_in_num = -1 //Configuration of the current pin will not be changed
};

void setup ()
{
  i2s_driver_install(i2s_num_in, &i2s_config_in, 0, NULL);   //install and start i2s driver for input
  i2s_driver_install(i2s_num_out, &i2s_config_out, 0, NULL);   //install and start i2s driver for output

  //Configure the pins for I2S
  i2s_set_pin(i2s_num_in, &pin_config_in);
  i2s_set_pin(i2s_num_out, &pin_config_out);

  //Enable Audio Amplifier
  pinMode(16, OUTPUT);
  digitalWrite(16, HIGH);

  //Set the sample rate of the audio signal
  i2s_set_sample_rates(i2s_num_in, SAMPLE_RATE); //set sample rates
  //i2s_set_clk(i2s_num_in, SAMPLE_RATE, SAMPLE_SIZE, I2S_CHANNEL_STEREO);  //set sample rate and bit width
}

void loop ()
{
  int data_sample;
  size_t read_lenght = 0;
  size_t write_lenght = 0;

  i2s_read(i2s_num_in, &data_sample, 8, &read_lenght, 5);
  i2s_write(i2s_num_out, &data_sample, 8, &write_lenght, 5);
}
