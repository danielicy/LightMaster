#pragma once

#define MAX_PMW_VAL 255

#include "Lamp.h"
#include "ColorManager.h"
#include "OutputManger.h"

class ColorManager;
class COutputManger;

class LampsManager
{
public:	
	LampsManager(ColorManager * colorManager, COutputManger * outputManger);
	~LampsManager();

	void SetLamps(short  lampindex);
	void SetCurrentLampState(short state);
	void SetLampState(short lamp, short state);
	Lamp MoveNext();
	Lamp GetCurrentLamp();
	int GetSize();
	Lamp* GetLamps();
	Lamp GetLamp(short idx);
private:
	short m_size;
	short m_CurrentIndex;
	Lamp* m_lamps;
	ColorManager* m_colorManager;
	COutputManger* m_outputManager;
};

