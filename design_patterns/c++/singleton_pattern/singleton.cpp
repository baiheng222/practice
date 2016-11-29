#include <stdio.h>
#include <string.h>

#include "singleton.h"

singleton *singleton::_instance = NULL;

singleton *singleton::instance(const char *name)
{
	if (NULL == _instance)
	{
		if (strcmp(name, "singletonA") == 0)
		{
			_instance = new singletonA();
		}
		else if (strcmp(name, "singletonB") == 0)
		{
			_instance = new singletonB();
		}
		else
		{
			_instance = new singleton();
		}
	}
	return _instance;
}

singleton::singleton()
{

}


singletonA::singletonA()
{

}



void singleton::show(void)
{
	printf("singleton show\n");
}

void singletonA::show(void)
{
	printf("singletonA show\n");
}


singletonB::singletonB()
{

}

void singletonB::show(void)
{
    printf("singletonB show\n");
}
