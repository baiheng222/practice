#include "subject.h"
#include "observer.h"

#include <iostream>
#include <list>

using namespace std;

Subject::Subject()
{
    _obvs = new list<Observer *>;
}

Subject::~Subject()
{

}

void Subject::Attach(Observer *obv)
{
    _obvs->push_front(obv);
}

void Subject::Detach(Observer *obv)
{
    if (NULL != obv)
    {
        _obvs->remove(obv);
    }
}

void Subject::Notify()
{
    list<Observer *>::iterator it;
    it = _obvs->begin();
    for (;it != _obvs->end(); it++)
    {
        (*it)->Update(this);
    }
}


ConcreateSubject::ConcreateSubject()
{
    _st = '\0';
}

ConcreateSubject::~ConcreateSubject()
{

}

State ConcreateSubject::GetStat()
{
    return _st;
}

void ConcreateSubject::SetState(const State &s)
{
    _st = s;
}
