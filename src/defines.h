#include <Arduino.h>
#ifndef TCMUX_DEFINES
#define TCMUX_DEFINES

// only 3 pins (select up to 8 choices)
const uint8_t LOWBIT_PIN = 5;
const uint8_t MIDDLEBIT_PIN = 6;
const uint8_t HIGHBIT_PIN = 7;

// pin that the mux's analog out is connected to
const uint8_t ANALOG_PIN = A0;

// temperature calibration definition
const float VREF = 5;
const uint16_t MAX_READING = 1023;
const float V_OFFSET = 1.25;
const float V_SCALE = 200;

extern bool sensorEnabled[8];
extern byte numSensors;

// returns true if a complete command has been inputted
extern char cmdBuffer[16];

// output types
const byte OUTPUT_MV = 0;
const byte OUTPUT_C = 1;
const byte OUTPUT_F = 2;

extern byte outputType;
bool readChar(char c);
// returns a reading given a zero-based sensor ID
uint16_t takeReading(byte sensorId);

// outputs temp reading as millivolts
void outputMv(uint16_t val);
// outputs temp reading as Celsius
void outputC(uint16_t val);
// outputs temp reading as Farenheit
void outputF(uint16_t val);

// outputs the last stored command
void outputLastCmd();
#endif