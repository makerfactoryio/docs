# FAQ

**Error compiling the examples**  
If there are problems compiling the firmware: The provided firmware as well as the examples were developed with Arduino version 1.8.3. Alternatively, you can download it from [Arduino](https://www.arduino.cc/en/Main/Software).  

**Sound output too low**  
Check the setting of the "Vol." trimmer. Build a small "speaker box" into the robot board speaker. This increases the volume and improves the sound considerably.  

**There is no communication with SPI devices and the user board**  
Set the Chip Select (CS) pin of the user board to "High" and check your connection at the ISP_U connector and of the used SPI component is supplied with power.  
> const int chipSelect = 8;  
pinMode(chipSelect, OUTPUT);  
digitalWrite(chipSelect, HIGH);  

**The Gamepad does not connect or show any reaction**  

- Check the batteries in the transmitter  
- Is the reciever correctly connected to the robot board?  
- Is the "motion firmware" installed on the robot board?  
- Disonnect the power supply of the robot board, switch on the Gamepad and then re-establish the connection to the power supply of the Hexapod (plug in the battery).  
- Is the Gamepad PS2 compatible?  
- Jumper J7 must not be plugged in.  

**The robot does not react to the gamepad**  

- Check the batteries in the transmitter  
- Is the reciever correctly connected to the robot board?  
- Is the "motion firmware" installed on the robot board?  
- Disonnect the power supply of the robot board, switch on the Gamepad and then re-establish the connection to the power supply of the Hexapod (plug in the battery).  
- Is the Gamepad PS2 compatible?  
- Jumper J7 removed?  

**The robot is not running cleanly**  

- Have the legs been calibrated?  
- Are the batteries sufficient strong and charged?  
- Is the robot too heavy?  
- Have the servos been set to the middle position before installation?  
- Are the legs slipping on the ground?  
- Are all screws tightened?  
- Does the machanics wobble?  
- Is the machanics too stiff?  

**Where can I find the circuit diagram?**  
The circuit diagram can be found in the "Schematic" folder in the download bundle or can be downloaded from [Conrad](https://www.conrad.com).  


**The robot carries out the reset after switching on or getting up**  

- Make sure that the battery is fully charged.  
- Is the battery connection cable too thin (< 1.5 mm²) or longer than 20 cm?  
- Is the battery plug soldered on cleanly?  
- If the battery is too small, it cannot supply the necessary operating current for the servos.  
- Is/are there any servo(s) blocked?  
- Does the machanics mave too sluggishly?  

