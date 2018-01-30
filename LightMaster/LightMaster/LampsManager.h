#pragma once

#define MAX_PMW_VAL 1023

#include "Lamp.h"


class LampsManager
{
public:
	LampsManager();
	~LampsManager();

	void SetLamps(int  *lampArray, int size);	
	void SetCurrentLampState(int state);
	void SetLampState(int lamp,int state);
	Lamp MoveNext();
	Lamp GetCurrentLamp();
	int GetSize();
	Lamp* GetLamps();
	Lamp GetLamp(int idx);
private:
	int m_size;
 	volatile int m_CurrentIndex;
	Lamp* m_lamps;
};

