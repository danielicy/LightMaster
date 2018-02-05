/*
 Name:		MCP23017.cpp
 Created:	2/1/2018 4:37:27 PM
 Author:	administrator
 Editor:	http://www.visualmicro.com
*/



/*  MCP23017 library for Arduino
Copyright (C) 2009 David Pye    <davidmpye@gmail.com

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "MCP23017.h"

MCP23017::MCP23017(int i2cAddress) {
	_i2cAddress = (I2C_BASE_ADDRESS >> 1) | (i2cAddress & 0x07);
	//Default state is 0 for our pins
	_GPIO = 0x0000;
	_IODIR = 0x0000;
	_GPPU = 0x0000;
}

void MCP23017::init() {
	//Set the IOCON.BANK bit to 0 to enable sequential addressing
	//IOCON 'default' address is 0x05, but will
	//change to our definition of IOCON once this write completes.
	writeRegister(0x05, (byte)0x0);
	//Our pins default to being outputs by default.
	writeRegister(IODIR, (word)_IODIR);
}

void MCP23017::pinMode(int pin, int mode) {
	//Arduino defines OUTPUT as 1, but 
	//MCP23017 uses OUTPUT as 0. (input is 0x1)
	mode = !mode;
	if (mode) _IODIR |= 1 << pin;
	else _IODIR &= ~(1 << pin);
	writeRegister(IODIR, (word)_IODIR);
}

int MCP23017::digitalRead(int pin) {
	_GPIO = readRegister(GPIO);
	if (_GPIO & (1 << pin)) return HIGH;
	else return LOW;
}

void MCP23017::digitalWrite(int pin, int val) {
	//If this pin is an INPUT pin, a write here will
	//enable the internal pullup
	//otherwise, it will set the OUTPUT voltage
	//as appropriate.
	bool isOutput = !(_IODIR & 1 << pin);

	if (isOutput) {
		//This is an output pin so just write the value
		if (val) _GPIO |= 1 << pin;
		else _GPIO &= ~(1 << pin);
		writeRegister(GPIO, (word)_GPIO);
	}
	else {
		//This is an input pin, so we need to enable the pullup
		if (val) _GPPU |= 1 << pin;
		else _GPPU &= ~(1 << pin);
		writeRegister(GPPU, (word)_GPPU);
	}
}

word MCP23017::digitalWordRead() {
	_GPIO = readRegister(GPIO);
	return _GPIO;
}

void MCP23017::digitalWordWrite(word w) {
	_GPIO = w;
	writeRegister(GPIO, (word)_GPIO);
}

void MCP23017::inputPolarityMask(word mask) {
	writeRegister(IPOL, mask);
}

void MCP23017::inputOutputMask(word mask) {
	_IODIR = mask;
	writeRegister(IODIR, (word)_IODIR);
}

void MCP23017::internalPullupMask(word mask) {
	_GPPU = mask;
	writeRegister(GPPU, (word)_GPPU);
}

//PRIVATE
void MCP23017::writeRegister(int regAddress, byte data) {
	Wire.beginTransmission(_i2cAddress);
	Wire.send(regAddress);
	Wire.send(data);
	Wire.endTransmission();
}

void MCP23017::writeRegister(int regAddress, word data) {
	Wire.beginTransmission(_i2cAddress);
	Wire.send(regAddress);
	Wire.send(highByte(data));
	Wire.send(lowByte(data));
	Wire.endTransmission();
}

word MCP23017::readRegister(int regAddress) {
	word returnword = 0x00;
	Wire.beginTransmission(_i2cAddress);
	Wire.send(regAddress);
	Wire.endTransmission();
	Wire.requestFrom((int)_i2cAddress, 2);
	//Wait for our 2 bytes to become available
	while (Wire.available() < 2) {}
	//high byte
	returnword = Wire.receive() << 8;
	//low byte
	returnword |= Wire.receive();

	return returnword;
}


