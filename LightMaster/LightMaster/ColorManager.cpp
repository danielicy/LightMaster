
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "stdfax.h"
#endif

#include "ColorManager.h"


ColorManager::ColorManager()
{
}



ColorManager::~ColorManager()
{
}

int * ColorManager::SetRed(int & size)
{	
	int color[] = { REDPIN };	
	size = sizeof(color) / sizeof(int);
	return color;
}

int * ColorManager::SetYellow(int & size)
{
	int color[] = { YELLOWPIN };
	size = sizeof(color) / sizeof(int);
	return color;
}

int * ColorManager::SetGreen(int & size)
{
	int color[] = { GREENPIN };
	size = sizeof(color) / sizeof(int);
	return color;
}

int * ColorManager::SetRedYellow(int & size)
{
	int color[] = { REDPIN, YELLOWPIN };
	size = sizeof(color) / sizeof(int);
	return color;
}

int * ColorManager::SetRedGreen(int & size)
{
	int color[] = { REDPIN, GREENPIN };
	size = sizeof(color) / sizeof(int);
	return color;
}

int * ColorManager::SetYellowGreen(int & size)
{
	int color[] = {  YELLOWPIN   , GREENPIN };
	size = sizeof(color) / sizeof(int);
	return color;
}

int * ColorManager::SetRedYellowGreen(int & size)
{
	int color[] = { REDPIN, YELLOWPIN   , GREENPIN };
	size = sizeof(color) / sizeof(int);
	return color;
}

 