
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "stdfax.h"

#endif
#include <stdlib.h>

#include "Lamp.h"
#include "LampsManager.h"


LampsManager::LampsManager()
{
}

LampsManager::~LampsManager()
{
}

void LampsManager::SetLamps(int *lampArray, int size)
{
	//TO DO: Clear lamps
	

	for (int i = 0; i < size; i++)
	{
		  lamps[i].LampName = lampArray[i];
		 lamps[i].State = 0;
	}  
}

void resize(int size, Lamp arr[]) {
	size_t newSize = size * 2;
	Lamp* newArr = new Lamp[newSize];

	memcpy(newArr, arr, size * sizeof(int));

	size = newSize;
	delete[] arr;
	arr = newArr;
}