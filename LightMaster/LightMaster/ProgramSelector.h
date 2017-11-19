// ProgramSelector.h

#ifndef _PROGRAMSELECTOR_h
#define _PROGRAMSELECTOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif


#endif

class ProgramSelector
{
public:
	ProgramSelector(int pin);
	ProgramSelector();
	~ProgramSelector();
	void Select(int i);
private:
	void Fade();
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

