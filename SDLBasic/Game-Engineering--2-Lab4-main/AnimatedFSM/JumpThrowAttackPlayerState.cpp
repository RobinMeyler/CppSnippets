#include <Events.h>

#include <JumpThrowAttackPlayerState.h>

#include <RunRightPlayerState.h>
#include <GlidePlayerState.h>
#include <DiedPlayerState.h>

PlayerState* JumpThrowAttackPlayerState::handleInput(gpp::Events& input)
{
	if (input.getCurrent() == gpp::Events::Event::DIED_EVENT) {
		DEBUG_MSG("JumpThrowAttackPlayerState -> DiedPlayerState");
		return new DiedPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::THROW_STOP_EVENT)
	{
		DEBUG_MSG("JumpThrowAttackPlayerState -> GlidePlayerState");
		return new GlidePlayerState();
	}
	return nullptr;
}
void JumpThrowAttackPlayerState::update(Player& player) {}
void JumpThrowAttackPlayerState::enter(Player& player)
{
	DEBUG_MSG("Entering JumpThrowAttackPlayerState");
	player.getAnimatedSprite().clearFrames();

	SDL_Rect frame = { 4596, 0, 360, 43 };
	player.getAnimatedSprite().addFrame(frame);
	SDL_Rect frame2 = { 4956, 0, 360, 431 };
	player.getAnimatedSprite().addFrame(frame2);
	SDL_Rect frame3 = { 5316, 0, 360, 431 };
	player.getAnimatedSprite().addFrame(frame3);
	SDL_Rect frame4 = { 4596, 431, 360, 431 };
	player.getAnimatedSprite().addFrame(frame4);
	SDL_Rect frame5 = { 4956, 431, 360, 431 };
	player.getAnimatedSprite().addFrame(frame5);
	SDL_Rect frame6 = { 5316, 431, 360, 431 };
	player.getAnimatedSprite().addFrame(frame6);
	SDL_Rect frame7 = { 4596, 862, 360, 431 };
	player.getAnimatedSprite().addFrame(frame7);
	SDL_Rect frame8 = { 4956, 862, 360, 431 };
	player.getAnimatedSprite().addFrame(frame8);
	SDL_Rect frame9 = { 5316, 862, 360, 431 };
	player.getAnimatedSprite().addFrame(frame9);
	SDL_Rect frame10 = { 4596, 1293, 360, 431 };
	player.getAnimatedSprite().addFrame(frame10);


	player.getAnimatedSprite().setTime((0.05f));
}
void JumpThrowAttackPlayerState::exit(Player& player)
{
	DEBUG_MSG("Exiting JumpThrowAttackPlayerState");
}

void JumpThrowAttackPlayerState::name()
{
	DEBUG_MSG("JumpThrowAttackPlayerState");
}
