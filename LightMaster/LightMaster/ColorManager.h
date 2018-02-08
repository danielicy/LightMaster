#pragma once
#include "LMSystem.h"
/*
#define D0 16
#define D1 5 // I2C Bus SCL (clock)
#define D2 4 // I2C Bus SDA (data)
#define D3 0
#define D4 2 // Same as "LED_BUILTIN", but inverted logic
#define D5 14 // SPI Bus SCK (clock)
#define D6 12 // SPI Bus MISO
#define D7 13 // SPI Bus MOSI
#define D8 15 // SPI Bus SS (CS)
#define D9 3 // RX0 (Serial console)
#define D10 1 // TX0 (Serial console)
*/

#ifndef ORANGEPIN
#define REDPIN  D_3
#define ORANGEPIN  D_4
#define YELLOWPIN  D_5
#define GREENPIN  D_6

#endif

#define DELAY 1000

class ColorManager
{
public:
	ColorManager();
	~ColorManager();
	
	

	int*  SetRed(byte & size);
	int*  SetOrange(byte & size);
	int*  SetYellow(byte & size);
	int*  SetGreen(byte & size);
	int*  SetRedOrange(byte & size);
	int*  SetRedYellow(byte & size);
	int*  SetRedGreen(byte & size);
	int * SetOrangeYellow(byte & size);
	int * SetOrangeGreen(byte & size);
	int * SetOrangeRedYellowOrange(byte & size);
	int * SetYellowGreen(byte & size);
	int*  SetRedOrangeYellowGreen(byte & size);

private:
	int * SetColor(byte  size, byte  color[]);

	
};

