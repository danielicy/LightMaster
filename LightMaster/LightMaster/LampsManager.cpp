
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "stdfax.h"

#endif
#include <stdlib.h>

#include "Lamp.h"
#include "LampsManager.h"
#include "ColorManager.h"

LampsManager::LampsManager(ColorManager* colorManager, COutputManger* outputManger)
{
	m_size = 1;
	m_CurrentIndex = 0;
	m_outputManager = outputManger;
	m_colorManager = colorManager;
}

LampsManager::~LampsManager()
{
}


void LampsManager::SetLamps(int lampindex)
{

	int *col =nullptr;
	int  size;	
 
	switch (lampindex)
	{
	case 1:
		col =  m_colorManager->SetRed(size);	 
		break;
	case 2:
		col =   m_colorManager->SetOrange(size);		 
		break;
	case 3:
		col = m_colorManager->SetYellow(size);
		break;
	case 4:
		col = m_colorManager->SetGreen(size);
		break;
	case 5:
		col = m_colorManager->SetRedOrange(size);
		break;
	case 6:
		col = m_colorManager->SetRedYellow(size);
		break;
	case 7:
		col = m_colorManager->SetRedGreen(size);
		break;
	case 8:
		col = m_colorManager->SetOrangeYellow(size);
		break;
	case 9:
		col = m_colorManager->SetOrangeGreen(size);
		break;
	case 10:
		col = m_colorManager->SetYellowGreen(size);
		break;
	case 11:
		col = m_colorManager->SetRedOrangeYellowGreen(size);
		break;
	case 12:
		col = m_colorManager->SetOrangeRedYellowOrange(size);
	default:
		break;
	}


	m_outputManager->Log("col 0: ", col[0]);
	m_outputManager->Log("col 1: ", col[1]);
	m_outputManager->Log("col 2: ", col[2]);
	m_outputManager->Log("col 3: ", col[3]);
	//resets and disposes previous lamps
	
	ResetLamps();

	if(m_lamps != NULL)
	delete[] m_lamps;

	m_lamps = new Lamp[size];
	
	m_outputManager->Log("size ",size);

	//delay(1000);
	for (int i = 0; i < size; i++)
	{
		m_lamps[i].LampName = col[i];
		m_lamps[i].State = 0;
	} 
	
//	delay(500);
	m_size = size;
	 
	m_isLampChanged = true;
	

	delete[] col;

	m_outputManager->Log("deleted col ");	

}

void LampsManager::ResetLamps()
{
	if (m_lamps != NULL)
	{
		m_outputManager->Log("Reseting Lamps");
		SetCurrentLampState(0);
		m_CurrentIndex = 0;

		if (m_size > 0)
		{
			for (int ix = 0; ix < m_size; ix++)
			{				
				SetLampState(ix, 0);
				m_outputManager->Log("reseted LampName: ", m_lamps[ix].LampName);				

			}
		}

		m_outputManager->Log("All Lamps Are Reset");
		
	}
}


void LampsManager::SetCurrentLampState(int state)
{
	 
	m_outputManager->Log("LampsManager SettingCurrentLampState began\n Current LampState: ", m_lamps[m_CurrentIndex].State);
	m_lamps[m_CurrentIndex].State = state;
	AnaloglWrite(GetCurrentLamp().LampName, m_lamps[m_CurrentIndex].State);
	m_outputManager->Log("LampsManager SettingCurrentLampState ended\n LampName: ", GetCurrentLamp().LampName);
	
}

void LampsManager::SetLampState(int lampIndex, int state)
{	 
	m_lamps[lampIndex].State = state;
	AnaloglWrite(m_lamps[lampIndex].LampName, state);
}

Lamp LampsManager::MoveNext()
{
	m_CurrentIndex++;

	if (m_CurrentIndex == m_size)
	{
		m_CurrentIndex = 0;
	}

	m_outputManager->Log("Moving to Next Lamp\n ,m_CurrentIndex: ", m_CurrentIndex);
 
	m_outputManager->Log("LampName: ", m_lamps[m_CurrentIndex].LampName);

	return m_lamps[m_CurrentIndex];
}

Lamp LampsManager::GetCurrentLamp()
{
	return m_lamps[m_CurrentIndex];
}

int LampsManager::GetSize()
{
	m_outputManager->Log("Getting size: ", m_size);
	
	return m_size;
}

Lamp * LampsManager::GetLamps()
{
	return m_lamps;
}


bool LampsManager::IsLampChanged()
{	
	return m_isLampChanged;
}

void LampsManager::LampChanged()
{
	m_isLampChanged = false;
}
void LampsManager::AnaloglWrite(int pin, int value)
{
	m_outputManager->AnaloglWrite(pin, value);
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