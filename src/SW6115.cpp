// Another rediculously good mod by Mick ;)
// MIT licence
// This code is provided as is
// I'm not responsible or liable if stuff breaks or people die as a result of my shitty code

#include "SW6115.h"

SW6115::SW6115(uint8_t address, TwoWire& bus) {
	_deviceAddr = address;
	_bus = &bus;
}

SW6115::~SW6115() {}

float SW6115::readVbatt()
{
	_bus->beginTransmission(_deviceAddr);
	_bus->write(static_cast<uint8_t>(SW6115Register::ADC_VDATA_1));
	_bus->endTransmission();
	_bus->requestFrom(_deviceAddr, (uint8_t)1);
	uint8_t r14 = _bus->read();
        _bus->beginTransmission(_deviceAddr);
	_bus->write(static_cast<uint8_t>(SW6115Register::ADC_VDATA_2));
	_bus->endTransmission();
	_bus->requestFrom(_deviceAddr, (uint8_t)1);
        uint8_t r15 = _bus->read();
        return (((r15 << 8) | r14) & 0xFFF) * 1.2;
	//VBAT = ((Reg0x15[3:0]<<8)+ Reg0x14[7:0]) *1.2 mV
}

float SW6115::readVout()
{
        _bus->beginTransmission(_deviceAddr);
	_bus->write(static_cast<uint8_t>(SW6115Register::ADC_VDATA_2));
	_bus->endTransmission();
	_bus->requestFrom(_deviceAddr, (uint8_t)1);
        uint8_t r15 = _bus->read();
	_bus->beginTransmission(_deviceAddr);
	_bus->write(static_cast<uint8_t>(SW6115Register::ADC_VDATA_3));
	_bus->endTransmission();
	_bus->requestFrom(_deviceAddr, (uint8_t)1);
	uint8_t r16 = _bus->read();
        return ((((r15>>4) << 8) | r16) & 0xFFF) * 4;
	//Vout= ((Reg0x15[7:4]<<8)+ Reg0x16[7:0]) *4 mV
}

float SW6115::readIchrg()
{
	_bus->beginTransmission(_deviceAddr);
	_bus->write(static_cast<uint8_t>(SW6115Register::ADC_IDATA_1));
	_bus->endTransmission();
	_bus->requestFrom(_deviceAddr, (uint8_t)1);
	uint8_t r17 = _bus->read();
        _bus->beginTransmission(_deviceAddr);
	_bus->write(static_cast<uint8_t>(SW6115Register::ADC_IDATA_2));
	_bus->endTransmission();
	_bus->requestFrom(_deviceAddr, (uint8_t)1);
        uint8_t r18 = _bus->read();
        return (((r18 << 8) | r17) & 0xFFF) * 25/7;
	//ICharge = ((Reg0x18[3:0]<<8)+ Reg0x17[7:0])*25/7 mA
}

float SW6115::readIdischrg()
{
        _bus->beginTransmission(_deviceAddr);
	_bus->write(static_cast<uint8_t>(SW6115Register::ADC_IDATA_2));
	_bus->endTransmission();
	_bus->requestFrom(_deviceAddr, (uint8_t)1);
        uint8_t r18 = _bus->read();
	_bus->beginTransmission(_deviceAddr);
	_bus->write(static_cast<uint8_t>(SW6115Register::ADC_IDATA_3));
	_bus->endTransmission();
	_bus->requestFrom(_deviceAddr, (uint8_t)1);
	uint8_t r19 = _bus->read();
        return ((((r18>>4) << 8) | r19) & 0xFFF) * 25/7;
	//IDischarge = ((Reg0x18[7:4]<<8)+ Reg0x19[7:0])*25/7 mA
}

float SW6115::readTic()
{

	_bus->beginTransmission(_deviceAddr);
	_bus->write(static_cast<uint8_t>(SW6115Register::ADC_TDATA_1));
	_bus->endTransmission();
	_bus->requestFrom(_deviceAddr, (uint8_t)1);
	uint8_t r20 = _bus->read();
        _bus->beginTransmission(_deviceAddr);
	_bus->write(static_cast<uint8_t>(SW6115Register::ADC_TDATA_2));
	_bus->endTransmission();
	_bus->requestFrom(_deviceAddr, (uint8_t)1);
        uint8_t r21 = _bus->read();
        return ((((r21 << 8) | r20) & 0xFFF) - 1851) * 1/6.82;
	//TDie= ((Reg0x1B[3:0]<<8)+ Reg0x1A[7:0] - 1851)*1/6.82 ℃
}

float SW6115::readVntc()
{
        _bus->beginTransmission(_deviceAddr);
	_bus->write(static_cast<uint8_t>(SW6115Register::ADC_TDATA_2));
	_bus->endTransmission();
	_bus->requestFrom(_deviceAddr, (uint8_t)1);
        uint8_t r21 = _bus->read();
	_bus->beginTransmission(_deviceAddr);
	_bus->write(static_cast<uint8_t>(SW6115Register::ADC_TDATA_3));
	_bus->endTransmission();
	_bus->requestFrom(_deviceAddr, (uint8_t)1);
	uint8_t r22 = _bus->read();
        return ((((r21>>4) << 8) | r22) & 0xFFF) *1.1;
	//VNTC = ((Reg0x1B[7:4]<<8)+ Reg0x1C[7:0])*1.1mV;
}

void SW6115::powerOff()
{
        _bus->beginTransmission(_deviceAddr);
	_bus->write(static_cast<uint8_t>(SW6115Register::KEY_EVENT_CTRL));
	_bus->write(0b00010000);
	_bus->endTransmission();
}
