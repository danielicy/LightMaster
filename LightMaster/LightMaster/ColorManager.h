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

#define REDPIN1		0
#define REDPIN2		1
#define YELLOW		2
#define GREEN1		3
#define GREEN2		4
#define GREEN3		5
#define GREEN4		6
#define WRMWHITE1	7
#define WRMWHITE2	8
#define WRMWHITE3	9
#define WHITE1		10
#define WHITE2		11
#define WHITE3		12
#define PURPLE1		13
#define PURPLE2		14
#define PURPLE3		15
#define BLUE1		16
#define BLUE2		17
#define BLUE3		18
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

