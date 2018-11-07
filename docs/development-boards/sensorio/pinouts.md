#Board Pinouts

The MCU PinNames mappings are described here [PortName_Bit]. When available, the alternate functions are described.

!!! tip
	For the mbed platform, the pin mappings are done in the SensorIO target (**mbed-os/targets/TARGET_STM/TARGET_STM32F4/TARGET_STM32F413xH/TARGET_SENSORIO/PinNames.h**) 

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

#### Micro-SD / MMC

PinName | Signal Name | Description / Alternative functions
------------ | ------------- | ------------
PC_8  | MMC_D0    | MMC Data 0
PC_9  | MMC_D1    | MMC Data 1
PC_10 | MMC_D2    | MMC Data 2 
PC_11 | MMC_D3/CD | MMC Data 3 / Card Detect
PC_12 | MMC_CLK   | MMC bus clock
PD_2 | MMC_CMD    | MMC command / data

#### CC3120 WiFi

PinName | Signal Name | Description / Alternative functions
------------ | ------------- | ------------
PE_8  | CC_NRESET    | CC3120 #Reset
PE_9  | CC_IRQ    | CC3120 Interrupt
PE_10 | CC_RESTORE    | Ext.Flash Factory Restore 
PA_4 | CC_SPI_CS | SPI1_NSS (Chip Select)
PA_5 | CC_SPI_CLK  | SPI1 Clock
PA_6 | CC_SPI_MISO    | SPI1 MISO
PA_7 | CC_SPI_MOSI    | SPI1 MOSI


## Expansion interfaces

### MikroBUS

!!! info
	The I2C (I2C1) and SPI (SPI5) buses are shared by both connectors (but not with other interfaces). 

	This should be taken in account if these pins want to be used as digital IN/OUT (in this case, only one MikroBUS interface should be used).

#### MB1

PinName | Signal Name | Description / Alternative functions
------------ | ------------- | ------------
PB_6 | MB_I2C_SCL | I2C1 Clock (shared with MB2)
PB_7 | MB_I2C_SDA | I2C1 Data (shared with MB2)
PE_12 | MB_SPI_SCK | SPI5 Clock (shared with MB2)
PE_13 | MB_SPI_MISO | SPI5 MISO (shared with MB2)
PE_14 | MB_SPI_MOSI | SPI5 MOSI (shared with MB2)
PB_1 | MB1_SPI_CS | SPI Chip Select / PWM / AnalogIn (ADC1_IN9)
PG_14 | MB1_RST | Reset / UART6_TX
PD_0 | MB2_INT | IRQ (InterruptIn) / UART4_RX / CAN1_RX
PC_1 | MB1_AN | AnalogIn (ADC1_IN11) 
PB_14 | MB1_PWM | PWM out
PF_6 | MB1_UART_RX | UART7 RXD / PWM
PF_7 | MB1_UART_TX | UART7 TXD / PWM


#### MB2

PinName | Signal Name | Description / Alternative functions
------------ | ------------- | ------------
PB_6 | MB_I2C_SCL | I2C1 clock (shared with MB1)
PB_7 | MB_I2C_SDA | I2C1 data (shared with MB1)
PE_12 | MB_SPI_SCK | SPI5 Clock (shared with MB1)
PE_13 | MB_SPI_MISO | SPI5 MISO (shared with MB1)
PE_14 | MB_SPI_MOSI | SPI5 MOSI (shared with MB1)
PE_11 | MB2_SPI_CS | SPI Chip Select / PWM 
PG_15 | MB2_RST | Reset / I/O
PC_6 | MB2_INT | IRQ (InterruptIn) / PWM / I2C_SCL / I2S2_MCK / USART6_TX
PC_2 | MB2_AN | AnalogIn (ADC1_IN12) 
PB_15 | MB2_PWM | PWM out / I2S2_SD
PB_12 | MB2_UART_RX | UART5 RXD / I2S2_CK / CAN2_RX
PB_13 | MB2_UART_TX | UART5 TXD / PWM / I2S2_CK / CAN2_TX

### Grove

