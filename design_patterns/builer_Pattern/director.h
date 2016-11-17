#ifndef DIRECTOR_H
#define	DIRECTOR_H

class Builder;

class Director
{
public:
	Director();
	void CreateBuilder(Builder *b);

private:
	Builder *builder;
};

#endif

