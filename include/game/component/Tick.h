#ifndef _TICK_
#define _TICK_
#include<functional>
#include<vector>

#include<game/Entity.h>

typedef std::function<void(Entity, float)> Tick;

extern std::vector<Tick> ticks;
extern std::vector<Entity> tickedEntities;

#endif // !_TICK_