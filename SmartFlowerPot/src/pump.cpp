// Pump.cpp
//base  functions to trigger the mosfet to water the plant

#include "avr/io.h"


void pumpSetup() {
    // Initialization code for the pump
    // Set the pump pin as output
    DDRB |= (1 << PB0); // Assuming the pump is connected to PB0
    PORTB &= ~(1 << PB0); // Initialize the pump pin to low
}

void waterPlant() {
    // Code to turn on the pump
    PORTB |= (1 << PB0);
}

void stopWatering() {
    // Code to turn off the pump
    PORTB &= ~(1 << PB0);
}