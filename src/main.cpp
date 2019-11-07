#include "defines.h"

long lastRun;
void setup() {
	pinMode(LOWBIT_PIN, OUTPUT);
	pinMode(MIDDLEBIT_PIN, OUTPUT);
	pinMode(HIGHBIT_PIN, OUTPUT);
	pinMode(ANALOG_PIN, INPUT);

	Serial.begin(115200);
	lastRun = millis();
}
char c;
uint16_t reading;
long thisRun;
void loop() {
	while( ( c = Serial.read() ) != -1 ) {
		if(readChar(c)) {
			outputLastCmd();
		}
	}
	for(byte i = 0; i < 8; i++) {
		if(!sensorEnabled[i]) {
			continue;
		}
		reading = takeReading(i);
		if(outputType == OUTPUT_MV) {
			outputMv(reading);
		}
		else if(outputType == OUTPUT_C) {
			outputC(reading);
		}
		else if(outputType == OUTPUT_F) {
			outputF(reading);
		}
		Serial.print('\t');
	}
	// the last column will be the delta time (in decimal milliseconds)
	thisRun = millis();
	Serial.println(thisRun - lastRun);
	lastRun = thisRun;
}