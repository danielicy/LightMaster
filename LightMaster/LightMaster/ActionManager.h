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

	void AddLamp(int * arr, int size);

	
	ActionBase* LoadAction(int index);
	void Execute();
	
	 
	//Lamps LampsCollection();
private:
	Lamp* m_lamps;
	IAction* m_action;
	Lamps* LampCollection;
};

