#ifndef FACTORY_H
#define FACTORY_H

class Product;

class Factory
{
public:
	~Factory();
	virtual Product * CreateProduct() = 0;

protected:
	Factory();
private:
	
};

class ConcreteFactory:public Factory
{
public:
	ConcreteFactory();
	~ConcreteFactory();
	Product * CreateProduct();
protected:

private:

};

#endif


