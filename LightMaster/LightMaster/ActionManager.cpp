
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "stdfax.h"
#endif

#include "ActionManager.h"
#include "LampsManager.h"
#include "Fade.h"
#include "Flicker.h"
#include "Runner.h"

#include "Lamp.h"
#include "Lamps.h"



//https://stackoverflow.com/questions/8767166/passing-a-2d-array-to-a-c-function
ActionManager::ActionManager(LampsManager* lampManager)
{
	m_lampManager = lampManager;
}


ActionManager::~ActionManager()
{
}

 


ActionBase* ActionManager::LoadAction(int index)
{
	ActionBase* _action = nullptr;
	 
	switch (index)
	{
	case 1:
		m_action = new Fade(m_lampManager);
		break;
	case 2:
		m_action = new Flicker(m_lampManager);
		break;
	case 3:
		m_action = new Runner(m_lampManager);
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
	if(m_action != nullptr)
	m_action->Execute();
}

