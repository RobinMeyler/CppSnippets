#pragma once

#include "Component.h"
#include "Entity.h"
#include "MyVector3.h"

class PositionComponent : public Component
{
public:
	PositionComponent() {}

	MyVector3 getPosition();
	void setPosition(MyVector3 t_position);

private:
	MyVector3 m_position;
};

