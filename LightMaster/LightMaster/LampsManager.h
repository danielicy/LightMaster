#pragma once
//https://www.codeguru.com/cpp/cpp/cpp_mfc/events/article.php/c4075/How-to-Work-with-Events-in-a-C-Class.htm
#define MAX_PMW_VAL 255
// evh_native.cpp  
#include <stdio.h>  

#include "LMSystem.h"
#include "Lamp.h"
#include "ColorManager.h"
#include "OutputManger.h"

struct Lamp;
class ColorManager;
class COutputManger;

class LampsManager
{
public:	
	LampsManager(ColorManager * colorManager, COutputManger * outputManger);
	~LampsManager();

	__event void ColorChangedEvent(int nValue);
	void SetLamps(byte  lampindex);
	void SetCurrentLampState(byte state);
	void SetLampState(byte lamp, byte state);
	Lamp* MoveNext();
	Lamp* GetCurrentLamp();
	int GetSize();
	Lamp* GetLamps();
	Lamp GetLamp(byte idx);
	
private:
	byte m_size;
	byte m_CurrentIndex;
	Lamp* m_lamps;
	ColorManager* m_colorManager;
	COutputManger* m_outputManager;
};

