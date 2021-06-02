#include <Events.h>

#include <AttackPlayerState.h>

#include <RunRightPlayerState.h>
#include <IdlePlayerState.h>
#include <DiedPlayerState.h>

PlayerState* AttackPlayerState::handleInput(gpp::Events& input)
{
	if (input.getCurrent() == gpp::Events::Event::RUN_RIGHT_START_EVENT)
	{
		DEBUG_MSG("AttackPlayerState -> RunRightPlayerState");
		return new RunRightPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::ATTACK_STOP_EVENT)
	{
		DEBUG_MSG("AttackPlayerState -> IdlePlayerState");
		return new IdlePlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::DIED_EVENT) {
		DEBUG_MSG("AttackPlayerState -> DiedPlayerState");
		return new DiedPlayerState();
	}
	return nullptr;
}
void AttackPlayerState::update(Player& player) {}
void AttackPlayerState::enter(Player& player)
{
	DEBUG_MSG("Entering AttackPlayerState");
	player.getAnimatedSprite().clearFrames();

	SDL_Rect frame = { 0, 0, 536, 495 };
	player.getAnimatedSprite().addFrame(frame);
	SDL_Rect frame2 = { 536, 0, 536, 495 };
	player.getAnimatedSprite().addFrame(frame2);
	SDL_Rect frame3 = { 1072, 0, 536, 495 };
	player.getAnimatedSprite().addFrame(frame3);
	SDL_Rect frame4 = { 0, 495, 536, 495 };
	player.getAnimatedSprite().addFrame(frame4);
	SDL_Rect frame5 = { 536, 495, 536, 495 };
	player.getAnimatedSprite().addFrame(frame5);
	SDL_Rect frame6 = { 1072, 495, 536, 495 };
	player.getAnimatedSprite().addFrame(frame6);
	SDL_Rect frame7 = { 0, 990, 536, 495 };
	player.getAnimatedSprite().addFrame(frame7);
	SDL_Rect frame8 = { 536, 990, 536, 495 };
	player.getAnimatedSprite().addFrame(frame8);
	SDL_Rect frame9 = { 1072, 990, 536, 495 };
	player.getAnimatedSprite().addFrame(frame9);
	SDL_Rect frame10 = { 0, 1485, 536, 495 };
	player.getAnimatedSprite().addFrame(frame10);

	player.getAnimatedSprite().setTime((0.03f));
}
void AttackPlayerState::exit(Player& player)
{
	DEBUG_MSG("Exiting AttackPlayerState");
}

void AttackPlayerState::name()
{
	DEBUG_MSG("AttackPlayerState");
}
