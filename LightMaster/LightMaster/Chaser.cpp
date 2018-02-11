#pragma once
#include "Chaser.h"


#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "stdfax.h"
#endif

#include "Fade.h"
#include "LampsManager.h"
#include "Lamp.h"
#include "OutputManger.h"


void myEvent(int &iNum)
{
	printf("Value of property 'i' = %d.\n", iNum);
}
 

Chaser::Chaser(LampsManager* lampsNamager) :ActionBase(lampsNamager)
{
	m_currentLamp = m_lampsManager->GetCurrentLamp();
	m_multiFadeAmount = new int[m_lampsManager->GetSize()];
	
}

Chaser::~Chaser()
{
}

void Chaser::Execute()
{

}
