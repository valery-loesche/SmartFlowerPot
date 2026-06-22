//I2C implementation for the Smart Flower Pot project
#include "I2C.h"
#include <avr/io.h>

void I2CSetup() {
    // Set SCL and SDA as output
    DDRC |= (1 << 4) | (1 << 5); // Set PC4 (SDA) and PC5 (SCL) as output
    PORTC |= (1 << 4) | (1 << 5); // Enable pull-up resistors on SDA and SCL
}

void I2CStart() {
    // Generate a start condition
    PORTC &= ~(1 << 4); // Pull SDA low
    PORTC &= ~(1 << 5); // Pull SCL low
}

void I2CStop() {
    // Generate a stop condition
    PORTC &= ~(1 << 4); // Pull SDA low
    PORTC |= (1 << 5); // Pull SCL high
    PORTC |= (1 << 4); // Pull SDA high
}

void I2CSendByte(uint8_t data) {
    // Send a byte of data
    for (int i = 0; i < 8; i++) {
        if (data & 0x80) {
            PORTC |= (1 << 4); // Set SDA high
        } else {
            PORTC &= ~(1 << 4); // Set SDA low
        }
        PORTC |= (1 << 5); // Set SCL high
        PORTC &= ~(1 << 5); // Set SCL low
        data <<= 1; // Shift data left by 1 bit
    }
}