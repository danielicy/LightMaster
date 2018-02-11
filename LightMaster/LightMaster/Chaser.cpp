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


void myEvent(int &iNum)
{
	printf("Value of property 'i' = %d.\n", iNum);
}
 

Chaser::Chaser(LampsManager* lampsNamager) :ActionBase(lampsNamager)
{
	m_currentLamp = m_lampsManager->GetCurrentLamp();
	m_multiFadeAmount = new int[m_lampsManager->GetSize()];
	hookEvent(m_lampsManager);
}

Chaser::~Chaser()
{
	unhookEvent(m_lampsManager);
}

void Chaser::Execute()
{

}
void Chaser::ColorChangedEventHandler(int nValue) {
	m_outputManager->Log("Color Changed Event", m_currentLamp->LampName);
	m_outputManager->Wait(1000);
	
}



void Chaser::hookEvent(LampsManager* pSource) {
	__hook(&LampsManager::ColorChangedEvent, pSource, &Chaser::ColorChangedEventHandler);
	
}

void Chaser::unhookEvent(LampsManager* pSource) {
	(&LampsManager::ColorChangedEvent, pSource, &Chaser::ColorChangedEventHandler);
	
}
