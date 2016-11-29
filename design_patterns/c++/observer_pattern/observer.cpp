#include "observer.h"
#include "subject.h"

#include <iostream>
#include <string>

using namespace std;

Observer::Observer()
{
    _st = '\0';
}

Observer::~Observer()
{

}

ConcreateObserverA::ConcreateObserverA(Subject *sub)
{
    _sub = sub;
    _sub->Attach(this);
}

ConcreateObserverA::~ConcreateObserverA()
{
    _sub->Detach(this);
    if (NULL != _sub)
    {
        delete _sub;
        _sub = NULL;
    }
}

Subject * ConcreateObserverA::GetSubject()
{
    return _sub;
}


void ConcreateObserverA::PrintInfo()
{
    cout<< "ConcreateObserverA observer " << _sub->GetStat() << endl;
}

void ConcreateObserverA::Update(Subject *sub)
{
    _st = sub->GetStat();
    PrintInfo();
}


ConcreateObserverB::ConcreateObserverB(Subject *sub)
{
    _sub = sub;
    _sub->Attach(this);
}

ConcreateObserverB::~ConcreateObserverB()
{
    _sub->Detach(this);
    if (NULL != _sub)
    {
        delete _sub;
        _sub = NULL;
    }
}

Subject * ConcreateObserverB::GetSubject()
{
    return _sub;
}


void ConcreateObserverB::PrintInfo()
{
    cout<< "ConcreateObserverB observer " << _sub->GetStat() << endl;
}

void ConcreateObserverB::Update(Subject *sub)
{
    _st = sub->GetStat();
    PrintInfo();
}
