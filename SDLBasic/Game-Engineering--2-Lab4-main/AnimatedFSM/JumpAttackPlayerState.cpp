#include <Events.h>

#include <JumpAttackPlayerState.h>

#include <RunRightPlayerState.h>
#include <GlidePlayerState.h>
#include <DiedPlayerState.h>

PlayerState* JumpAttackPlayerState::handleInput(gpp::Events& input)
{
	if (input.getCurrent() == gpp::Events::Event::DIED_EVENT) {
		DEBUG_MSG("JumpAttackPlayerState -> DiedPlayerState");
		return new DiedPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::ATTACK_STOP_EVENT)
	{
		DEBUG_MSG("JumpAttackPlayerState -> GlidePlayerState");
		return new GlidePlayerState();
	}
	return nullptr;
}
void JumpAttackPlayerState::update(Player& player) {}
void JumpAttackPlayerState::enter(Player& player)
{
	DEBUG_MSG("Entering JumpAttackPlayerState");
	player.getAnimatedSprite().clearFrames();


	SDL_Rect frame = { 1329, 1992, 504, 522 };
	player.getAnimatedSprite().addFrame(frame);
	SDL_Rect frame2 = { 1851, 1992, 504, 522 };
	player.getAnimatedSprite().addFrame(frame2);
	SDL_Rect frame3 = { 2373, 1992, 504, 522 };
	player.getAnimatedSprite().addFrame(frame3);
	SDL_Rect frame4 = { 1329, 2514, 504, 522 };
	player.getAnimatedSprite().addFrame(frame4);
	SDL_Rect frame5 = { 1851, 2514, 504, 522 };
	player.getAnimatedSprite().addFrame(frame5);
	SDL_Rect frame6 = { 2373, 2514, 504, 522 };
	player.getAnimatedSprite().addFrame(frame6);
	SDL_Rect frame7 = { 1329, 3036, 504, 522 };
	player.getAnimatedSprite().addFrame(frame7);
	SDL_Rect frame8 = { 1851, 3036, 504, 522 };
	player.getAnimatedSprite().addFrame(frame8);
	SDL_Rect frame9 = { 2373, 3036, 504, 522 };
	player.getAnimatedSprite().addFrame(frame9);
	SDL_Rect frame10 = { 1329, 3558, 504, 522 };
	player.getAnimatedSprite().addFrame(frame10);

	player.getAnimatedSprite().setTime((0.03f));
}
void JumpAttackPlayerState::exit(Player& player)
{
	DEBUG_MSG("Exiting JumpAttackPlayerState");
}

void JumpAttackPlayerState::name()
{
	DEBUG_MSG("JumpAttackPlayerState");
}
