#pragma once
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
	int m_CurrentIndex;
	Lamp lamps[];
};

