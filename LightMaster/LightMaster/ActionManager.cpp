#include "ActionManager.h"


//https://stackoverflow.com/questions/8767166/passing-a-2d-array-to-a-c-function
ActionManager::ActionManager(int buffer[][2])//int &buffer)
{
	m_buffer = buffer[0];
}


ActionManager::~ActionManager()
{
}


void ActionManager::Fade()
{
	
}
