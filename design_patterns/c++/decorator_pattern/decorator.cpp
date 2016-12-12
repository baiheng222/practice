#include "decorator.h"

#include <iostream>

using namespace std;

Compoment::Compoment()
{

}

Compoment::~Compoment()
{

}

void Compoment::Operation()
{
    cout << "Compoment Operation" << endl;
}

ConcreteCompoment::ConcreteCompoment()
{

}

ConcreteCompoment::~ConcreteCompoment()
{

}

void ConcreteCompoment::Operation()
{
    cout<< "ConcreteCompoment Operatin" << endl;
}

Decorator::Decorator(Compoment *com)
{
    _com = com;
}

Decorator::~Decorator()
{
    delete _com;
}

void Decorator::Operation()
{
    cout<< "Decorator Operation" << endl;
}

ConcreteDecorator::ConcreteDecorator(Compoment *com):Decorator(com)
{

}

ConcreteDecorator::~ConcreteDecorator()
{

}

void ConcreteDecorator::AddedBehavior()
{
    cout<< "ConcreteDecorator AddedBehavior ..." << endl;
}

void ConcreteDecorator::Operation()
{
    _com->Operation();
    AddedBehavior();
    cout<< "ConcreteDecorator Operation" << endl;

}
