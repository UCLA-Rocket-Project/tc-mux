#include <Arduino.h>
#ifndef TCMUX_DEFINES
#define TCMUX_DEFINES

// only 3 pins (select up to 8 choices)
const uint8_t LOWBIT_PIN = 5;
const uint8_t MIDDLEBIT_PIN = 6;
const uint8_t HIGHBIT_PIN = 7;

// pin that the mux's analog out is connected to
const uint8_t ANALOG_PIN = A0; 

extern bool sensorEnabled[8];
extern byte numSensors;

// returns true if a complete command has been inputted
extern char cmdBuffer[16];
bool readChar(char c);
// returns a reading given a zero-based sensor ID
uint16_t takeReading(byte sensorId);
// outputs a uint16_t in decimal
void outputShort(uint16_t val);
// outputs the last stored command
void outputLastCmd();
#endif