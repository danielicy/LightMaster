
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "stdfax.h"
#endif

#include "ActionBase.h"
#include "Lamp.h"
#include "LampsManager.h"


ActionBase::ActionBase(LampsManager* lampsManager)
{	
	m_lampsManager = lampsManager;
	m_outputManager = new COutputManger();
}


ActionBase::~ActionBase()
{
	delete[] m_outputManager;
}
