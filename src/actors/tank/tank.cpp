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
#include "actors/tank/Tank.h"
#include "actors/player/Player.h"
#include<game/component/State.h>
#include<game/component/Layer.h>
#include<game/component/Timer.h>


std::vector<Entity> tanks;
std::string TANK_TAG = "TAG";

static void InitTankBody(Entity tank) {
	Body* tankBody = new Body;
	Vertex tankVertex;

	tankVertex.coords.push_back({ 0, 0 });
	tankVertex.coords.push_back({ 0, 26 });
	tankVertex.coords.push_back({ 20, 26 });
	tankVertex.coords.push_back({ 20, 0 });

	Vertex cannonVertex;

	cannonVertex.coords.push_back({ 0,  3 });
	cannonVertex.coords.push_back({ 0, 6 });
	cannonVertex.coords.push_back({ 10, 6 });
	cannonVertex.coords.push_back({ 10,  3 });

	cannonVertex.color = SfToHex(sf::Color::Black);
	cannonVertex.outline = SfToHex(sf::Color::Cyan);
	cannonVertex.tag = "cannon";

	tankVertex.color = SfToHex(sf::Color::Black);
	tankVertex.outline = SfToHex(sf::Color::Blue);
	tankVertex.tag = "main";

	Coord offset{ -10, -13 };
	Coord empty_offset{ 0, 0 };

	tankVertex.offset = empty_offset;
	cannonVertex.offset = offset;

	tankBody->components.push_back(tankVertex);
	tankBody->components.push_back(cannonVertex);
	tankBody->shape_generated = false;

	bodies.resize(GetCurrentEntity());
	bodies[tank] = tankBody;
}

static void InitTankPosition(Entity tank) {
	Position tankPosition{};
	tankPosition.x = 0.f;
	tankPosition.y = 450.f;

	positions[tank] = tankPosition;
}

static void InitTankTransform(Entity tank) {
	Transform tankTransform{};
	tankTransform.rotation = 45.f;

	transforms[tank] = tankTransform;
}

static void InitState(Entity tank) {
	State state{};
	state.active = true;
	state.tag = TANK_TAG;

	states[tank] = state;
}

void InitTank() {
	Entity tank;
	bool activated_tank = false;

	for (size_t i = 0; i < tanks.size(); i++) {
		const Entity b = tanks.at(i);
		if (!states[b].active) {
			tank = b;
			activated_tank = true;
			break;
		}
	}

	if (!activated_tank) {
		tank = CreateEntity();
		InitTankBody(tank);

		tanks.push_back(tank);
	}

	std::cout << "Init tank with ID: " << tank << std::endl;

	InitTankPosition(tank);
	InitTankTransform(tank);
	InitState(tank);
	AddActorToLayer(tank, 0);
}

void DeactivateTank(Entity tank) {
	positions[tank] = { -100.f, -100.f };
	transforms[tank].rotation = 0.f;
	velocities[tank] = { 0.f, 0.f };
	states[tank].active = false;
}