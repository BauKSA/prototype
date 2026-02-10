#include<actors/splinter/Splinter.h>
#include<vector>
#include<SFML/Graphics/Color.hpp>
#include<iostream>

#include<game/Entity.h>
#include<game/component/Body.h>
#include<game/component/Position.h>
#include<game/component/Transform.h>
#include<game/component/Speed.h>
#include<game/component/Velocity.h>
#include<game/utils/ColorConversor.h>
#include<game/utils/Random.h>
#include<game/component/State.h>
#include<game/component/Layer.h>
#include<game/component/Timer.h>
#include<string>

std::vector<Entity> splinters;
std::string SPLINTER_TAG = "SPLINTER";

static void InitSplinterBody(Entity splinter) {
    Body* splinterBody = new Body;
    Vertex splinterVertex;

    splinterVertex.coords.push_back({ 0, 0 });
    splinterVertex.coords.push_back({ 1, 1 });
    splinterVertex.coords.push_back({ 0, 2 });
    splinterVertex.coords.push_back({ 1, -1 });
    splinterVertex.coords.push_back({ 1, 0 });
    splinterVertex.coords.push_back({ 0, -1 });
    splinterVertex.coords.push_back({ -1, -2 });
    splinterVertex.coords.push_back({ -1, -1 });
    splinterVertex.coords.push_back({ -2, 0 });
    splinterVertex.coords.push_back({ -1, 1 });

    splinterVertex.color = SfToHex(sf::Color::Yellow);
    splinterVertex.outline = SfToHex(sf::Color::Red);

    splinterBody->components.push_back(splinterVertex);
	splinterBody->shape_generated = false;

    bodies[splinter] = splinterBody;
}

static void InitSplinterPosition(Entity splinter, float x, float y) {
    Position splinterPosition{};
    splinterPosition.x = x;
    splinterPosition.y = y;

    positions[splinter] = splinterPosition;
}

static void InitSplinterTransform(Entity splinter, float angle) {
    Transform splinterTransform{};

    splinterTransform.rotation = angle;

    transforms[splinter] = splinterTransform;
}

static void InitSplinterMovement(Entity splinter) {
    speeds[splinter] = .75f;

    velocities[splinter] = { 0.f, 0.f };
}

static void InitState(Entity splinter) {
    State state{};
    state.active = true;
    state.tag = SPLINTER_TAG;

    states[splinter] = state;
}

static void InitSplinterTimer(Entity splinter) {
    int t = random(50, 200);

    Timer timer{};
    timer.timer = 0.f;
    timer.cb_time = t;
    timer.callback = DeactivateSplinter;

    timers.resize(GetCurrentEntity());
    timers[splinter] = timer;
    timedEntities.push_back(splinter);
}

void InitSplinter(float x, float y, float angle) {
    Entity splinter;
    bool activated_splinter = false;

    for (size_t i = 0; i < splinters.size(); i++) {
        const Entity b = splinters.at(i);
        if (!states[b].active) {
            splinter = b;
            activated_splinter = true;
            break;
        }
    }

    if (!activated_splinter) {
        splinter = CreateEntity();
        InitSplinterBody(splinter);
        InitSplinterTimer(splinter);

        splinters.push_back(splinter);
    }

    std::cout << "Init splinter with ID: " << splinter << std::endl;

    InitState(splinter);
    InitSplinterPosition(splinter, x, y);
    InitSplinterTransform(splinter, angle);
    InitSplinterMovement(splinter);
    AddActorToLayer(splinter, 0);
}

void DeactivateSplinter(Entity bullet) {
    positions[bullet] = { -100.f, -100.f };
    transforms[bullet].rotation = 0.f;
    velocities[bullet] = { 0.f, 0.f };
    states[bullet].active = false;
}