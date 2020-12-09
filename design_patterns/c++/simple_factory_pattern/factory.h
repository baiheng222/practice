#include "abstract_product.h"
#include "product.h"

#include <stdio.h>

class Factory
{
	public:
	AbstractProduct *getProduct(int productID)
	{
		printf("getProduct\n");
		AbstractProduct *product = nullptr;

		if (productID == 1)
		{
			product = new Basketball();
		}
		else if (productID == 2)
		{
			product = new Football();
		}
		else if (productID == 3)
		{
			product = new Volleyball();
		}
		
		return product;
	}
};
