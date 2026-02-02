#include<vector>
#include<iostream>

#include<game/system/AABB.h>
#include<game/system/CollisionSystem.h>
#include<game/component/Body.h>
#include<game/component/Shape.h>
#include<game/Entity.h>

static void Compare(ShapeComponent a, ShapeComponent b, Entity entity_a, Entity entity_b) {
	if (AABB_Intersect(a.shape, b.shape)) {
		std::cout << "Collision detected between Entity " << entity_a << " and Entity " << entity_b << std::endl;
	}
}

void CheckCollisions() {
	for (size_t i = 0; i < bodies.size(); i++) {
		Entity entity_a = i;
		const Body& body = *bodies[i];
		if (!body.shape_generated) continue;

		for (const ShapeComponent& shape : shapes[i]) {
			for (size_t j = 0; j < bodies.size(); j++) {
				Entity entity_b = j;
				if (entity_a == entity_b) continue;

				for (const ShapeComponent& other : shapes[j]) {
					Compare(shape, other, entity_a, entity_b);
				}
			}
		}
	}
}