
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
		 
		for (int x = 0; x < m_lampsManager->GetSize(); x++)
		{		
			Serial.println("SettingCurrentLampState");
			m_lampsManager->SetCurrentLampState(MAX_PMW_VAL);		

			Serial.println("SetCurrentLampState finished");
			m_lampsManager->MoveNext();			
		}
	
		m_lampsManager->LampChanged();

	}
	
}





