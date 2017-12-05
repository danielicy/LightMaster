#include "stdafx.h"
#include "ActionManager.h"
#include "Fade.h"

//https://stackoverflow.com/questions/8767166/passing-a-2d-array-to-a-c-function
ActionManager::ActionManager(int buffer[][2])//int &buffer)
{
	m_buffer = buffer[0];
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
		m_action = new Fade(&m_buffer);
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

