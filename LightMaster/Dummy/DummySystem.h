#pragma once
#include "../LightMaster/Lamp.h"

#define PINCNT 20

class DummySystem
{
public:
	DummySystem();
	~DummySystem();
	void DoWork(char c);

private:
	Lamp *m_lamps;
};

