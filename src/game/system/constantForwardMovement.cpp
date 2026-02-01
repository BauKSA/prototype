#include<cmath>
#include<iostream>

#include<actors/player/Player.h>
#include<game/system/ConstantForwardMovement.h>
#include<game/component/Velocity.h>
#include<game/component/Speed.h>
#include<game/component/Transform.h>
#include<game/component/State.h>
#include<game/Entity.h>
#include<actors/bullet/Bullet.h>

const double PI = 3.14159265358979323846;

static void ConstantMove(Entity e) {
	Transform& transform = transforms[e];
	Velocity& velocity = velocities[e];
	Speed& speed = speeds[e];

	const float rad = transform.rotation * PI / 180;

	velocity.vx = std::sin(rad) * speed;
	velocity.vy = -std::cos(rad) * speed;
}

void ConstantForwardMovement() {
	if (Player >= velocities.size()) return;

	ConstantMove(Player);

	for (size_t i = 0; i < Bullets.size(); i++) {
		if (!states[Bullets.at(i)].active) continue;
		ConstantMove(Bullets.at(i));
	}
}