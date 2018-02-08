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


 

Chaser::Chaser(LampsManager* lampsNamager) :ActionBase(lampsNamager)
{
}

Chaser::~Chaser()
{
}

void Chaser::Execute()
{

}
