#include <iostream>

#include "simplecontroller.h"
#include "light.h"
#include "lightcommand.h"

using namespace std;

int main(int argc, char **argv)
{
	SimpleController *controller = new SimpleController();	
	Light *light = new Light();
	LightCommand *lcmd = new LightCommand(light);
	
	controller->setCommand(lcmd);

	controller->buttonPressed();
}
