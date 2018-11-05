#Board Pinouts

The MCU PinNames mappings are listed here [PortName_Bit]. When available, the alternate functions are described.
## OnBoard interfaces

#### RGB LED

PinName | Signal Name | Description / Alternative functions
------------ | ------------- | ------------
PF_3 | RED_LED  | DigitalOut / TIM5_CH1 (PWM)
PF_4 | GREEN_LED  | DigitalOut / TIM5_CH2 (PWM)
PF_5 | BLUE_LED  | DigitalOut / TIM5_CH3 (PWM)

#### User Button

PinName | Signal Name | Description / Alternative functions
------------ | ------------- | ------------
PC_13 | BUTTON_1  | DigitalIn / InterruptIn


#### Relays

PinName | Signal Name | Description / Alternative functions
------------ | ------------- | ------------
PG_2 | RELAY_1  | DigitalOut
PG_3 | RELAY_2  | DigitalOut

#### Sensors

PinName | Signal Name | Description / Alternative functions
------------ | ------------- | ------------
PF_0 | I2C_SDA  | Sensors I2C data line
PF_1 | I2C_SCL  | Sensors I2C clock line
PD_4 | ACCEL_INT1 | BMA253 IRQ #1
PD_5 | ACCEL_INT2 | BMA253 IRQ #2
PG_13 | LTR303_INT | Luminosity sensor IRQ

#### OLED display

PinName | Signal Name | Description / Alternative functions
------------ | ------------- | ------------
PE_6 | OLED_MOSI  | SPI4 data
PE_2 | OLED_SCK  | SPI4 clock
PE_5 | OLED_D/C# | Data / #command
PE_3 | OLED_RESET | Display reset line
PE_4 | OLED_CS | SPI4 Chip Select

#### MicroSD / MMC

PinName | Signal Name | Description / Alternative functions
------------ | ------------- | ------------
PC_8  | MMC_D0    | MMC Data 0
PC_9  | MMC_D1    | MMC Data 1
PC_10 | MMC_D2    | MMC Data 2 
PC_11 | MMC_D3/CD | MMC Data 3 / Card Detect
PC_12 | MMC_CLK   | MMC clock
PD_2 | MMC_CMD    | MMC command

#### CC3210 WiFi

PinName | Signal Name | Description / Alternative functions
------------ | ------------- | ------------
PE_8  | CC_NRESET    | CC3120 #Reset
PE_9  | CC_IRQ    | CC3120 Interrupt
PE_10 | CC_RESTORE    | Ext.Flash Factory Restore 
PA_4 | CC_SPI_CS | SPI1_NSS (Chip Select)
PA_5 | CC_SPI_CLK  | SPI1 Clock
PA_6 | CC_SPI_MISO    | SPI1 MISO
PA_7 | CC_SPI_MOSI    | SPI1 MOSI


## External interfaces

### MikroBUS

#### MB1

PinName | Signal Name | Description / Alternative functions
------------ | ------------- | ------------


#### MB2

PinName | Signal Name | Description / Alternative functions
------------ | ------------- | ------------


### Grove

#### Grove 1

PinName | Signal Name | Description / Alternative functions
------------ | ------------- | ------------


#### Grove 2

PinName | Signal Name | Description / Alternative functions
------------ | ------------- | ------------


### Arduino R3

PinName | Signal Name | Description / Alternative functions
------------ | ------------- | ------------

