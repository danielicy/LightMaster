#pragma once
#include "IAction.h"
#include "ActionBase.h"
#include "LMSystem.h"
#include "Lamps.h"
#include "LampsManager.h"


class ActionManager
{
public:
	ActionManager(LampsManager* m_lampManager);//int &pinbuffer);
	~ActionManager();
			
	ActionBase* LoadAction(int index);
	void Execute();	 
	
private:
	LampsManager* m_lampManager;
	IAction* m_action;
	
};

