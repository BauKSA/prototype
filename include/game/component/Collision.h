#ifndef _COLLISION_
#define _COLLISION_
#include<vector>
#include<game/Entity.h>
#include<string>
#include<unordered_set>
#include<functional>

struct CollisionEvent {
	std::string tag_a;
	std::string tag_b;
	Entity entity_a;
	Entity entity_b;
};

struct EntityPair {
	std::string tag_a;
	std::string tag_b;
	Entity entity_a;
	Entity entity_b;

    bool operator==(const EntityPair& other) const {
        return (tag_a == other.tag_a && tag_b == other.tag_b)
			|| (tag_a == other.tag_b && tag_b == other.tag_a);
    }
};

struct EntityPairHash {
    std::size_t operator()(const EntityPair& p) const {
        return std::hash<std::string>()(p.tag_a) ^ std::hash<std::string>()(p.tag_b);
    }
};

extern std::unordered_set<EntityPair, EntityPairHash> previousCollisions;
extern std::unordered_set<EntityPair, EntityPairHash> currentCollisions;

extern std::vector<CollisionEvent> collisionEvents;
extern std::vector<CollisionEvent> exitEvents;
extern unsigned int collissionEventCount;
extern unsigned int exitEventCount;
#endif // !_COLLISION_
