#pragma once

#include "Lamp.h"
#include "LMSystem.h"

struct Lamp;

class Lamps
{
public:
	Lamps();
	~Lamps();
	void Add(Lamp** lamp);
	Lamp Next();
	int Size;
	
	void Clear();
private:
	Lamp* LampCollection;

};

