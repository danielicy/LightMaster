
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
	
	Serial.print("Fading Lamp:");
	Serial.println( m_currentLamp.LampName);
	Serial.print("state: ");
	Serial.println( m_currentLamp.State);
	Serial.println("----------------:");



	//m_outputManager->DigitalWrite(m_currentLamp.LampName, m_currentLamp.State);

	

	// change the brightness for next time through the loop:
	m_currentLamp.State = m_currentLamp.State + fadeAmount;
	
	m_lampsManager->SetCurrentLampState(m_currentLamp.State);
	
	/*Serial.print("m_currentLamp.LampName: ");
	Serial.println(m_currentLamp.LampName);
	Serial.print("m_currentLamp.State: ");
	Serial.println(m_currentLamp.State);
	delay(1000);*/
	analogWrite(m_currentLamp.LampName, m_currentLamp.State);
	// reverse the direction of the fading at the ends of the fade:
	if (m_currentLamp.State <= 0 || m_currentLamp.State >= MAX_PMW_VAL) {
		fadeAmount = -fadeAmount;
				
		 m_currentLamp = m_lampsManager->MoveNext();
	}

	// wait for 30 milliseconds to see the dimming effect	
	m_outputManager->Wait(30);

	Serial.println("Faded:");

	
	//delay(30);

	/*Serial.println("Fading:");
	delay(10000);*/
	/*
	analogWrite(pin, brightness);

	// change the brightness for next time through the loop:
	brightness = brightness + fadeAmount;

	// reverse the direction of the fading at the ends of the fade:
	if (brightness <= 0 || brightness >= 255) {
	fadeAmount = -fadeAmount;
	}
	// wait for 30 milliseconds to see the dimming effect
	delay(30);
	previouspin = pin;
	*/

}

