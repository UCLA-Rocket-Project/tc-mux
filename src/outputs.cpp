#include "defines.h"
void outputShort(uint16_t val) {
	byte lowByte, highByte;
	lowByte = val & 0xFF;
	highByte = (val >> 8) & 0xFF;
	Serial.print(highByte, HEX);
	Serial.print(lowByte, HEX);
}
void outputLastCmd() {
	// just dump the command buffer (using a for loop for bounds check)
	for(byte i = 0; i < sizeof(cmdBuffer); i++) {
		if(cmdBuffer[i] == 0) {
			Serial.println();
			return;
		}
		Serial.print(cmdBuffer[i]);
	}
	Serial.println("ERR");
}