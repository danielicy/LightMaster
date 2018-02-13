#pragma once
#include "ActionBase.h"
#include "Lamp.h"
#include "LampsManager.h"

class Fixed :
	public ActionBase
{
public:	
	Fixed(LampsManager *lampsManager);
	~Fixed();

	void  setLampsState();

	// Inherited via ActionBase
	virtual void Execute() override;

	
	 
};

