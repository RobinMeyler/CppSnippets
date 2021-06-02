#include <Events.h>

#include <GlidePlayerState.h>

#include <DiedPlayerState.h>
#include <IdlePlayerState.h>

PlayerState* GlidePlayerState::handleInput(gpp::Events& input)
{
	if (input.getCurrent() == gpp::Events::Event::HIT_GROUND_EVENT)
	{
		DEBUG_MSG("GlidePlayerState -> IdlePlayerState");
		return new IdlePlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::DIED_EVENT)
	{
		DEBUG_MSG("GlidePlayerState -> DiedPlayerState");
		return new DiedPlayerState();
	}
	return nullptr;
}
void GlidePlayerState::update(Player& player) {
	DEBUG_MSG("GlidePlayerState -> IdlePlayerState");
	float newTime = SDL_GetTicks();
	time = (newTime - lastTime) / 1000;	// Per second
	if (time > 1.2f) {
		PlayerState* temp = player.getPlayerState();
		PlayerState* state = new IdlePlayerState();
		player.getPlayerState()->exit(player);
		player.setPlayerState(state);
		player.getPlayerState()->enter(player);
		delete temp;
	}
}
void GlidePlayerState::enter(Player& player)
{
	DEBUG_MSG("Entering RevivedPlayerState");

	player.getAnimatedSprite().clearFrames();
	time = SDL_GetTicks();
	lastTime = time;
	SDL_Rect frame = { 0, 1992, 443, 454 };
	player.getAnimatedSprite().addFrame(frame);
	SDL_Rect frame2 = { 443, 1992, 443, 454 };
	player.getAnimatedSprite().addFrame(frame2);
	SDL_Rect frame3 = { 886, 1992, 443, 454 };
	player.getAnimatedSprite().addFrame(frame3);
	SDL_Rect frame4 = { 0, 2446, 443, 454 };
	player.getAnimatedSprite().addFrame(frame4);
	SDL_Rect frame5 = { 443, 2446, 443, 454 };
	player.getAnimatedSprite().addFrame(frame5);
	SDL_Rect frame6 = { 886, 2446, 443, 454 };
	player.getAnimatedSprite().addFrame(frame6);
	SDL_Rect frame7 = { 0, 2900, 443, 454 };
	player.getAnimatedSprite().addFrame(frame7);
	SDL_Rect frame8 = { 443, 2900, 443, 454 };
	player.getAnimatedSprite().addFrame(frame8);
	SDL_Rect frame9 = { 886, 2900, 443, 454 };
	player.getAnimatedSprite().addFrame(frame9);
	SDL_Rect frame10 = { 0, 3354, 443, 454 };
	player.getAnimatedSprite().addFrame(frame10);

	player.getAnimatedSprite().setTime((0.03f));
}
void GlidePlayerState::exit(Player& player)
{
	DEBUG_MSG("Exiting RevivedPlayerState");
}

void GlidePlayerState::name()
{
	DEBUG_MSG("RevivedPlayerState");
}
