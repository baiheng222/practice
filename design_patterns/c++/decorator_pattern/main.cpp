#include "decorator.h"

#include <iostream>

int main(int argc, char **argv)
{
    Compoment *com = new ConcreteCompoment();
    Decorator * dec = new ConcreteDecorator(com);
    dec->Operation();
    delete dec;
    return 0;
}

