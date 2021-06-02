#include <Events.h>

#include <SlidePlayerState.h>

#include <RunRightPlayerState.h>
#include <DiedPlayerState.h>
#include <IdlePlayerState.h>

PlayerState* SlidePlayerState::handleInput(gpp::Events& input)
{
	if (input.getCurrent() == gpp::Events::Event::RUN_RIGHT_START_EVENT)
	{
		DEBUG_MSG("SlidePlayerState -> RunRightPlayerState");
		return new RunRightPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::DIED_EVENT) {
		DEBUG_MSG("SlidePlayerState -> DiedPlayerState");
		return new DiedPlayerState();
	}
	return nullptr;
}
void SlidePlayerState::update(Player& player) {
	// Switch from SlidePlayerState to IdlePlayerState
	// There is a fixed time at which the slide switched
	// back to IdlePlayerState....as the gameplay programmer
	// you may wish to stop the slide and have an appropriate
	// state and animation at the end of the slide
	// this was added so sliding does not go one indefinitely
	float newTime = SDL_GetTicks();
	time = (newTime - lastTime) / 1000;	// Per second
	if (time > 2.0f) {
		DEBUG_MSG("SlidePlayerState -> IdlePlayerState");
		PlayerState* temp = player.getPlayerState();
		PlayerState* state = new IdlePlayerState();
		player.getPlayerState()->exit(player);
		player.setPlayerState(state);
		player.getPlayerState()->enter(player);
		delete temp; // Delete previous
	}
}
void SlidePlayerState::enter(Player& player)
{
	DEBUG_MSG("Entering SlidePlayerState");
	player.getAnimatedSprite().clearFrames();
	time = SDL_GetTicks();
	lastTime = time;
	SDL_Rect frame = { 0, 5388, 373, 351 };
	player.getAnimatedSprite().addFrame(frame);
	SDL_Rect frame2 = { 373, 5388, 373, 351 };
	player.getAnimatedSprite().addFrame(frame2);
	SDL_Rect frame3 = { 746, 5388, 373, 351 };
	player.getAnimatedSprite().addFrame(frame3);
	SDL_Rect frame4 = { 0, 5739, 373, 351 };
	player.getAnimatedSprite().addFrame(frame4);
	SDL_Rect frame5 = { 373, 5739, 373, 351 };
	player.getAnimatedSprite().addFrame(frame5);
	SDL_Rect frame6 = { 746, 5739, 373, 351 };
	player.getAnimatedSprite().addFrame(frame6);
	SDL_Rect frame7 = { 0, 6090, 373, 351 };
	player.getAnimatedSprite().addFrame(frame7);
	SDL_Rect frame8 = { 373, 6090, 373, 351 };
	player.getAnimatedSprite().addFrame(frame8);
	SDL_Rect frame9 = { 746, 6090, 373, 351 };
	player.getAnimatedSprite().addFrame(frame9);
	SDL_Rect frame10 = { 0, 6441, 373, 351 };
	player.getAnimatedSprite().addFrame(frame10);

	player.getAnimatedSpriteFrame().setTime((0.03f));
}
void SlidePlayerState::exit(Player& player)
{
	DEBUG_MSG("Exiting SlidePlayerState");
}

void SlidePlayerState::name()
{
	DEBUG_MSG("SlidePlayerState");
}
