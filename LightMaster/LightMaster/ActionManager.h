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

	void SetLamps(int *lamps);

private:
	Lamp* m_lamps;
	IAction* m_action;
};

