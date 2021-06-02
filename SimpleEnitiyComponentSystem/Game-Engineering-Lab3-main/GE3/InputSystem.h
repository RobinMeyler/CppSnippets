#pragma once

#include "Component.h"
#include "GamePadComponent.h"
#include "PhysicsSystem.h"
#include "Entity.h"
#include <iostream>
#include <string>
#include <typeindex>

class InputSystem
{
public:
	InputSystem() {}

	void addEntity(Entity e);
	void setup();
	void update();
	void setPhysicsRef(std::shared_ptr<PhysicsSystem> t_systemRef);
private:

	std::vector<Entity> m_entites;
	std::vector<std::shared_ptr<GamePadComponent>> m_compPtrs;
	std::shared_ptr<PhysicsSystem> m_gamePhysics;
};

