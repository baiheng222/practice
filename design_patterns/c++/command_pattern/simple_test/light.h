#ifndef LIGHT_H
#define LIGHT_H

#include <iostream>

using namespace std;

class Light
{
	public:
		void on()
		{
			cout<< "light is on" << endl;
		}
		
		void off()
		{
			cout<< "light is off" << endl;
		}

};

#endif
