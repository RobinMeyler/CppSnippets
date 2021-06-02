#include "PositionComponent.h"

MyVector3 PositionComponent::getPosition()
{
	return m_position;
}

void PositionComponent::setPosition(MyVector3 t_position)
{
	m_position = t_position;
}
