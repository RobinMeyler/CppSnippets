#include "PhysicsSystem.h"

void PhysicsSystem::addEntity(Entity e)
{
	m_entites.push_back(e);
}

void PhysicsSystem::setup()
{
	std::vector<int> toRemove;
	for (int i = 0; i < m_entites.size(); i++)
	{
		int found = -1;
		for (int j = 0; j < (m_entites.at(i).getComponents()).size(); j++)
		{
			if (typeid(PhysicsComponent) == typeid(*(m_entites.at(i).getComponents().at(j))))
			{
				found = j;
				m_compPtrs.push_back(std::dynamic_pointer_cast<PhysicsComponent>(m_entites.at(i).getComponents().at(j))); // Add reference so it can be calledback later
				m_compPtrs.at(i) = std::make_shared <PhysicsComponent>();
			}
		}
		if (found < 0)
		{
			toRemove.push_back(i);
		}
	}
	for (auto r : toRemove)
	{
		m_entites.erase(m_entites.begin() + r);
	}
}

void PhysicsSystem::setBoundaries(float t_width, float t_height)
{
	m_width = t_width;
	m_height = t_height;
}

void PhysicsSystem::update(MyVector3 t_updateVelocity)
{
	std::cout << "Physics System update" << std::endl;
	for (int i = 0; i < m_compPtrs.size(); i++)
	{
		m_compPtrs.at(i)->setVelocity(t_updateVelocity);
		// Add new velocity
		MyVector3 newPosition = m_compPtrs.at(i)->getPosition() + t_updateVelocity;

		// Boundary check
		if (!newPosition.x < 0
			|| !newPosition.y > m_width
			|| !newPosition.y < 0
			|| !newPosition.y > m_height)
		{
			m_compPtrs.at(i)->setPosition(newPosition); // Set new position
		}

		std::cout << m_compPtrs.at(i)->getID() << " " << std::to_string(i) << " Element updated" << std::endl;
	}

}
