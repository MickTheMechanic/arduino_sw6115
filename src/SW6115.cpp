#include "SW6115.h"

SW6115::SW6115(uint8_t address, TwoWire& bus) {
	_deviceAddr = address;
	_bus = &bus;
}

SW6115::~SW6115() {}

float SW6115::readVoltage()
{
	_bus->beginTransmission(_deviceAddr);
	_bus->write(ADC_VDATA_1);
	_bus->endTransmission();
	_bus->requestFrom(_deviceAddr, (uint8_t)1);
	uint8_t r14 = _bus->read();
        _bus->beginTransmission(_deviceAddr);
	_bus->write(ADC_VDATA_2);
	_bus->endTransmission();
	_bus->requestFrom(_deviceAddr, (uint8_t)1);
        uint8_t r15 = _bus->read();
        return (((r15 << 8) | r14) & 0xFFF) * 0.0012;
}

