#include<string>
#include<iostream>

#include<game/collision/PlayerBullet_EnemyCollision.h>
#include<game/component/State.h>
#include<game/Entity.h>
#include<game/utils/CompareTag.h>

void PlayerBullet_EnemyCollision(
	std::string tag_a,
	std::string tag_b,
	Entity entity_a,
	Entity entity_b
) {
	if (!CompareTag(tag_a, tag_b, "BULLET_main", "STAR_main")) return;
	states[entity_a].active = false;
	states[entity_b].active = false;

	std::cout << "PlayerBullet_EnemyCollision triggered between " << tag_a << " and " << tag_b << std::endl;

	return;
}