#pragma once
#include "ActionBase.h"


class Fade :
	public ActionBase
{
public:
	Fade(int **arr);
	~Fade();
	 
	// Inherited via ActionBase
	virtual void Execute() override;

};

