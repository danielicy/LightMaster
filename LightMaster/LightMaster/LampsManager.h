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

	
	void SetLamps(int  lampindex);
	void ResetLamps();
	void SetCurrentLampState(int state);
	void SetLampState(int lamp,int state);
	Lamp MoveNext();
	Lamp GetCurrentLamp();
	int GetSize();
	Lamp* GetLamps();
	Lamp GetLamp(int idx);
	bool IsLampChanged();
	void LampChanged();
	

private:
	void AnaloglWrite(int pin, int value);
	bool m_isLampChanged;
	int m_size;
	int m_CurrentIndex;
	Lamp* m_lamps;
	ColorManager* m_colorManager;
	COutputManger* m_outputManager;
};

