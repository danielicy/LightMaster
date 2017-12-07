
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "stdfax.h"
#endif

#include "ActionBase.h"
#include "Lamp.h"

ActionBase::ActionBase(Lamp *lamps)
{
	
	m_lamps = lamps;
}


ActionBase::~ActionBase()
{
}
