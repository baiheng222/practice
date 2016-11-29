#include "director.h"
#include "builder.h"


Director::Director()
{
	
}

void Director::CreateBuilder(Builder *b)
{
	builder = b;
	
	builder->buildHead();
	builder->buildBody();
	builder->buildArms();
	builder->buildLegs();
	builder->buildFeet();
}