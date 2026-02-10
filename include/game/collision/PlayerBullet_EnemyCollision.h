#ifndef _PLAYERBULLET_ENEMYCOLLISION_
#define _PLAYERBULLET_ENEMYCOLLISION_
#include<string>
#include<game/Entity.h>

void PlayerBullet_EnemyCollision(
	std::string tag_a,
	std::string tag_b,
	Entity entity_a,
	Entity entity_b
);

#endif // !_PLAYERBULLET_ENEMYCOLLISION_