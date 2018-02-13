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

	void SetColorChangedEvent(void(*iChange)(LampsManager * lampsManager));
	void DisposeColorChangedEvent();

	void SetLamps(int  lampindex);
	void SetCurrentLampState(int state);
	void SetLampState(int lamp,int state);
	Lamp MoveNext();
	Lamp GetCurrentLamp();
	int GetSize();
	Lamp* GetLamps();
	Lamp GetLamp(int idx);
private:
	void(*colorChangedEvent)(LampsManager * lampsManager);
	int i;
	int m_size;
	int m_CurrentIndex;
	Lamp* m_lamps;
	ColorManager* m_colorManager;
	COutputManger* m_outputManager;
};

