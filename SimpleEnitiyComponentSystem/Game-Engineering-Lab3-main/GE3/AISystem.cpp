#include "AISystem.h"

void AISystem::addEntity(Entity e)
{
	m_entites.push_back(e);
}

void AISystem::setup()
{
	for (int i = 0; i < m_entites.size(); i++)
	{
		for (int j = 0; j < (m_entites.at(i).getComponents()).size(); j++)
		{
			if (typeid(AIComponent) == typeid(*(m_entites.at(i).getComponents().at(j))))
			{
				m_compPtrs.push_back(std::dynamic_pointer_cast<AIComponent>(m_entites.at(i).getComponents().at(j))); // Add reference so it can be calledback later
				m_compPtrs.at(i) = std::make_shared <AIComponent>();
			}
		}
	}
}

void AISystem::update(MyVector3 t_updateValue)
{
	std::cout << "AI System update" << std::endl;
	for (int i = 0; i < m_compPtrs.size(); i++)
	{
		/*MyVector3 updatePosition = m_compPtrs.at(i)->getPosition();
		updatePosition = t_updateValue + t_updateValue;*/
		m_compPtrs.at(i)->setPosition(t_updateValue);

		std::cout << m_compPtrs.at(i)->getID() << " " << std::to_string(i) << " Element updated" << std::endl;
	}
	
}
