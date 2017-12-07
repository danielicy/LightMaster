
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "stdfax.h"
#endif

#include "ActionManager.h"
#include "Fade.h"
#include "Lamp.h"

//https://stackoverflow.com/questions/8767166/passing-a-2d-array-to-a-c-function
ActionManager::ActionManager()
{
	
}


ActionManager::~ActionManager()
{
}

Lamp ActionManager::Lamps()
{
	return *m_lamps;
}


ActionBase* ActionManager::LoadAction(int index)
{
	ActionBase* _action = nullptr;

	switch (index)
	{
	case 1:
		m_action = new Fade(m_lamps);
		break;
	case 2:
		//Fade(YELLOWPIN);
		break;
	case 3:
		//Fade(GREENPIN);
		break;
	case 4:
		//DisolveTwo(REDPIN, YELLOWPIN);
		break;
	case 5:
		//DisolveTwo(REDPIN, GREENPIN);
		break;
	case 6:
		//DisolveTwo(GREENPIN, YELLOWPIN);
		break;
	case 7:
		//DisolveThree(REDPIN, YELLOWPIN, GREENPIN);
		break;
		/*case 8:
		Prog8();
		break;*/
	}

	return _action;
}

void ActionManager::Execute()
{
	m_action->Execute();
}

