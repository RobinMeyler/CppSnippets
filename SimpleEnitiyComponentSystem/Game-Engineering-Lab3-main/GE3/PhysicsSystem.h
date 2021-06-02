#pragma once

#include "Component.h"
#include "PhysicsComponent.h"
#include "Entity.h"
#include <iostream>
#include <string>
#include <typeindex>

class PhysicsSystem
{
public:
	PhysicsSystem() {}

	void addEntity(Entity e);
	void setup();
	void setBoundaries(float t_width, float t_height);
	void update(MyVector3 t_updateValue);

private:
	float m_width, m_height;
	std::vector<Entity> m_entites;
	std::vector<std::shared_ptr<PhysicsComponent>> m_compPtrs;
};

