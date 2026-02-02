#ifndef _COLLISION_
#define _COLLISION_
#include<vector>
#include<game/Entity.h>

struct CollisionEvent {
	std::string tag_a;
	std::string tag_b;
	Entity entity_a;
	Entity entity_b;
};

extern std::vector<CollisionEvent> collisionEvents;
extern unsigned int collissionEventCount;
#endif // !_COLLISION_
