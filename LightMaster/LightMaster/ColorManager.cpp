
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


int * ColorManager::SetColor(int  size, int  color[])
{
	int * ret = new int[size];

	for (int a = 0; a < size; a++)
		ret[a] = color[a];

	return ret;
}

int * ColorManager::SetRed(int & size)
{

	int color[] =  { REDPIN };
	size = sizeof(color) / sizeof(int);
	return SetColor(size, color);
	
}

int * ColorManager::SetOrange(int & size)
{	
	int color[] = { ORANGEPIN };
	size = sizeof(color) / sizeof(int);
	return SetColor(size, color);	
}

int * ColorManager::SetYellow(int & size)
{
	int color[] = { YELLOWPIN };
	size = sizeof(color) / sizeof(int);
	return SetColor(size, color);	
}

int * ColorManager::SetGreen(int & size)
{
	int color[] = { GREENPIN }; 
	size = sizeof(color) / sizeof(int);
	return SetColor(size, color);	
}

int * ColorManager::SetRedOrange(int & size)
{
	int color[] = { REDPIN, ORANGEPIN };
	size = sizeof(color) / sizeof(int);
	return SetColor(size, color);
}

int * ColorManager::SetRedYellow(int & size)
{
	int color[] = { REDPIN, YELLOWPIN };
	size = sizeof(color) / sizeof(int);
	return SetColor(size, color);
}

int * ColorManager::SetRedGreen(int & size)
{
	int color[] = { REDPIN   , GREENPIN };
	size = sizeof(color) / sizeof(int);
	return SetColor(size, color);
}

//
int * ColorManager::SetOrangeYellow(int & size)
{
	int color[] = { ORANGEPIN   , YELLOWPIN };
	size = sizeof(color) / sizeof(int);
	return SetColor(size, color);
}
int * ColorManager::SetOrangeGreen(int & size)
{
	int color[] = { ORANGEPIN   , GREENPIN };
	size = sizeof(color) / sizeof(int);
	return SetColor(size, color);
}
int * ColorManager::SetYellowGreen(int & size)
{
	int color[] = { YELLOWPIN   , GREENPIN };
	size = sizeof(color) / sizeof(int);
	return SetColor(size, color);
}
int * ColorManager::SetOrangeRedYellowOrange(int & size)
{
	int color[] = { REDPIN, ORANGEPIN , YELLOWPIN };
	size = sizeof(color) / sizeof(int);
	return SetColor(size, color);
}

//

int * ColorManager::SetRedOrangeYellowGreen(int & size)
{
	int color[] = { REDPIN, ORANGEPIN , YELLOWPIN ,GREENPIN };
	size = sizeof(color) / sizeof(int);
	return SetColor(size, color);
}

 