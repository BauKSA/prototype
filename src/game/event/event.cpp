#include<game/event/Event.h>
#include<game/component/Collision.h>

void DispatchEvents() {
	if (collissionEventCount == 0) return;

	for (size_t i = 0; i < collissionEventCount; i++) {
		CollisionEvent& event = collisionEvents[i];
		for (const Event& e : events) {
			e(event.tag_a, event.tag_b, event.entity_a, event.entity_b);
		}
	}
}