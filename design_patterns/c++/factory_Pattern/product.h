#ifndef PRODUCT_H
#define PRODUCT_H

class Product
{
public:
	virtual ~Product() = 0;

protected:
	Product(void);
private:

};

class ConcreteProduct:public Product
{
public:
	ConcreteProduct();
	~ConcreteProduct();

protected:

private:

};

#endif

