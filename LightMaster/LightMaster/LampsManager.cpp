
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "stdfax.h"

#endif
#include <stdlib.h>

#include "Lamp.h"
#include "LampsManager.h"
#include "ColorManager.h"

LampsManager::LampsManager(ColorManager* colorManager )
{

	m_size = 1;
	m_CurrentIndex = 0;
	m_colorManager = new ColorManager();
	
}

LampsManager::~LampsManager()
{
}

void LampsManager::SetLamps(int lampindex)
{
	int col[20] = { 0 };
	int  size;
	
#if defined(ARDUINO) && ARDUINO >= 100
	Serial.print("lampindex: ");
	Serial.println(lampindex);
#endif
	switch (lampindex)
	{
	case 1:
	//	col =   m_colorManager->SetRed(size);
		memcpy( m_colorManager->SetRed(size),col, size * sizeof(int));
		break;
	case 2:
		//col = { 2 }; m_colorManager->SetOrange(size);
		memcpy( m_colorManager->SetOrange(size),col, size * sizeof(int));
		break;
	case 3:
		//col = m_colorManager->SetYellow(size);
		break;
	case 4:
		//col = m_colorManager->SetGreen(size);
		break;
	case 5:
		//col = m_colorManager->SetRedYellow(size);
		break;
	case 6:
		//col = m_colorManager->SetRedGreen(size);
		break;
	case 7:
		//col = m_colorManager->SetYellowGreen(size);
		break;

	case 8:
	//	col = m_colorManager->SetOrangeYellow(size);
		break;
	case 9:
		//col = m_colorManager->SetOrangeGreen(size);
		break;
	case 10:
		//col = m_colorManager->SetOrangeRed(size);
		break;
	case 11:
		//col = m_colorManager->SetOrangeRedYellowGreen(size);
		break;
	case 12:
	//	col = m_colorManager->SetRedYellowGreen(size);
	default:
		break;
	}
	//Lamp* tLamps = new Lamp[size];

	
	//resets lamps
	//memset(lamps, -1, sizeof(Lamp)*m_size);
	//memcpy( lamps, tlamps,20 * sizeof(int));
	if(m_lamps != NULL)
	delete[] m_lamps;

	m_lamps = new Lamp[size];




	//clears lamps array
	/*for (int i = 0; i < m_size; i++)
	{
		m_lamps[i].LampName = -1;
		m_lamps[i].State = 0;
	}*/

	Serial.print("size:");
	Serial.println(size);
	delay(3000);
	for (int i = 0; i < size; i++)
	{

		m_lamps[i].LampName = col[i];
		m_lamps[i].State = 0;
#if defined(ARDUINO) && ARDUINO >= 100
		Serial.print("i:");
		Serial.println(i);
		Serial.print("col[i]: ");
		Serial.println(col[i]);
		delay(7000);
#endif
	}  
	m_size = size;
	delete[] col;
}

void LampsManager::SetCurrentLampState(int state)
{
	m_lamps[m_CurrentIndex].State = state;
}

void LampsManager::SetLampState(int lamp, int state)
{	 
	m_lamps[lamp].State = state;
}

Lamp LampsManager::MoveNext()
{
	m_CurrentIndex++;

	if (m_CurrentIndex== m_size)
	{
		m_CurrentIndex = 0;
	}

 
 
#if defined(ARDUINO) && ARDUINO >= 100
	Serial.print("MoveNext: ");
	Serial.print("m_CurrentIndex: ");
	Serial.println(m_CurrentIndex);
#endif

	return m_lamps[m_CurrentIndex];
}

Lamp LampsManager::GetCurrentLamp()
{
#if defined(ARDUINO) && ARDUINO >= 100
	Serial.print("m_CurrentIndex: ");
	Serial.println(m_CurrentIndex);
	Lamp i = m_lamps[m_CurrentIndex];
	Serial.print("lampName: ");
	Serial.println(i.LampName);
#endif

	return m_lamps[m_CurrentIndex];
}

int LampsManager::GetSize()
{
	return m_size;
}

Lamp * LampsManager::GetLamps()
{
	return m_lamps;
}

Lamp LampsManager::GetLamp(int idx)
{
	return m_lamps[idx];
}

 

void resize(int size, Lamp arr[]) {
	size_t newSize = size * 2;
	Lamp* newArr = new Lamp[newSize];

	memcpy(newArr, arr, size * sizeof(int));

	size = newSize;
	delete[] arr;
	arr = newArr;
}