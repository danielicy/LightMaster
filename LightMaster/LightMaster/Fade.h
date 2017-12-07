#pragma once
#include "ActionBase.h"
#include "Lamp.h"

//#include "Arduino.h"

class Fade :
	public ActionBase
{
public:
	Fade(Lamp *lamps);
	~Fade();
	 
	// Inherited via ActionBase
	virtual void Execute() override;

};

