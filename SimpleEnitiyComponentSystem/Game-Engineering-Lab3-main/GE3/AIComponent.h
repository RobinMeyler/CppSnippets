#pragma once

#include "Component.h"
#include "Entity.h"
#include "MyVector3.h"
#include <string>

class AIComponent : public Component
{
public:
	AIComponent() {}

	virtual std::string getID() override { return id; };
	MyVector3 getPosition() { return m_targetPosition; };
	void setPosition(MyVector3 t_newValue) { m_targetPosition = t_newValue; };

private:
	const std::string id = "AI";
	MyVector3 m_targetPosition;
};


