#include <stdio.h>

#include "factory.h"
#include "abstract_product.h"

int main(int argc, char **argv)
{
	Factory *fac = new Factory();
	
	AbstractProduct *product = nullptr;

	product = fac->getProduct(1);
	delete product;

	product = fac->getProduct(2);
	delete product;

	product = fac->getProduct(3);
	delete product;
	product = nullptr;

	delete fac;
	fac = nullptr;

	return 0;
}
