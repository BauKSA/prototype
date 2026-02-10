#include<game/event/Event.h>
#include<game/component/Collision.h>

void DispatchEvents() {
	if (collissionEventCount == 0 && exitEventCount == 0) return;

	for (size_t i = 0; i < collissionEventCount; i++) {
		CollisionEvent& event = collisionEvents[i];
		for (const Event& e : EnterCollisionEvents) {
			e(event.tag_a, event.tag_b, event.entity_a, event.entity_b);
		}
	}

	for (size_t i = 0; i < exitEventCount; i++) {
		CollisionEvent& event = exitEvents[i];
		for (const Event& e : ExitCollisionEvents) {
			e(event.tag_a, event.tag_b, event.entity_a, event.entity_b);
		}
	}
}