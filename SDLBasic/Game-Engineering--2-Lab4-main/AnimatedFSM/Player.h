#pragma once

#include "InputHandler.h"
#include <Events.h>
#include <PlayerState.h>
#include <AnimatedSprite.h>


class Player
{
private:
	PlayerState* m_state;
	AnimatedSprite m_animated_sprite;
	InputHandler m_commandPatternInput;

public:
	Player(const AnimatedSprite&);
	virtual void handleInput(gpp::Events);
	virtual void update();

	AnimatedSprite& getAnimatedSprite();
	SDL_Rect& getSourceSDLRectAtFrame();
	AnimatedSprite& getAnimatedSpriteFrame();
	void setAnimatedSprite(AnimatedSprite&);
	PlayerState* getPlayerState();
	void setPlayerState(PlayerState*);
	InputHandler* getHandler();
};



