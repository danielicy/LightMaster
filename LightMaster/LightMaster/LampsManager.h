#pragma once
#include "Lamp.h"


class LampsManager
{
public:
	LampsManager();
	~LampsManager();

	void SetLamps(int  *lampArray, int size);	
	void SetCurrentLampState(int state);
	Lamp MoveNext();
	Lamp GetCurrentLamp();

private:
	int m_size;
	int m_CurrentIndex;
	Lamp lamps[];
};

