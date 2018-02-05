
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


int * ColorManager::SetColor(int & size, int  color[])
{
	size = sizeof(color) / sizeof(int);
	
	int * ret = new int[size];

	for (int a = 0; a < size; a++)
		ret[a] = color[a];

	return ret;
}

int * ColorManager::SetRed(int & size)
{

	int color[] = {REDPIN};
	return SetColor(size, color);
	
}

int * ColorManager::SetOrange(int & size)
{	
	int color[] = { ORANGEPIN };
	return SetColor(size, color);	
}

int * ColorManager::SetYellow(int & size)
{
	int color[] = { YELLOWPIN };
	return SetColor(size, color);	
}

int * ColorManager::SetGreen(int & size)
{
	int color[] = { GREENPIN }; 
	return SetColor(size, color);	
}

int * ColorManager::SetRedYellow(int & size)
{
	int color[] = { REDPIN, YELLOWPIN };
	
	return SetColor(size, color);
}

int * ColorManager::SetRedGreen(int & size)
{
	int color[] = { REDPIN, GREENPIN };
	
	return SetColor(size, color);
}

int * ColorManager::SetYellowGreen(int & size)
{
	int color[] = {  YELLOWPIN   , GREENPIN };
	
	return SetColor(size, color);
}

//
int * ColorManager::SetOrangeYellow(int & size)
{
	int color[] = { ORANGEPIN   , YELLOWPIN };
	
	return SetColor(size, color);
}
int * ColorManager::SetOrangeGreen(int & size)
{
	int color[] = { ORANGEPIN   , GREENPIN };
	
	return SetColor(size, color);
}
int * ColorManager::SetOrangeRed(int & size)
{
	int color[] = { ORANGEPIN   , REDPIN };
	
	return SetColor(size, color);
}
int * ColorManager::SetOrangeRedYellowGreen(int & size)
{
	int color[] = { ORANGEPIN ,REDPIN  , YELLOWPIN,GREENPIN };
	
	return SetColor(size, color);
}

//

int * ColorManager::SetRedYellowGreen(int & size)
{
	int color[] = { ORANGEPIN, YELLOWPIN   , GREENPIN };
	
	return SetColor(size, color);
}

 