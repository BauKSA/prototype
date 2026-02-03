#include<game/utils/EventContainer.h>
#include<game/event/Event.h>

#include<game/collision/PlayerBullet_EnemyCollision.h>

void InitCollisionEvents() {
	events.push_back(PlayerBullet_EnemyCollision);
}