
#pragma once
#include "Component.h"
#include "FXComponent.h"
#include "Entity.h"
#include <iostream>
#include <string>
#include <typeindex>
class FXSystem
{
public:
	FXSystem() {}

	void addEntity(Entity e);
	void setup();
	void update(int t_updateState);

private:

	std::vector<Entity> m_entites;
	std::vector<std::shared_ptr<FXComponent>> m_compPtrs;
};

