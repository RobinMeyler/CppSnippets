#include <Events.h>

#include <RevivedPlayerState.h>

#include <DiedPlayerState.h>
#include <IdlePlayerState.h>

PlayerState* RevivedPlayerState::handleInput(gpp::Events& input)
{
	if (input.getCurrent() == gpp::Events::Event::DIED_EVENT)
	{
		DEBUG_MSG("RevivedPlayerState -> DiedPlayerState");
		return new DiedPlayerState();
	}
	return nullptr;
}
void RevivedPlayerState::update(Player& player) {
	// Switch from RevivedPlayerState to IdlePlayerState
	DEBUG_MSG("RevivedPlayerState -> IdlePlayerState");
	float newTime = SDL_GetTicks();
	time = (newTime - lastTime) / 1000;	// Per second
	if (time > 0.5f) {
		PlayerState* temp = player.getPlayerState();
		PlayerState* state = new IdlePlayerState();
		player.getPlayerState()->exit(player);
		player.setPlayerState(state);
		player.getPlayerState()->enter(player);
		//delete temp;
	}
}
void RevivedPlayerState::enter(Player& player)
{
	DEBUG_MSG("Entering RevivedPlayerState");

	// How long in State Clock
	time = SDL_GetTicks();
	lastTime = time;
	// Clear existing frames
	player.getAnimatedSprite().clearFrames();

	// Set animation control members
	player.getAnimatedSprite().setPlayed(false);
	player.getAnimatedSprite().setLooped(false);

	// Add animation frames
	SDL_Rect frame = { 2454, 1494, 482, 498 };
	player.getAnimatedSprite().addFrame(frame);
	SDL_Rect frame2 = { 3418, 996, 482, 498 };
	player.getAnimatedSprite().addFrame(frame2);
	SDL_Rect frame3 = { 2936, 996, 482, 498 };
	player.getAnimatedSprite().addFrame(frame3);
	SDL_Rect frame4 = { 2454, 996, 482, 498 };
	player.getAnimatedSprite().addFrame(frame4);
	SDL_Rect frame5 = { 3418, 498, 482, 498 };
	player.getAnimatedSprite().addFrame(frame5);
	SDL_Rect frame6 = { 2936, 498, 482, 498 };
	player.getAnimatedSprite().addFrame(frame6);
	SDL_Rect frame7 = { 2454, 498, 482, 498 };
	player.getAnimatedSprite().addFrame(frame7);
	SDL_Rect frame8 = { 3418, 0, 482, 498 };
	player.getAnimatedSprite().addFrame(frame8);
	SDL_Rect frame9 = { 2936, 0, 482, 498 };
	player.getAnimatedSprite().addFrame(frame9);
	SDL_Rect frame10 = { 2454, 0, 482, 498 };
	player.getAnimatedSprite().addFrame(frame10);

	// Set the animation time
	player.getAnimatedSprite().setTime((0.03f));
}
void RevivedPlayerState::exit(Player& player)
{
	DEBUG_MSG("Exiting RevivedPlayerState");
	player.getAnimatedSprite().setPlayed(false);
	player.getAnimatedSprite().setLooped(true);
}

void RevivedPlayerState::name()
{
	DEBUG_MSG("RevivedPlayerState");
}
