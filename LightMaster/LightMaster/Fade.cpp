
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "stdfax.h"
#endif

#include "Fade.h"
#include "LampsManager.h"
#include "Lamp.h"


Fade::Fade(LampsManager* lampsNamager) :ActionBase(lampsNamager)
{
		
}


Fade::~Fade()
{
	
}

void Fade::Execute()
{	
	Lamp  lamp = m_lampsManager->GetCurrentLamp();
		  
	lamp.State = lamp.State + fadeAmount;
	 
	m_lampsManager->SetCurrentLampState(lamp.State);

	
	if (lamp.State <= 0 || lamp.State > MAX_PMW_VAL) {
		fadeAmount = -fadeAmount;

		//Serial.println("Fade Limit");

		if (lamp.State <= 0)
		  m_lampsManager->MoveNext();
	}	

}

