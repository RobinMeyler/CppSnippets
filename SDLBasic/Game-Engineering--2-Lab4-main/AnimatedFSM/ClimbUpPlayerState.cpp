#include <Events.h>

#include <ClimbUpPlayerState.h>

#include <ClimbPausePlayerState.h>
#include <ClimbDownPlayerState.h>
#include <DecendLadderPlayerState.h>


PlayerState* ClimbUpPlayerState::handleInput(gpp::Events& input)
{
	if (input.getCurrent() == gpp::Events::Event::MOVE_UP_STOP_EVENT)
	{
		DEBUG_MSG("ClimbUpPlayerState -> ClimbPausePlayerState");
		return new ClimbPausePlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::MOVE_DOWN_START_EVENT)
	{
		DEBUG_MSG("ClimbUpPlayerState -> ClimbDownPlayerState");
		return new ClimbDownPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::HIT_LADDER_TOP_EVENT)
	{
		DEBUG_MSG("ClimbUpPlayerState -> DecendLadderPlayerState");
		return new DecendLadderPlayerState();
	}
	
	return nullptr;
}
void ClimbUpPlayerState::update(Player& player) {}
void ClimbUpPlayerState::enter(Player& player) 
{
	DEBUG_MSG("Entering ClimbUpPlayerState");

	// Climb Up Animated Sprite
	player.getAnimatedSprite().clearFrames();

	SDL_Rect frame = { 1608, 1392, 282, 464 };
	player.getAnimatedSprite().addFrame(frame);
	SDL_Rect frame2 = { 2172, 928, 282, 464 };
	player.getAnimatedSprite().addFrame(frame2);
	SDL_Rect frame3 = { 1890, 928, 282, 464 };
	player.getAnimatedSprite().addFrame(frame3);
	SDL_Rect frame4 = { 1608, 928, 282, 464 };
	player.getAnimatedSprite().addFrame(frame4);
	SDL_Rect frame5 = { 2172, 464, 282, 464 };
	player.getAnimatedSprite().addFrame(frame5);
	SDL_Rect frame6 = { 1890, 464, 282, 464 };
	player.getAnimatedSprite().addFrame(frame6);
	SDL_Rect frame7 = { 1608, 464, 282, 464 };
	player.getAnimatedSprite().addFrame(frame7);
	SDL_Rect frame8 = { 2172, 0, 282, 464 };
	player.getAnimatedSprite().addFrame(frame8);
	SDL_Rect frame9 = { 1890, 0, 282, 464 };
	player.getAnimatedSprite().addFrame(frame9);
	SDL_Rect frame10 = { 1608, 0, 282, 464 };
	player.getAnimatedSprite().addFrame(frame10);

	player.getAnimatedSprite().setTime((0.05f));
}
void ClimbUpPlayerState::exit(Player& player)
{
	DEBUG_MSG("Exiting ClimbUpPlayerState");
}

void ClimbUpPlayerState::name()
{
	DEBUG_MSG("ClimbUpPlayerState");
}
