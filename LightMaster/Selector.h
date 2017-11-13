// Selector.h

#ifndef _SELECTOR_h
#define _SELECTOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
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
	void Select(int i);
private:
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



};

#endif

