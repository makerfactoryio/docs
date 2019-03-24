/******************************************************************
Created with PROGRAMINO IDE for Arduino
Project     : Maker-Factory ESP32 Board
Libraries   : https://github.com/laurb9/StepperDriver
Author      : UlliS

Description : Stepper Driver for DRV8824/25 and A4988

Layout and circuited issue: stepper driver /reset /sleep set to +5 Vcc

SW304 all on
SW305 1 ON

Copyright (c) 2018 Conrad Electronic SE.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

******************************************************************/
#include <Arduino.h>
#include <BasicStepperDriver.h>

// Motor steps per revolution. Most steppers are 200 steps or 1.8 degrees/step
#define MOTOR_STEPS 200

// All the wires needed for full functionality
#define DIR 33
#define STEP 23
//Uncomment line to use enable/disable functionality
//#define ENBL 7

// Since microstepping is set externally, make sure this matches the selected mode
// 1=full step, 2=half step etc.
#define MICROSTEPS 16

// 2-wire basic config, microstepping is hardwired on the driver
BasicStepperDriver stepper(MOTOR_STEPS, DIR, STEP);

//Uncomment line to use enable/disable functionality
//BasicStepperDriver stepper(MOTOR_STEPS, DIR, STEP, ENBL);

void setup() {
    /*
    * Set target motor RPM.
    * These motors can do up to about 200rpm.
    * Too high will result in a high pitched whine and the motor does not move.
    */
    stepper.setRPM(100);
}

void loop() {
    
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
