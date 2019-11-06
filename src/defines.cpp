#include "defines.h"
int ADDR_PINS[3] = {0, 1, 2};
bool sensorEnabled[8] = {false, false, false, false, false, false, false, false};
byte numSensors = 0;
char readBuffer[16];
byte bufferIndex = 0;

bool processBuffer();
void setAllSensors(bool b);
bool readChar(char c) {
	if(c == '$') {
		bufferIndex = 0;
		return false;
	}
	if(bufferIndex >= sizeof(readBuffer)) {
		return false;
	}
	if(c == '\n' || c == '\r') {
		readBuffer[bufferIndex++] = 0;
		return processBuffer();
	}
	readBuffer[bufferIndex++] = c;
	return false;
}
/**
 * Returns true if the array sensorEnabled has been modified
 **/
bool processBuffer() {
	setAllSensors(false);
	numSensors = 0;
	for(byte i = 0; i < sizeof(readBuffer); i++) {
		char c = readBuffer[i];
		if(c == 0) {
			return true;
		}
		if(c == 'a' || c == 'A') {
			setAllSensors(true);
			return true;
		}
		byte sensorId = c - '0';
		if(sensorId >= 8) {
			return false;
		}
		sensorEnabled[sensorId] = true;
		numSensors++;
	}
	return true;
}
void setAllSensors(bool b) {
	for(byte i = 0; i < 8; i++) {
		sensorEnabled[i] = b;
	}
}