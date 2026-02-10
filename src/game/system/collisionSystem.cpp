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
		EntityPair pair{ a.tag, b.tag, entity_a, entity_b };
		currentCollisions.insert(pair);

		if (previousCollisions.find(pair) == previousCollisions.end()) {
			CollisionEvent event;
			event.entity_a = entity_a;
			event.entity_b = entity_b;
			event.tag_a = a.tag;
			event.tag_b = b.tag;

			collisionEvents.push_back(event);
			collissionEventCount++;
			std::cout << "Collision detected between " << entity_a << " and " << entity_b << std::endl;
		}
	}
}

static void HandleExitCollision() {
	for (const auto& pair : previousCollisions) {
		if (currentCollisions.find(pair) == currentCollisions.end()) {
			std::cout << "Exit collision between " << pair.tag_a << " and " << pair.tag_b << std::endl;

			CollisionEvent exitEvent;
			exitEvent.entity_a = pair.entity_a;
			exitEvent.entity_b = pair.entity_b;
			exitEvent.tag_a = pair.tag_a;
			exitEvent.tag_b = pair.tag_b;

			exitEvents.push_back(exitEvent);
			exitEventCount++;
		}
	}

	previousCollisions = currentCollisions;
	currentCollisions.clear();
}

void CheckCollisions() {
	collisionEvents.clear();
	collissionEventCount = 0;

	exitEvents.clear();
	exitEventCount = 0;

	for (size_t i = 0; i < bodies.size(); i++) {
		Entity entity_a = i;
		if (bodies[i] == nullptr) continue;
		const Body& body = *bodies[i];
		if (!body.shape_generated) continue;
		if (!states[i].active) continue;

		for (const ShapeComponent& shape : shapes[i]) {
			for (size_t j = i + 1; j < bodies.size(); j++) {
				Entity entity_b = j;
				if (bodies[j] == nullptr) continue;

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

	HandleExitCollision();
}