
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "stdfax.h"
#endif

#include "LampsManager.h"


LampsManager::LampsManager()
{
}

LampsManager::~LampsManager()
{
}

void LampsManager::SetLamps(int * arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		 lamps[i].LampName = arr[i];
		 lamps[i].State = 0;
	}  
}