// Status interface for the Smart Flower Pot project
//using the OLED to display the status of the plant
#include "status.h"
#include "oled.h"

void statusSetup() {
    oledSetup();
}

void displayStatus(const char* message) {
    displayMessage(message);
}