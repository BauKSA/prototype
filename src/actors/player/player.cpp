#include <vector>
#include <SFML/Graphics/Color.hpp>

#include "game/Entity.h"
#include "game/component/Body.h"
#include "game/component/Position.h"
#include "game/component/Transform.h"
#include "game/component/Speed.h"
#include "game/component/Velocity.h"
#include "game/utils/ColorConversor.h"
#include "actors/player/Player.h"
#include<game/component/State.h>
#include<game/component/Layer.h>
#include<game/component/Animation.h>

Entity Player = CreateEntity();

static void InitPlayerBody() {
    Body* shipBody = new Body;
    Body* shipBodyGreen = new Body;
    Vertex shipVertex;

    // Agregamos los puntos de la nave
    shipVertex.coords.push_back({ 0, -15 });
    shipVertex.coords.push_back({ -15, 15 });
    shipVertex.coords.push_back({ 0, 5 });
    shipVertex.coords.push_back({ 15, 15 });

    shipVertex.color = SfToHex(sf::Color::Black);
    shipVertex.outline = SfToHex(sf::Color::White);

    Vertex shipVertexGreen;

    // Agregamos los puntos de la nave
    shipVertexGreen.coords.push_back({ 0, -15 });
    shipVertexGreen.coords.push_back({ -15, 15 });
    shipVertexGreen.coords.push_back({ 0, 5 });
    shipVertexGreen.coords.push_back({ 15, 15 });

    shipVertexGreen.color = SfToHex(sf::Color::Black);
    shipVertexGreen.outline = SfToHex(sf::Color::Green);


    // Agregamos el vertex al body
    shipBody->components.push_back(shipVertex);
    shipBodyGreen->components.push_back(shipVertexGreen);

    // Contenedor global de bodies (ECS estilo simple)
    bodies.resize(GetCurrentEntity());
    bodies[Player] = shipBody;

    Animation anim{};
    anim.active = true;
	anim.name = "PLAYER_IDLE";
	anim.entity = Player;
    anim.frame_count = 2;
    anim.bodies.push_back(*shipBody);
    anim.bodies.push_back(*shipBodyGreen);

    animations_to_update.resize(GetCurrentEntity());
	animations_to_update[Player] = false;

    animations.resize(GetCurrentEntity());
    animations[Player][0] = anim;
}

static void InitPlayerPosition() {
    Position playerPosition{};
    playerPosition.x = 400;
    playerPosition.y = 300;

    positions.resize(GetCurrentEntity());
    positions[Player] = playerPosition;
}

static void InitPlayerTransform() {
    Transform playerTransform{};
    playerTransform.rotation = 75.f;

    transforms.resize(GetCurrentEntity());
    transforms[Player] = playerTransform;
}

static void InitPlayerMovement() {
    speeds.resize(GetCurrentEntity());
    speeds[Player] = .35f;
    
    velocities.resize(GetCurrentEntity());
    velocities[Player] = { 0.f, 0.f };
}

static void InitState() {
    State state{};
    state.tag = "PLAYER";
    state.active = true;

    states.resize(GetCurrentEntity());
    states[Player] = state;
}

void InitPlayer() {
    InitPlayerBody();
    InitPlayerPosition();
    InitPlayerTransform();
    InitPlayerMovement();
    InitState();
	AddActorToLayer(Player, 1);
}