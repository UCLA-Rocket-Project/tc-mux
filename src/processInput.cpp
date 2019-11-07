#include "defines.h"
bool sensorEnabled[8] = { false };
byte numSensors = 0;
char cmdBuffer[16];
byte bufferIndex = 0;
byte nextOutputType;

void processBuffer();
void setAllSensors(bool b);
bool readChar(char c) {
	if(c == 'V' || c == 'F' || c == 'C') {
		if(c == 'V') {
			nextOutputType = OUTPUT_MV;
		}
		else if(c == 'F') {
			nextOutputType = OUTPUT_F;
		}
		else if(c == 'C') {
			nextOutputType = OUTPUT_C;
		}
		bufferIndex = 0;
		return false;
	}
	if(bufferIndex >= sizeof(cmdBuffer)) {
		return false;
	}
	if(c == '\n' || c == '\r') {
		cmdBuffer[bufferIndex++] = 0;
		processBuffer();
		return true;
	}
	cmdBuffer[bufferIndex++] = c;
	return false;
}
/**
 * Returns true if the array sensorEnabled has been modified
 **/
void processBuffer() {
	outputType = nextOutputType;
	setAllSensors(false);
	numSensors = 0;
	for(byte i = 0; i < sizeof(cmdBuffer); i++) {
		char c = cmdBuffer[i];
		if(c == 0) {
			return;
		}
		if(c == 'a' || c == 'A') {
			setAllSensors(true);
			return;
		}
		byte sensorId = c - '0';
		if(sensorId >= 8) {
			return;
		}
		sensorEnabled[sensorId] = true;
		numSensors++;
	}
}
void setAllSensors(bool b) {
	for(byte i = 0; i < 8; i++) {
		sensorEnabled[i] = b;
	}
}