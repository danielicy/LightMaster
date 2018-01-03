
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
	m_size = 0;
}

LampsManager::~LampsManager()
{
}

void LampsManager::SetLamps(int *lampArray, int size)
{
	 
	//resets lamps
	memset(lamps, 0, sizeof(Lamp)*m_size);
	
	for (int i = 0; i < size; i++)
	{
		  lamps[i].LampName = lampArray[i];
		 lamps[i].State = 0;
	}  
	m_size = size;
}

Lamp * LampsManager::GetLamps()
{
	return  lamps;
}

void resize(int size, Lamp arr[]) {
	size_t newSize = size * 2;
	Lamp* newArr = new Lamp[newSize];

	memcpy(newArr, arr, size * sizeof(int));

	size = newSize;
	delete[] arr;
	arr = newArr;
}