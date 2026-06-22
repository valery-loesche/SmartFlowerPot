// Water Level Sensor implementation in AVR C++ for the Smart Flower Pot project
//based on the code for the analog sensor
#include "waterLevelSensor.h"
#include "analogSensor.h"
#include <avr/io.h>

int pin = 0; // Example pin for the water level sensor

void waterLevelSensorSetup() {
    //set pin as input
    DDRC &= ~(1 << pin); // Set pin as input
    analogSensorSetup();
}

int readWaterLevelSensor() {
    return readAnalogSensor(pin);
}