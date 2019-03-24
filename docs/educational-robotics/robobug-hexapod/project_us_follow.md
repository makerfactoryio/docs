#Follow objects with an ultrasonic sensor

## Requirements:
- Fully assembled Pan & Tilt Unit
- Arduino UNO (or similar)
- Ultrasonic Sensor Module (eg 1616245)
- RGB-LED WS2812

## Schematic:


![Figure S1](../../images/robobug-hexapod/Abb_S1.png "Figure S1")   
Figure S1

###RGB-LED WS2812
DIN 		  → 9 <br>
DOUT		  → empty<br>
VSS(VCC): → 5V<br>
VDD(GND):	→ GND <br>

###HC-SR04
Trig		→ A0<br>
Echo		→ A1<br>
VCC	  	→ 5V<br>
GND		  → GND<br>


##Functions:

###**Description:**

The demo shows how the MAKERFACTORY Robobug can follow obstacles (eg your hand) with help of an ultrasonic sensor HC-SR04. 

###**Plug in:**

After plugging in the power supply, the Robobug gives a melody and waits for the start signal.

###**Start:**

Press the button T1 on the locomotion controller board. The Robobug gets up on its and starts measuring

###**Measuring:**

The Robobug tries to keep the distance of any obstacle between 10 and 20 cm. If the obstacle moves closer to the Robobug’s head, the RGB-LED turns red and the roboter moves backwards. If the obstacle moves away, the LED turns blue and the robobug will follow the obstacle until the distance is less than 20 cm again. And if the nearest obstacle’s distance is higher than 60cm, the Robobug stops walking.

##Parameters:

||||
|:---:|:---:|:---:|
|**PARAMETER**|**Description**|**Default**|
|SERVO_TILT_PIN|Servo Tilt Pin|SU1|
|SERVO_PAN_PIN|Servo Pan Pin|SU2|
|WS2812_PIN|RGB-LED-Pin|SU3	(PIN 9)|
|SR04_TRG_PIN|Ultrasonic Trigger Pin|A0|
|SR04_ECHO_PIN|Ultrasonic Echo Pin|A1|
||||
|DIST_MIN|Minimum Distance in cm|10|
|DIST_MAX|Maximum Distance in cm|20|
|DIST_STOP|Max Distance for STOP|60|

##Code:

