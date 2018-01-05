#pragma once

#include "IAction.h"
#include "Lamp.h"
#include "LampsManager.h"

class ActionBase : public IAction
{
public:
	ActionBase(LampsManager* lampsManager);
	~ActionBase();
	 
	virtual	void Execute() = 0;

protected:
	LampsManager* m_lampsManager;
};

