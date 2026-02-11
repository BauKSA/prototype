#include<vector>
#include<string>

#include<actors/star/Star.h>
#include<game/Entity.h>

#include<game/component/Body.h>
#include<game/component/Position.h>
#include<game/component/Transform.h>
#include<game/component/Speed.h>
#include<game/component/Velocity.h>
#include<game/component/State.h>
#include<game/component/Layer.h>
#include<game/utils/ColorConversor.h>
#include <SFML/Graphics/Color.hpp>

std::vector<Entity> stars;
std::string STAR_TAG = "STAR";

static void InitStarBody(Entity star) {
    Body* starBody = new Body;
    Vertex starVertex;

    // Agregamos los puntos de la nave
    starVertex.coords.push_back({ 0, 9 });
    starVertex.coords.push_back({ 3, 6 });
    starVertex.coords.push_back({ 6, 6 });
    starVertex.coords.push_back({ 6, 3 });
    starVertex.coords.push_back({ 9, 0 });
    starVertex.coords.push_back({ 6, -3 });
    starVertex.coords.push_back({ 6, -3 });
    starVertex.coords.push_back({ 6, -6 });
    starVertex.coords.push_back({ 3, -6 });
    starVertex.coords.push_back({ 0, -9 });
    starVertex.coords.push_back({ -3, -6 });
    starVertex.coords.push_back({ -6, -6 });
    starVertex.coords.push_back({ -6, -3 });
    starVertex.coords.push_back({ -9, 0 });
    starVertex.coords.push_back({ -9, 0 });
    starVertex.coords.push_back({ -6, 3 });
    starVertex.coords.push_back({ -6, 6 });
    starVertex.coords.push_back({ -3, 6 });

    starVertex.color = SfToHex(sf::Color::Black);
    starVertex.outline = SfToHex(sf::Color::Cyan);
    starVertex.tag = "main";

    Coord offset{ 0, 0 };
	starVertex.offset = offset;

    // Agregamos el vertex al body
    starBody->components.push_back(starVertex);
	starBody->shape_generated = false;

    // Contenedor global de bodies (ECS estilo simple)
    bodies.resize(GetCurrentEntity());
    bodies[star] = starBody;
}

static void InitStarPosition(Entity star) {
    Position starPosition{};
    starPosition.x = 400;
    starPosition.y = 300;

    positions.resize(GetCurrentEntity());
    positions[star] = starPosition;
}

static void InitStarTransform(Entity star) {
    Transform starTransform{};
    starTransform.rotation = 0.f;

    transforms.resize(GetCurrentEntity());
    transforms[star] = starTransform;
}

static void InitStarMovement(Entity star) {
    speeds.resize(GetCurrentEntity());
    speeds[star] = .35f;

    velocities.resize(GetCurrentEntity());
    velocities[star] = { 0.f, 0.f };
}

static void InitState(Entity star) {
    State state{};
    state.tag = STAR_TAG;
    state.active = true;

    states.resize(GetCurrentEntity());
    states[star] = state;
}

void InitStar() {
	Entity star = CreateEntity();
    AddActorToLayer(star, 0);
    InitStarBody(star);
    InitStarPosition(star);
    InitStarTransform(star);
    InitStarMovement(star);
    InitState(star);
}