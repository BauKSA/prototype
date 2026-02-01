#include<game/system/AnimFrames.h>
#include<game/component/Animation.h>
#include<game/component/Body.h>
#include<game/component/Shape.h>
#include<game/Entity.h>
#include<array>
#include <iostream>

void UpdateFrames(float delta_time) {
	for (size_t i = 0; i < animations.size(); i++)
	{
		std::array<Animation, MAX_ANIMATIONS>& anims = animations[i];
		for (size_t j = 0; j < MAX_ANIMATIONS; j++)
		{
			Animation& anim = anims[j];
			if (!anim.active) continue;
			anim.elapsed_time += delta_time;

			if (anim.elapsed_time >= MILLISECONDS_PER_FRAME) {
				std::cout << "Entity " << anim.entity << " Animation: " << anim.name
					<< " Frame: " << anim.current_frame << std::endl;
				int new_frame = ++anim.current_frame;

				animations_to_update[anim.entity] = true;

				if (anim.current_frame >= anim.frame_count) {
					anim.current_frame = 0;
				}

				anim.elapsed_time = 0;

				bodies[anim.entity] = &anim.bodies[anim.current_frame];
			}
		}
	}
}

void ChangeAnimation(Entity e, ANIMATION_INDEX index) {
	std::array<Animation, MAX_ANIMATIONS>& anims = animations[e];

	for (size_t i = 0; i < MAX_ANIMATIONS; i++)
	{
		Animation& anim = anims[i];
		if (!anim.active) continue;

		anim.active = false;
		anim.elapsed_time = 0;
		anim.current_frame = 0;
		break;
	}

	if (index >= MAX_ANIMATIONS) return;
	anims[index].active = true;
}