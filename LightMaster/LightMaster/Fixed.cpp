
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
	for (int x = 0; x < m_lampsManager->GetSize(); x++)
	{
		m_lampsManager->SetLampState(x, MAX_PMW_VAL);
			//SetCurrentLampState(MAX_PMW_VAL);

		m_lampsManager->MoveNext();
	}

}

Fixed::~Fixed()
{
	
}



void Fixed::Execute()
{
	/*if (m_lampsManager->IsLampChanged())
	{		 
		for (int x = 0; x < m_lampsManager->GetSize(); x++)
		{					
			m_lampsManager->SetCurrentLampState(MAX_PMW_VAL);	
						
			m_lampsManager->MoveNext();			
		}
	
		m_lampsManager->LampChanged();

	}*/
	
}





