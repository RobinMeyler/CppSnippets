#include "FXSystem.h"


void FXSystem::addEntity(Entity e)
{
	m_entites.push_back(e);
}

void FXSystem::setup()
{
	for (int i = 0; i < m_entites.size(); i++)
	{
		for (int j = 0; j < (m_entites.at(i).getComponents()).size(); j++)
		{
			if (typeid(FXComponent) == typeid(*(m_entites.at(i).getComponents().at(j))))
			{
				m_compPtrs.push_back(std::dynamic_pointer_cast<FXComponent>(m_entites.at(i).getComponents().at(j))); // Add reference so it can be calledback later
				m_compPtrs.at(i) = std::make_shared <FXComponent>();
			}
		}
	}
}

void FXSystem::update(int t_updateValue)
{
	std::cout << "FX System update" << std::endl;
	for (int i = 0; i < m_compPtrs.size(); i++)
	{
		m_compPtrs.at(i)->setFxState(t_updateValue);

		std::cout << m_compPtrs.at(i)->getID() << " " << std::to_string(i) << " Element updated" << std::endl;
	}

}
