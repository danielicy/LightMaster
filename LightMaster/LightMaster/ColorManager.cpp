
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

int * ColorManager::SetRed()
{	
	int color[] = { REDPIN };
	return color;
}

int * ColorManager::SetYellow()
{
	int color[] = { YELLOWPIN };
	return color;
}

int * ColorManager::SetGreen()
{
	int color[] = { GREENPIN };
	return color;
}

int * ColorManager::SetRedYellow()
{
	int color[] = { REDPIN, YELLOWPIN };
	return color;
}

int * ColorManager::SetRedGreen()
{
	int color[] = { REDPIN, GREENPIN };
	return color;
}

int * ColorManager::SetYellowGreen()
{
	int color[] = {  YELLOWPIN   , GREENPIN };
	return color;
}

int * ColorManager::SetRedYellowGreen()
{
	int color[] = { REDPIN, YELLOWPIN   , GREENPIN };
	return color;
}

 