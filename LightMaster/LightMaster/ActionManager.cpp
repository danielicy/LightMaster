
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "stdfax.h"
#endif

#include "ActionManager.h"
#include "Fade.h"


#include "Lamp.h"
#include "Lamps.h"



//https://stackoverflow.com/questions/8767166/passing-a-2d-array-to-a-c-function
ActionManager::ActionManager()
{
	
}


ActionManager::~ActionManager()
{
}

 

void ActionManager::AddLamp(Lamp** lamp)
{
	int i = 0;
	//while (lamps[i] > 0)
	//{
	
	//	//LampCollection->Add(&lamp);
	//}


	LampCollection->Add(lamp);
	/*int i = 0;
	while (col[i] >= 0)
	{

		m_pinBuffer[i][0] = col[i];
		m_pinBuffer[i][1] = LOW;

		i++;
	}*/
}

//Lamps ActionManager::LampsCollection()
//{
//	return Lamps();
//}


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
	if(m_action != nullptr)
	m_action->Execute();
}

