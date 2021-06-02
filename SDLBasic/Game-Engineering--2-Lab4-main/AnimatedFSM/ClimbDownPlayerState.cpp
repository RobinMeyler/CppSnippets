#include <Events.h>

#include <ClimbDownPlayerState.h>

#include <ClimbPausePlayerState.h>
#include <AccendLadderPlayerState.h>


PlayerState* ClimbDownPlayerState::handleInput(gpp::Events& input)
{
	if (input.getCurrent() == gpp::Events::Event::MOVE_DOWN_STOP_EVENT)
	{
		DEBUG_MSG("ClimbDownPlayerState -> ClimbPausePlayerState");
		return new ClimbPausePlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::HIT_LADDER_BOTTOM_EVENT)
	{
		DEBUG_MSG("ClimbDownPlayerState -> AccendLadderPlayerState");
		return new AccendLadderPlayerState();
	}
	return nullptr;
}
void ClimbDownPlayerState::update(Player& player) {}
void ClimbDownPlayerState::enter(Player& player)
{
	DEBUG_MSG("Entering ClimbDownPlayerState");
	// Climb Down Animated Sprite
	player.getAnimatedSprite().clearFrames();

	SDL_Rect frame = { 1608, 0, 282, 464 };
	player.getAnimatedSprite().addFrame(frame);
	SDL_Rect frame2 = { 1890, 0, 282, 464 };
	player.getAnimatedSprite().addFrame(frame2);
	SDL_Rect frame3 = { 2172, 0, 282, 464 };
	player.getAnimatedSprite().addFrame(frame3);
	SDL_Rect frame4 = { 1608, 464, 282, 464 };
	player.getAnimatedSprite().addFrame(frame4);
	SDL_Rect frame5 = { 1890, 464, 282, 464 };
	player.getAnimatedSprite().addFrame(frame5);
	SDL_Rect frame6 = { 2172, 464, 282, 464 };
	player.getAnimatedSprite().addFrame(frame6);
	SDL_Rect frame7 = { 1608, 928, 282, 464 };
	player.getAnimatedSprite().addFrame(frame7);
	SDL_Rect frame8 = { 1890, 928, 282, 464 };
	player.getAnimatedSprite().addFrame(frame8);
	SDL_Rect frame9 = { 2172, 928, 282, 464 };
	player.getAnimatedSprite().addFrame(frame9);
	SDL_Rect frame10 = { 1608, 1392, 282, 464 };
	player.getAnimatedSprite().addFrame(frame10);

	player.getAnimatedSprite().setTime((0.05f));

}
void ClimbDownPlayerState::exit(Player& player) 
{
	DEBUG_MSG("Exiting ClimbDownPlayerState");
}

void ClimbDownPlayerState::name()
{
	DEBUG_MSG("ClimbDownPlayerState");
}
