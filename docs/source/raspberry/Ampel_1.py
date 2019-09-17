import RPi.GPIO as GPIO
GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)
import time


# Hier startet das Programm
GPIO.setup(17, GPIO.OUT)
while True:
        GPIO.output (17,1)
        time.sleep (1)
        GPIO.output (17,0)
        time.sleep (1)
        

