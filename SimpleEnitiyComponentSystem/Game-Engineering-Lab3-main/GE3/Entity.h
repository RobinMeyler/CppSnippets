#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <typeindex>
#include "Component.h"

class Entity
{
public:
	Entity() {  };
	void addComponent(std::shared_ptr<Component> c)
	{
		for (int j = 0; j < (getComponents()).size(); j++)
		{
			if (typeid(*c) == typeid(*(getComponents().at(j))))
			{
				// Already exists
				return;
			}
		}
		m_components.push_back(c);
	}
	void removeComponent(std::shared_ptr<Component> c)
	{
		// Find a component, remove it
		for (int j = 0; j < (m_components).size(); j++)
		{
			if (typeid(*c) == typeid(*(m_components.at(j))))
			{
				m_components.erase(m_components.begin() + j);
			}
		}
	}
	std::vector<std::shared_ptr<Component>> getComponents()
	{
		return m_components;
	}

	int id;
private:
	std::vector<std::shared_ptr<Component>> m_components;

};


