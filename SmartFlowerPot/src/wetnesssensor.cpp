// Wetness Sensor implementation in AVR C++ for the Smart Flower Pot project
//based on the code for the analog sensor
#include "wetnesssensor.h"
#include "analogSensor.h"
#include <avr/io.h>

int pin = 1; // Example pin for the wetness sensor

void wetnessSensorSetup() {
    //set pin as input 
    DDRC &= ~(1 << pin); // Set pin as input
    analogSensorSetup();
}

int readWetnessSensor() {
    return readAnalogSensor(pin);
}