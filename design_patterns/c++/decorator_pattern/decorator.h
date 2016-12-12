#ifndef DECORATOR_H
#define DECORATOR_H

class Compoment
{
public:
    virtual ~Compoment();
    virtual void Operation();

protected:
    Compoment();

};

class ConcreteCompoment:public Compoment
{
public:
    ConcreteCompoment();
    ~ConcreteCompoment();
    void Operation();

protected:

private:

};

class Decorator:public Compoment
{
public:
    Decorator(Compoment *com);
    virtual ~Decorator();
    void Operation();

protected:
    Compoment *_com;
};

class ConcreteDecorator:public Decorator
{
public:
    ConcreteDecorator(Compoment *com);
    ~ConcreteDecorator();
    void Operation();
    void AddedBehavior();
};

#endif
