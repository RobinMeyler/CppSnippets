#include <Events.h>

#include <DiedPlayerState.h>

#include <RevivedPlayerState.h>

PlayerState* DiedPlayerState::handleInput(gpp::Events& input)
{
	if (input.getCurrent() == gpp::Events::Event::REVIVED_EVENT)
	{
		DEBUG_MSG("DiedPlayerState -> RevivedPlayerState");
		return new RevivedPlayerState();
	}
	return nullptr;
}
void DiedPlayerState::update(Player& player) {}
void DiedPlayerState::enter(Player& player)
{
	DEBUG_MSG("Entering DiedPlayerState");
	player.getAnimatedSprite().clearFrames();

	player.getAnimatedSprite().setPlayed(false);
	player.getAnimatedSprite().setLooped(false);

	SDL_Rect frame = { 2454, 0, 482, 498 };
	player.getAnimatedSprite().addFrame(frame);
	SDL_Rect frame2 = { 2936, 0, 482, 498 };
	player.getAnimatedSprite().addFrame(frame2);
	SDL_Rect frame3 = { 3418, 0, 482, 498 };
	player.getAnimatedSprite().addFrame(frame3);
	SDL_Rect frame4 = { 2454, 498, 482, 498 };
	player.getAnimatedSprite().addFrame(frame4);
	SDL_Rect frame5 = { 2936, 498, 482, 498 };
	player.getAnimatedSprite().addFrame(frame5);
	SDL_Rect frame6 = { 3418, 498, 482, 498 };
	player.getAnimatedSprite().addFrame(frame6);
	SDL_Rect frame7 = { 2454, 996, 482, 498 };
	player.getAnimatedSprite().addFrame(frame7);
	SDL_Rect frame8 = { 2936, 996, 482, 498 };
	player.getAnimatedSprite().addFrame(frame8);
	SDL_Rect frame9 = { 3418, 996, 482, 498 };
	player.getAnimatedSprite().addFrame(frame9);
	SDL_Rect frame10 = { 2454, 1494, 482, 498 };
	player.getAnimatedSprite().addFrame(frame10);

	player.getAnimatedSprite().setTime((0.03f));
}
void DiedPlayerState::exit(Player& player)
{
	DEBUG_MSG("Exiting DiedPlayerState");
	player.getAnimatedSprite().setPlayed(false);
	player.getAnimatedSprite().setLooped(true);
}

void DiedPlayerState::name()
{
	DEBUG_MSG("DiedPlayerState");
}
