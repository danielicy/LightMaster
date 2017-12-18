
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "stdfax.h"
#endif


#include "Lamp.h"
#include "Lamps.h"

//#include <algorithm>
//#include <iostream>
//#include <string>


Lamps::Lamps()
{
	
}


Lamps::~Lamps()
{
}

void Lamps::Add(Lamp** lamp)
{
	//if (LampCollection == nullptr)
	//{
	////	LampCollection = new { lamp };

	//}
	//else
	//{



	//	int old_size = sizeof(LampCollection[0]) / sizeof(LampCollection);
	//	int new_size = old_size + 1;

	//	Lamp* newArr = new Lamp[new_size];

	//	Lamp* oldArray = LampCollection;


	//	//std::copy(LampCollection, LampCollection + std::min(old_size, new_size), newArr);
	//	delete[] oldArray;
	//	//LampCollection = newArr;
	//}

	/*Lamp* newArr = new Lamp[new_size];
	
	std::copy(oldArr, oldArr + std::min(old_size, new_size), newArr);
	delete[] oldArr;
	oldArr = newArr;
}*/
}
 
Lamp Lamps::Next()
{
	return Lamp();
}

void Lamps::Clear()
{
}


