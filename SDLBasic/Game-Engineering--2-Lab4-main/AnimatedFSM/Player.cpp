#include <stdio.h>
#include <Player.h>
#include <Events.h>
#include <IdlePlayerState.h>


Player::Player(const AnimatedSprite& sprite) : m_animated_sprite(sprite)
{
	// Set the Player to Default to IdlePlayer State 
	// and Enter that State
	m_state = new IdlePlayerState();
	m_state->enter(*this);
}

void Player::handleInput(gpp::Events input) {
	PlayerState * state = m_state->handleInput(input);

	if (state != NULL) {
		m_state->exit(*this);
		m_state = state;
		m_commandPatternInput.addHistory(m_state);
		m_state->enter(*this);	
	}
}

void Player::update() {
	m_animated_sprite.update();
	m_state->update(*this);
}

AnimatedSprite& Player::getAnimatedSprite() {
	return m_animated_sprite;
}

SDL_Rect& Player::getSourceSDLRectAtFrame()
{
	int frame = m_animated_sprite.getCurrentFrame();
	return m_animated_sprite.getFrame(frame);
}

AnimatedSprite& Player::getAnimatedSpriteFrame() {
	return m_animated_sprite;
}

void Player::setAnimatedSprite(AnimatedSprite& animated_sprite) {
	this->m_animated_sprite = animated_sprite;
}

PlayerState* Player::getPlayerState() { return this->m_state; }

void Player::setPlayerState(PlayerState* state) { this->m_state = state; }

InputHandler* Player::getHandler()
{
	return &m_commandPatternInput;
}

