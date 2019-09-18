
/******************************************************************
Created with PROGRAMINO IDE for Arduino
Project     : SEEED Grove-GSR_Sensor
Author      : MF

Description : Connect the galvanic skin response (polygraph) sensor to Grove -> Analog1.

GSR stands for galvanic skin response, is a method of measuring the electrical conductance of the skin. 
Strong emotion can cause stimulus to your sympathetic nervous system, 
resulting more sweat being secreted by the sweat glands. 
Grove - GSR allows you to spot such strong emotions by simple attaching two electrodes to two fingers on one hand. 
It is an interesting to create emotion related projects like sleep quality monitor.

http://wiki.seeedstudio.com/Grove-GSR_Sensor/

Switches:
GROVE SW204 ON

Steps:
1. Upload the code
2. Wear the GSR sensor (it is not relevant which fingers are used)
3. Open the Serial Plotter
4. Press reset and wait for calibration (find offset)
5. We will see the graph. Please deep breath and see the trends.

GPIO ADC Channel:
GPIO 0 ==> ADC2_CH1
GPIO 2 ==> ADC2_CH2
GPIO 4 ==> ADC2_CH0
GPIO 12 => ADC2_CH5
GPIO 13 => ADC2_CH4
GPIO 14 => ADC2_CH6
GPIO 15 => ADC2_CH3
GPIO 25 => ADC2_CH8
GPIO 26 => ADC2_CH9
GPIO 27 => ADC2_CH7
GPIO 32 => ADC1_CH4
GPIO 33 => ADC1_CH5
GPIO 34 => ADC1_CH6
GPIO 35 => ADC1_CH7
GPIO 36 => ADC1_CH0
GPIO 37 => ADC1_CH1
GPIO 38 => ADC1_CH2
GPIO 39 => ADC1_CH3

******************************************************************/

const int GSR=39;
int sensorValue = 0;
int gsr_average = 0;
int gsr_offset = 0;

void setup()
{
    Serial.begin(115200);
    
    // init (search offset)
    long sum = 0;
    
    for(int i=0;i<100;i++)           // Average the 100 measurements to remove the offset
    {
        sensorValue = analogRead(GSR);
        sum += sensorValue;
        delay(20);
    }
    
    gsr_average = sum/100;
    gsr_offset = map(gsr_average,0,4095,0,1023);
    
}

void loop()
{
    long sum = 0;
    
    for(int i=0;i<10;i++)           // Average the 10 measurements to remove the glitch
    {
        sensorValue = analogRead(GSR);
        sum += sensorValue;
        delay(5);
    }
    
    gsr_average = sum/10;
    gsr_average = map(gsr_average,0,4095,0,1023);
    gsr_average = gsr_offset - gsr_average;
    
    Serial.println(gsr_average);
    
}
