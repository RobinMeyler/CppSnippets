#include <Events.h>

#include <ThrowAttackPlayerState.h>

#include <RunRightPlayerState.h>
#include <IdlePlayerState.h>
#include <DiedPlayerState.h>

PlayerState* ThrowAttackPlayerState::handleInput(gpp::Events& input)
{
	if (input.getCurrent() == gpp::Events::Event::RUN_RIGHT_START_EVENT)
	{
		DEBUG_MSG("AttackPlayerState -> RunRightPlayerState");
		return new RunRightPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::THROW_STOP_EVENT)
	{
		DEBUG_MSG("AttackPlayerState -> IdlePlayerState");
		return new IdlePlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::DIED_EVENT) {
		DEBUG_MSG("ThrowAttackPlayerState -> DiedPlayerState");
		return new DiedPlayerState();
	}
	return nullptr;
}
void ThrowAttackPlayerState::update(Player& player) {}
void ThrowAttackPlayerState::enter(Player& player)
{
	DEBUG_MSG("Entering AttackPlayerState");
	player.getAnimatedSprite().clearFrames();

	SDL_Rect frame = { 6075, 0, 377, 451 };
	player.getAnimatedSprite().addFrame(frame);
	SDL_Rect frame2 = { 6452, 0, 377, 451 };
	player.getAnimatedSprite().addFrame(frame2);
	SDL_Rect frame3 = { 6829, 0, 377, 451 };
	player.getAnimatedSprite().addFrame(frame3);
	SDL_Rect frame4 = { 6075, 451, 377, 451 };
	player.getAnimatedSprite().addFrame(frame4);
	SDL_Rect frame5 = { 6452, 451, 377, 451 };
	player.getAnimatedSprite().addFrame(frame5);
	SDL_Rect frame6 = { 6829, 451, 377, 451 };
	player.getAnimatedSprite().addFrame(frame6);
	SDL_Rect frame7 = { 6075, 902, 377, 451 };
	player.getAnimatedSprite().addFrame(frame7);
	SDL_Rect frame8 = { 6452, 902, 377, 451 };
	player.getAnimatedSprite().addFrame(frame8);
	SDL_Rect frame9 = { 6829, 902,377, 451 };
	player.getAnimatedSprite().addFrame(frame9);
	SDL_Rect frame10 = { 6075, 1353, 377, 451 };
	player.getAnimatedSprite().addFrame(frame10);


	player.getAnimatedSprite().setTime((0.03f));
}
void ThrowAttackPlayerState::exit(Player& player)
{
	DEBUG_MSG("Exiting AttackPlayerState");
}

void ThrowAttackPlayerState::name()
{
	DEBUG_MSG("AttackPlayerState");
}
