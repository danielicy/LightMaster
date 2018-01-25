
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

	m_size = 1;
	m_CurrentIndex = 0;	
	
}

LampsManager::~LampsManager()
{
}

void LampsManager::SetLamps(int *lampArray, int size)
{
	//Lamp* tLamps = new Lamp[size];

	
	//resets lamps
	//memset(lamps, -1, sizeof(Lamp)*m_size);
	//memcpy( lamps, tlamps,20 * sizeof(int));
	if(lamps != NULL)
	delete[] lamps;

	lamps = new Lamp[size];




	//clears lamps array
	for (int i = 0; i < m_size; i++)
	{
		lamps[i].LampName = -1;
		lamps[i].State = 0;
	}

	
	for (int i = 0; i < size; i++)
	{
		  lamps[i].LampName = lampArray[i];
		 lamps[i].State = 0;
	}  
	m_size = size;
}

void LampsManager::SetCurrentLampState(int state)
{
	lamps[m_CurrentIndex].State = state;
}

void LampsManager::SetLampState(int lamp, int state)
{	 
	lamps[lamp].State = state;
}

Lamp LampsManager::MoveNext()
{
	m_CurrentIndex++;

	if (m_CurrentIndex== m_size)
	{
		m_CurrentIndex = 0;
	}
 
	return lamps[m_CurrentIndex];
}

Lamp LampsManager::GetCurrentLamp()
{
	return lamps[m_CurrentIndex];
}

int LampsManager::GetSize()
{
	return m_size;
}

Lamp * LampsManager::GetLamps()
{
	return lamps;
}

Lamp LampsManager::GetLamp(int idx)
{
	return lamps[idx];
}

 

void resize(int size, Lamp arr[]) {
	size_t newSize = size * 2;
	Lamp* newArr = new Lamp[newSize];

	memcpy(newArr, arr, size * sizeof(int));

	size = newSize;
	delete[] arr;
	arr = newArr;
}