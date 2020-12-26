#ifndef FACTORY_H
#define FACTORY_H

#include "mylog.h"
#include "product.h"

class AbstractFactory
{
	public:
		virtual AbstractBall * getBall() = 0;
		virtual AbstractShirt * getShirt() = 0;
};

class BasketBallFactory : public AbstractFactory
{
	public:
		AbstractBall * getBall()
		{
			LOGD("get basketball");
			return new BasketBall();
		}

		AbstractShirt * getShirt()
		{
			LOGD("get basketball shirt");
			return new BasketBallShirt();
		}
};


class FootBallFactory : public AbstractFactory
{
    public:
        AbstractBall * getBall()
        {
            LOGD("get football");
            return new FootBall();
        }

        AbstractShirt * getShirt()
        {
            LOGD("get football shirt");
            return new FootBallShirt();
        }

};

#endif

