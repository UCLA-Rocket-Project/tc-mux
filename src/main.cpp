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
byte numOutputted;
uint16_t reading;
long thisRun;
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
		Serial.print('\t');
	}
	// the last column will be the delta time (in decimal milliseconds)
	thisRun = millis();
	Serial.println(thisRun - lastRun);
	lastRun = thisRun;
}