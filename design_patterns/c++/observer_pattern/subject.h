#ifndef     SUBJECT_H
#define     SUBJECT_H

#include <list>
#include <string>

using namespace std;
typedef string State;
class Observer;
class Subject
{
    public:
        virtual ~Subject();
        virtual void Attach(Observer *obj);
        virtual void Detach(Observer *obj);
        virtual void Notify();
        virtual void SetState(const State &s) = 0;
        virtual State GetStat() = 0;

    protected:
        Subject();

    private:
        list<Observer *> *_obvs;

};

class ConcreateSubject:public Subject
{
    public:
        ConcreateSubject();
        ~ConcreateSubject();
        State GetStat();
        void SetState(const State &st);

    protected:

    private:
        State _st;

};


#endif
