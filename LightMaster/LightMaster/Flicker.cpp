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

	m_isEven = !m_isEven;

	Lamp* lamps = m_lampsManager->GetLamps();

	if (size % 2 == 0)
	{
		
	}
	else
	{
		
	}

	for (int indx = 0; indx < size; indx++)
	{
		Lamp lamp = m_lampsManager->GetLamp(indx);

		m_outputManager->DigitalWrite(lamp.LampName,lamp.State);
	}

}
