#ifndef     OBSERVER_H
#define     OBSERVER_H

#include "subject.h"

#include <string>

using namespace std;
typedef string State;

class Observer
{
public:
    virtual ~Observer();
    virtual void Update(Subject *sub) = 0;
    virtual void PrintInfo() = 0;

protected:
    Observer();
    State _st;

private:

};

class ConcreateObserverA:public Observer
{
public:
    virtual Subject * GetSubject();
    ConcreateObserverA(Subject *sub);
    virtual ~ConcreateObserverA();
    void Update(Subject *sub);
    void PrintInfo();

protected:

private:
    Subject *_sub;
};


class ConcreateObserverB:public Observer
{
public:
    virtual Subject * GetSubject();
    ConcreateObserverB(Subject *sub);
    virtual ~ConcreateObserverB();
    void Update(Subject *sub);
    void PrintInfo();

protected:

private:
    Subject *_sub;
};

#endif
