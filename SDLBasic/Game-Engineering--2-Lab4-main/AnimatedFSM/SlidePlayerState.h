#ifndef SLIDE_PLAYER_STATE_H
#define SLIDE_PLAYER_STATE_H

#include <Player.h>
#include <PlayerState.h>

class SlidePlayerState : public PlayerState {
public:
	virtual PlayerState* handleInput(gpp::Events& input);
	virtual void update(Player&);
	virtual void enter(Player&);
	virtual void exit(Player&);
	virtual void name();
private:
	float time{ 0 };
	float lastTime{ 0 };
};

#endif