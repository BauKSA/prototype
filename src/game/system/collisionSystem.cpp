#include<vector>
#include<iostream>

#include<game/system/AABB.h>
#include<game/system/CollisionSystem.h>
#include<game/component/Body.h>
#include<game/component/Shape.h>
#include<game/component/Collision.h>
#include<game/component/State.h>
#include<game/Entity.h>

static void Compare(ShapeComponent a, ShapeComponent b, Entity entity_a, Entity entity_b) {
	if (AABB_Intersect(a.shape, b.shape)) {
		std::cout << "Collision detected between main Entity " << entity_a << " and secondary Entity " << entity_b << std::endl;
		CollisionEvent event;
		event.entity_a = entity_a;
		event.entity_b = entity_b;
		event.tag_a = a.tag;
		event.tag_b = b.tag;

		collisionEvents.push_back(event);
		collissionEventCount++;
	}
}

void CheckCollisions() {
	collisionEvents.clear();
	collissionEventCount = 0;

	for (size_t i = 0; i < bodies.size(); i++) {
		Entity entity_a = i;
		const Body& body = *bodies[i];
		if (!body.shape_generated) continue;
		if (!states[i].active) continue;

		for (const ShapeComponent& shape : shapes[i]) {
			for (size_t j = i + 1; j < bodies.size(); j++) {
				Entity entity_b = j;
				const Body& body_b = *bodies[j];

				if (!body_b.shape_generated) continue;
				if (!states[j].active) continue;
				if (entity_a == entity_b) continue;

				for (const ShapeComponent& other : shapes[j]) {
					Compare(shape, other, entity_a, entity_b);
				}
			}
		}
	}
}