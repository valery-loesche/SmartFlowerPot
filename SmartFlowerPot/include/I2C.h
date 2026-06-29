// I2C interface for the Smart Flower Pot project
#ifndef I2C_H
#define I2C_H

#include <Arduino.h>
void i2c_setup();
unsigned char i2c_start(uint16_t command);
void i2c_stop();
void i2c_write(uint8_t data);

#endif // I2C_H