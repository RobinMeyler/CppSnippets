#pragma once

#include "Component.h"
#include <string>

class Component
{
public:
	Component() {};

	virtual std::string getID() { return "blank"; };
	virtual float getValue() { return 0; };
	virtual void setValue(float t_newValue) {};
};

