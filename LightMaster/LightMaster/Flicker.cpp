#include "Flicker.h"

#include "Fade.h"
#include "LampsManager.h"
#include "Lamp.h"
#include "OutputManger.h"

Flicker::Flicker(LampsManager* lampsNamager) :ActionBase(lampsNamager)
{
}


Flicker::~Flicker()
{
}

void Flicker::Execute()
{

	int size = m_lampsManager->GetSize();
		

	for (int indx = 0; indx < size; indx+=2)
	{
		ProcessLamp(indx);

		if (indx < size - 1)
		{
			ProcessLamp(indx + 1);
		}		
	}

	// reverse the direction of the fading at the ends of the fade:
	if (m_lastLampState <= 0 || m_lastLampState >= 255) {
		fadeAmount = -fadeAmount;
	}


}

void Flicker::ProcessLamp(int index)
{
	Lamp lamp1 = m_lampsManager->GetLamp(index);

	m_lastLampState = lamp1.State = lamp1.State + fadeAmount;


	m_lampsManager->AnaloglWrite(lamp1.LampName, lamp1.State);

	m_lampsManager->SetLampState(index, lamp1.State);
	
}

