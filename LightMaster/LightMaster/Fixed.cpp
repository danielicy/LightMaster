
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "stdfax.h"
#endif

#include "Fixed.h"
#include "LampsManager.h"
#include "Lamp.h"
#include "OutputManger.h"



void ColorChangedHandler(LampsManager * lampsManager)
{
	COutputManger * m_outputManager = new COutputManger();
	for (int x = 0; x < lampsManager->GetSize(); x++)
	{
		lampsManager->SetCurrentLampState(MAX_PMW_VAL);
		m_outputManager->AnaloglWrite(lampsManager->GetCurrentLamp().LampName, MAX_PMW_VAL);
		lampsManager->MoveNext();
	}

	//m_outputManager->Log("Color Changed Event", m_currentLamp.LampName);
	m_outputManager->Wait(2000);
}

Fixed::Fixed(LampsManager * lampsManager) :ActionBase(lampsManager)
{
	
	m_lampsManager->SetColorChangedEvent(ColorChangedHandler);
	ColorChangedHandler(lampsManager);
}

Fixed::~Fixed()
{
	m_lampsManager->DisposeColorChangedEvent();
}



void Fixed::Execute()
{
	
	
}

void Fixed::Dispose()
{
	m_lampsManager->DisposeColorChangedEvent();
}


void  Fixed::setLampsState()
{
	for (int x = 0; x < m_lampsManager->GetSize(); x++)
	{
		m_lampsManager->SetCurrentLampState(MAX_PMW_VAL);
		m_outputManager->AnaloglWrite(m_lampsManager->GetCurrentLamp().LampName, MAX_PMW_VAL);
		m_lampsManager->MoveNext();
	}

	m_outputManager->Log("Color Changed Event", m_currentLamp.LampName);
	m_outputManager->Wait(2000);
}



