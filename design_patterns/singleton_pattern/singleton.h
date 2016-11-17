#ifndef SINGLETON_H
#define SINGLETON_H

class singleton
{
public:
	static singleton * instance(const char * name);
	virtual void show();
protected:
	singleton();

private:
	static singleton *_instance;
};

class singletonA : public singleton
{
	friend class singleton;
public:
	void show();
protected:
	singletonA();
};

class singletonB : public singleton
{
	friend class singleton;
public:
	void show();
protected:
	singletonB();
};


#endif


