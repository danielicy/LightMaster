
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

	//Serial.print("  ");
	////m_currentLamp.State = m_currentLamp.State + fadeAmount;
	//Serial.print("Fade state: ");
	//Serial.println(m_lampsManager->GetCurrentLamp().State);

	//Serial.print("fadeAmonut::");
	//Serial.println(fadeAmount);
	//
	//int newstate = m_lampsManager->GetCurrentLamp().State + fadeAmount;

	//Serial.print("newstate::");
	//Serial.println(newstate);
	//Serial.print("  ");
	//
	
	
	//Serial.print("New state: ");
	//Serial.println(m_lampsManager->GetCurrentLamp().State);
	//delay(5000);
	// reverse the direction of the fading at the ends of the fade:
	if (lamp.State <= 0 || lamp.State > MAX_PMW_VAL) {
		fadeAmount = -fadeAmount;

		//Serial.println("Fade Limit");

		if (lamp.State <= 0)
		  m_lampsManager->MoveNext();
	}
	

}

