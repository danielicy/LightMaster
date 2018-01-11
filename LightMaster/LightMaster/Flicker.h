#pragma once
#include "ActionBase.h"
#include "Lamp.h"
#include "LampsManager.h"

class Flicker :
	public ActionBase
{
public:
	Flicker(LampsManager* lampsNamager);
	~Flicker();

	// Inherited via ActionBase
	virtual void Execute() override;

private:
	void ProcessLamp(int index);
	int m_lastLampState;
};

