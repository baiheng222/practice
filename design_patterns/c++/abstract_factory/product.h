#ifndef PRODUCT_H
#define PRODUCT_H

#include "mylog.h"

class AbstractBall
{
	public:
		virtual void play() = 0;
};

class FootBall : public AbstractBall
{
	public:
		FootBall()
		{
			play();
		}

		void play()
		{
			LOGD("play football");
		}
};

class BasketBall : public AbstractBall
{
    public:
        BasketBall()
        {
            play();
        }

        void play()
        {
            LOGD("play basketball");
        }
};


class AbstractShirt
{
	public:
		virtual void wearShirt() = 0;
};


class BasketBallShirt : public AbstractShirt
{
	public:
		BasketBallShirt()
		{
			wearShirt();
		}

		void wearShirt()
		{
			LOGD("wear basketball shirt");
		}
};

class FootBallShirt : public AbstractShirt
{
	public:
		FootBallShirt()
		{
			wearShirt();
		}

		void wearShirt()
		{
			LOGD("wear football shirt");
		}
};


#endif

