#ifndef _ANIMATION_
#define _ANIMATION_
#include<game/component/Body.h>
#include<game/Entity.h>
#include<string>
#include<cstdint>
#include<vector>
#include<array>

constexpr auto MAX_ANIMATIONS = 5;
constexpr auto MILLISECONDS_PER_FRAME = 1000;

enum ANIMATION_INDEX {};

struct Animation {
	std::string name;
	std::vector<Body> bodies;
	uint8_t frame_count;
	uint8_t current_frame;
	float elapsed_time;
	float timer;
	bool active;
	Entity entity;

	Animation()
		: name(""), frame_count(0), current_frame(0), elapsed_time(0), timer(0), active(false), entity(0) {}
};

extern std::vector<std::array<Animation, MAX_ANIMATIONS>> animations;
extern std::vector<bool> animations_to_update;

#endif // !_ANIMATION_
