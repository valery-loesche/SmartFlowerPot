// I2C interface for the Smart Flower Pot project
#ifndef I2C_H
#define I2C_H

#include <Arduino.h>

void I2CSetup();
void I2CStart();
void I2CStop();
void I2CSendByte(uint8_t data);

#endif // I2C_H