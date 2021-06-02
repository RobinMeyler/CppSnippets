#include "Game.h"

Game::Game() :
	//m_window{ sf::VideoMode{ 1000, 800, 32 }, "Command Pattern" },
	m_exitGame{ false }

{
	std::cout << "Press 1-4 for commands" << std::endl;
	std::cout << "Press U for Undo, Press R for Redo" << std::endl;
	std::cout << "Press L for a Macro list of the Undos and Redos available" << std::endl;
	std::cout << "" << std::endl;
}

Game::~Game()
{
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f); // 60 fps
	while (true)
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}

void Game::processEvents()
{
	while (m_window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type) // window message
		{
			m_window.close();
		}
		if (sf::Event::KeyPressed == event.type) //user key press
		{
			if (sf::Keyboard::Escape == event.key.code)
			{
				m_exitGame = true;
			}
		}
		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				
			}
		}
		if (event.type == sf::Event::MouseButtonReleased)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				
			}
		}
	}
}

void Game::update(sf::Time t_deltaTime)
{
	if (m_exitGame)
	{
		m_window.close();		// Exiting the game
	}
	if (gameInputTimer > 0.5f)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
		{
			m_gameInputManager.handleInput(INPUTS::INPUT1);
			gameInputTimer = 0;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
		{
			m_gameInputManager.handleInput(INPUTS::INPUT2);
			gameInputTimer = 0;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
		{
			m_gameInputManager.handleInput(INPUTS::INPUT3);
			gameInputTimer = 0;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
		{
			m_gameInputManager.handleInput(INPUTS::INPUT4);
			gameInputTimer = 0;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::U))
		{
			m_gameInputManager.Undo();
			gameInputTimer = 0;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		{
			m_gameInputManager.Redo();
			gameInputTimer = 0;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
		{
			m_gameInputManager.OutputMacro();
			gameInputTimer = 0;
		}	
	}
	gameInputTimer += t_deltaTime.asSeconds(); // Delay for keybord presses
}

void Game::render()
{	
}

