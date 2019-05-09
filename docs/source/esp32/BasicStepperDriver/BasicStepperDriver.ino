/******************************************************************
Created with PROGRAMINO IDE for Arduino
Project     : Basic stepper motor driver
Board       : MAKERFACTORY EBB ESP32
Version     : 1.0
Date        : 28.12.2018
Author      : MF

Description : Stepper driver for DRV8824/25 and A4988 breakout boards

Connect a stepper motor on J301
Motor connection from left to right:

GND     -   external motor power supply
VCC     -   external motor power supply
2B      -   motor coil 2
2A      -   motor coil 2
1A      -   motor coil 1
1B      -   motor coil 1

MOTOR   SW304 all ON  (direction and pulse)
MOTOR   SW305 1 - 3 OFF (microstepping)
        SW305 4     ON  (enable)


License:
Copyright (C)2015 Laurentiu Badea
This file may be redistributed under the terms of the MIT license.
A copy of this license has been included with this distribution in the file LICENSE.
******************************************************************/

#include <BasicStepperDriver.h> // https://github.com/laurb9/StepperDriver

// Motor steps per revolution. Most steppers are 200 steps or 1.8 degrees/step
#define MOTOR_STEPS 200

// All the wires needed for full functionality
#define DIR 33
#define STEP 23

// Uncomment line to use enable/disable functionality
//#define ENBL 7

// Since microstepping is set externally, make sure this matches the selected mode
// 1=full step, 2=half step etc.
#define MICROSTEPS 32

// 2-wire basic config, microstepping is hardwired on the driver
BasicStepperDriver stepper(MOTOR_STEPS, DIR, STEP);

// Uncomment line to use enable/disable functionality
//BasicStepperDriver stepper(MOTOR_STEPS, DIR, STEP, ENBL);

void setup() 
{
    /*
    * Set target motor RPM.
    * These motors can do up to about 200rpm.
    * Too high will result in a high pitched whine and the motor does not move.
    */
    stepper.setRPM(100);
}

void loop() 
{
    
    // energize coils - the motor will hold position
    // stepper.enable();
    
    /*
    * Tell the driver the microstep level we selected.
    * If mismatched, the motor will move at a different RPM than chosen.
    */
    stepper.setMicrostep(MICROSTEPS);
    
    /*
    * Moving motor one full revolution using the degree notation
    */
    stepper.rotate(360);
    delay(1000);
    
    /*
    * Moving motor to original position using steps
    */
    stepper.move(-200*MICROSTEPS);
    
    // pause and allow the motor to be moved by hand
    // stepper.disable();
    
    delay(1000);
}
