
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "stdfax.h"
#endif

#include "Fixed.h"
#include "LampsManager.h"
#include "Lamp.h"
#include "OutputManger.h"

void Fixed::setLampsState()
{
	for (int x=0; x < m_lampsManager->GetSize();x++)
	{
		m_lampsManager->SetCurrentLampState(MAX_PMW_VAL);
		m_outputManager->AnaloglWrite(m_lampsManager->GetCurrentLamp().LampName, MAX_PMW_VAL);
		m_lampsManager->MoveNext();
	}
}

Fixed::Fixed(LampsManager * lampsManager) :ActionBase(lampsManager)
{
	setLampsState();
}

Fixed::~Fixed()
{
}

void Fixed::Execute()
{
	
	
}
