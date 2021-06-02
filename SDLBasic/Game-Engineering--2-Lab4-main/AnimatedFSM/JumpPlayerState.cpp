#include <Events.h>

#include <JumpPlayerState.h>

#include <DiedPlayerState.h>
#include <JumpAttackPlayerState.h>
#include <JumpThrowAttackPlayerState.h>
#include <GlidePlayerState.h>

PlayerState* JumpPlayerState::handleInput(gpp::Events& input)
{
	if (input.getCurrent() == gpp::Events::Event::DIED_EVENT) {
		DEBUG_MSG("JumpPlayerState -> DiedPlayerState");
		return new DiedPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::ATTACK_START_EVENT)
	{
		DEBUG_MSG("JumpPlayerState -> JumpAttackPlayerState");
		return new JumpAttackPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::THROW_START_EVENT)
	{
		DEBUG_MSG("JumpPlayerState -> JumpThrowAttackPlayerState");
		return new JumpThrowAttackPlayerState();
	}
	return nullptr;
}
void JumpPlayerState::update(Player& player) {
	DEBUG_MSG("JumpPlayerState -> GlidePlayerState");
	float newTime = SDL_GetTicks();
	time = (newTime - lastTime) / 1000;	// Per second
	if (time > 1.2f) {
		PlayerState* temp = player.getPlayerState();
		PlayerState* state = new GlidePlayerState();
		player.getPlayerState()->exit(player);
		player.setPlayerState(state);
		player.getPlayerState()->enter(player);
		delete temp;
	}
}
void JumpPlayerState::enter(Player& player)
{
	DEBUG_MSG("Entering JumpPlayerState");
	player.getAnimatedSprite().clearFrames();
	time = SDL_GetTicks();
	lastTime = time;
	player.getAnimatedSprite().setPlayed(false);
	player.getAnimatedSprite().setLooped(false);

	SDL_Rect frame = { 3900, 1756, 362, 483 };
	player.getAnimatedSprite().addFrame(frame);
	SDL_Rect frame2 = { 4262, 1756, 362, 483 };
	player.getAnimatedSprite().addFrame(frame2);
	SDL_Rect frame3 = { 4624, 1756, 362, 483 };
	player.getAnimatedSprite().addFrame(frame3);
	SDL_Rect frame4 = { 3900, 2239, 362, 483 };
	player.getAnimatedSprite().addFrame(frame4);
	SDL_Rect frame5 = { 4262, 2239, 362, 483 };
	player.getAnimatedSprite().addFrame(frame5);
	SDL_Rect frame6 = { 4624, 2239, 362, 483 };
	player.getAnimatedSprite().addFrame(frame6);
	SDL_Rect frame7 = { 3900, 2722, 362, 483 };
	player.getAnimatedSprite().addFrame(frame7);
	SDL_Rect frame8 = { 4262, 2722, 362, 483 };
	player.getAnimatedSprite().addFrame(frame8);
	SDL_Rect frame9 = { 4624, 2722, 362, 483 };
	player.getAnimatedSprite().addFrame(frame9);
	SDL_Rect frame10 = { 3900, 3205, 362, 483 };
	player.getAnimatedSprite().addFrame(frame10);

	player.getAnimatedSpriteFrame().setTime((0.03f));
}
void JumpPlayerState::exit(Player& player)
{
	DEBUG_MSG("Exiting JumpPlayerState");
	player.getAnimatedSprite().setPlayed(false);
	player.getAnimatedSprite().setLooped(true);
}

void JumpPlayerState::name()
{
	DEBUG_MSG("JumpPlayerState");
}
