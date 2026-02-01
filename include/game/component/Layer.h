#ifndef _LAYER_
#define _LAYER_
#include<game/Entity.h>
#include <cstdint>
#include<vector>

struct Layer {
	Entity entity;
	int8_t depth;
};

void AddActorToLayer(Entity e, int8_t layer);
extern std::vector<Layer> layers;

#endif // !_LAYER_