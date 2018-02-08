#pragma once


#include "LMSystem.h"
#include "Lamp.h"

#include "IAction.h"

#include "LampsManager.h"
#include "OutputManger.h"

class Lamp;
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
	
	byte fadeAmount = 5;
	Lamp m_currentLamp;
};

