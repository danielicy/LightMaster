
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "stdfax.h"
#endif

#include "ActionBase.h"


ActionBase::ActionBase(int **arr)
{
	
	p_pinBuffer = arr;
}


ActionBase::~ActionBase()
{
}
