#pragma once
#include "ActionBase.h"
#include "Lamp.h"
#include "LampsManager.h"

class Flicker :
	public ActionBase
{
public:
	Flicker(LampsManager* lampsNamager);
	~Flicker();

	// Inherited via ActionBase
	virtual void Execute() override;

private:
	bool m_isEven;
};

