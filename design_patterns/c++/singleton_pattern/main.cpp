#include <stdio.h>

#include "singleton.h"

int main(int argc, char **argv)
{
	singleton *p = singleton::instance("singletonA");
	p->show();

	return 0;
}


