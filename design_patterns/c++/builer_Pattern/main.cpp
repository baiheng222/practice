#include <stdio.h>

#include "director.h"
#include "builder.h"

int main(int argc, char **argv)
{
	ThinBuilder builderThin;
	FatBuilder builderFat;
	Director dir;
	dir.CreateBuilder(&builderThin);
	dir.CreateBuilder(&builderFat);
	return 0;
}
