#include "defines.h"
byte outputType = OUTPUT_MV;

char writeBuffer[5];
float toVoltage(uint16_t val);

void outputMv(uint16_t val) {
	float mv = toVoltage(val) * 1000;
	sprintf(writeBuffer, "%04d", static_cast<int>(mv));
	Serial.print(writeBuffer);
}
void outputC(uint16_t val) {
	float voltage = toVoltage(val);
	float tempC = (voltage - V_OFFSET) * V_SCALE;
	Serial.print(tempC);
}
void outputF(uint16_t val) {
	float voltage = toVoltage(val);
	float tempC = (voltage - V_OFFSET) * V_SCALE;
	float tempF = tempC * 9 / 5.0 + 32;
	Serial.print(tempF);
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
inline float toVoltage(uint16_t val) {
	return val * (VREF / MAX_READING);
}