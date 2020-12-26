#include "product.h"
#include "factory.h"
#include "mylog.h"

int main(int argc, char **argv)
{
	LOGI("abstract factory mode");

	AbstractFactory * fac = nullptr;
	AbstractBall *ball = nullptr;
	AbstractShirt *shirt = nullptr;

	fac = new BasketBallFactory();
	ball = fac->getBall();
	shirt = fac->getShirt();

	delete fac;
	delete ball;
	delete shirt;

	fac = new FootBallFactory();
	ball = fac->getBall();
	shirt = fac->getShirt();

	delete fac;
    delete ball;
    delete shirt;

	fac = nullptr;
	ball = nullptr;
	shirt = nullptr;

	return 0;
}
