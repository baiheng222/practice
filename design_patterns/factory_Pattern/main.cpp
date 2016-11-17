#include "factory.h"
#include "product.h"

int main(int argc, char **argv)
{
	Factory * fac = new ConcreteFactory();
	Product * p = fac->CreateProduct();
	return 0;
}
