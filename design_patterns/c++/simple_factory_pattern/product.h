#include "abstract_product.h"

#include <stdio.h>

class Basketball : public AbstractProduct
{
	public:
		Basketball()
		{
			printName();
			play();
		}

		void printName()
		{
			printf("Basketball\n");
		}

		void play()
		{
			printf("play basketball\n");
		}
};

class Football : public AbstractProduct
{
	public:
		Football()
		{
			printfName();
			play();
		}

		void printName()
        {
            printf("Football\n");
        }

        void play()
        {
            printf("play football\n");
        }

};


class Volleyball : public AbstractProduct
{
	public:
		Volleyball()
		{
			printfName();
			play();
		}

		void printName()
        {
            printf("Volleyball\n");
        }

        void play()
        {
            printf("play Volleyball\n");
        }

};
