#include <Arduino.h>
#ifndef TCMUX_DEFINES
#define TCMUX_DEFINES
extern int ADDR_PINS[3];
extern bool sensorEnabled[8];
extern byte numSensors;
/*
 * Returns true if the array sensorEnabled has been modified
 */
bool readChar(char c);
#endif