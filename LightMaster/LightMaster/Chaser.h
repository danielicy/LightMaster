#pragma once
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
};

