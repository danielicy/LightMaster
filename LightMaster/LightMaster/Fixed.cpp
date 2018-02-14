
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

	delete[] m_outputManager;
}

Fixed::Fixed(LampsManager * lampsManager) :ActionBase(lampsManager)
{
	
	m_lampsManager->SetColorChangedEvent(ColorChangedHandler);
	ColorChangedHandler(lampsManager);
}

Fixed::~Fixed()
{
	
}



void Fixed::Execute()
{
	
	
}

void Fixed::Dispose()
{
	ActionBase::~ActionBase();
	m_outputManager->Log("Disposing Fixed Program");
	m_lampsManager->DisposeColorChangedEvent();
	m_outputManager->Log("Disposed Fixed Program");
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



