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
//#define REDPIN  D_3
//#define ORANGEPIN  D_4
//#define YELLOWPIN  D_5
//#define GREENPIN  D_6

#define REDPIN1			0
#define REDPIN2			1
#define YELLOWPIN		2
#define GREEN1PIN		3
#define GREEN2PIN		4
#define GREEN3PIN		5
#define GREEN4PIN		6
#define WRMWHITE1PIN	7
#define WRMWHITE2PIN	8
#define WRMWHITE3PIN	9
#define WHITE1PIN		10
#define WHITE2PIN		11
#define WHITE3PIN		12
#define PURPLE1PIN		13
#define PURPLE2PIN		14
#define PURPLE3PIN		15
#define BLUE1PIN		16
#define BLUE2PIN		17
#define BLUE3PIN		18
#endif

#define DELAY 1000

class ColorManager
{
public:
	ColorManager();
	~ColorManager();
	
	

	int*  SetRed(int & size);
	int*  SetOrange(int & size);
	int*  SetYellow(int & size);
	int*  SetGreen(int & size);
	int*  SetRedOrange(int & size);
	int*  SetRedYellow(int & size);
	int*  SetRedGreen(int & size);
	int * SetOrangeYellow(int & size);
	int * SetOrangeGreen(int & size);
	int * SetOrangeRedYellowOrange(int & size);
	int * SetYellowGreen(int & size);
	int*  SetRedOrangeYellowGreen(int & size);

private:
	int * SetColor(int  size, int  color[]);

	
};

