
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


int * ColorManager::SetColor(byte  size, byte  color[])
{
	int * ret = new int[size];

	for (byte a = 0; a < size; a++)
		ret[a] = color[a];

	return ret;
}

int * ColorManager::SetRed(byte & size)
{

	byte color[] =  { REDPIN };
	size = sizeof(color) / sizeof(byte);
	return SetColor(size, color);
	
}

int * ColorManager::SetOrange(byte & size)
{	
	byte color[] = { ORANGEPIN };
	size = sizeof(color) / sizeof(byte);
	return SetColor(size, color);	
}

int * ColorManager::SetYellow(byte & size)
{
	byte color[] = { YELLOWPIN };
	size = sizeof(color) / sizeof(byte);
	return SetColor(size, color);	
}

int * ColorManager::SetGreen(byte & size)
{
	byte color[] = { GREENPIN }; 
	size = sizeof(color) / sizeof(byte);
	return SetColor(size, color);	
}

int * ColorManager::SetRedOrange(byte & size)
{
	byte color[] = { REDPIN, ORANGEPIN };
	size = sizeof(color) / sizeof(byte);
	return SetColor(size, color);
}

int * ColorManager::SetRedYellow(byte & size)
{
	byte color[] = { REDPIN, YELLOWPIN };
	size = sizeof(color) / sizeof(byte);
	return SetColor(size, color);
}

int * ColorManager::SetRedGreen(byte & size)
{
	byte color[] = { REDPIN   , GREENPIN };
	size = sizeof(color) / sizeof(byte);
	return SetColor(size, color);
}

//
int * ColorManager::SetOrangeYellow(byte & size)
{
	byte color[] = { ORANGEPIN   , YELLOWPIN };
	size = sizeof(color) / sizeof(byte);
	return SetColor(size, color);
}
int * ColorManager::SetOrangeGreen(byte & size)
{
	byte color[] = { ORANGEPIN   , GREENPIN };
	size = sizeof(color) / sizeof(byte);
	return SetColor(size, color);
}
int * ColorManager::SetYellowGreen(byte & size)
{
	byte color[] = { YELLOWPIN   , GREENPIN };
	size = sizeof(color) / sizeof(byte);
	return SetColor(size, color);
}
int * ColorManager::SetOrangeRedYellowOrange(byte & size)
{
	byte color[] = { REDPIN, ORANGEPIN , YELLOWPIN };
	size = sizeof(color) / sizeof(byte);
	return SetColor(size, color);
}

//

int * ColorManager::SetRedOrangeYellowGreen(byte & size)
{
	byte color[] = { REDPIN, ORANGEPIN , YELLOWPIN ,GREENPIN };
	size = sizeof(color) / sizeof(byte);
	return SetColor(size, color);
}

 