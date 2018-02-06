
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "stdfax.h"
#endif

#include "Fade.h"
#include "LampsManager.h"
#include "Lamp.h"
#include "OutputManger.h"

Fade::Fade(LampsManager* lampsNamager) :ActionBase(lampsNamager)
{
	m_currentLamp = m_lampsManager->GetCurrentLamp();
}


Fade::~Fade()
{
}

void Fade::Execute()
{	

	m_outputManager->Log("Fading Lamp:", m_currentLamp.LampName);
	m_outputManager->Log("state: ", m_currentLamp.State);
	m_outputManager->Log("----------------:");;
			

	// change the brightness for next time through the loop:
	m_currentLamp.State = m_currentLamp.State + fadeAmount;
	
	m_lampsManager->SetCurrentLampState(m_currentLamp.State);
	
	m_outputManager->AnaloglWrite(m_currentLamp.LampName, m_currentLamp.State);
	
	// reverse the direction of the fading at the ends of the fade:
	if (m_currentLamp.State <= 0 || m_currentLamp.State >= MAX_PMW_VAL) {
		fadeAmount = -fadeAmount;
				
		if (m_currentLamp.State <= 0)
		 m_currentLamp = m_lampsManager->MoveNext();
	}

	// wait for 30 milliseconds to see the dimming effect	
	m_outputManager->Wait(30);	


}

