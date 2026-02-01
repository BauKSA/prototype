#include<game/system/Movement.h>
#include<game/Entity.h>
#include<game/component/Velocity.h>
#include<game/component/Position.h>
#include<game/component/State.h>

void MoveActors(float delta_time) {
	const int entities = GetCurrentEntity();

	for (size_t i = 0; i < entities; i++) {
		if (!states[i].active) continue;
		if (i > velocities.size()) continue;

		positions[i].x += velocities[i].vx * delta_time;
		positions[i].y += velocities[i].vy * delta_time;
	}
}