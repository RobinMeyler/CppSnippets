#ifndef GAME
#define GAME

#include <SFML\Graphics.hpp>
#include "Xbox360Controller.h"
#include "MacroCommand.h"
#include "InputHandler.h"

class Game
{
public:
	Game();
	~Game();
	/// <summary>
	/// main method for game
	/// </summary>
	void run();

private:

	void processEvents();				// Loop functions
	void update(sf::Time t_deltaTime);
	void render();
	sf::Event event;
	sf::RenderWindow m_window; // main SFML window
	sf::Font m_ArialBlackfont; // font used by message
	bool m_exitGame; // control exiting game
	
	InputHandler m_gameInputManager;
	float gameInputTimer{ 0 };
};

#endif // !GAME

