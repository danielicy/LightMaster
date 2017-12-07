#pragma once

#include "IAction.h"
#include "Lamp.h"

class ActionBase : public IAction
{
public:
	ActionBase(Lamp *lamps);
	~ActionBase();
	 
	virtual	void Execute() = 0;

protected:
	Lamp *m_lamps;
};

