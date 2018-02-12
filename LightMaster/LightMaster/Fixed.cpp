
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "stdfax.h"
#endif
#include "Fixed.h"
#include "LampsManager.h"
#include "Lamp.h"
#include "OutputManger.h"

Fixed::Fixed(LampsManager * lampsManager) :ActionBase(lampsManager)
{
}

Fixed::~Fixed()
{
}

void Fixed::Execute()
{
}
