#include <stdio.h>

#include "builder.h"

Builder::Builder()
{
	
}


ThinBuilder::ThinBuilder()
{
	
}

void ThinBuilder::buildHead()
{
	printf("build thin head \n");
}

void ThinBuilder::buildBody()
{
	printf("build thin body \n");
}

void ThinBuilder::buildArms()
{
	printf("build  thin arms \n");
}

void ThinBuilder::buildLegs()
{
	printf("build  thin legs \n");
}

void ThinBuilder::buildFeet()
{
	printf("build thin Feet \n");
}

FatBuilder::FatBuilder()
{
	
}

void FatBuilder::buildHead()
{
	printf("build fat head \n");
}

void FatBuilder::buildBody()
{
	printf("build fat body \n");
}

void FatBuilder::buildArms()
{
	printf("build  fat arms \n");
}

void FatBuilder::buildLegs()
{
	printf("build  fat legs \n");
}

void FatBuilder::buildFeet()
{
	printf("build fat Feet \n");
}

