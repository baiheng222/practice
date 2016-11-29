#include "observer.h"
#include "subject.h"

#include <iostream>

int main(int argc,char **argv)
{
    ConcreateSubject *sub = new ConcreateSubject();
    Observer *o1 = new ConcreateObserverA(sub);
    Observer *o2 = new ConcreateObserverB(sub);
    sub->SetState("old");
    sub->Notify();
    sub->SetState("new");
    sub->Notify();
    return 0;
}
