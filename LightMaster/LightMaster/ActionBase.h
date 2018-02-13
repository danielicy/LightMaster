#pragma once

#include "IAction.h"
#include "Lamp.h"
#include "LampsManager.h"
#include "OutputManger.h"

class LampsManager;

class ActionBase : public IAction
{
public:	
	ActionBase(LampsManager* lampsManager);
	~ActionBase();
	 
	virtual	void Execute() = 0;

protected:
	LampsManager* m_lampsManager;
	COutputManger* m_outputManager;
	int fadeAmount = 5;
	Lamp  m_currentLamp;
};

