#include<game/Entity.h>
#include<game/component/Body.h>
#include<game/component/Position.h>
#include<game/component/Transform.h>
#include<game/component/Speed.h>
#include<game/component/Velocity.h>
#include<game/component/State.h>

void Resize() {
    unsigned int& current = GetCurrentEntity();
    unsigned int size = current + 1;

    bodies.resize(size);
    positions.resize(size);
    transforms.resize(size);
    speeds.resize(size);
    velocities.resize(size);
    states.resize(size);
}