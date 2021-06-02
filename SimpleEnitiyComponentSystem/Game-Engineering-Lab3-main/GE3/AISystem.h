#pragma once

#include "Component.h"
#include "AIComponent.h"
#include "Entity.h"
#include <iostream>
#include <string>
#include <typeindex>

class AISystem
{
public:
	AISystem() {}

	void addEntity(Entity e);

	void setup();
	void update(MyVector3 t_updateValue);

private:

	std::vector<Entity> m_entites;
	std::vector<std::shared_ptr<AIComponent>> m_compPtrs;
};

