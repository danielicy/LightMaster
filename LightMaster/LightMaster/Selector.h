// Selector.h

#ifndef _SELECTOR_h
#define _SELECTOR_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#ifndef REDPIN
#define REDPIN  3
#define YELLOWPIN  4
#define GREENPIN  5
#endif




#endif
#ifndef Selector_h
#define Selector_h

#include "Arduino.h"

class Selector
{
public:
	Selector(int pin);
	Selector();
	~Selector();
	void Select(int i);
	void RunProgram();
	
private:
	void TurnOffPreviousPin();
	void Fade(int pin);
	void DisolveTwo(int pin1, int pin2);
	void DisolveThree(int pin1, int pin2, int pin3);
	/*void White();
	void Blue();
	void BlueWhite();
	void Purple();
	void PurpleWhite();
	void Green();
	void GreenWhite();
	void Red();
	void RedWhite();
	void Yellow();
	void YellowGreen();
	void PurpleBlue();*/

	int brightness = 0;    // how bright the LED is
	int fadeAmount = 5;    // how many points to fade the LED by
	int selectedProgram = 0;
	int previouspin = 0;

};

#endif

