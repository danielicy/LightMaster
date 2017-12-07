#pragma once
#include "IAction.h"
#include "ActionBase.h"

class ActionManager
{
public:
	ActionManager(Lamp* lamps);//int &pinbuffer);
	~ActionManager();

	ActionBase* LoadAction(int index);
	void Execute();


private:
	Lamp *m_lamps;
	IAction* m_action;
};

