#ifndef _EVENT_
#define _EVENT_
#include<vector>
#include<string>
#include<game/Entity.h>

typedef void (*Event)(
	std::string tag_a,
	std::string tag_b,
	Entity entity_a,
	Entity entity_b
	);

extern std::vector<Event> EnterCollisionEvents;
extern std::vector<Event> ExitCollisionEvents;

void DispatchEvents();

#endif // !_EVENT_
