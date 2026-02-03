#ifndef _PLAYERBULLET_ENEMYCOLLISION_
#define _PLAYERBULLET_ENEMYCOLLISION_
#include<string>
#include<game/event/Event.h>
#include<game/Entity.h>
#include<game/utils/CompareTag.h>
#include<game/component/State.h>

void PlayerBullet_EnemyCollision(
	std::string tag_a,
	std::string tag_b,
	Entity entity_a,
	Entity entity_b
);

#endif // !_PLAYERBULLET_ENEMYCOLLISION_