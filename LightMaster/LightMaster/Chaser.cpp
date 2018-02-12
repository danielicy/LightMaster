#pragma once
#include "Chaser.h"
#include <stdio.h>  

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "stdfax.h"
#endif

#include "Fade.h"
#include "LampsManager.h"
#include "Lamp.h"
#include "OutputManger.h"


void ColorChangedHandler(int &iNum)
{
	printf("Value of property 'i' = %d.\n", iNum);
}
 

Chaser::Chaser(LampsManager* lampsNamager) :ActionBase(lampsNamager)
{
	m_currentLamp = m_lampsManager->GetCurrentLamp();
	m_multiFadeAmount = new int[m_lampsManager->GetSize()];
	m_lampsManager->SetColorChangedEvent(ColorChangedHandler);
}

Chaser::~Chaser()
{
	m_lampsManager->DisposeColorChangedEvent();
}

void Chaser::Execute()
{
	 
	m_lampsManager->SetCurrentLampState(0);
	m_currentLamp = m_lampsManager->MoveNext();
	m_lampsManager->SetCurrentLampState(MAX_PMW_VAL);
}
void Chaser::ColorChangedEventHandler(int nValue) {
	m_outputManager->Log("Color Changed Event", m_currentLamp->LampName);
	m_outputManager->Wait(1000);
	
}


//
//void Chaser::hookEvent(LampsManager* pSource) {
//	__hook(&LampsManager::ColorChangedEvent, pSource, &Chaser::ColorChangedEventHandler);
//	
//}
//
//void Chaser::unhookEvent(LampsManager* pSource) {
//	(&LampsManager::ColorChangedEvent, pSource, &Chaser::ColorChangedEventHandler);
//	
//}
