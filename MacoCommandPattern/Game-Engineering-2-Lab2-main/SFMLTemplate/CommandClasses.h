#pragma once

#include "ICommand.h"
#include <iostream>

class RunCommand : public Command
{
public:
	virtual void execute() { 
		std::cout << "Run" <<std::endl;
	};
	const int VALUE = 20;
};

class WalkCommand : public Command
{
public:
	virtual void execute() {
		std::cout << "Walk" << std::endl;
	};
	const int VALUE = 5;
};

class CrouchCommand : public Command
{
public:
	virtual void execute() {
		std::cout << "Crouch" << std::endl;
	};
	const int VALUE = 10;
};

class AttackCommand : public Command
{
public:
	virtual void execute() { 
		std::cout << "Attack" << std::endl;
	};
	const int VALUE = 50;
};