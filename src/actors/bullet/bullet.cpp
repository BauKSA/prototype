#include<vector>
#include<SFML/Graphics/Color.hpp>
#include<iostream>
#include<string>

#include "game/Entity.h"
#include "game/component/Body.h"
#include "game/component/Position.h"
#include "game/component/Transform.h"
#include "game/component/Speed.h"
#include "game/component/Velocity.h"
#include "game/utils/ColorConversor.h"
#include "actors/bullet/Bullet.h"
#include "actors/player/Player.h"
#include<game/component/State.h>
#include<game/component/Layer.h>
#include<game/component/Timer.h>


std::vector<Entity> Bullets;
std::string BULLET_TAG = "BULLET";

static void InitBulletBody(Entity bullet) {
	Body* bulletBody = new Body;
	Vertex bulletVertex;

	bulletVertex.coords.push_back({ 0, -4 });
	bulletVertex.coords.push_back({ 0, 4 });
	bulletVertex.coords.push_back({ 2, 4 });
	bulletVertex.coords.push_back({ 2, -4 });

	bulletVertex.color = SfToHex(sf::Color::Black);
	bulletVertex.outline = SfToHex(sf::Color::Yellow);
	bulletVertex.tag = "main";

	Coord offset{ 0, 0 };
	bulletVertex.offset = offset;

	bulletBody->components.push_back(bulletVertex);
	bulletBody->shape_generated = false;

	bodies.resize(GetCurrentEntity());
	bodies[bullet] = bulletBody;
}

static void InitBulletPosition(Entity bullet) {
	Position bulletPosition{};
	bulletPosition.x = positions[Player].x;
	bulletPosition.y = positions[Player].y - 1;

	positions[bullet] = bulletPosition;
}

static void InitBulletTransform(Entity bullet) {
	Transform bulletTransform{};
	bulletTransform.rotation = transforms[Player].rotation;

	transforms[bullet] = bulletTransform;
}

static void InitBulletMovement(Entity bullet) {
	speeds[bullet] = 2.f;

	velocities[bullet] = { 0.f, 0.f };
}

static void InitState(Entity bullet) {
	State state{};
	state.active = true;
	state.tag = BULLET_TAG;

	states[bullet] = state;
}

static void InitBulletTimer(Entity bullet) {
	Timer timer{};
	timer.cb_time = 2000.f;
	timer.timer = 0.f;
	timer.callback = DeactivateBullet;

	timers.resize(GetCurrentEntity());
	timers[bullet] = timer;
}

void InitBullet() {
	Entity bullet;
	bool activated_bullet = false;

	for (size_t i = 0; i < Bullets.size(); i++) {
		const Entity b = Bullets.at(i);
		if (!states[b].active) {
			bullet = b;
			activated_bullet = true;
			break;
		}
	}

	if (!activated_bullet) {
		bullet = CreateEntity();
		InitBulletBody(bullet);

		Bullets.push_back(bullet);

	}

	std::cout << "Init bullet with ID: " << bullet << std::endl;

	InitBulletPosition(bullet);
	InitBulletTransform(bullet);
	InitBulletMovement(bullet);
	InitState(bullet);
	AddActorToLayer(bullet, 0);
}

void DeactivateBullet(Entity bullet) {
	positions[bullet] = { -100.f, -100.f };
	transforms[bullet].rotation = 0.f;
	velocities[bullet] = { 0.f, 0.f };
	states[bullet].active = false;
}