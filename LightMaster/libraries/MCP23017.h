/*
 Name:		MCP23017.h
 Created:	2/1/2018 4:37:27 PM
 Author:	administrator
 Editor:	http://www.visualmicro.com
*/

#ifndef _MCP23017_h
#define _MCP23017_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	 
#endif


#endif
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
#ifndef MCP23017_H
#define MCP23017_H


#include "Wire.h"
//Register defines from data sheet - we set IOCON.BANK to 0
//as it is easier to manage the registers sequentially.
#define IODIR 0x00
#define IPOL 0x2
#define GPINTEN 0x4
#define DEFVAL 0x6
#define INTCON 0x8
#define IOCON 0x0A
#define GPPU 0x0C
#define INTF 0x0E
#define INTCAP 0x10
#define GPIO 0x12
#define OLAT 0x14

#define I2C_BASE_ADDRESS 0x40

class MCP23017
{
public:
	//NB the i2c address here is the value of the A0, A1, A2 pins ONLY
	//as the class takes care of its internal base address.
	//so i2cAddress should be between 0 and 7 
	MCP23017(int i2cAddress);
	void init();

	//These functions provide an 'arduino'-like functionality for accessing
	//pin states/pullups etc.
	void pinMode(int pin, int mode);
	void digitalWrite(int pin, int val);
	int digitalRead(int pin);

	//These provide a more advanced mapping of the chip functionality
	//See the data sheet for more information on what they do

	//Returns a word with the current pin states (ie contents of the GPIO register)
	word digitalWordRead();
	//Allows you to write a word to the GPIO register
	void digitalWordWrite(word w);
	//Sets up the polarity mask that the MCP23017 supports
	//if set to 1, it will flip the actual pin value.
	void inputPolarityMask(word mask);
	//Sets which pins are inputs or outputs (1 = input, 0 = output) NB Opposite to arduino's
	//definition for these
	void inputOutputMask(word mask);
	//Allows enabling of the internal 100k pullup resisters (1 = enabled, 0 = disabled)      
	void internalPullupMask(word mask);

	//Interrupt functionality (not yet implemented)


private:
	void writeRegister(int regaddress, byte val);
	void writeRegister(int regaddress, word val);
	word readRegister(int regaddress);
	//Our actual i2c address
	byte _i2cAddress;

	//Cached copies of the register vales
	word _GPIO, _IODIR, _GPPU;
};
#endif

