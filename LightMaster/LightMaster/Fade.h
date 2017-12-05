#pragma once
#include "ActionBase.h"
#include "Arduino.h"

class Fade :
	public ActionBase
{
public:
	Fade(int **arr);
	~Fade();
	 
	// Inherited via ActionBase
	virtual void Execute() override;

};

