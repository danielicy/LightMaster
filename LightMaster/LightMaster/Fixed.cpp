
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "stdfax.h"
#endif

#include "Fixed.h"
#include "LampsManager.h"
#include "Lamp.h"
#include "OutputManger.h"





Fixed::Fixed(LampsManager * lampsManager) :ActionBase(lampsManager)
{
		
}

Fixed::~Fixed()
{
	
}



void Fixed::Execute()
{
	if (m_lampsManager->IsLampChanged())
	{
		int size = m_lampsManager->GetSize();

		for (int x = 0; x < size; x++)
		{
			//m_outputManager->Log("Fixed colorchangedEvent handler", size);
			m_lampsManager->SetCurrentLampState(MAX_PMW_VAL);

		

			m_lampsManager->MoveNext();
			//m_outputManager->Log("Fixxed colorchangedEvent Handled", x);
			//m_outputManager->Wait(3000);
		}

	//	m_outputManager->Log("Color Changed Event finished");
	//	m_outputManager->Wait(2000);

		m_lampsManager->LampChanged();

	}
	
}





