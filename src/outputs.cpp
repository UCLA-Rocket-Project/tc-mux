#include "defines.h"
char writeBuffer[5];
void outputShort(uint16_t val) {
	sprintf(writeBuffer, "%04d", val);
	Serial.print(writeBuffer);
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