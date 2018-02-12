#pragma once

#include <stdlib.h>

#include "ActionBase.h"
#include "Lamp.h"
#include "LampsManager.h"

class Chaser :
	public ActionBase
{
public:
	Chaser(LampsManager *lampsManager);
	~Chaser();

	// Inherited via ActionBase
	virtual void Execute() override;

	 void ColorChangedEventHandler(int nValue);
//private:
//	void hookEvent(LampsManager* nVal);
//	void unhookEvent(LampsManager* nVal);
};

