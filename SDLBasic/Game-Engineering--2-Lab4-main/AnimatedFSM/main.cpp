#include <Defines.h>

#include <iostream>
#include <Player.h>
#include <Events.h>
#include <Debug.h>
#include <SDL.h>
#include <SDL_image.h>

#include "InputHandler.h"

using namespace std;
int w, h;

int main(int argc, char* args[])
{
	SDL_Init(SDL_INIT_VIDEO);
	IMG_Init(IMG_INIT_PNG);

	SDL_Window* windowSDL = SDL_CreateWindow("Player Finite State Machine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
	SDL_Renderer* rendererSDL = SDL_CreateRenderer(windowSDL, -1, SDL_RENDERER_ACCELERATED);

	// Create the main window
	//sf::RenderWindow window(sf::VideoMode(800, 600), "Player Finite State Machine");
	SDL_Texture* player_texture;
#pragma region TextureLoading

	// Load a sprite to display

	player_texture = IMG_LoadTexture(rendererSDL, PLAYER_SPRITES);

#pragma endregion

#pragma region AnimatedSprite

	// Setup Players Default Animated Sprite
	AnimatedSprite player_animated_sprite(player_texture, 200, 0);

#pragma endregion

	Player player(player_animated_sprite);

	gpp::Events input;

	// Start the game loop
	bool close = true;
	while (close)
	{
		// Process events
		//sf::Event event;
		SDL_Event event;

		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				close = false;
				break;
			case SDL_KEYDOWN:

				// Died Event
				if (event.key.keysym.sym == SDLK_d) 
				{
					DEBUG_MSG("gpp::Events::Event::DIED_EVENT");
					input.setCurrent(gpp::Events::Event::DIED_EVENT);
				}
				// Revieved Event
				else if (event.key.keysym.sym == SDLK_r)
				{
					DEBUG_MSG("gpp::Events::Event::REVIVED_EVENT");
					input.setCurrent(gpp::Events::Event::REVIVED_EVENT);
				}
				// Running attack
				else if (event.key.keysym.sym == SDLK_z
							&& event.key.keysym.sym == SDLK_RIGHT)
				{
					DEBUG_MSG("gpp::Events::Event::ATTACK_START");
					input.setCurrent(gpp::Events::Event::ATTACK_START_EVENT);
				}
				// Attack
				else if (event.key.keysym.sym == SDLK_z)
				{
					DEBUG_MSG("gpp::Events::Event::ATTACK_START_EVENT");
					input.setCurrent(gpp::Events::Event::ATTACK_START_EVENT);
				}
				// Throw attack
				else if (event.key.keysym.sym == SDLK_x
							&& event.key.keysym.sym == SDLK_RIGHT)
				{
					DEBUG_MSG("gpp::Events::Event::THROW_START_EVENT");
					input.setCurrent(gpp::Events::Event::THROW_START_EVENT);
				}
				// Throw Attack
				else if (event.key.keysym.sym == SDLK_x)
				{
					DEBUG_MSG("gpp::Events::Event::THROW_START_EVENT");
					input.setCurrent(gpp::Events::Event::THROW_START_EVENT);
				}
				// Run Right
				else if (event.key.keysym.sym == SDLK_RIGHT)
				{
					DEBUG_MSG("gpp::Events::Event::RUN_RIGHT_START_EVENT");
					input.setCurrent(gpp::Events::Event::RUN_RIGHT_START_EVENT);
				}
				// Climb Up
				else if (event.key.keysym.sym == SDLK_UP)
				{
					DEBUG_MSG("gpp::Events::Event::MOVE_UP_START_EVENT");
					input.setCurrent(gpp::Events::Event::MOVE_UP_START_EVENT);
				}
				// Climb Down
				else if (event.key.keysym.sym == SDLK_DOWN)
				{
					DEBUG_MSG("gpp::Events::Event::MOVE_DOWN_START_EVENT");
					input.setCurrent(gpp::Events::Event::MOVE_DOWN_START_EVENT);
				}
				// Hit Bottom of Ladder Event
				else if (event.key.keysym.sym == SDLK_c)
				{
					DEBUG_MSG("gpp::Events::Event::HIT_LADDER_BOTTOM_EVENT");
					input.setCurrent(gpp::Events::Event::HIT_LADDER_BOTTOM_EVENT);
				}
				// Hit Top of Ladder Event
				else if (event.key.keysym.sym == SDLK_t)
				{
					DEBUG_MSG("gpp::Events::Event::HIT_LADDER_TOP_EVENT");
					input.setCurrent(gpp::Events::Event::HIT_LADDER_TOP_EVENT);
				}
				// Jump Run
				if (event.key.keysym.sym == SDLK_SPACE
						&& event.key.keysym.sym == SDLK_RIGHT)
				{
					DEBUG_MSG("gpp::Events::Event::JUMP_UP_EVENT");
					input.setCurrent(gpp::Events::Event::JUMP_UP_EVENT);
				}
				// Jump Event
				else if (event.key.keysym.sym == SDLK_SPACE)
				{
					DEBUG_MSG("gpp::Events::Event::JUMP_UP_EVENT");
					input.setCurrent(gpp::Events::Event::JUMP_UP_EVENT);
				}
				// Running Slide
				else if (event.key.keysym.sym == SDLK_DOWN
							&& event.key.keysym.sym == SDLK_RIGHT)
				{
					DEBUG_MSG("gpp::Events::Event::SLIDE_EVENT");
					input.setCurrent(gpp::Events::Event::SLIDE_EVENT);
				}
				// Hit Ground Event
				else if (event.key.keysym.sym == SDLK_h)
				{
					DEBUG_MSG("gpp::Events::Event::HIT_GROUND_EVENT");
					input.setCurrent(gpp::Events::Event::HIT_GROUND_EVENT);
				}

				// Jump Attack Event
				else if (event.key.keysym.sym == SDLK_h)
				{
					DEBUG_MSG("gpp::Events::Event::HIT_GROUND_EVENT");
					input.setCurrent(gpp::Events::Event::HIT_GROUND_EVENT);
				}

				// Jump Throw Attack Event
				else if (event.key.keysym.sym == SDLK_h)
				{
					DEBUG_MSG("gpp::Events::Event::HIT_GROUND_EVENT");
					input.setCurrent(gpp::Events::Event::HIT_GROUND_EVENT);
				}
				else if (event.key.keysym.sym == SDLK_o)			// Output
				{
					player.getHandler()->OutputMacro();
				}
				else if (event.key.keysym.sym == SDLK_u)			// Undo
				{
					player.getHandler()->Undo();
				}
				else if (event.key.keysym.sym == SDLK_p)			// Redo
				{
					player.getHandler()->Redo(&player);
				}
				break;

				// Deal with KeyReleased
			case SDL_KEYUP:
				// Run and Stop Attack
				if (event.key.keysym.sym == SDLK_z
					&& event.key.keysym.sym == SDLK_RIGHT)
				{
					DEBUG_MSG("gpp::Events::Event::RUN_RIGHT_START_EVENT");
					input.setCurrent(gpp::Events::Event::RUN_RIGHT_START_EVENT);
				}
				// Stop Attack
				else if(event.key.keysym.sym == SDLK_z)
				{
					DEBUG_MSG("gpp::Events::Event::ATTACK_STOP_EVENT");
					input.setCurrent(gpp::Events::Event::ATTACK_STOP_EVENT);
				}
				// Run and Stop Throw Attack
				else if (event.key.keysym.sym == SDLK_x
					&& event.key.keysym.sym == SDLK_RIGHT)
				{
					DEBUG_MSG("gpp::Events::Event::RUN_RIGHT_START_EVENT");
					input.setCurrent(gpp::Events::Event::RUN_RIGHT_START_EVENT);
				}
				// Stop Throw Attack
				else if (event.key.keysym.sym == SDLK_x)
				{
					DEBUG_MSG("gpp::Events::Event::THROW_STOP_EVENT");
					input.setCurrent(gpp::Events::Event::THROW_STOP_EVENT);
				}
				// Stop Running Right
				else if (event.key.keysym.sym == SDLK_RIGHT)
				{
					DEBUG_MSG("gpp::Events::Event::RUN_RIGHT_STOP_EVENT");
					input.setCurrent(gpp::Events::Event::RUN_RIGHT_STOP_EVENT);
				}
				// Stop Slide
				else if (event.key.keysym.sym == SDLK_DOWN
					&&
					event.key.keysym.sym == SDLK_RIGHT)
				{
					DEBUG_MSG("gpp::Events::Event::RUN_RIGHT_START_EVENT");
					input.setCurrent(gpp::Events::Event::RUN_RIGHT_START_EVENT);
				}
				// Stop Moving Up
				else if (event.key.keysym.sym == SDLK_UP)
				{
					DEBUG_MSG("gpp::Events::Event::MOVE_UP_STOP_EVENT");
					input.setCurrent(gpp::Events::Event::MOVE_UP_STOP_EVENT);
				}
				// Stop Moving Down
				else if (event.key.keysym.sym == SDLK_DOWN)
				{
					DEBUG_MSG("gpp::Events::Event::MOVE_DOWN_STOP_EVENT");
					input.setCurrent(gpp::Events::Event::MOVE_DOWN_STOP_EVENT);
				}
				break;

			default:
				input.setCurrent(gpp::Events::Event::NONE);
				break;
			}
			// Handle input to Player
			player.handleInput(input);
		}

		// Update the Player
		player.update();

		// Clear screen
		SDL_SetRenderDrawColor(rendererSDL, 0, 0, 0, 255);
		SDL_RenderClear(rendererSDL);

		player.getAnimatedSprite().w = player.getSourceSDLRectAtFrame().w;
		player.getAnimatedSprite().h = player.getSourceSDLRectAtFrame().h;
		SDL_RenderCopy(rendererSDL, player_texture, &player.getSourceSDLRectAtFrame(), &player.getAnimatedSprite());

		// Update the window
		SDL_RenderPresent(rendererSDL);
	}

	SDL_DestroyRenderer(rendererSDL);
	SDL_DestroyWindow(windowSDL);
	IMG_Quit();
	SDL_Quit();
	return EXIT_SUCCESS;
};