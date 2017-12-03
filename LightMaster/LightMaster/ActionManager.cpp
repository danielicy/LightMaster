#include "ActionManager.h"


//https://stackoverflow.com/questions/8767166/passing-a-2d-array-to-a-c-function
ActionManager::ActionManager(int buffer[][2])//int &buffer)
{
	m_buffer = buffer[0];
}


ActionManager::~ActionManager()
{
}


void ActionManager::Fade()
{
	/*
	Serial.println("Fading:");
	

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
