
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "stdfax.h"
#endif

#include "ActionBase.h"
#include "Lamp.h"

ActionBase::ActionBase(LampsManager* lampsManager)
{
	
	m_lampsManager = lampsManager;
}


ActionBase::~ActionBase()
{
}