```c
/******************************************************************
Created with PROGRAMINO IDE for Arduino
Project     : MAKERFACTORY Ultrasonic Demo
Author      : UlliS

Description : 
The demo shows how the MAKERFACTORY can follow a obstacles in front of the robot 
with the Pan & Tilt unit and an ultrasonic sensor HC-SR04.

Userboard is ARDUINO UNO
---------------------------
- IR Daten      7
- SU1           6 Pan 
- SU2           5 Tilt
- SU3           9 +/- WS2812
- A0            US Trigger
- A1            US Echo
- A4            free              
- A5            free
- 10            free

******************************************************************/

#include <Adafruit_NeoPixel.h> // https://github.com/adafruit/Adafruit_NeoPixel
#ifdef __AVR__
    #include <avr/power.h>
#endif

#include <Servo.h>

// Arduino
#define ARDUINO
#include <Hexapod_Lib.h>

/******************************************************************************
WS2812 RGB-LED
******************************************************************************/
// WS2812/13 (Neopixel) smart RGB LED
#define WS2812_PIN      SU3

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
// NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
// NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
// NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
// NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
// NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)

Adafruit_NeoPixel pixel = Adafruit_NeoPixel(1, WS2812_PIN, NEO_GRB + NEO_KHZ800);

/******************************************************************************
HC-SR04 ULTRASONIC SENSOR
******************************************************************************/
// pins for ultrasonic sensor
#define SR04_TRG_PIN    A0
#define SR04_ECHO_PIN   A1

/******************************************************************************
SERVO PAN & TILT
******************************************************************************/
// declare your servo as an object
#define SERVO_PAN_PIN   SU2
#define SERVO_TILT_PIN  SU1
Servo servo_pan;
Servo servo_tilt;

#define PAN_CENTER      100 // lower value scanner more left
#define TILT_CENTER     95  // lower value scanner more up

#define DIST_MIN    10
#define DIST_MAX    20
#define DIST_STOP   60

/******************************************************************************
SETUP
******************************************************************************/
void setup()
{
    // WS2812 RGB-LED    
    pixel.begin();  // this initializes the NeoPixel library.
    WS2812_SET_RGB(255,255,255);
    
    // high-Z for the audio output
    pinMode(PA_PIN,INPUT);
    digitalWrite(PA_PIN,LOW);
    
    // switches T1 and T2
    pinMode(T1,INPUT);
    pinMode(T2,INPUT);
    
    // HC-SR04
    pinMode(SR04_TRG_PIN, OUTPUT);
    pinMode(SR04_ECHO_PIN, INPUT);
    
    // open serial communications and wait for port to open:
    Serial.begin(SERIAL_STD_BAUD);
    while(!Serial);
    
    // set the data rate for the SoftwareSerial port (User-Board to Locomotion-Controller)
    SERIAL_CMD.begin(SERIAL_CMD_BAUD);
    
    // reset the Locomotion-Controller
    ROBOT_RESET();
    delay(250);
    ROBOT_RESET();
    delay(150);
    ROBOT_RESET();
    
    // wait for Boot-Up
    delay(1500);
    ROBOT_INIT();
    
    // pan & tilt servos
    servo_pan.attach(SERVO_PAN_PIN);
    servo_tilt.attach(SERVO_TILT_PIN);
    servo_pan.write(PAN_CENTER);
    servo_tilt.write(TILT_CENTER);
    
    // rnd init
    randomSeed(analogRead(0));
    
    // RBG LED
    for(int i = 0; i < 765; i++)
    {
        WS2812_ColorSweep(i);
        delay(2);
    }
    WS2812_SET_RGB(0,255,0); // green
    
    // print a hello world over the USB connection
    Serial.println("> Hello here is the MAKERFACTORY Robobug");   
}

/******************************************************************************
MAIN LOOP
******************************************************************************/
void loop()
{
    // start demo
    if(!digitalRead(T1)) 
    {
        delay(50);
        if(!digitalRead(T1)) 
        {
            MSound(1, 100, 1000);
            
            // basic robot movement parameter
            ROBOT_PWR_ON();
            delay(1000);
            ROBOT_SPEED(30);
            ROBOT_HEIGHT(40);
            
            while(1)
            {  
                int dist = SR04_DISTANCE();
                if (dist < DIST_MIN)
                {
                    WS2812_SET_RGB(255,0,0); // red
                    ROBOT_WALK_BWD();              
                }
                else if (dist > DIST_MAX && dist < DIST_STOP)
                {
                    WS2812_SET_RGB(0,0,255); // blue
                    ROBOT_WALK_FWD();                   
                }
                else if (dist < DIST_MAX && dist > DIST_MIN)
                {
                    WS2812_SET_RGB(0,255,0); // green
                    ROBOT_STOP();
                }
                else
                    ROBOT_STOP();
                
                delay(500);             
                
            }
            
        }
    }
}

/******************************************************************************
HC-SR04 FUNCTIONS
******************************************************************************/
int SR04_DISTANCE()
{
    long duration = 0;
    int distance  = 0;
    
    // AVG value (2 samples)
    for (int i = 0; i < 2; i++)
    {
        // Clears the trigPin
        digitalWrite(SR04_TRG_PIN, LOW);
        delayMicroseconds(2);
        
        // Sets the trigPin on HIGH state for 10 micro seconds
        digitalWrite(SR04_TRG_PIN, HIGH);
        delayMicroseconds(10);
        digitalWrite(SR04_TRG_PIN, LOW);
        
        // Reads the echoPin, returns the sound wave travel time in microseconds
        duration = pulseIn(SR04_ECHO_PIN, HIGH);
        
        // Calculating the avg distance
        distance += duration*0.034/2;
        delay(5);
        
    }
    
    return round(distance/2); // cm
    
}

/******************************************************************************
WS2812 RGB-LED FUNCTIONS
******************************************************************************/
void WS2812_ColorSweep(int i)
{
    // WS2812 color change
    // Farbwerte mit Vorbesetzung, begonnen wird mit rot
    static int red   = 255;
    static int green = 0;
    static int blue  = 0;
    
    if (i < 255)      // Phase 1: von rot nach grün
    {
        red--;       // red down
        green++;     // green up
        blue = 0;    // blue low
    }
    else if (i < 510) // Phase 2: von grün nach blau
    {
        red = 0;     // red low
        green--;     // green down
        blue++;      // blue up
    } 
    else if (i < 766) // Phase 3: von blau nach rot
    {
        red++;       // red up
        green = 0;   // green low
        blue--;      // blue down
    }
    
    pixel.setPixelColor(0, pixel.Color(red, green, blue)); 
    pixel.show();
}

void WS2812_SET_RGB(byte r, byte g, byte b)
{
    // WS2812 color change
    pixel.setPixelColor(0, pixel.Color(r, g, b)); 
    pixel.show();
}


```
[Download .ino](../../source/robobug/US-Following.ino)
