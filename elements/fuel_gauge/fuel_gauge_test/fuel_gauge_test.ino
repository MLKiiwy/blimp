#include <MAX17043.h>             // Fuel gauge

#include <Wire.h>
#include <SPI.h> //Why? Because library supports SPI and I2C connection

MAX17043 batteryMonitor;  // Fuel gauge

// I2C Configuration
// SDA (=SDI) ; SCL (=SCK)
#define SDA_I2C 5 // D1
#define SDL_I2C 4 // D2

// Fuel gauge
float cellVoltage;
float stateOfCharge;

void readSensors() {
  // From Fuel gauge
  cellVoltage = batteryMonitor.getVCell();
  stateOfCharge = batteryMonitor.getSoC();
}

void initFuelGaugeSensor() {
  batteryMonitor.reset();
  batteryMonitor.quickStart();
}


void setup() {
  Serial.begin(115200);

  Wire.begin(SDA_I2C, SDL_I2C);

  initFuelGaugeSensor();
}

void loop() {
  readSensors();
  
  Serial.println("------------------------------------");
  Serial.print  ("State of charge:       "); 
  Serial.println(String(stateOfCharge).c_str());
  Serial.print  ("Cell voltage:   "); 
  Serial.println(String(cellVoltage).c_str());
  Serial.println("------------------------------------");
  Serial.println("");

  delay(2000);
}
