#pragma once

#include "Component.h"
#include "Entity.h"
#include "MyVector3.h"

class GamePadComponent : public Component
{
public:
	GamePadComponent() {}


	virtual std::string getID() override { return id; };
	int getInputValue() { return m_gamePadInput; };
	void setInputValue(int t_input) { m_gamePadInput = t_input; };

private:
	const std::string id = "GamePad";
	int m_gamePadInput{ 0 };
};

