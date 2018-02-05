#pragma once

#define MAX_PMW_VAL 255

#include "Lamp.h"
#include "ColorManager.h"

class ColorManager;

class LampsManager
{
public:
	LampsManager(ColorManager* colorManager );
	~LampsManager();

	void SetLamps(int  lampindex);
	void SetCurrentLampState(int state);
	void SetLampState(int lamp,int state);
	Lamp MoveNext();
	Lamp GetCurrentLamp();
	int GetSize();
	Lamp* GetLamps();
	Lamp GetLamp(int idx);
private:
	int m_size;
	int m_CurrentIndex;
	Lamp* m_lamps;
	ColorManager* m_colorManager;
};

