#include<vector>
#include<SFML/Graphics/Color.hpp>
#include<iostream>
#include<string>

#include "game/Entity.h"
#include "game/component/Body.h"
#include "game/component/Position.h"
#include "game/component/Transform.h"
#include "game/utils/ColorConversor.h"
#include<game/component/State.h>
#include<game/component/Layer.h>
#include<actors/circuits/CircuitTag.h>

static void InitCircuitBody(Entity circuit) {
	Body* circuitBody = new Body;
	Vertex circuitVertex;

	circuitVertex.coords.push_back({ 0, -250 });
	circuitVertex.coords.push_back({ 0, 250 });
	circuitVertex.coords.push_back({ 8000, 250 });
	circuitVertex.coords.push_back({ 8000, -250 });

	circuitVertex.color = SfToHex(sf::Color::Transparent);
	circuitVertex.outline = SfToHex(sf::Color::Magenta);
	circuitVertex.tag = "main";

	Coord offset{ 0, 0 };
	circuitVertex.offset = offset;

	circuitBody->components.push_back(circuitVertex);
	circuitBody->shape_generated = false;

	bodies.resize(GetCurrentEntity());
	bodies[circuit] = circuitBody;
}

static void InitCircuitPosition(Entity circuit) {
	Position circuitPosition{};
	circuitPosition.x = 400;
	circuitPosition.y = 300;

	positions[circuit] = circuitPosition;
}

static void InitCircuitTransform(Entity circuit) {
	Transform circuitTransform{};
	circuitTransform.rotation = 0.f;

	transforms[circuit] = circuitTransform;
}

static void InitState(Entity circuit) {
	State state{};
	state.active = true;
	state.tag = CIRCUIT_TAG;

	states[circuit] = state;
}

void InitExampleCircuit() {
	Entity circuit = CreateEntity();

	InitCircuitBody(circuit);


	std::cout << "Init Example Circuit with ID: " << circuit << std::endl;

	InitCircuitPosition(circuit);
	InitCircuitTransform(circuit);
	InitState(circuit);
	AddActorToLayer(circuit, -1);
}