#include<game/event/Event.h>

#include<game/collision/PlayerBullet_EnemyCollision.h>
#include<game/collision/PlayerOutCircuit.h>

void InitCollisionEvents() {
	EnterCollisionEvents.push_back(PlayerBullet_EnemyCollision);
	ExitCollisionEvents.push_back(PlayerOutCircuit);
}