#pragma once


#ifndef REDPIN
#define REDPIN  3
#define YELLOWPIN  4
#define GREENPIN  5
#endif

#define DELAY 1000

class ColorManager
{
public:
	ColorManager();
	~ColorManager();
	
	int*  SetRed();
	int*  SetYellow();
	int*  SetGreen();
	int*  SetRedYellow();
	int*  SetRedGreen();
	int*  SetYellowGreen();
	int*  SetRedYellowGreen();
	
};

