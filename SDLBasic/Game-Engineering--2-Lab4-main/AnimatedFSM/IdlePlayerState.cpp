#include <Events.h>

#include <IdlePlayerState.h>

#include <AttackPlayerState.h>
#include <ThrowAttackPlayerState.h>
#include <RunRightPlayerState.h>
#include <AccendLadderPlayerState.h>
#include <DecendLadderPlayerState.h>
#include <JumpPlayerState.h>
#include <DiedPlayerState.h>


PlayerState* IdlePlayerState::handleInput(gpp::Events& input) {

	if (input.getCurrent() == gpp::Events::Event::ATTACK_START_EVENT)
	{
		DEBUG_MSG("IdlePlayerState -> AttackPlayerState");
		return new AttackPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::THROW_START_EVENT)
	{
		DEBUG_MSG("IdlePlayerState -> ThrowAttackPlayerState");
		return new ThrowAttackPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::RUN_RIGHT_START_EVENT) {
		DEBUG_MSG("IdlePlayerState -> RunRightPlayerState");
		return new RunRightPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::HIT_LADDER_BOTTOM_EVENT) {
		DEBUG_MSG("IdlePlayerState -> AccendLadderPlayerState");
		return new AccendLadderPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::HIT_LADDER_TOP_EVENT) {
		DEBUG_MSG("IdlePlayerState -> DecendLadderPlayerState");
		return new DecendLadderPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::JUMP_UP_EVENT) {
		DEBUG_MSG("IdlePlayerState -> JumpPlayerState");
		return new JumpPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::DIED_EVENT) {
		DEBUG_MSG("IdlePlayerState -> DiedPlayerState");
		return new DiedPlayerState();
	}
	return nullptr;
}

void IdlePlayerState::update(Player& player) {}

void IdlePlayerState::enter(Player& player) 
{
	DEBUG_MSG("Entering IdlePlayerState");
	player.getAnimatedSprite().clearFrames();

	SDL_Rect frame = { 3900, 0, 232, 439 };
	player.getAnimatedSprite().addFrame(frame);
	SDL_Rect frame2 = { 4132, 0, 232, 439 };
	player.getAnimatedSprite().addFrame(frame2);
	SDL_Rect frame3 = { 4364, 0, 232, 439 };
	player.getAnimatedSprite().addFrame(frame3);
	SDL_Rect frame4 = { 3900, 439, 232, 439 };
	player.getAnimatedSprite().addFrame(frame4);
	SDL_Rect frame5 = { 4132, 439, 232, 439 };
	player.getAnimatedSprite().addFrame(frame5);
	SDL_Rect frame6 = { 4364, 439, 232, 439 };
	player.getAnimatedSprite().addFrame(frame6);
	SDL_Rect frame7 = { 3900, 878, 232, 439 };
	player.getAnimatedSprite().addFrame(frame7);
	SDL_Rect frame8 = { 4132, 878, 232, 439 };
	player.getAnimatedSprite().addFrame(frame8);
	SDL_Rect frame9 = { 4364, 878, 232, 439 };
	player.getAnimatedSprite().addFrame(frame9);
	SDL_Rect frame10 = { 3900, 1317, 232, 439 };
	player.getAnimatedSprite().addFrame(frame10);

	player.getAnimatedSprite().setTime((0.05f));
}

void IdlePlayerState::exit(Player& player)
{
	DEBUG_MSG("Exiting IdlePlayerState");
}

void IdlePlayerState::name()
{
	DEBUG_MSG("IdlePlayerState");
}
