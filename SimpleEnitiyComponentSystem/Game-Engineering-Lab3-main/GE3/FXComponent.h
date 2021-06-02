#pragma once

#include "Component.h"
#include "Entity.h"
#include "MyVector3.h"

class FXComponent : public Component
{
public:
	FXComponent() {}

	virtual std::string getID() override { return id; };
	int getFxState() { return m_fxState; };
	void setFxState(int t_state) { m_fxState = t_state; };

private:
	const std::string id = "FX";
	int m_fxState{ 3 };
};

