#include "Console.h"


//
//Console::Console()
//{
//}
//
//
//Console::~Console()
//{
//}

 

#include "stdafx.h"
#include "LM_System.h"


LMSystem *m_lMSystem = new LMSystem();


int main()
{
	char c;

	puts("Enter text. Include a dot ('.') in a sentence to exit:");
	do {
		c = getchar();

		putchar(c);

	} while (c != '.');

	return 0;


}