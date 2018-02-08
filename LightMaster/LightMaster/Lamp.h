#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "LMSystem.h"
#endif

struct Lamp
{
	byte LampName;
	byte State;
};
