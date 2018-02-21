#pragma once
#include "ActionBase.h"
#include "Lamp.h"
#include "LampsManager.h"


class Fade :
	public ActionBase
{
public:
	Fade(LampsManager *lampsManager);
	~Fade();
	 
	// Inherited via ActionBase
	virtual void Execute() override;
	
};

