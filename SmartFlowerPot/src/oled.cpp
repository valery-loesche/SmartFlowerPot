//placeholder for OLED implementation
#include "oled.h"   
#include "I2C.h"

void oledSetup() {
    //placeholder implementation
    I2CSetup();
}

void displayMessage(const char* message) {
    //placeholder implementation
    I2CStart();
    I2CSendByte(0x78); // OLED address
    I2CSendByte(0x00); // Command mode
        // Send the message byte by byte
    for (const char* p = message; *p != '\0'; p++) {
        I2CSendByte(*p);
    }
    I2CStop();
}