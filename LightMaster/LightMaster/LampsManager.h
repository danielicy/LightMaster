#pragma once
#include "Lamp.h"


class LampsManager
{
public:
	LampsManager();
	~LampsManager();

	void SetLamps(int  *lampArray, int size);	
	Lamp MoveNext();
private:
	int m_size;
	int m_CurrentIndex;
	Lamp lamps[];
};

