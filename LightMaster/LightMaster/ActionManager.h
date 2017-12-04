#pragma once
#include "IAction.h"
#include "ActionBase.h"

class ActionManager
{
public:
	ActionManager(int buffer[][2]);//int &pinbuffer);
	~ActionManager();

	ActionBase* LoadAction(int index);
	void Execute();
	

private:	
	int* m_buffer;
	IAction* m_action;
};

