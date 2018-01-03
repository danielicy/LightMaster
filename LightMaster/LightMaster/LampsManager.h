#pragma once
#include "Lamp.h"


class LampsManager
{
public:
	LampsManager();
	~LampsManager();

	void SetLamps(int  *lampArray, int size);
	Lamp* GetLamps();
private:
	int m_size;
	Lamp lamps[];
};

