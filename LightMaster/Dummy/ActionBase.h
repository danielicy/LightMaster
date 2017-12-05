#pragma once

#include "IAction.h"

class ActionBase : public IAction
{
public:
	ActionBase(int **arr);
	~ActionBase();
	 
	virtual	void Execute() = 0;

protected:
	int** p_pinBuffer;
};

