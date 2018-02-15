#pragma once
#include "ActionBase.h"
#include "Lamp.h"
#include "LampsManager.h"


class Runner :
	public ActionBase
{
public:
	Runner(LampsManager *lampsManager);
	~Runner();

	// Inherited via ActionBase
	virtual void Execute() override;
	
};

