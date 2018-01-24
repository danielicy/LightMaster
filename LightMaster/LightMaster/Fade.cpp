
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
}


Fade::~Fade()
{
}

void Fade::Execute()
{
	Lamp lamp = m_lampsManager->GetCurrentLamp();

	
	m_outputManager->DigitalWrite(lamp.LampName, lamp.State);

	// change the brightness for next time through the loop:
	lamp.State = lamp.State + fadeAmount;

	// reverse the direction of the fading at the ends of the fade:
	if (lamp.State <= 0 || lamp.State >= MAX_PMW_VAL) {
		fadeAmount = -fadeAmount;
		m_lampsManager->MoveNext();
	}

	m_lampsManager->SetCurrentLampState(lamp.State);


	m_outputManager->Wait(30);
	// wait for 30 milliseconds to see the dimming effect
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

