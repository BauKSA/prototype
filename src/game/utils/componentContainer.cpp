#include<vector>
#include<unordered_set>

#include<game/component/Position.h>
#include<game/component/Body.h>
#include<game/component/Transform.h>
#include<game/component/Velocity.h>
#include<game/component/Speed.h>
#include<game/component/State.h>
#include<game/component/Shape.h>
#include<game/component/Collision.h>
#include<game/component/Timer.h>
#include<game/event/Event.h>
#include<game/Entity.h>

std::vector<Position> positions;
std::vector<Body*> bodies;
std::vector<Transform> transforms;
std::vector<Velocity> velocities;
std::vector<Speed> speeds;
std::vector<State> states;
std::vector<bool> animations_to_update;
std::vector<Shape> shapes;
std::vector<CollisionEvent> collisionEvents;
std::vector<CollisionEvent> exitEvents;
std::vector<Event> EnterCollisionEvents;
std::vector<Event> ExitCollisionEvents;
unsigned int collissionEventCount;
unsigned int exitEventCount;
std::unordered_set<EntityPair, EntityPairHash> previousCollisions;
std::unordered_set<EntityPair, EntityPairHash> currentCollisions;
std::vector<Event> events;
std::vector<Timer> timers;
std::vector<Entity> timedEntities;