
#pragma once

#include "Component.h"
#include "Entity.h"
#include "MyVector3.h"

struct Transform {
	MyVector3 translation;
	float rotation;
	float scale;
};

class PhysicsComponent : public Component
{
public:
	PhysicsComponent() {}

	virtual std::string getID() override { return id; };

	MyVector3 getPosition() { return m_position; };
	void setPosition(MyVector3 t_state) { m_position = t_state; };
	MyVector3 getVelocity() { return m_velocity; };
	void setVelocity(MyVector3 t_state) { m_velocity = t_state; };
	Transform getTransform() { return m_transform; };
	void setTransform(Transform t_state) { m_transform = t_state; };

private:
	const std::string id = "Physics";
	MyVector3 m_position;
	MyVector3 m_velocity;
	Transform m_transform;
};

