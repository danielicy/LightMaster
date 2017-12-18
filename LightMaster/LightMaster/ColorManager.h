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
	
	int*  SetRed(int & size);
	int*  SetYellow(int & size);
	int*  SetGreen(int & size);
	int*  SetRedYellow(int & size);
	int*  SetRedGreen(int & size);
	int*  SetYellowGreen(int & size);
	int*  SetRedYellowGreen(int & size);
	
};

