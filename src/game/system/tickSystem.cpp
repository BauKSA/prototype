#include<game/system/TickSystem.h>
#include<game/component/Tick.h>
#include<game/Entity.h>

void TickSystem(float delta_time) {
	for (size_t i = 0; i < tickedEntities.size(); i++) {
		Entity e = tickedEntities.at(i);
		ticks[e](e, delta_time);
	}
}