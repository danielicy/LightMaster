#pragma once
#include "IAction.h"
#include "ActionBase.h"
#include "LMSystem.h"
#include "Lamps.h"



class ActionManager
{
public:
	ActionManager();//int &pinbuffer);
	~ActionManager();
			
	ActionBase* LoadAction(int index);
	void Execute();
	
	 
	
private:
	Lamp* m_lamps;
	IAction* m_action;
	
};

