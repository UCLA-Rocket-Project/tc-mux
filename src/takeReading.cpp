#include "defines.h"

uint16_t takeReading(byte sensorId) {
	byte lowBit, middleBit, highBit;
	lowBit = sensorId & 1;
	middleBit = (sensorId >> 1) & 1;
	highBit = (sensorId >> 2) & 1;

	digitalWrite(LOWBIT_PIN, lowBit);
	digitalWrite(MIDDLEBIT_PIN, middleBit);
	digitalWrite(HIGHBIT_PIN, highBit);

	// give the mux and TC amp time to settle
	delay(1);

	return analogRead(ANALOG_PIN);
}