!!! info
	This interface multiplexes the UART, I2C, Analog and PWM lines to the external connectors. Please check the [Grove description](../interfaces#grove-connectors) for information on how to configure them.

#### Grove 1

PinName | Signal Name | Description / Alternative functions
------------ | ------------- | ------------
**I2C:**
PF_14 | I2CFMP1_SCL | I2C Clock (shared with Grove 2)
PF_15 | I2CFMP1_SDA | I2C Data (shared with Grove 2)
**UART:**
PE_0 | GROVE1_RXD | UART8_RX 
PE_1 | GROVE1_TXD | UART8_TX
**Analog:**
PC_3 | GROVE1_AI1 | Pin#1 Analog Input (ADC1_IN13)
PC_4 | GROVE1_AI2 | Pin#2 Analog Input (ADC1_IN14)
**PWM / I/O:**
PD_14 | GROVE1_P1_PWM | Pin#1 PWM out
PD_15 | GROVE1_P2_PWM | Pin#2 PWM out
**Multiplexer & Power control**
PD_10 | GROVE1_MUXA | [Multiplexer pin A](../interfaces#grove-connectors)
PD_11 | GROVE1_MUXB | [Multiplexer pin B](../interfaces#grove-connectors)
PG_9 | GROVE1_SW_5V | VCC control switch


#### Grove 2

PinName | Signal Name | Description / Alternative functions
------------ | ------------- | ------------
**I2C:**
PF_14 | I2CFMP1_SCL | I2C Clock (shared with Grove 1)
PF_15 | I2CFMP1_SDA | I2C Data (shared with Grove 1)
**UART:**
PG_0 | GROVE2_RXD | UART9_RX 
PG_1 | GROVE2_TXD | UART9_TX
**Analog:**
PB_0 | GROVE2_AI1 | Pin#1 Analog Input (ADC1_IN8)
PC_5 | GROVE2_AI2 | Pin#2 Analog Input (ADC1_IN15)
**PWM / I/O:**
PD_12 | GROVE2_P1_PWM | Pin#1 PWM out
PD_13 | GROVE2_P2_PWM | Pin#2 PWM out
**Multiplexer & Power control**
PG_4 | GROVE1_MUXA | [Multiplexer pin A](../interfaces#grove-connectors)
PG_5 | GROVE1_MUXB | [Multiplexer pin B](../interfaces#grove-connectors)
PG_10 | GROVE1_SW_5V | VCC control switch



### Arduino R3

!!! info
	This interface uses an analog multiplexer for the Analog Inputs A0 to A5. Check the [Arduino interface](../interfaces##arduino-r3-socket) for more information.


PinName | Signal Name | Description / Alternative functions
------------ | ------------- | ------------
PB_4 (1) | ARD_A4/SDA | I2C3_SDA / PWM / UART7_TX / CAN3_TX
PA_8 (1) | ARD_A5/SCL | I2C3_SCL / PWM / UART7_TX / CAN3_RX
PA_1 | ARD_D0/RX | UART4_RX / PWM / ADC1_IN1
PA_0 | ARD_D1/TX | UART4_TX / PWM / ADC1_IN0
PF_9 | ARD_D2 | UART8_RX / PWM
PA_2 | ARD_D3 | PWM (TIM9_CH1)
PF_10 | ARD_D4 | PWM (TIM5_CH4)
PA_2 | ARD_D5 | PWM (TIM9_CH2) / UART2_TX / I2S2_CKIN / ADC1_IN2
PB_10 | ARD_D6 | PWM (TIM2_CH3) / I2S3_MCK / USART3_TX
PF_11 | ARD_D7 | I/O
PF_12 | ARD_D8 | I/O
PB_10 | ARD_D9 | PWM (TIM2_CH4) / I2S3_MCK
PA_11 | ARD_D10/CS | SPI2_NSS (Chip Select) / PWM / CAN1_RX / UART6_TX
PA_10 | ARD_D11/MOSI | SPI2_MOSI / PWM / UART1_RX
PA_12 | ARD_D12/MISO | SPI2_MISO / UART6_RX/ CAN1_TX/ UART4_RX
PC_0 | ARD_ANALOG_IN | Analog inputs [A0:A5] + Calib LOW/HIGH
**Analog Multiplexer control**
PG_6 | ARD_MUX_A | Analog Multiplexer pin A
PG_7 | ARD_MUX_B | Analog Multiplexer pin B
PG_8 | ARD_MUX_C | Analog Multiplexer pin C

!!! note
	(1) In the Arduino UNO R3 interface, pins A4 is shared with D14 and A5 is shared with D15. Therefore, if these pins are to be used as Analog Inputs, the correspondent I2C pins PB_4 and PA_8 need to be configured as Input (high-impedance, default behaviour).