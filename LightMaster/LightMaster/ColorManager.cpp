#include "ColorManager.h"
#include "Arduino.h"

ColorManager::ColorManager()
{
}



ColorManager::~ColorManager()
{
}

int * ColorManager::SetRed()
{

	Serial.println("RED");
	delay(DELAY);
	int color[] = { REDPIN };
	return color;
}

int * ColorManager::SetYellow()
{
	Serial.println("Yellow");
	delay(DELAY);
	int color[] = { YELLOWPIN };
	return color;
}

int * ColorManager::SetGreen()
{
	Serial.println("Green");
	delay(DELAY);
	int color[] = { GREENPIN };
	return color;
}

int * ColorManager::SetRedYellow()
{
	Serial.println("RedYellow");
	delay(DELAY);
	int color[] = { REDPIN, YELLOWPIN };
	return color;
}

int * ColorManager::SetRedGreen()
{
	Serial.println("RedGreen");
	delay(DELAY);
	int color[] = { REDPIN, GREENPIN };
	return color;
}

int * ColorManager::SetYellowGreen()
{
 
	Serial.println("YelloGreen");
	delay(DELAY);
	int color[] = {  YELLOWPIN   , GREENPIN };
	return color;
}

int * ColorManager::SetRedYellowGreen()
{
	Serial.println("RedYellowGreen");
	delay(DELAY);
	int color[] = { REDPIN, YELLOWPIN   , GREENPIN };
	return color;
}

 