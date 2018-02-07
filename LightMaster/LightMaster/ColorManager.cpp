
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


int * ColorManager::SetColor(short  size, short  color[])
{
	int * ret = new int[size];

	for (short a = 0; a < size; a++)
		ret[a] = color[a];

	return ret;
}

int * ColorManager::SetRed(short & size)
{

	short color[] =  { REDPIN };
	size = sizeof(color) / sizeof(short);
	return SetColor(size, color);
	
}

int * ColorManager::SetOrange(short & size)
{	
	short color[] = { ORANGEPIN };
	size = sizeof(color) / sizeof(short);
	return SetColor(size, color);	
}

int * ColorManager::SetYellow(short & size)
{
	short color[] = { YELLOWPIN };
	size = sizeof(color) / sizeof(short);
	return SetColor(size, color);	
}

int * ColorManager::SetGreen(short & size)
{
	short color[] = { GREENPIN }; 
	size = sizeof(color) / sizeof(short);
	return SetColor(size, color);	
}

int * ColorManager::SetRedOrange(short & size)
{
	short color[] = { REDPIN, ORANGEPIN };
	size = sizeof(color) / sizeof(short);
	return SetColor(size, color);
}

int * ColorManager::SetRedYellow(short & size)
{
	short color[] = { REDPIN, YELLOWPIN };
	size = sizeof(color) / sizeof(short);
	return SetColor(size, color);
}

int * ColorManager::SetRedGreen(short & size)
{
	short color[] = { REDPIN   , GREENPIN };
	size = sizeof(color) / sizeof(short);
	return SetColor(size, color);
}

//
int * ColorManager::SetOrangeYellow(short & size)
{
	short color[] = { ORANGEPIN   , YELLOWPIN };
	size = sizeof(color) / sizeof(short);
	return SetColor(size, color);
}
int * ColorManager::SetOrangeGreen(short & size)
{
	short color[] = { ORANGEPIN   , GREENPIN };
	size = sizeof(color) / sizeof(short);
	return SetColor(size, color);
}
int * ColorManager::SetYellowGreen(short & size)
{
	short color[] = { YELLOWPIN   , GREENPIN };
	size = sizeof(color) / sizeof(short);
	return SetColor(size, color);
}
int * ColorManager::SetOrangeRedYellowOrange(short & size)
{
	short color[] = { REDPIN, ORANGEPIN , YELLOWPIN };
	size = sizeof(color) / sizeof(short);
	return SetColor(size, color);
}

//

int * ColorManager::SetRedOrangeYellowGreen(short & size)
{
	short color[] = { REDPIN, ORANGEPIN , YELLOWPIN ,GREENPIN };
	size = sizeof(color) / sizeof(short);
	return SetColor(size, color);
}

 