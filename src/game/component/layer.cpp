#include<game/component/Layer.h>
#include<game/Entity.h>
#include<cstdint>
#include<vector>
#include<algorithm>

std::vector<Layer> layers;

void AddActorToLayer(Entity e, int8_t layer) {
	layers.push_back({ e, layer });

	std::sort(layers.begin(), layers.end(), [](const Layer& a, const Layer& b) {
		return a.depth < b.depth;
		});
}