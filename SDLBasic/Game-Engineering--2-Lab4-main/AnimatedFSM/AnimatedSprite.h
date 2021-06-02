#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H

#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include <Debug.h>

using namespace std;

class AnimatedSprite: public SDL_Rect  {
public:
	AnimatedSprite();
	AnimatedSprite( SDL_Texture*, float xPos, float yPos);
	AnimatedSprite( SDL_Texture*, const SDL_Rect&);
	~AnimatedSprite();

	float& getTime();
	const vector<SDL_Rect>& getFrames();
	void clearFrames();
	SDL_Rect& getFrame(int);
	void addFrame(const SDL_Rect&);
	const int getCurrentFrame();
	void setLooped(bool);
	const bool getLooped();
	void setPlayed(bool);
	const bool getPlayed();
	void setTime(float);
	void update();
	
private:
	float m_time;
	vector<SDL_Rect> m_frames;
	unsigned int m_current_frame;
	bool m_loop;
	unsigned int m_play_count;
	unsigned int m_max_plays;
	bool m_played;
	SDL_Texture* m_texture;
	int m_textureWidth;
	int m_textureHeight;

	float currentTime;
	float lastFrameTime;
};

#endif // !ANIMATED_SPRITE_H
