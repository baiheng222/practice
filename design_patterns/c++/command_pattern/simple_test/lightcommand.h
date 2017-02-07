#include <iostream>

#include "command.h"
#include "light.h"

using namespace std;

class LightCommand:public Command
{
	public:
		LightCommand(Light *l)
		{
			light = l;
		}
		void execute()
		{
			light->on();
		}

	private:
		Light *light;
	
};
