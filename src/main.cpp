#include "defines.h"

void setup() {
	pinMode(LOWBIT_PIN, OUTPUT);
	pinMode(MIDDLEBIT_PIN, OUTPUT);
	pinMode(HIGHBIT_PIN, OUTPUT);
	pinMode(ANALOG_PIN, INPUT);

	Serial.begin(115200);
}
char c;
byte numOutputted;
uint16_t reading;
void loop() {
	while( ( c = Serial.read() ) != -1 ) {
		if(readChar(c)) {
			outputLastCmd();
		}
	}
	numOutputted = 0;
	for(byte i = 0; i < 8; i++) {
		if(!sensorEnabled[i]) {
			continue;
		}
		reading = takeReading(i);
		outputShort(reading);
		numOutputted++;
		// if its not the last sensor to be outputted print the delimiter
		if(numOutputted < numSensors) {
			Serial.print('\t');
		}
		else {
			Serial.println();
		}
	}
}