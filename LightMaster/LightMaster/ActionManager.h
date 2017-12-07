#pragma once
#include "IAction.h"
#include "ActionBase.h"
#include "LMSystem.h"

class ActionManager
{
public:
	ActionManager();//int &pinbuffer);
	~ActionManager();

	ActionBase* LoadAction(int index);
	void Execute();
	Lamp Lamps();

private:
	Lamp m_lamps[PINCNT];
	IAction* m_action;
};

