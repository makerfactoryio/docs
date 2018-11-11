#Technical specifications

## Absolute maximum ratings

Parameter 	| Min | Typ	| Max | Unit
--------- |  --- | --- | ---- | ----
Supply Input Voltage (USB)	| -0.3	| -| +5.7 |	V
Supply Output Current - MikroBUS +5V | - | -	| 2.0 | A
Supply Output Current - MikroBUS +3.3V | - | -	| 2.0 | A
Supply Output Current - Arduino +5V | - | -	| 1.0 | A
Supply Output Current - Arduino +3.3V | - | -	| 2.0 | A
Supply Output Current - Grove Vcc output | - | -	| 1.0 | A
Storage Temperature |		-40 | - |	+85 | 	°C


## Recommended operating conditions

Parameter 	| Min | Typ	| Max | Unit
--------- |  --- | --- | ---- | ----
Supply Input Voltage (USB)	| +2.5	| +5.0 | +5.5 | V
Supply Input Current (WiFi off, LEDs & display on)	| - | 70 | 90 | mA
Supply Input Current (WiFi, LEDs & display on)	| - | 105 | 150 | mA
Power consumption (WiFi, LEDs & display on) | - | 0.5 | 0.75 | W
Operation Temperature |		-20 | - |	+60 | 	°C
Humidity Range / non-condensing |		- | - |	95 | %RH
STM32F413 operating frequency |		- | 200 **(1)** |	200 | MHz 

**(1)** default configuration for the mbed target.

## Wi-Fi Specifications (TI CC3120R)

Wi-Fi modes:

* 802.11b/g/n

Security:

* WPA2 Personal and Enterprise Security: WEP, WPA/WPA2 PSK, WPA2 Enterprise (802.1x)
* Secure Sockets: SSLv3, TLS1.0/1.1/TLS1.2 (integrated on the CC3210, newer versions can be further supported from the main MCU application) 
* Secure Key Storage
* Software Tamper Detection

TX Power:

* 18.0dBm@1DSSS
* 14.5dBm@54OFDM

RX Sensitivity:

* -96.0dBm @ 1DSSS
* -74.5 dBm @ 54 OFDM


On-board PCB Antenna:

* Return loss @ WiFi bands (2.412-2.472 GHz): -19.4 dB max. (VSWR: 1.24:1)
* Bandwidth (defined @ VSWR 2:1): 200 MHz


External u-Fl connector:

* Characteristic impedance: 50 Ω
* Maximum output power: 18.0dBm


## I/O Characteristics

All I/Os are CMOS and TTL compliant. The following characteristics are based on the STM32F423ZH datasheet:

Parameter 	| Min | Typ	| Max | Unit
----------- | ------------- | ------ | ------ | ------
Input logic LOW level voltage | -| - | 0.9 | V
Input logic HIGH level voltage | 2.3 | - | - | V
Input hysteresis | 0.1 | - | - | V
Weak pull-up equivalent resistor | 30 | 40 | 50 | kΩ
Weak pull-down equivalent resistor | 30 | 40 | 50 | kΩ
I/O pin capacitance | - | 5 | - | pF

!!! note "Notes:"
	* For I/O timings and maximum operating frequency of the different peripherals (I2C, SPI, UART, I2S) please refer to the [STM32F413ZH datasheet](https://www.st.com/resource/en/datasheet/stm32f413zh.pdf).
	* The main oscillator is driven by the external [crystal Y4](https://support.epson.biz/td/api/doc_check.php?dl=brief_FA-20H&lang=en) (16.000 MHz ± 10 p.p.m.). 
	* The low frequency oscillator is driven by the  [crystal Y3](https://abracon.com/Resonators/ABS07.pdf) (32.768 kHz ± 20 p.p.m.).

## Solid-state outputs characteristics

[Toshiba TLP241A](https://toshiba.semicon-storage.com/info/docget.jsp?did=14237&prodName=TLP241A):

Parameter 	| Min | Typ	| Max | Unit
----------- | ------------- | ------ | ------ | ------
ON-state current (continuous) | - | - | 2 | A
ON-state current (pulsed, t=100 mseg, duty=10%) | - | - | 6 | A
ON-state resistance (continuous) | - | 90 | 150 | mΩ
Isolation voltage | 5,000 | - | - | V
Maximum DC voltage **(1)** | - | - | 26 | V[dc]
Maximum AC voltage **(1)**| - | - | 20 | V[rms]

**(1)** Limited by the protection varistors (R63 and R69).


## Mechanical Dimensions

Dimension | Value | Unit | Comment
------------ | ------------- | ------ | -----
External dimensions |  100.97 x 65.79 x 19 | mm
Mounting holes diameter | 3.25 | mm | for M3 screws size
Mounting holes distances |  93.22 (X), 58.17 (Y) | mm


<img src="/images/sensorio/PCB-dimensions.png" class="img-left" width="70%" > 