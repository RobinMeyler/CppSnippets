
#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 

#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "AISystem.h"
#include "PhysicsSystem.h"
#include "InputSystem.h"
#include "FXSystem.h"
#include "PositionComponent.h"
#include "AIComponent.h"
#include "PhysicsComponent.h"
#include "GamePadComponent.h"
#include "FXComponent.h"

int main()
{
	// Creating Entities
	Entity player, dog, troll, orc, cat, pig;

	//Creating Components
	FXComponent fxComponent;
	PhysicsComponent physicsComponent;
	GamePadComponent gamePad;
	AIComponent aiComponent;

	std::shared_ptr<Component> fxComp = std::make_shared<FXComponent>();
	std::shared_ptr<Component> phyComp = std::make_shared<PhysicsComponent>();
	std::shared_ptr<Component> aiComp = std::make_shared<AIComponent>();
	std::shared_ptr<Component> padComp = std::make_shared<GamePadComponent>();

	// Adding Components
	player.addComponent(phyComp);
	player.addComponent(fxComp);

	dog.addComponent(aiComp);
	dog.addComponent(phyComp);
	dog.addComponent(padComp);

	troll.addComponent(aiComp);
	troll.addComponent(fxComp);

	orc.addComponent(aiComp);
	orc.addComponent(phyComp);

	cat.addComponent(aiComp);
	cat.addComponent(phyComp);
	cat.addComponent(fxComp);

	pig.addComponent(aiComp);
	pig.addComponent(phyComp);
	pig.addComponent(fxComp);

	// Creating systems
	// Adding Entities to systems
	std::shared_ptr<PhysicsSystem> physicsSystem = std::make_shared <PhysicsSystem>();
	physicsSystem->addEntity(player);
	physicsSystem->addEntity(dog);
	physicsSystem->addEntity(orc);
	physicsSystem->addEntity(cat);
	physicsSystem->addEntity(pig);

	std::shared_ptr<InputSystem> inputSystem = std::make_shared <InputSystem>();
	inputSystem->addEntity(dog);
	
	std::shared_ptr<FXSystem> fxSystem = std::make_shared <FXSystem>();
	fxSystem->addEntity(player);
	fxSystem->addEntity(troll);
	fxSystem->addEntity(cat);
	fxSystem->addEntity(pig);

	std::shared_ptr<AISystem> aiSystem = std::make_shared <AISystem>();
	aiSystem->addEntity(dog);
	aiSystem->addEntity(troll);
	aiSystem->addEntity(orc);
	aiSystem->addEntity(cat);
	aiSystem->addEntity(pig);

	inputSystem->setPhysicsRef(physicsSystem);
	aiSystem->setup();
	fxSystem->setup();
	physicsSystem->setup();
	inputSystem->setup();

	float pressDelay = 0;
	int newFx = 3;
	while (true)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && pressDelay > 50.f)
		{
			pressDelay = 0;
			aiSystem->update(MyVector3(2,2,0));
			std::cout << "" << std::endl;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::I) && pressDelay > 50.f)
		{
			pressDelay = 0;
			inputSystem->update();
			std::cout << "" << std::endl;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F) && pressDelay > 50.f)
		{
			pressDelay = 0;
			fxSystem->update(++newFx);
			std::cout << "" << std::endl;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::P) && pressDelay > 50.f)
		{
			pressDelay = 0;
			physicsSystem->update(MyVector3(2, -1, 0));
			std::cout << "" << std::endl;
		}
		if (newFx > 10) newFx = 0;
		pressDelay += 0.001f;
	}
	return 0;
}

