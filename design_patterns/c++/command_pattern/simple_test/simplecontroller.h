#include <iostream>

#include "command.h"

using namespace std;

class SimpleController
{
	public:
		void setCommand(Command *cmd)
		{
			command = cmd;
		}

		void buttonPressed()
		{
			command->execute();
		}

	private:
		Command *command;	
};
