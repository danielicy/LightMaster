#pragma once

#include "Lamp.h"
#include "LMSystem.h"


#include "IAction.h"

#include "LampsManager.h"
#include "OutputManger.h"


class LampsManager;
struct Lamp;

class ActionBase : public IAction
{
	
public:
	ActionBase(LampsManager* lampsManager);
	~ActionBase();
	 
	virtual	void Execute() = 0;

protected:
	Lamp m_currentLamp;
	LampsManager* m_lampsManager;
	COutputManger* m_outputManager;	
	byte fadeAmount = 5;	
};

