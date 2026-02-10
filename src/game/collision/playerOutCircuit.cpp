#include<string>

#include<game/collision/PlayerOutCircuit.h>
#include<game/Entity.h>
#include<game/utils/CompareTag.h>
#include<game/component/State.h>
#include<game/component/Position.h>
#include<actors/explosion/Explosion.h>

void PlayerOutCircuit(
	std::string tag_a,
	std::string tag_b,
	Entity entity_a,
	Entity entity_b
) {
	if (!CompareTag(tag_a, tag_b, "PLAYER_main", "CIRCUIT_main")) return;

	Entity player = (tag_a == "PLAYER_main") ? entity_a : entity_b;
	states[player].active = false;

	InitExplosion(positions[player].x, positions[player].y, 20);
}