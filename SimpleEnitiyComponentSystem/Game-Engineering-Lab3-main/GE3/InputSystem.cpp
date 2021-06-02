#include "InputSystem.h"


void InputSystem::addEntity(Entity e)
{
	m_entites.push_back(e);
}

void InputSystem::setup()
{
	for (int i = 0; i < m_entites.size(); i++)
	{
		for (int j = 0; j < (m_entites.at(i).getComponents()).size(); j++)
		{
			if (typeid(GamePadComponent) == typeid(*(m_entites.at(i).getComponents().at(j))))
			{
				m_compPtrs.push_back(std::dynamic_pointer_cast<GamePadComponent>(m_entites.at(i).getComponents().at(j))); // Add reference so it can be calledback later
				m_compPtrs.at(i) = std::make_shared <GamePadComponent>();
			}
		}
	}
}

void InputSystem::update()
{
	std::cout << "Input System update" << std::endl;
	for (int i = 0; i < m_compPtrs.size(); i++)
	{
		int inputCheck = m_compPtrs.at(i)->getInputValue();
		std::cout << m_compPtrs.at(i)->getID() << " " << std::to_string(i) << " Element updated" << std::endl;
		if (inputCheck < 4)
		{
			// Inter System interaction
			if (inputCheck == 1)
			{
				m_gamePhysics->update(MyVector3(-1, -1,0));
			}
			m_compPtrs.at(i)->setInputValue(++inputCheck);
		}
		else
		{
			m_compPtrs.at(i)->setInputValue(0);
		}
	}
}

void InputSystem::setPhysicsRef(std::shared_ptr<PhysicsSystem> t_systemRef)
{
	m_gamePhysics = t_systemRef;
}
