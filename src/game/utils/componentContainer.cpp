#include<vector>

#include<game/component/Position.h>
#include<game/component/Body.h>
#include<game/component/Transform.h>
#include<game/component/Velocity.h>
#include<game/component/Speed.h>
#include<game/component/State.h>
#include<game/component/Shape.h>
#include<game/component/Collision.h>
#include<game/event/Event.h>

std::vector<Position> positions;
std::vector<Body*> bodies;
std::vector<Transform> transforms;
std::vector<Velocity> velocities;
std::vector<Speed> speeds;
std::vector<State> states;
std::vector<bool> animations_to_update;
std::vector<Shape> shapes;
std::vector<CollisionEvent> collisionEvents;
unsigned int collissionEventCount;
std::vector<Event> events;