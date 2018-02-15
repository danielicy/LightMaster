
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
	int size = lampsManager->GetSize();
	COutputManger * m_outputManager = new COutputManger();
	for (int x = 0; x < size; x++)
	{
		m_outputManager->Log("Fixed colorchangedEvent handler",size);
		lampsManager->SetCurrentLampState(MAX_PMW_VAL);
		m_outputManager->AnaloglWrite(lampsManager->GetCurrentLamp().LampName, MAX_PMW_VAL);
		lampsManager->MoveNext();
		m_outputManager->Log("Fixxed colorchangedEvent Handled", x);
		m_outputManager->Wait(3000);
	}

	m_outputManager->Log("Color Changed Event finished");
	m_outputManager->Wait(2000);

	delete m_outputManager;
}

Fixed::Fixed(LampsManager * lampsManager) :ActionBase(lampsManager)
{
	
	m_lampsManager->SetColorChangedEvent(ColorChangedHandler);
	ColorChangedHandler(lampsManager);
}

Fixed::~Fixed()
{
	m_outputManager->Log("Disposing Fixed Program");
	m_lampsManager->DisposeColorChangedEvent();
	m_outputManager->Log("Disposed Fixed Program");
}



void Fixed::Execute()
{
	
	
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



