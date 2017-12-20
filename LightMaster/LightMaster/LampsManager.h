#pragma once
#include "Lamp.h"

class LampsManager
{
public:
	LampsManager();
	~LampsManager();

	void SetLamps(int * arr, int size);

private:
	Lamp lamps[];
};

