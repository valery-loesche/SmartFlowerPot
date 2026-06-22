#include <Arduino.h>
#include "pump.h"
#include "status.h"
#include "waterLevelSensor.h"
#include "wetnesssensor.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pumpSetup();
  statusSetup();
  waterLevelSensorSetup();
  wetnessSensorSetup();
}

void loop() {
  // put your main code here, to run repeatedly:
  int waterLevel = readWaterLevelSensor();
  int wetness = readWetnessSensor();

  Serial.print("Water Level: ");
  Serial.print(waterLevel);
  Serial.print(" | Wetness: ");
  Serial.println(wetness);

  if (waterLevel < 300) {
    displayStatus("Water level low! Please refill.");
    pumpOff();
  } else if (wetness < 300) {
    displayStatus("Soil is dry! Watering the plant.");
    pumpOn();
  } else {
    displayStatus("Plant is healthy!");
    pumpOff();
  }

  delay(5000); // Wait for 5 seconds before the next reading
}
